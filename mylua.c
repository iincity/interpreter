#include <stdio.h>
#include <lexer.h>
#include <parser.h>
#include <stringbuffer.h>
#include <string.h>
#include <ast.h>
#include <interpreter.h>
#include <dict.h>
#include <fs.h>
#include <preetyprint.h>


int main(int argc, const char ** argv)
{
    //const char *fileName = "../main.pivo";
    if(argc != 2) 
    {
        puts(">>>ERROR: Invalid run arguments\nTip: Add filename to firts argument\nExample: ./task3.out ../main.mlua");
        return EXIT_FAILURE;
    }
    const char *fileName = argv[1];
    if(!fileExists(fileName)) return EXIT_FAILURE;
    int size = getFileSize(fileName);
    char input[size + size];
    readFileToBuffer(fileName, input, size + size);
    input[size] = '\0';
    List *tokens = List_new();
    if (0 != Lexer_splitTokens(input, tokens))
    {
        Lexer_clearTokens(tokens);
        List_free(tokens);
        return EXIT_FAILURE;
    }
    Tree *prog = Parser_buildNewAstTree(tokens);
    if (prog)
    {
        int runStatus = Interpreter_execute(prog);
        Parser_freeAstTree(prog);
    }
    Lexer_clearTokens(tokens);
    List_free(tokens);
    return EXIT_SUCCESS;
}
