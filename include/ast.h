#pragma once
#include <stdlib.h>

typedef enum {
    AstNodeType_UNKNOWN,
    //
    AstNodeType_ASSIGN,
    AstNodeType_ADD,
    AstNodeType_SUB,
    AstNodeType_MUL,
    AstNodeType_DIV,
    AstNodeType_MOD,
    AstNodeType_EQ,
    AstNodeType_NEQ,
    AstNodeType_NOT,
    AstNodeType_GT,
    AstNodeType_LT,
    AstNodeType_LTEQ,
    AstNodeType_GTEQ,
    AstNodeType_AND,
    AstNodeType_OR,
    //...
    AstNodeType_NUMBER,
    AstNodeType_STRING,
    AstNodeType_ID,
    AstNodeType_BOOL,
    AstNodeType_CHARACTER,
    //
    AstNodeType_ARGLIST,
    //
    AstNodeType_BLOCK,
    AstNodeType_IF,
    AstNodeType_ELSE,
    AstNodeType_WHILE,
    AstNodeType_DECLAREVAR,
    //
    AstNodeType_PROGRAM,
} AstNodeType;

typedef struct __AstNode AstNode;
struct __AstNode
{
    AstNodeType type;
    const char *name;
    // @todo extra data
};

AstNode *AstNode_new(AstNodeType type, const char *name);
void AstNode_free(AstNode *self);