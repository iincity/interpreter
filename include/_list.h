#pragma once
#include <iterator.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
static const int INITIAL_CAPACITY  = 16;

typedef struct List List;

List * List_new(void);
void List_free(List * self);
void List_insert(List * self, int index, void * value);
void List_add(List * self, void * value);
size_t List_count(List * self);
void * List_at(List * self, int index);
void * List_removeAt(List * self, int index);

void * List_set(List * self, size_t index, void * value);

Iterator * List_getNewBeginIterator (List * self);
Iterator * List_getNewEndIterator   (List * self);