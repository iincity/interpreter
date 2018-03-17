#include <parser.h>
#include <ctype.h>
#include <_list.h>
#include <stdlib.h>
#include <ast.h>
#include <string.h>
#include <tree.h>
#include <stringbuffer.h>

// check current token type
static Tree * accept(Parser * self, TokenType tokenType);
// expect exactly that token type or fail
static Tree * expect(Parser * self, TokenType tokenType);
static AstNodeType TokenType_toAstNodeType(TokenType);

void Parser_freeAstTree(Tree * self)
{
    if(self == NULL) return;

    int count = List_count(self->children);
    for(int i = 0; i < count; i++)
    {
        Tree * child = (Tree *)List_at(self->children, i);
        Parser_freeAstTree(child);
    }
    AstNode * node = (AstNode *)self->value;
    //puts(node->name);
    AstNode_free(node);
    Tree_free(self);
}

static Tree * prog      (Parser * parser);
static Tree * var_decl  (Parser * parser);
static Tree * st        (Parser * parser);
static Tree * ID        (Parser * parser);
static Tree * expr      (Parser * parser);
static Tree * expr_st   (Parser * parser);
static Tree * block_st  (Parser * parser);
static Tree * select_st (Parser * parser);
static Tree * iter_st   (Parser * parser);
static Tree * assign    (Parser * parser);
static Tree * assign_ap (Parser * parser);
static Tree * log_or    (Parser * parser);
static Tree * log_or_ap (Parser * parser);
static Tree * log_and   (Parser * parser);
static Tree * log_and_ap(Parser * parser);
static Tree * eq        (Parser * parser);
static Tree * eq_ap     (Parser * parser);
static Tree * rel       (Parser * parser);
static Tree * rel_ap    (Parser * parser);
static Tree * add       (Parser * parser);
static Tree * add_ap    (Parser * parser);
static Tree * mult      (Parser * parser);
static Tree * mult_ap   (Parser * parser);
static Tree * unary     (Parser * parser);
static Tree * primary   (Parser * parser);
static Tree * NUMBER    (Parser * parser);
static Tree * CHARACTER (Parser * parser);
static Tree * STRING    (Parser * parser);
static Tree * var_or_call(Parser * parser);
static Tree * parentheses(Parser * parser);
static Tree * fn_call    (Parser * parser);
static Tree * arg_list   (Parser * parser);

// ebnf

static bool isNullChild(Parser * parser, Tree * self)
{
    int count = List_count(self->children);
    for(int i = 0; i < count; i++)
        if(!List_at(self->children, i))
        {
            (void)List_removeAt(self->children, i);
            if(!parser->error) parser->error = ft_strdup("invalid expression");
            Parser_freeAstTree(self);
            return true;
        }
    return false;
}

static bool isNullAllChild(Parser * parser, Tree * self)
{
    if(self->children == NULL) return false;

    int count = List_count(self->children);
    if(isNullChild(parser, self)) return true;
    for(int i = 0; i < count; i++)
        if(isNullAllChild(parser, List_at(self->children, i))) return true;

    return false;
}

Tree * Parser_buildNewAstTree(List * tokens)
{
    Parser parser = 
    {
        .tokens = List_getNewBeginIterator(tokens),
        .tokensEnd = List_getNewEndIterator(tokens),
        .error = NULL,
        .level = -1
    };
    Tree * progNode = prog(&parser);

    if(parser.error)
    {
        fprintf(stderr, ">>>>ERROR: %s\n", parser.error);
        free((void*)parser.error);
        Iterator_free(parser.tokens);
        Iterator_free(parser.tokensEnd);
        Parser_freeAstTree(progNode);
        return NULL;
    }
    else  if(!Iterator_equals(parser.tokens, parser.tokensEnd))
    {
        Token * token  = Iterator_value(parser.tokens);
        fprintf(stderr, ">>>>ERROR: unexpected token %s\n", TokenType_printToString(token->type));  
        Iterator_free(parser.tokens);
        Iterator_free(parser.tokensEnd);
        Parser_freeAstTree(progNode);
        return NULL;
    }
    Iterator_free(parser.tokens);
    Iterator_free(parser.tokensEnd);
    return progNode;

}

typedef Tree * (*GrammarRule)(Parser * parser);

static bool ebnf_multiple(Parser * parser, List * nodes,  GrammarRule rule)
{
    Tree * node = NULL;
    while((node = rule(parser)) && !parser->error)
    {
        List_add(nodes, node);
    }
    return parser->error == NULL ? true : false;
}

static Tree * ebnf_select(Parser * parser, GrammarRule rules[], size_t rulesLen)
{
    Tree * node = NULL;
    for(int i = 0; i < rulesLen && !node; i++)
    {
        GrammarRule rule = rules[i];
        node = rule(parser);
        if(parser->error) return NULL;
    }
    return node;
}

static Tree * ebnf_selectLexemes(Parser * parser, TokenType types[], size_t typesLen)
{
    Tree * node = NULL;
    for(int i = 0; i < typesLen && !node; i++)
        node = accept(parser, types[i]);
    return node;
}

static Tree * ebnf_ap_main_rule(Parser * parser, GrammarRule next, GrammarRule ap)
{
    Tree * nextNode = next(parser);
    if(nextNode)
    {
        Tree * apNode = ap(parser);
        if(apNode) {
            List_insert(apNode->children, 0 ,nextNode);
            //
            return apNode;
        }
        return nextNode;
    }
    return NULL;
}

static Tree * ebnf_ap_recursive_rule(Parser * parser, TokenType types[], size_t typesLen, GrammarRule next, GrammarRule ap)
{
    Tree * opNode = ebnf_selectLexemes(parser, types, typesLen);
    if(opNode == NULL) return NULL;
    Tree * rightSubtree = NULL;
    Tree * nextNode = next(parser);
    Tree * apNode = ap(parser);
    if(apNode)
    {
        List_insert(apNode->children, 0, nextNode);
        rightSubtree = apNode;
    }
    else rightSubtree = nextNode;

    List_add(opNode->children, rightSubtree);
    return opNode;
}

static bool eoi(Parser * self)
{
    return Iterator_equals(self->tokens, self->tokensEnd);
}

static AstNodeType TokenType_toAstNodeType(TokenType type)
{
    switch(type)
    {
        case TokenType_ASSIGNMENT: return AstNodeType_ASSIGN;
        case TokenType_TRUE: return AstNodeType_BOOL;
        case TokenType_FALSE: return AstNodeType_BOOL;
        case TokenType_PLUS: return AstNodeType_ADD;
        case TokenType_MINUS: return AstNodeType_SUB;
        case TokenType_MULT: return AstNodeType_MUL;
        case TokenType_DIV: return AstNodeType_DIV;
        case TokenType_MOD: return AstNodeType_MOD;
        case TokenType_EQUALITY: return AstNodeType_EQ;
        case TokenType_NEQUALITY: return AstNodeType_NEQ;
        case TokenType_NOT: return AstNodeType_NOT;
        case TokenType_LOW: return AstNodeType_LT;
        case TokenType_HIGH: return AstNodeType_GT;
        case TokenType_EQLOW: return AstNodeType_LTEQ;
        case TokenType_EQHIGH: return AstNodeType_GTEQ;
        case TokenType_LOGAND: return AstNodeType_AND;
        case TokenType_LOGOR: return AstNodeType_OR;
        //
        case TokenType_IDENTIFIER: return AstNodeType_ID;
        case TokenType_NUMBER: return AstNodeType_NUMBER;
        case TokenType_STRING: return AstNodeType_STRING;
        case TokenType_CHARPAR: return AstNodeType_CHARACTER;
        //
        default: return AstNodeType_UNKNOWN;
    }
}

static Tree * accept(Parser * self, TokenType tokenType)
{
    if(eoi(self)) return NULL;
    Token * token = Iterator_value(self->tokens);
    if(token->type == tokenType)
    {
        AstNodeType astType = TokenType_toAstNodeType(tokenType);
       // char * astName = ft_strdup((char *)token->name);
        char * astName = (char *)token->name;
        AstNode * node = AstNode_new(astType, astName);
        Tree * tree = Tree_new(node);
        Iterator_next(self->tokens);
        return tree;
    }
    return NULL;
}


#define TRACE_CALL() \
parser->level++; \
Parser * _parserPtr  __attribute((cleanup(Parser_decLevel))) = parser;
// __attribute((cleanup(Parser_decLevel)))
//trace(parser, __func__);
void Parser_decLevel(Parser ** parserPtr)
{
    (*parserPtr)->level--;
}

#define TRACE_EXPECT(TYPE) \
;


//traceExpect(parser, TYPE);

static void traceLevel(int level)
{
    for(int i = 0; i < level; i++)
    {
        putchar('.');
        putchar('.');        
    }
}

static void traceExpect(Parser * parser, TokenType expectedType)
{
    traceLevel(parser->level);
    printf("<%s>\n", TokenType_printToString(expectedType));
}

static void trace(Parser * parser, const char * fn)
{
    traceLevel(parser->level);
    if(eoi(parser))
    {
        printf("%s: <EOI>\n", fn);
        return;
    }
    Token *  token = Iterator_value(parser->tokens);
    TokenType type = token->type;
    switch(type)
    {
        case TokenType_IDENTIFIER:
        case TokenType_NUMBER:
        case TokenType_STRING:
        case TokenType_CHARPAR:
        {
            printf("%s: <%s,%s>\n", 
            fn,
            TokenType_printToString(token->type), token->name);
            break;
        }
        default: 
        {
            printf("%s: <%s>\n", 
            fn,
            TokenType_printToString(token->type));
            break;
        }
    }
    
}
 
// expect exactly that token type or fail
static Tree * expect(Parser * parser, TokenType tokenType)
{
    Tree * tree = accept(parser, tokenType);
    if(tree != NULL)
    {
        TRACE_EXPECT(tokenType);
        return tree;
    }
    const char * currentTokenType = eoi(parser)
        ? "end-of-input" 
        : TokenType_printToString(((Token *)Iterator_value(parser->tokens))->type);

    StringBuffer * sb = StringBuffer_new();
    if(!strcmp(currentTokenType, "var")) StringBuffer_append(sb,"Invalid variable declaration");
    else StringBuffer_appendFormat(sb, "expected '%s' got '%s'.\n", TokenType_printToString(tokenType), currentTokenType);
    parser->error = StringBuffer_toNewString(sb);
    StringBuffer_free(sb);
    return NULL;
}

static Tree * ID        (Parser * parser)
{
    TRACE_CALL();
    return accept(parser, TokenType_IDENTIFIER);
}
static Tree * NUMBER     (Parser * parser)
{
    TRACE_CALL();
    return accept(parser, TokenType_NUMBER);
}

static Tree * BOOL_TRUE     (Parser * parser)
{
    TRACE_CALL();
    return accept(parser, TokenType_TRUE);
}
static Tree * BOOL_FALSE     (Parser * parser)
{
    TRACE_CALL();
    return accept(parser, TokenType_FALSE);
}

static Tree * CHARACTER     (Parser * parser)
{
    TRACE_CALL();
    return accept(parser, TokenType_CHARPAR);
}

static Tree * STRING     (Parser * parser)
{
    TRACE_CALL();
    return accept(parser, TokenType_STRING);
}

static Tree * ID_expect       (Parser * parser)
{  
    return expect(parser, TokenType_IDENTIFIER);
}
static Tree * NUMBER_expect     (Parser * parser)
{
    return expect(parser, TokenType_NUMBER);
}
static Tree * STRING_expect     (Parser * parser)
{
    return expect(parser, TokenType_STRING);
}

static Tree * prog      (Parser * parser)
{
    TRACE_CALL();
    Tree * progNode = Tree_new(AstNode_new(AstNodeType_PROGRAM, "program"));
    
    while(!eoi(parser))
    {
        (void)ebnf_multiple(parser, progNode->children, st);
        if(parser->error) 
        {
            Parser_freeAstTree(progNode);
            return NULL; 
        } 
    }
    return progNode;
}
static Tree * var_decl  (Parser * parser)
{
    TRACE_CALL();
    Tree * vardeclNode = accept(parser, TokenType_VARDECL);
    if(!vardeclNode) return NULL;
    Parser_freeAstTree(vardeclNode);
    Tree * idNode = ID_expect(parser);
    if(!idNode) return NULL;

    Tree * assignNode = expect(parser, TokenType_ASSIGNMENT);
    if(!assignNode)
    {
        //@todo error
        if(!parser->error) parser->error = ft_strdup("expected '='");
        Parser_freeAstTree(idNode);
        return NULL;
    }
    Parser_freeAstTree(assignNode);
    Tree * exprNode = expr(parser);
    if(exprNode == NULL)
    {
        //@todo error
        if(!parser->error) parser->error = ft_strdup("expected expression");
        Parser_freeAstTree(idNode);
        //Parser_freeAstTree(exprNode);
        return NULL;
    }
    Tree * separatorNode = expect(parser, TokenType_SEPARATOR);

    if(!separatorNode)
    {
        //@todo error
        if(!parser->error) parser->error = ft_strdup("expected ';");
        Parser_freeAstTree(idNode);
        Parser_freeAstTree(exprNode);
        return NULL;
    }
    Parser_freeAstTree(separatorNode);
    Tree * varDecl = Tree_new(AstNode_new(AstNodeType_DECLAREVAR, "declareVar"));

    List_add(varDecl->children, idNode);
    List_add(varDecl->children, exprNode);

    return varDecl;
}
static Tree * st        (Parser * parser)
{
    TRACE_CALL();
    return ebnf_select(parser,
        (GrammarRule[]) {
            var_decl,
            block_st,
            select_st,
            iter_st,
            expr_st
        }, 5);
}

static Tree * expr      (Parser * parser)
{
    TRACE_CALL();
    return assign(parser);
}
static Tree * expr_st   (Parser * parser)
{
    TRACE_CALL();
    Tree * exprNode = expr(parser);
    if(exprNode)
    {
        Tree * separator = expect(parser, TokenType_SEPARATOR);
        if(!separator) {
            Parser_freeAstTree(exprNode);
            //return NULL;
        }
        Parser_freeAstTree(separator);
    }
    else 
    {
        Tree * separator = accept(parser, TokenType_SEPARATOR);
        Parser_freeAstTree(separator);
    }
    return exprNode;
}
static Tree * block_st  (Parser * parser)
{
    TRACE_CALL();
    Tree * openBlock = accept(parser, TokenType_LBLOCK);
    if(!openBlock) return NULL;
    Parser_freeAstTree(openBlock);
    Tree * blockNode = Tree_new(AstNode_new(AstNodeType_BLOCK, "block"));
    if(ebnf_multiple(parser, blockNode->children, st))
    {
       Tree * closeBlock = expect(parser, TokenType_RBLOCK);
       Parser_freeAstTree(closeBlock);
    } 
    return blockNode;
}
static Tree * select_st (Parser * parser)
{
    TRACE_CALL();
    Tree * ifOpen = accept(parser, TokenType_IF);
    if(ifOpen)
    {
        Tree * openSt = expect(parser, TokenType_LPAR);
        if(!openSt)
        {
            Parser_freeAstTree(ifOpen);
            return NULL;
        }
        Parser_freeAstTree(openSt);
    }
    else return NULL;
    Parser_freeAstTree(ifOpen);
    Tree * testExprNode = expr(parser);
    if(testExprNode == NULL)
    {
        //@todo error
       if (!parser->error)
            parser->error = ft_strdup("invalid expression");
        return NULL;
    }
    if(isNullAllChild(parser, testExprNode)) return NULL;
    Tree * closeSt = expect(parser, TokenType_RPAR);
    if(!closeSt) 
    {
        //@todo clear testExpr
        //@todo error
        Parser_freeAstTree(testExprNode);
        if (!parser->error) parser->error = ft_strdup("expected ')'");
        return NULL;
    }
    Parser_freeAstTree(closeSt);
    Tree * stNode =  st(parser);
    if(stNode == NULL) 
    {
        //@todo clear testExpr
        //@todo error
        Parser_freeAstTree(testExprNode);
        if (!parser->error) parser->error = ft_strdup("invalid statement");
        return NULL;
    }

    Tree * ifNode = Tree_new(AstNode_new(AstNodeType_IF, "if"));
    List_add(ifNode->children, testExprNode);
    List_add(ifNode->children, stNode);

    Tree * elseSt = accept(parser, TokenType_ELSE);
    if(elseSt)
    {
        Parser_freeAstTree(elseSt);
        Tree * elseNode = st(parser);
        if(elseNode == NULL || parser->error)
        {
            //@todo error
            if (!parser->error) parser->error = ft_strdup("invalid statement");
            Parser_freeAstTree(testExprNode);
            Parser_freeAstTree(stNode);
            return NULL;
        }
        List_add(ifNode->children, elseNode);
    }
    return ifNode;
}
static Tree * iter_st   (Parser * parser)
{
    TRACE_CALL();
    Tree * whileSt = accept(parser, TokenType_WHILE);
    if(whileSt)
    {
        Tree * openWhile = expect(parser, TokenType_LPAR);
        if(!openWhile)
        {
            Parser_freeAstTree(whileSt);
            return NULL;
        }
        Parser_freeAstTree(openWhile);
    }
    else return NULL;
    Parser_freeAstTree(whileSt);
    Tree * testExprNode = expr(parser);
    if(testExprNode == NULL)
    {
        //@todo error
        //Parser_freeAstTree(testExprNode);
        if (!parser->error) parser->error = ft_strdup("invalid expression");
        return NULL;
    }
    if(isNullAllChild(parser, testExprNode)) return NULL;
    Tree * closeWhile = expect(parser, TokenType_RPAR);
    if(!closeWhile) 
    {
        //@todo clear testExpr
        //@todo error
        if (!parser->error) parser->error = ft_strdup("expected ')'");
        Parser_freeAstTree(testExprNode);
        return NULL;
    }
    Parser_freeAstTree(closeWhile);
    Tree * stNode =  st(parser);
    if(stNode == NULL) 
    {
        //@todo clear testExpr
        if (!parser->error) parser->error = ft_strdup("invalid statement");
        //@todo error
        Parser_freeAstTree(testExprNode);
        return NULL;
    }

    Tree * whileNode = Tree_new(AstNode_new(AstNodeType_WHILE, "while"));
    List_add(whileNode->children, testExprNode);
    List_add(whileNode->children, stNode);
    return whileNode;
}
static Tree * assign     (Parser * parser)
{
    TRACE_CALL();
    Tree * assignNode = ebnf_ap_main_rule(parser, log_or, assign_ap);
    return assignNode;
}
static Tree * assign_ap  (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_ASSIGNMENT
    }, 1, log_or, assign_ap);
}
static Tree * add        (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_main_rule(parser, mult, add_ap);
}
static Tree * add_ap     (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_PLUS,
        TokenType_MINUS
    }, 2,
     mult, add_ap);
}
static Tree * log_or        (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_main_rule(parser, log_and, log_or_ap);
}
static Tree * log_or_ap     (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_LOGOR
    }, 1,
     log_and, log_or_ap);
}
static Tree * log_and        (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_main_rule(parser, eq, log_and_ap);
}
static Tree * log_and_ap     (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_LOGAND
    }, 1,
     eq, log_and_ap);
}
static Tree * eq        (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_main_rule(parser, rel, eq_ap);
}
static Tree * eq_ap     (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_EQUALITY,
        TokenType_NEQUALITY
    }, 2,
     rel, eq_ap);
}
static Tree * rel        (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_main_rule(parser, add, rel_ap);
}
static Tree * rel_ap     (Parser * parser)
{
    TRACE_CALL()
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_EQLOW,
        TokenType_EQHIGH,
        TokenType_LOW,
        TokenType_HIGH
    }, 4,
     add, rel_ap);
}
static Tree * mult       (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_main_rule(parser, unary, mult_ap);
}
static Tree * mult_ap    (Parser * parser)
{
    TRACE_CALL();
    return ebnf_ap_recursive_rule(parser, 
        (TokenType[]) {
        TokenType_MULT,
        TokenType_DIV,
        TokenType_MOD
    }, 3,
     unary, mult_ap);
}
static Tree * unary      (Parser * parser)
{
    TRACE_CALL();
    Tree * opNode = ebnf_selectLexemes(parser, 
    (TokenType[]) {
        TokenType_PLUS,
        TokenType_MINUS,
        TokenType_NOT
    }, 3);
    Tree * primNode = primary(parser);
    // @todo check NULL prim
    if(!primNode) 
    {
        if(opNode) Parser_freeAstTree(opNode);
        return NULL;
    }
    if(opNode)
    {
        List_add(opNode->children, primNode); 
        return opNode;
    }
    return primNode;
}
static Tree * primary    (Parser * parser)
{
    TRACE_CALL();
    return ebnf_select(parser,
        (GrammarRule[]) {
            NUMBER,
            STRING,
            CHARACTER,
            BOOL_TRUE,
            BOOL_FALSE,
            parentheses,
            var_or_call,
        }, 7);
}
static Tree * var_or_call(Parser * parser)
{
    TRACE_CALL();
    Tree * varNode = ID(parser);
    Tree * argListNode = fn_call(parser);
    if(argListNode)
        List_add(varNode->children, argListNode);
    return varNode;
}
static Tree * parentheses(Parser * parser)
{
    TRACE_CALL();
    Tree * openChild = accept(parser, TokenType_LPAR);
    if(!openChild) return NULL;
    Parser_freeAstTree(openChild);
    Tree * exprNode = expr(parser);
    Tree * closeChild = expect(parser, TokenType_RPAR); //@todo mb
    Parser_freeAstTree(closeChild);
    return exprNode;
}
static Tree * fn_call    (Parser * parser)
{
    TRACE_CALL();
    Tree * openSt = accept(parser, TokenType_LPAR);
    if(!openSt) return NULL;
    Parser_freeAstTree(openSt);
    Tree * argListNode = arg_list(parser);
    Tree * closeSt = expect(parser, TokenType_RPAR); //@todo mb
    Parser_freeAstTree(closeSt);
    return argListNode;
}
static Tree * arg_list   (Parser * parser)
{ 
    TRACE_CALL();
    Tree * exprNode = expr(parser);
    Tree * argListNode = Tree_new(AstNode_new(AstNodeType_ARGLIST, "arglist"));
    if(exprNode)
    {
        List_add(argListNode->children, exprNode);
        while(true)
        {
            Tree * comma = accept(parser, TokenType_COMMA);
            if(!comma) break;
            Parser_freeAstTree(comma);
            exprNode = expr(parser);
            if(exprNode)
                List_add(argListNode->children, exprNode);
            else break;

        }
        return argListNode;
    } 
    return argListNode;
}
