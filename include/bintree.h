#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct __BinTree BinTree;
struct __BinTree {
    void  * value;
    BinTree * left;
    BinTree * right;
};

BinTree * BinTree_new(void * value);
void BinTree_free(BinTree * self);
