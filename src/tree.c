#include <tree.h>

Tree * Tree_new(void * value)
{
    Tree * self = malloc(sizeof(Tree));
    self->children = List_new();
    self->value = value;
    return self;
}
void Tree_free(Tree * self)
{
    List_free(self->children);
    free(self);
}