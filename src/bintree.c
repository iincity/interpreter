#include <bintree.h> 

BinTree * BinTree_new(void * value)
{
    BinTree * self = malloc(sizeof(BinTree));
    if(self == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        abort();
    }
    self->value = value;
    self->right = NULL;
    self->left = NULL;
    return self;
}
void BinTree_free(BinTree * self)
{
    if(self == NULL) return;
    free(self);
}