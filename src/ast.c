#include <ast.h>
#include <stringbuffer.h>

AstNode *AstNode_new(AstNodeType type, const char *name)
{
    AstNode * self = malloc(sizeof(AstNode));
    if(self == NULL)
    {
     //   fprintf(stderr, "No memory");
        abort();
    }
    self->type = type;
    self->name = ft_strdup((char *)name);
    return self;
}
void AstNode_free(AstNode *self)
{
    if(self == NULL) return;
    free((void *)self->name);
    free(self);
    self = NULL;
}
//