#include <dict.h>
#include <string.h>

typedef struct
{
    char * key;
    void * value;
}KeyValuePair;
struct __Dict
{
    List * pairs;
};


KeyValuePair * Kvp_new(char * key, void * value)
{
    KeyValuePair * self = malloc(sizeof(KeyValuePair));
    self->key = key;
    self->value = value;
    return self;
}

void Kvp_free(KeyValuePair * self) {
    free(self);
}

Dict * Dict_new(void)
{
    Dict * self = malloc(sizeof(Dict));
    self->pairs = List_new();
    return self;
}
void Dict_free(Dict * self)
{
    List_free(self->pairs);
    free(self);
}

void   Dict_add      (Dict * self, char * key, void * value)
{
    KeyValuePair * pair = Kvp_new(key, value);
    List_add(self->pairs, pair);
}
bool   Dict_contains (Dict * self, char * key)
{
    int count =  List_count(self->pairs);
    for(int i = 0; i <count; i++)
    {
        KeyValuePair * pair = List_at(self->pairs, i);
        if(!strcmp(pair->key, key)) return true;
    }
    return false;
}
void * Dict_get      (Dict * self, char * key)
{
    int count =  List_count(self->pairs);
    for(int i = 0; i <count; i++)
    {
        KeyValuePair * pair = List_at(self->pairs, i);
        if(!strcmp(pair->key, key)) return pair->value;
    }
    // @todo error
    return NULL;
}
void * Dict_set      (Dict * self, char * key, void * value)
{
    int count =  List_count(self->pairs);
    for(int i = 0; i <count; i++)
    {
        KeyValuePair * pair = List_at(self->pairs, i);
        if(!strcmp(pair->key, key))
        {
            void * oldValue = pair->value;
            pair->value = value;
            return oldValue;
        }
    }
    // @todo error
    return NULL;
}
void * Dict_remove   (Dict * self, char * key)
{
    int index = -1;
    int count =  List_count(self->pairs);
    for(int i = 0; i <count; i++)
    {
        KeyValuePair * pair = List_at(self->pairs, i);
        if(!strcmp(pair->key, key))
        {
           index = i;
           break;
        }
    }
    if(index > -1)
    {
        KeyValuePair * removedPair = List_removeAt(self->pairs, index);
        void * oldValue = removedPair->value;
        Kvp_free(removedPair);
        return oldValue;
    }
    // @todo error
    return NULL;
}
void   Dict_clear    (Dict * self)
{
    int count =  List_count(self->pairs);
    for(int i = count - 1; i >= 0 ; i--)
    {
        KeyValuePair * pair = List_at(self->pairs, i); 
        (void)List_removeAt(self->pairs, i);
        Kvp_free(pair);
    }   
}
size_t Dict_count    (Dict * self)
{
    return List_count(self->pairs);
}

void   Dict_keys     (Dict * self, List * keys)
{
    int count =  List_count(self->pairs);
    for(int i = 0; i <count; i++)
    {
        KeyValuePair * pair = List_at(self->pairs, i);
        List_add(keys, pair->key);
    }
}
void   Dict_values   (Dict * self, List * values)
{
    int count =  List_count(self->pairs);
    for(int i = 0; i <count; i++)
    {
        KeyValuePair * pair = List_at(self->pairs, i);
        List_add(values, pair->value);
    }
}
