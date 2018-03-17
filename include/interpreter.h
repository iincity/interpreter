#pragma once

#include <tree.h>
#include <dict.h>

typedef struct __Program Program;
typedef struct __Value Value;
typedef enum {
   ValueType_NUMBER,
   ValueType_BOOL,
   ValueType_STRING,
   ValueType_UNDEFINED,
   ValueType_CHARACTER,
   ValueType_TABLE
} ValueType;

struct __Value {
   ValueType type;
   void * value;
};

typedef struct __Table{
    List* table;
}Table;

int Interpreter_execute(Tree * astTree);
void Value_print(Value * self);
Value * Value_newUndefined(void);
Value * Value_newNumber(double number);
Value * Value_newBool(bool boolean);
Value * Value_newTable(void);
Value * Value_newString(char *  str);
Value * Value_newChar(char * str);
Value *Value_newCharFromChar(char character);
Value *Value_newTableFromTable(Table * table);
Value *Value_TableFromTable(Table * table);
void Value_freeTable(Value * self);
void Value_free(Value * self);
double Value_number(Value * self);
bool Value_bool(Value * self);
char * Value_string(Value * self);
Table * Value_table(Value * self);
void Value_tableAdd(Value * self, Value * toAdd);
char Value_char(Value * self);
char * Value_string(Value * self);
bool Value_asBool(Value * self);
Value * Value_newCopy(Value * origin);
bool Value_equals(Value * a, Value * b);
void Program_setError(Program * self, char * error);

typedef Value * (*Function)(Program * program, List * values);