#include <stack.h>
#include <_list.h>
struct _Stack
{
    List * list;
};

Stack * Stack_new()
{
    Stack * self = malloc(sizeof(Stack));
    self->list = List_new();
    return self;
}
void  Stack_free(Stack * self)
{
    List_free(self->list);
    free(self);
}

void Stack_push(Stack * self, void * value)
{
    List_add(self->list, value);
}
void * Stack_peek(Stack * self)
{
    int lastI = List_count(self->list) -1;
    return List_at(self->list, lastI);
}
void * Stack_pop(Stack * self)
{
    int lastI = List_count(self->list) -1;
    void * tmp = List_at(self->list, lastI);
    List_removeAt(self->list, lastI);
    return tmp;
}
bool Stack_isEmpty(Stack * self)
{
    return List_count(self->list) == 0;
}