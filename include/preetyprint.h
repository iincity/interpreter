#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <tree.h>

void AstTree_prettyPrint(Tree *astTree);
void AstTree_prettyPrintToFile(Tree *astTree, FILE * fp);
