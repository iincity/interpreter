#pragma once
#include <stdbool.h>
typedef struct _Stack Stack;

Stack * Stack_new();
void  Stack_free(Stack * self);

void Stack_push(Stack * self, void * value);
void * Stack_peek(Stack * self);
void * Stack_pop(Stack * self);
bool Stack_isEmpty(Stack * self);