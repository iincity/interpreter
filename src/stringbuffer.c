#include <stringbuffer.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

struct __StringBuffer
{
    char * buffer;
    size_t capacity;
    size_t length;

};

static const int INITIAL_CAPACITY = 256;

 char *ft_strdup(char *src)
{
    char *str;
    char *p;
    int len = 0;

    while (src[len])
        len++;
    str = malloc(len + 1);
    p = str;
    while (*src)
        *p++ = *src++;
    *p = '\0';
    return str;
}



StringBuffer * StringBuffer_new(void)
{
    StringBuffer * self = malloc(sizeof(StringBuffer));
    self->capacity = INITIAL_CAPACITY;
    self->length = 1;
    self->buffer = malloc(sizeof(char)* self->capacity);
    self->buffer[0]  = '\0';
    return self;
}
void StringBuffer_free(StringBuffer * self)
{
    free(self->buffer);
    free(self);
}

void StringBuffer_appendFormat(StringBuffer * self, const char * fmt, ...)
{
    va_list vlist;
    va_start(vlist, fmt);
    size_t bufsz = vsnprintf(NULL, 0, fmt, vlist);
    char * buf = malloc(bufsz + 1);
    va_start(vlist, fmt);
    vsnprintf(buf, bufsz + 1, fmt, vlist);
    va_end(vlist);
    StringBuffer_append(self, buf);
    free(buf);
}

void StringBuffer_append(StringBuffer * self, const char * str)
{
    size_t strLen = strlen(str);
    size_t newBufferLength = strLen + self->length;
    if(newBufferLength > self->capacity)
    {
        self->capacity *= 2;
        self->buffer = realloc(self->buffer, self->capacity * sizeof(char));
        if(self->buffer == NULL)
        {
            // out of memory
            abort();
        }
    }
    strcat(self->buffer + (self->length - 1), str);
}

void StringBuffer_appendChar(StringBuffer * self, char charA)
{
    self->buffer[self->length-1] = charA;
    self->buffer[self->length] = '\0';
    self->length++;
}

char * StringBuffer_toNewString(StringBuffer * self)
{   
    return ft_strdup(self->buffer);
}
void StringBuffer_clear(StringBuffer * self)
{
    self->buffer[0] = '\0';
    self->length = 1;
}