#pragma once
#include <_list.h>
#include <stringbuffer.h>
#include <stdlib.h>
#include <stdbool.h>

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
    TokenType_ERROR,
    TokenType_NEQUALITY,
    TokenType_MOD,
    TokenType_NOT,
    TokenType_TRUE,
    TokenType_FALSE
} TokenType;

typedef struct __Token Token;

struct __Token {
   TokenType type;
   const char * name;
   // @todo extra data
};

Token * Token_new(TokenType type, const char * name);
void Token_free(Token * self);
bool Token_equals(Token * self, Token * other);


void TokenType_print(TokenType type);
const char * TokenType_printToString(TokenType type);
void Lexer_printTokensToFile(List *tokens, FILE *f);
void TokenType_printToBuffer(TokenType type, FILE *f);

int Lexer_splitTokens(const char * input, List * tokens);
void Lexer_clearTokens(List * tokens);

void Lexer_printTokens(List * tokens);
