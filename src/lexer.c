#include <lexer.h>
#include <ctype.h>
#include <string.h>
#include <stringbuffer.h>


/*
typedef enum {
    TokenType_LPAR,
    TokenType_RPAR,
    TokenType_LBLOCK,
    TokenType_RBLOCK,
    TokenType_PLUS,
    TokenType_MINUS,
    TokenType_SEPARATOR,
    TokenType_MULT,
    TokenType_ASSIGNMENT,
    TokenType_COMMA,
    TokenType_CHARPAR,
    TokenType_BOOLOPERATOR,
    TokenType_EQUALITY,
    TokenType_EQLOW,
    TokenType_EQHIGH,
    TokenType_LOW,
    TokenType_HIGH,
    TokenType_LOGOR,
    TokenType_LOGAND,    
    TokenType_DIV,
    TokenType_POW,
    TokenType_NUMBER,
    TokenType_KEYWORD,
    TokenType_IF,
    TokenType_ELSE,
    TokenType_WHILE,
    TokenType_VARDECL,
    TokenType_IDENTIFIER,
    TokenType_NEWLINE,
    TokenType_STRING,
    TokenType_ERROR
} TokenType;
*/

static const char * tokenTable[] =
{
    "(",
    ")",
    "{",
    "}",
    "+",
    "-",
    ";",
    "*",
    "=",
    ",",
    "'",
    "bool",
    "==",
    "<=",
    ">=",
    "<",
    ">",
    "||",
    "&&",
    "/",
    "pow",
    "number",
    "keyword",
    "if",
    "else",
    "while",
    "var",
    "id",
    "\'n",
    "str",
    "error",
    "!=",
    "mod",
    "!",
    "true",
    "false"
};

Token *Token_new(TokenType type, const char *name)
{
    Token *self = malloc(sizeof(Token));
    if (self == NULL)
    {
        // out of memory
        abort();
    }
    self->name = name;
    self->type = type;
    return self;
}

static  void printLine(const char * str)
{
    while(*str != '\n' && *str != '\0')
    {
        putchar(*str);
        str++;
    }
    putchar('\n');
}

void Token_free(Token *self)
{
    if (self == NULL)
        return;
    // if(self->type == TokenType_NUMBER)
    free((char *)self->name);
    free(self);
    self = NULL;
}
bool Token_equals(Token *self, Token *other)
{
    if (self->type == other->type && !strcmp(self->name, other->name))
        return true;
    return false;
}

void TokenType_print(TokenType type)
{
    switch (type)
    {
    case TokenType_DIV:
        printf("/");
        break;
    case TokenType_MINUS:
        printf("-");
        break;
    case TokenType_MULT:
        printf("*");
        break;
    case TokenType_NUMBER:
        printf("NUM, ");
        break;
    case TokenType_ASSIGNMENT:
        printf("=");
        break;
    case TokenType_BOOLOPERATOR:
        printf("BOOL");
        break;
    case TokenType_COMMA:
        printf(",");
        break;
    case TokenType_CHARPAR:
        printf("CHARACTER");
        break;
    case TokenType_POW:
        printf("**");
        break;
    case TokenType_PLUS:
        printf("+");
        break;
    case TokenType_LPAR:
        printf("(");
        break;
    case TokenType_RPAR:
        printf(")");
        break;
    case TokenType_STRING:
        printf("STRING");
        break;
    case TokenType_KEYWORD:
        printf("KEYWORD, ");
        break;
    case TokenType_NEWLINE:
        printf("NEWLINE");
        break;
    case TokenType_IF:
        printf("IF");
        break;
    case TokenType_WHILE:
        printf("WHILE");
        break;
    case TokenType_VARDECL:
        printf("VARDECL");
        break;
    case TokenType_IDENTIFIER:
        printf("ID, ");
        break;
    case TokenType_RBLOCK:
        printf("END");
    case TokenType_LBLOCK:
        printf("DO");
        break;
    default:
        printf("Undefined");
        break;
    }
}

void TokenType_printToFile(TokenType type, FILE *f)
{
    switch (type)
    {
    case TokenType_DIV:
        fprintf(f, "/");
        break;
    case TokenType_LOGOR:
        fprintf(f, "||");
    break;
    case TokenType_LOGAND:
        fprintf(f, "&&");
    break;
    case TokenType_EQUALITY:
        fprintf(f, "==");
    break;
    case TokenType_EQHIGH:
        fprintf(f, ">=");
    break;
    case TokenType_EQLOW:
        fprintf(f, "<=");
    break;
    case TokenType_HIGH:
    fprintf(f, ">");
    break;
    case TokenType_LOW:
    fprintf(f, "<");
    break;
    case TokenType_MINUS:
        fprintf(f, "-");
        break;
    case TokenType_MULT:
        fprintf(f, "*");
        break;
    case TokenType_NUMBER:
        fprintf(f, "NUM, ");
        break;
    case TokenType_ASSIGNMENT:
        fprintf(f, "=");
        break;
    case TokenType_BOOLOPERATOR:
        fprintf(f, "BOOL, ");
        break;
    case TokenType_COMMA:
        fprintf(f, ",");
        break;
    case TokenType_CHARPAR:
        fprintf(f, "CHARACTER, ");
        break;
    case TokenType_POW:
        fprintf(f, "**");
        break;
    case TokenType_PLUS:
        fprintf(f, "+");
        break;
    case TokenType_LPAR:
        fprintf(f, "(");
        break;
    case TokenType_RPAR:
        fprintf(f, ")");
        break;
    case TokenType_STRING:
        fprintf(f, "STRING, ");
        break;
    case TokenType_SEPARATOR:
        fprintf(f, "SEPARATOR");
        break;
    case TokenType_KEYWORD:
        fprintf(f, "KEYWORD, ");
        break;
    case TokenType_NEWLINE:
        fprintf(f, "NEWLINE");
        break;
    case TokenType_IDENTIFIER:
        fprintf(f, "ID, ");
        break;
    case TokenType_IF:
        fprintf(f, "IF");
        break;
    case TokenType_VARDECL:
        fprintf(f, "VARDECL");
        break;
    case TokenType_WHILE:
        fprintf(f, "WHILE");
        break;
    case TokenType_RBLOCK:
        fprintf(f, "END");
        break;
    case TokenType_LBLOCK:
        fprintf(f, "DO");
        break;
    case TokenType_TRUE:
        fprintf(f, "TRUE");
        break;
    case TokenType_FALSE:
        fprintf(f, "FALSE");
        break;
    default:
        fprintf(f, "Undefined");
        break;
    }
}
void Lexer_printTokensToFile(List *tokens, FILE *f)
{
    int size = List_count(tokens);
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "<");
        Token *b = List_at(tokens, i);
        TokenType_printToFile(b->type, f);
        if (b->type == TokenType_NUMBER || b->type == TokenType_IDENTIFIER || b->type == TokenType_KEYWORD || b->type == TokenType_CHARPAR || b->type == TokenType_STRING || b->type == TokenType_BOOLOPERATOR)
            fprintf(f, "%s", b->name);
        fprintf(f, ">");
        if (b->type == TokenType_SEPARATOR 
            || b->type == TokenType_LBLOCK
            || b->type == TokenType_RBLOCK)
            fprintf(f, "\n");
    }
}

int Lexer_splitTokens(const char *input, List *tokens)
{
    StringBuffer *sb = StringBuffer_new();
    while (1)
    {
        if (*input == '\0')
        {
            break;
        }
        else if (*input == '(')
        {
            StringBuffer_appendChar(sb, '(');
            List_add(tokens, Token_new(TokenType_LPAR, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == ')')
        {
            StringBuffer_appendChar(sb, ')');
            List_add(tokens, Token_new(TokenType_RPAR, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '+')
        {
            StringBuffer_appendChar(sb, '+');
            List_add(tokens, Token_new(TokenType_PLUS, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '-')
        {
            StringBuffer_appendChar(sb, '-');
            List_add(tokens, Token_new(TokenType_MINUS, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '%')
        {
            StringBuffer_appendChar(sb, '%');
            List_add(tokens, Token_new(TokenType_MOD, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '*')
        {
            StringBuffer_appendChar(sb, '*');
            List_add(tokens, Token_new(TokenType_MULT, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == ';')
        {
            StringBuffer_appendChar(sb, ';');
            List_add(tokens, Token_new(TokenType_SEPARATOR, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '{')
        {
            StringBuffer_appendChar(sb, '{');
            List_add(tokens, Token_new(TokenType_LBLOCK, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '}')
        {
            StringBuffer_appendChar(sb, '}');
            List_add(tokens, Token_new(TokenType_RBLOCK, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '/')
        {
            StringBuffer_appendChar(sb, '/');
            List_add(tokens, Token_new(TokenType_DIV, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '\n')
        {
            StringBuffer_appendChar(sb, '\n');
           // List_add(tokens, Token_new(TokenType_NEWLINE, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (isdigit(*input))
        {
            StringBuffer_clear(sb);
            if(*input == '0' && isdigit(*(input + 1)))
            {
                printf("ERROR>>: unknown token at line:\n");
                printLine(input);
                StringBuffer_free(sb);
                return 1;
            }

            while (isdigit(*input) || *input == '.')
            {
                StringBuffer_appendChar(sb, *input);
                input++;
            }
            List_add(tokens, Token_new(TokenType_NUMBER, StringBuffer_toNewString(sb)));
            input--;
            StringBuffer_clear(sb);
        }
        else if (isalnum(*input) || *input == '_')
        {
            StringBuffer_clear(sb);
            while (isalnum(*input) ||  *input == '_')
            {
                StringBuffer_appendChar(sb, *input);
                input++;
            }
            char *lexeme = StringBuffer_toNewString(sb);
            if (!strcmp(lexeme, "while"))
                List_add(tokens, Token_new(TokenType_WHILE, lexeme));
            else if (!strcmp(lexeme, "if"))
                List_add(tokens, Token_new(TokenType_IF, lexeme));
            else if (!strcmp(lexeme, "else"))
                List_add(tokens, Token_new(TokenType_ELSE, lexeme));
            else if (!strcmp(lexeme, "var"))
                List_add(tokens, Token_new(TokenType_VARDECL, lexeme));
            else if (!strcmp(lexeme, "true"))
                List_add(tokens, Token_new(TokenType_TRUE, lexeme));
            else if (!strcmp(lexeme, "false"))
                List_add(tokens, Token_new(TokenType_FALSE, lexeme));
            else
                List_add(tokens, Token_new(TokenType_IDENTIFIER, lexeme));
            input--;
            StringBuffer_clear(sb);
        }
        else if (*input == '"')
        {
            input++;
            StringBuffer_clear(sb);
            while (*input != '"' && *input != '\0')
            {
                StringBuffer_appendChar(sb, *input);
                input++;
            }
            if (*input == '\0')
            {
                StringBuffer_free(sb);
                return 1;
            }
            char *lexeme = StringBuffer_toNewString(sb);
            List_add(tokens, Token_new(TokenType_STRING, lexeme));
            //input--;
            StringBuffer_clear(sb);
        }
        else if (*input == '=' || *input == '>' || *input == '<' || *input == '!')
        {
            StringBuffer_clear(sb);
            while (*input == '=' || *input == '>' || *input == '<' || *input == '!')
            {
                StringBuffer_appendChar(sb, *input);
                input++;
            }
            char *lexeme = StringBuffer_toNewString(sb);
            if (!strcmp(lexeme, "="))
                List_add(tokens, Token_new(TokenType_ASSIGNMENT, lexeme));
            else if (!strcmp(lexeme, "=="))
                List_add(tokens, Token_new(TokenType_EQUALITY, lexeme));
            else if (!strcmp(lexeme, "<="))
                List_add(tokens, Token_new(TokenType_EQLOW, lexeme));
            else if (!strcmp(lexeme, ">="))
                List_add(tokens, Token_new(TokenType_EQHIGH, lexeme));
            else if (!strcmp(lexeme, "<"))
                List_add(tokens, Token_new(TokenType_LOW, lexeme));
            else if (!strcmp(lexeme, ">"))
                List_add(tokens, Token_new(TokenType_HIGH, lexeme));
            else if (!strcmp(lexeme, "!="))
                List_add(tokens, Token_new(TokenType_NEQUALITY, lexeme));
            else if (!strcmp(lexeme, "!"))
                List_add(tokens, Token_new(TokenType_NOT, lexeme));
            else
            {
                printf("ERROR>>: unknown token at line:\n");
                printLine(input);
                StringBuffer_free(sb);
                free(lexeme);
                return 1;
            }
            input--;
            StringBuffer_clear(sb);
        }
        else if (*input == '&' || *input == '|')
        {
            StringBuffer_clear(sb);
            while (!isspace(*input) && !isalnum(*input))
            {
                StringBuffer_appendChar(sb, *input);
                input++;
            }
            char *lexeme = StringBuffer_toNewString(sb);
            if (!strcmp(lexeme, "||"))
                List_add(tokens, Token_new(TokenType_LOGOR, lexeme));
            else if (!strcmp(lexeme, "&&"))
                List_add(tokens, Token_new(TokenType_LOGAND, lexeme));
            else
            {
                printf("ERROR>>: unknown token at line:\n");
                printLine(input);
                StringBuffer_free(sb);
                free(lexeme);
                return 1;
            }
            input--;
            StringBuffer_clear(sb);
        }
        else if (isspace(*input))
        {
            //do nothing
        }
        else if (*input == ',')
        {
            StringBuffer_appendChar(sb, ',');
            List_add(tokens, Token_new(TokenType_COMMA, StringBuffer_toNewString(sb)));
            StringBuffer_clear(sb);
        }
        else if (*input == '\'')
        {
            input++;
            StringBuffer_clear(sb);
            while (*input != '\'' && *input != '\0')
            {
                StringBuffer_appendChar(sb, *input);
                input++;
            }
            if (*input == '\0')
            {
                StringBuffer_free(sb);
                return 1;
            }
            char *lexeme = StringBuffer_toNewString(sb);
            List_add(tokens, Token_new(TokenType_CHARPAR, lexeme));
            //input--;
            StringBuffer_clear(sb);
        }
        else
        {
            printf("ERROR>>: unknown token at line:\n");
            printLine(input);
            StringBuffer_free(sb);
            return 1;
        }
        input++;
    }
    StringBuffer_free(sb);
    return 0;
}
void Lexer_clearTokens(List *tokens)
{
    if (tokens == NULL)
        return;
    int count = List_count(tokens);
    for (int i = 0; i < count; i++)
    {
        Token_free(List_at(tokens, i));
    }
}

void Lexer_printTokens(List *tokens)
{
    int size = List_count(tokens);
    for (int i = 0; i < size; i++)
    {
        printf("<");
        Token *b = List_at(tokens, i);
        TokenType_print(b->type);
        if (b->type == TokenType_NUMBER || b->type == TokenType_IDENTIFIER || b->type == TokenType_KEYWORD)
            printf("%s", b->name);
        printf(">");
        if (b->type == TokenType_SEPARATOR)
            puts("");
    }
}

const char * TokenType_printToString(TokenType type)
{
   /* char * buf = tokenTable[type];
    char * res = malloc((strlen(buf) + 1) * sizeof(char));
    res[0] = '\0';
        strcpy(res, buf);*/
    return tokenTable[type];
}