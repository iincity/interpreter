#include <_list.h>
#define NDEBUG

struct List
{
    void ** items;
    size_t length;
    size_t capacity;
};

List * List_new(void)
{
    List * self = malloc(sizeof(List));
    if(self == NULL)
    {
        fprintf(stderr, "Out of memory");
        abort();
    }
    self->capacity = INITIAL_CAPACITY;
    self->length = 0;
    void ** selfItems = malloc(sizeof(void*) * INITIAL_CAPACITY);
    if(selfItems == NULL) 
    {
        free(self);
        fprintf(stderr, "Out of memory");
        abort();
    }
    self->items = selfItems;
    return self;
}

void List_free(List * self)
{
    if(self == NULL) return;
    free(self->items);
    free(self);
}

void List_add(List * self, void * value)
{
    if(self->length == self->capacity)
    { 
        self->capacity *= 2;
        self->items = realloc(self->items, self->capacity * (sizeof(void *)));
        if(self == NULL)
        {
            fprintf(stderr, "Out of memory");
            abort();
        }
    }
    self->items[self->length] = value;
    self->length++;
}

size_t List_count(List * self) { return self->length; }

void * List_at(List * self, int index)
{
    if(self == NULL)
    {
        fprintf(stderr, "Pointer on NULL");
        assert(0 && "ptr null");
        return 0;
    }
    if(index >= self->length)
    {
        fprintf(stderr, "Invalid index");
        printf("!!!!!%i", index);
        assert(0 && "index invalid");
        return 0;
    }
    return self->items[index];
}

void List_insert(List * self, int index, void * value)
{
    if(self == NULL)
    {
        fprintf(stderr, "NULL PTR");
        assert(0);
        return;
    }
    if (List_count(self) <= index) 
    {

        fprintf(stderr, "Invalid index %i", (int)index);
        assert(0);
        return;
    }
    if(self->length == self->capacity)
    { 
        self->capacity *= 2;
        self->items = realloc(self->items, self->capacity * (sizeof(void *)));
        if(self == NULL)
        {
            fprintf(stderr, "Out of memory");
            abort();
        }
    }
    self->length++;
    for(int i = self->length-1; i >= (int)index; i--)
        self->items[i+1] = self->items[i];
    self->items[index] = value;
}

void * List_removeAt(List * self, int index)
{
    bool error = false;
    if(self == NULL) 
    {
        bool error = true;
        fprintf(stderr, "Pointer on NULL");
        assert(0 && "ptr null");
    }
    if(List_count(self) <= index)
    {
        bool error = true;
        fprintf(stderr, "Invalid index");
        assert(0 &&  "index");
    }
    if(error) return 0;

    void * toRemove = List_at(self,index);
    for(int i = index; i < self->length; i++)
        self->items[i] = self->items[i+1];
    self->length--;
    return toRemove;
}

void * List_set(List * self, size_t index, void * value)
{
    bool error = false;
    if(self == NULL) 
    {
        bool error = true;
        fprintf(stderr, "Pointer on NULL");
        assert(0);
    }
    if(List_count(self) <= index)
    {
        bool error = true;
        fprintf(stderr, "Invalid index");
        assert(0);
    }
    if(error) return 0;
    void * oldValue = List_at(self, index);
    self->items[index] = value;
    return oldValue;
}

//iterator

struct __Iterator {
    List * list;
    int index;
};

static Iterator * Iterator_new(List *list, int index)
{
    Iterator * self = malloc(sizeof(Iterator));
    self->list = list;
    self->index = index;
    return self;
}

Iterator * List_getNewBeginIterator(List* self)
{
    return Iterator_new(self, 0);
}

Iterator * List_getNewEndIterator(List* self)
{
    return Iterator_new(self, List_count(self));
}
void Iterator_free(Iterator * self)
{
    free(self);
}

void * Iterator_value    (Iterator * self)
{
    assert(self->index < List_count(self->list));
    return List_at(self->list, self->index);
}
void   Iterator_next     (Iterator * self)
{
    self->index++;
}
void   Iterator_prev     (Iterator * self)
{
    self->index--;
}
void   Iterator_advance  (Iterator * self, IteratorDistance n)
{
    self->index += n;
}
bool   Iterator_equals   (Iterator * self, Iterator * other)
{
    return self->list == other->list
            && self->index == other->index;
}
IteratorDistance Iterator_distance (Iterator * begin, Iterator * end)
{
    return end->index - begin->index;
}