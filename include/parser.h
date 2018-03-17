#pragma once
#include <_list.h>
#include <stdbool.h>
#include <lexer.h>
#include <tree.h>

//bool Parser_match(List * tokens);

typedef struct {
    Iterator * tokens;
    Iterator * tokensEnd;
    char * error;
    int level;
    // optional extra fields
} Parser;

Tree * Parser_buildNewAstTree(List * tokens);
void Parser_freeAstTree(Tree * self);
