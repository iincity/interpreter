#pragma once

#include <_list.h>

typedef struct __Tree Tree;
struct __Tree {
   void * value;
   List * children;
};

Tree * Tree_new(void * value);
void Tree_free(Tree * self);