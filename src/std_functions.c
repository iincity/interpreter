#include <std_functions.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stringbuffer.h>
#include <assert.h>
Value * std_print(Program * program, List * values)
{
    for(int i = 0; i < List_count(values); i++)
    {
        Value * value = List_at(values, i);
        //printf(">> ");
        Value_print(value);
        if(i > 0) puts("");
    }
    //printf("# %s()", __func__);

    return Value_newUndefined();
}

Value * std_pow(Program * program, List * values)
{
    if(List_count(values) != 2)
    {
        Program_setError(program, ft_strdup("Invalid number of pow arguments"));
        return NULL;
    }
    Value * toPowVal = List_at(values, 0);
    Value * powVal = List_at(values, 1);
    if(toPowVal->type != ValueType_NUMBER
    || powVal->type != ValueType_NUMBER) 
    {
        Program_setError(program, ft_strdup("Invalid pow argument type"));
        return NULL;
    }
    double toPow = Value_number(toPowVal);
    double powV = Value_number(powVal);

    return Value_newNumber(pow(toPow, powV));
}

Value * std_sqrt(Program * program, List * values)
{
    if(List_count(values) != 1)
    {
        Program_setError(program, ft_strdup("Invalid number of sqrt arguments"));
        return NULL;
    }
    Value * toSqrtVal = List_at(values, 0);
    if(toSqrtVal->type != ValueType_NUMBER)
    {
        Program_setError(program, ft_strdup("Invalid sqrt argument type"));
        return NULL;
    }
    double toSqrt = Value_number(toSqrtVal);
    if(toSqrt < 0)
    {
        Program_setError(program, ft_strdup("Invalid sqrt argument type"));
        return NULL;
    }


    return Value_newNumber(sqrt(toSqrt));
}


Value * std_strlen(Program * program, List * values)
{
    if(List_count(values) != 1)
    {
        Program_setError(program, ft_strdup("Invalid number of strlen arguments"));
        return NULL;
    }
    Value * strVal = List_at(values, 0);
    if(strVal->type != ValueType_STRING)
    {
        Program_setError(program, ft_strdup("Invalid argument type"));
        return NULL;
    }
    char * str = Value_string(strVal);
    int len = strlen(str);

    return Value_newNumber((double)len);
}
Value * std_substr(Program * program, List* values)
{
    if(List_count(values) != 3)
    {
        Program_setError(program, ft_strdup("Invalid number of substr arguments"));
        return NULL;
    }
    Value * strVal = List_at(values, 0);
    Value * startIndexVal = List_at(values, 1);
    Value * endIndexVal = List_at(values, 2);
    if(strVal->type != ValueType_STRING
    || startIndexVal->type != ValueType_NUMBER 
    || endIndexVal->type != ValueType_NUMBER)
    {
        Program_setError(program, ft_strdup("Invalid argument type"));
        return NULL;
    }
    char * str = Value_string(strVal);
    int start = (int)Value_number(startIndexVal);
    int end = (int)Value_number(endIndexVal);

    int len = strlen(str);

    if(end > len 
    || start >= len
    || start > end)
    {
        Program_setError(program, ft_strdup("Invalid argument value"));
        return NULL;
    }
    char result[len];
    result[0] = '\0';
    int j = 0;
    for(int i = start; i < end; i++)
    {
        result[j] = str[i];
        j++;
    }
    result[j] = '\0';
    return Value_newString(result);
}

Value * std_newTable(Program * program, List* values)
{
    if(List_count(values) != 0)
    {
        Program_setError(program, ft_strdup("Invalid number of substr arguments"));
        return NULL;
    }
    return Value_newTable();
}

Value * std_push(Program * program, List* values)
{
    if(List_count(values) != 2)
    {
        Program_setError(program, ft_strdup("Invalid number of push arguments"));
        return NULL;
    }
    

    Value * tableVal = List_at(values, 0);
    Table * table = tableVal->value;
    if(tableVal->type != ValueType_TABLE)
    {
        Program_setError(program, ft_strdup("Invalid argument value"));
        return NULL;
    }
    Value * toAddVal = List_at(values, 1);

    //List_removeAt(values, 0);
    List_add(table->table, Value_newCopy(toAddVal));
    Value * retVal = Value_newTableFromTable(table);
    //Value_freeTable(tableVal);
    return retVal;
}

Value * std_at(Program * program, List* values)
{
    if(List_count(values) != 2)
    {
        Program_setError(program, ft_strdup("Invalid number of at arguments"));
        return NULL;
    }
    Value * tableVal = List_at(values, 0);
    Value * indexVal = List_at(values, 1);
   
    if( indexVal->type != ValueType_NUMBER)
    {
        Program_setError(program, ft_strdup("Invalid argument at value"));
        return NULL;
    }
    if(tableVal->type == ValueType_TABLE)
    {
        Table * table = Value_table(tableVal);
        int index = Value_number(indexVal);
    
        if(index >= List_count(table->table) || index < 0)
        {
            Program_setError(program, ft_strdup("Invalid argument at value"));
            return NULL;
        }
        return Value_newCopy(List_at(table->table, index));
    }
    else if(tableVal->type == ValueType_STRING)
    {
        char * str = Value_string(tableVal);
        int index = Value_number(indexVal);
    
        if(index > strlen(str) || index < 0)
        {
            Program_setError(program, ft_strdup("Invalid argument at value"));
            return NULL;
        }
        return Value_newCharFromChar(str[index]);
    }

    Program_setError(program, ft_strdup("Invalid argument at value"));
    return NULL;
    
}

Value * std_scan(Program * program, List* values)
{
    if(List_count(values) != 0)
    {
        Program_setError(program, ft_strdup("Invalid number of scan arguments"));
        return NULL;
    }
    size_t size = 200;
    char buffer[size];
    fgets(buffer, size, stdin);
    buffer[strlen(buffer) - 1] = '\0';

    return Value_newString(buffer);
}

Value * std_strtonum(Program * program, List* values)
{
    if(List_count(values) != 1)
    {
        Program_setError(program, ft_strdup("Invalid number of strtonum arguments"));
        return NULL;
    }
    Value * strVal = (Value *)List_at(values, 0);
    if(strVal->type != ValueType_STRING)
    {
        Program_setError(program, ft_strdup("Invalid argument strtonum value"));
        return NULL;
    }
    char * str = Value_string(strVal);
    for(int i = 0; i < strlen(str); i++)
    {

        if(str[i] == '-' && i == 0 && strlen(str) > 1)
        {
            continue;
        }
        if(!isdigit(str[i]) && str[i] != '.')
        {
            Program_setError(program, ft_strdup("Invalid argument strtonum value"));
            return NULL;
        }
    }

    return Value_newNumber(atof((const char *)str));
}
Value * std_count(Program * program, List* values)
{
    if(List_count(values) != 1)
    {
        Program_setError(program, ft_strdup("Invalid number of count arguments"));
        return NULL;
    }
    Value * tableVal = (Value *)List_at(values, 0);
    if(tableVal->type != ValueType_TABLE)
    {
        Program_setError(program, ft_strdup("Invalid argument count value"));
        return NULL;
    }
    Table * table = Value_table(tableVal);
    return Value_newNumber(List_count(table->table));
}

Value * std_numtostr(Program * program, List* values)
{
    if(List_count(values) != 1)
    {
        Program_setError(program, ft_strdup("Invalid number of numtostr arguments"));
        return NULL;
    }
    Value * numVal = (Value *)List_at(values, 0);

    char strVal[200];
    strVal[0] = '\0';
    snprintf(strVal, 200, "%.5f", Value_number(numVal));

    return Value_newString(strVal);
}