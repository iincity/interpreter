#include <interpreter.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ast.h>
#include <string.h>
#include <stringbuffer.h>
#include <assert.h>
#include <math.h>
#include <std_functions.h>


static void Dict_freeAllVariables(Dict * self);
static void Program_freeVars(Program * program);

Table * Table_new(void)
{
    Table * table = malloc(sizeof(Table));
    table->table = List_new();
    return table;
}

void Table_free(Table * self)
{
   List_free(self->table);
   free(self);
}

Value * Value_new(ValueType type, void * value)
{
    Value * self = malloc(sizeof(Value));
    self->type = type;
    self->value = value;
    return self;
}
void Value_free(Value * self)
{
    if(self->type == ValueType_TABLE)
    {   
        Table * table = self->value;
        Table_free(table);
       // free(table);
    }
    else free(self->value);
    free(self);
}

void Value_freeTable(Value * self)
{
    if(self->type != ValueType_TABLE)
        assert(0 && "Not table");
    Table * table = self->value;
    List * list = table->table;
    int count = List_count(list);
    for(int i = 0; i < count; i++)
    {
        Value * val = (Value *)List_at(list, i);
        if(val->type == ValueType_TABLE) Value_freeTable(val);
        else Value_free(val);
    }
    Table_free(table);
    free(self);
}

void ValueType_print(ValueType self)
{
    switch(self)
    {
        case ValueType_NUMBER:
        printf(" | number"); break;
        case ValueType_BOOL:
        printf(" | bool"); break;
        case ValueType_STRING:
        printf(" | string"); break;
        case ValueType_UNDEFINED:
        printf(" | undefined"); break;
        case ValueType_CHARACTER:
        printf(" | character"); break;
        case ValueType_TABLE:
        printf(" | table"); break;
        default: printf("<?>"); break;
    }
}
void Value_print(Value * self)
{
    switch(self->type)
    {
        case ValueType_TABLE:
        {
            Table * table = (Table*)self->value;
            List * list = table->table;
            int count = List_count(list);
            if(count == 0) printf("empty table");
            else for(int i = 0; i < count; i++)
            {
                Value * val = (Value *)List_at(list, i);
                Value_print(val);
                if( i < count - 1)
                printf(" ,");
               // else printf(" | ");
            }
            break;
        }
        case ValueType_NUMBER:
        {
            double val = *(double*)self->value;
            printf("%lf", val); 

            break;
        }
        case ValueType_BOOL:
        {
            bool val = *(bool*)self->value;
            printf("%s", val ? "TRUE" : "FALSE"); 
            break;
        }
        case ValueType_STRING:
        {
            char * val = (char*)self->value;
            printf("%s", val); 
            break;
        }
        case ValueType_UNDEFINED:
        {
            printf("undefined");  
            break;
        }
        case ValueType_CHARACTER:
        {
            char val = *(char*)self->value;
            printf("%c", val);
            break;
        }
        default: printf("<?>"); break;
    }
    //ValueType_print(self->type);

}

struct __Program {
    List * variables;
    Dict * functions;
    char * error;
};

void Program_setError(Program * self, char * error)
{
    self->error = error;
}
Value * Value_newNumber(double number)
{
    double * numberMem = malloc(sizeof(double));
    *numberMem = number;
    return Value_new(ValueType_NUMBER, numberMem);
}

Value * Value_newBool(bool boolean)
{
    bool * mem = malloc(sizeof(bool));
    *mem = boolean;
    return Value_new(ValueType_BOOL, mem);
}

Value * Value_newString(char *  str)
{
    return Value_new(ValueType_STRING, ft_strdup(str));
}
Value * Value_newUndefined(void)
{
    return Value_new(ValueType_UNDEFINED, NULL);
}
Value * Value_newChar(char * str)
{
    
    char * mem = malloc(sizeof(char));
    if(!strcmp(str, "\\0"))
    *mem = '\0';
    else if(!strcmp(str, "\\n"))
    *mem = '\n';
    else if(strlen(str) > 1) assert(0 && "Invalid character");
    else *mem = *str; 

    return Value_new(ValueType_CHARACTER, mem);
}

Value * Value_newTable(void)
{
    Table * self = Table_new();
    return Value_new(ValueType_TABLE, self);
}

Value *Value_newCharFromChar(char character)
{
    char * mem = malloc(sizeof(char));
    *mem = character;
    return Value_new(ValueType_CHARACTER, mem); 
}

Value *Value_newTableFromTable(Table * table)
{
    Table * newTable = malloc(sizeof(Table));
    List * copy = List_new();
    for(int i = 0; i < List_count(table->table); i++)
    {
        List_add(copy, List_at(table->table, i));
    }
    newTable->table = copy;
    return Value_new(ValueType_TABLE, newTable);
}

Value *Value_TableFromTable(Table * table)
{
    return Value_new(ValueType_TABLE, table);
}


double Value_number(Value * self)
{
    assert(self->type == ValueType_NUMBER);
    return *((double*)self->value);
}

bool Value_bool(Value * self)
{
    assert(self->type == ValueType_BOOL);
    return *((bool*)self->value);
}

char * Value_string(Value * self)
{
    assert(self->type == ValueType_STRING);
    return ((char*)self->value);
}

Table * Value_table(Value * self)
{
    assert(self->type == ValueType_TABLE);
    return ((Table *)self->value);
}
void Value_tableAdd(Value * self, Value * toAdd)
{
     assert(self->type == ValueType_TABLE);
     Table * table = self->value;
     List_add(table->table, toAdd);
}

char Value_char(Value * self)
{
    assert(self->type == ValueType_CHARACTER);
    return *((char*)self->value);
}

bool Value_asBool(Value * self)
{
    switch(self->type)
    {
        case ValueType_BOOL: return Value_bool(self);
        case ValueType_NUMBER: return fabs(Value_number(self)) > 1e-6;
        case ValueType_STRING: return Value_string(self) != NULL; //@todo empty strings are true or false?
        case ValueType_UNDEFINED: return false;
        case ValueType_CHARACTER: return Value_char(self) != '\0';
        case ValueType_TABLE: return Value_table(self) != NULL;
        default: assert(0 && "Not supported");
    }
}


Value * Value_newCopy(Value * origin){
    switch(origin->type)
    {
        case ValueType_BOOL: return Value_newBool(Value_bool(origin));
        case ValueType_NUMBER: return Value_newNumber(Value_number(origin));
        case ValueType_STRING: return Value_newString(Value_string(origin));
        case ValueType_UNDEFINED: assert(0 && "Implement undefined"); return NULL;
        case ValueType_CHARACTER: return Value_newCharFromChar(Value_char(origin));
        case ValueType_TABLE: return Value_newTableFromTable(Value_table(origin));
        default: ValueType_print(origin->type); assert(0 && "Not supported");
    }
}

static Value * Program_getVariableValue(Program * self, char * varId)
{
    int count = List_count(self->variables);
    bool varFound = false;
    for(int i = count - 1; i >= 0; i--)
    {
        Dict * dict = List_at(self->variables, i);
        if(!Dict_contains(dict, varId))
           continue;
        else return Dict_get(dict, varId);
    }
    if(!self->error) self->error = ft_strdup("Var id not found");
    return NULL;
}

static Value * Program_setVarValue(Program * self, char * varId, Value * newVal) 
{
    int count = List_count(self->variables);
    bool varFound = false;
    for(int i = count - 1; i >= 0; i--)
    {
        Dict * dict = List_at(self->variables, i);
        if(!Dict_contains(dict, varId))
           continue;
        else
        {
            return Dict_set(dict, varId, newVal);
        }
    }
    if(!self->error) self->error = ft_strdup("Var id not found");
    return NULL;
}

static bool Program_getIsVarContains(Program * self, char * varId)
{
    int count = List_count(self->variables);
    bool varFound = false;
    for(int i = count - 1; i >= 0; i--)
    {
        Dict * dict = List_at(self->variables, i);
        if(!Dict_contains(dict, varId))
           continue;
        else return true;
    }
    return false;
}

bool Value_equals(Value * a, Value * b)
{
    if(a->type != b->type) return false;
    switch(a->type)
    {
        case ValueType_BOOL: return Value_bool(a) == Value_bool(b);
        case ValueType_NUMBER: return fabs(Value_number(a) -  Value_number(b)) < 1e-6;
        case ValueType_STRING: return !strcmp(Value_string(a), Value_string(b));
        case ValueType_UNDEFINED: return true;
        case ValueType_CHARACTER: return Value_char(a) == Value_char(b);
        case ValueType_TABLE: return Value_table(a) == Value_table(b);
        default: assert(0 && "Not supported");
    }
}
bool Value_GT(Value * a, Value * b)
{
    if(a->type != b->type) return false;
    switch(a->type)
    {
        case ValueType_BOOL: return ((Value_bool(a) == true && Value_bool(b) == false) ? true: false);
        case ValueType_NUMBER: return Value_number(a) -  Value_number(b) > 1e-6;
        case ValueType_STRING: return (strlen(Value_string(a)) > strlen(Value_string(b)));
        case ValueType_UNDEFINED: return false;
        case ValueType_CHARACTER: return Value_char(a) > Value_char(b);
        case ValueType_TABLE: return Value_table(a) == Value_table(b);
        default: assert(0 && "Not supported");
    }
}
bool Value_LT(Value * a, Value * b)
{
    if(a->type != b->type) return false;
    switch(a->type)
    {
        case ValueType_BOOL: return ((Value_bool(a) == true && Value_bool(b) == false) ? false: true);
        case ValueType_NUMBER: return Value_number(b) -  Value_number(a) > 1e-6;
        case ValueType_STRING: return (strlen(Value_string(a)) < strlen(Value_string(b)));
        case ValueType_UNDEFINED: return false;
        case ValueType_CHARACTER: return Value_char(a) < Value_char(b);
        case ValueType_TABLE: return Value_table(a) == Value_table(b);
        default: assert(0 && "Not supported");
    }
}
typedef struct {
    Function ptr;
}StdFunction;

StdFunction * StdFunction_new(Function ptr)
{
    StdFunction * self = malloc(sizeof(StdFunction));
    self->ptr = ptr;
    return self;
}

void StdFunction_free(StdFunction* self)
{
    free(self);
}

Value * eval(Program * program, Tree * node)
{
    AstNode * astNode = (AstNode *)node->value;
    switch(astNode->type)
    {
        case AstNodeType_NUMBER: {
            double number = atof(astNode->name);
            return Value_newNumber(number);
            break;
        }
        case AstNodeType_STRING: {
            char * str = (char *)astNode->name;
            return Value_newString(str);
            break;
        }
        case AstNodeType_CHARACTER: {
            char * str = (char *)astNode->name;
            return Value_newChar(str);
            break;
        }
        case AstNodeType_BOOL: {
            char * str = (char *)astNode->name;
            bool val = false;
            if(!strcmp(str, "true")) val = true;
            return Value_newBool(val);
            break;
        }
        case AstNodeType_ADD: {
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;
            if(firstValue->type != ValueType_NUMBER)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                return NULL;
            }
            int nchild = List_count(node->children);
            if(nchild == 1) {
                //@todo 
                return firstValue;
            } else {
                Tree * secondChild = List_at(node->children, 1);
                Value * secondValue = eval(program, secondChild);
                if(program->error) return NULL;
                if(secondValue->type != ValueType_NUMBER)
                {
                    program->error = ft_strdup((char *)"Invalid operation");
                    Value_free(firstValue);
                    Value_free(secondValue);
                    return NULL;
                }
                double res = Value_number(firstValue) + Value_number(secondValue);
                Value_free(firstValue);
                Value_free(secondValue);
                return Value_newNumber(res);
            }
            break;
        }
        case AstNodeType_SUB: {
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;
            if(firstValue->type != ValueType_NUMBER)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                return NULL;
            }
            int nchild = List_count(node->children);
            if(nchild == 1) {
                //@todo 
                double * value = (double *)firstValue->value;
                *value = -(*value);
                return firstValue;
            } else {
                Tree * secondChild = List_at(node->children, 1);
                Value * secondValue = eval(program, secondChild);
                if(program->error) return NULL;
                if(secondValue->type != ValueType_NUMBER)
                {
                    program->error = ft_strdup((char *)"Invalid operation");
                    Value_free(firstValue);
                    Value_free(secondValue);
                    return NULL;
                }
                double res = Value_number(firstValue) - Value_number(secondValue);
                Value_free(firstValue);
                Value_free(secondValue);
                return Value_newNumber(res);
            }
            break;
        }
        case AstNodeType_ID: {
            char * varId = (char *)astNode->name;
            bool varFound =  false;
            if(List_count(node->children) != 0)
            {
                Tree * argListNode = List_at(node->children, 0);
                AstNode * argList = argListNode->value;
                assert(argList->type == AstNodeType_ARGLIST);
                //
                if(!Dict_contains(program->functions, varId)) {
                    program->error = ft_strdup("Call unknown function");
                    return NULL;
                }
                //
                List * arguments = List_new();
                for(int i = 0; i < List_count(argListNode->children); i++)
                {
                    Tree * argListChildNode = List_at(argListNode->children, i);
                    Value * argumentValue = eval(program, argListChildNode);
                    
                    if(program->error) {
                        //@todo error
                        // free all arguments
                        List_free(arguments);
                        return NULL;
                    } 
                    List_add(arguments, argumentValue);
                }
                // call function
                StdFunction * func =  Dict_get(program->functions, varId);
                Value * retValue = func->ptr(program, arguments);
                //@todo free all arguments
                for(int i = 0; i < List_count(arguments);i++)
                {
                    Value * val = (Value *)List_at(arguments, i);
                    
                    if(val->type != ValueType_TABLE)
                        Value_free(val);
                    else free(val);
                        //val = retValue;
                    
                }
                List_free(arguments);
                return retValue;
            }

            Value * varValue = Program_getVariableValue(program, varId);
            if(program->error) return NULL;
            if(varValue->type != ValueType_TABLE)
                return Value_newCopy(varValue);
            //Value_print(varValue);
            Table * tbl = varValue->value;
            return Value_TableFromTable(tbl);
        }
        case AstNodeType_MUL:{
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            if(firstValue->type != ValueType_NUMBER)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                return NULL;
            }
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            if(secondValue->type != ValueType_NUMBER)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                Value_free(secondValue);
                return NULL;
            }
            double res = Value_number(firstValue) * Value_number(secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newNumber(res);
            break;
        }
        case AstNodeType_DIV:{
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            if(firstValue->type != ValueType_NUMBER)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                return NULL;
            }
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            if(secondValue->type != ValueType_NUMBER)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                Value_free(secondValue);
                return NULL;
            }
            if(fabs(Value_number(secondValue)) < 1e-6)
            {
                program->error = ft_strdup((char *)"Invalid operation");
                Value_free(firstValue);
                Value_free(secondValue);
                return NULL;
            }
            double res = Value_number(firstValue) / Value_number(secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newNumber(res);
            break;
        }

        case AstNodeType_ASSIGN:{
            //assert(0 && "Assign");
            Tree * firstChild = List_at(node->children, 0);
            AstNode * firstChildNode = (AstNode *)firstChild->value;
            char * varName = (char *)firstChildNode->name;
            if(!Program_getIsVarContains(program, varName))
            {
                program->error = ft_strdup((char *)"Invalid operation");
                return NULL;
            }
            Tree * secondChild = List_at(node->children, 1);
            Value * secondVal = eval(program, secondChild);
            if(program->error) return NULL;
            Value * removedVal = Program_setVarValue(program, varName, Value_newCopy(secondVal));
            if(removedVal->type != ValueType_TABLE )Value_free(removedVal);
            //else Value_free(removedVal);
            //Value_free(secondVal);
            return secondVal;
        }
        case AstNodeType_AND:{
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_asBool(firstValue) && Value_asBool(secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res);
            break;
        }
        case AstNodeType_OR:{
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_asBool(firstValue) || Value_asBool(secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res);
            break;
        }

        case AstNodeType_EQ:{
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_equals(firstValue, secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res);
            break;
        }
        case AstNodeType_NEQ:{
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = !Value_equals(firstValue, secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res);
            break;
        }
        case AstNodeType_GT:
        {
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_GT(firstValue, secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res);
            break;
        }
        case AstNodeType_LT:
        {
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_LT(firstValue, secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res);
            break;
        }
        case AstNodeType_GTEQ:
        {
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_GT(firstValue, secondValue);
            bool res1 = Value_equals(firstValue, secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res || res1);
            break;
        }
        case AstNodeType_LTEQ:
        {
            Tree * firstChild = List_at(node->children, 0);
            Value * firstValue = eval(program, firstChild);
            if(program->error) return NULL;            
            Tree * secondChild = List_at(node->children, 1);
            Value * secondValue = eval(program, secondChild);
            if(program->error) return NULL;
            bool res = Value_LT(firstValue, secondValue);
            bool res1 = Value_equals(firstValue, secondValue);
            Value_free(firstValue);
            Value_free(secondValue);
            return Value_newBool(res || res1);
            break;
        }
        case AstNodeType_DECLAREVAR: {
            Tree * fChildNode = List_at(node->children, 0);
            AstNode * fChild = fChildNode->value;
            Tree * sChildNode = List_at(node->children, 1);
            AstNode * sChild = sChildNode->value;
            //
            char * varName = ft_strdup((char *)fChild->name);
            Value * varValue = eval(program, sChildNode);
            if(program->error) break;
            //
            if(Program_getIsVarContains(program, varName))
            {
                program->error = ft_strdup("Duplicate variable id");
                Value_free(varValue);
                return NULL;
            }
            Dict * dict = List_at(program->variables, List_count(program->variables) - 1);
            Dict_add(dict, varName, varValue);
            break;
        }
        default:{
            assert(0 && "Not implemented");
            break;
        }
    }
    return NULL;
}

void executeBlock(Program * program, Tree * blockTreeNode);
void executeIf(Program * program, Tree * node) ;
void executeStatement(Program * program, Tree * node);
void executeWhile(Program * program, Tree * node);
void executeStatement(Program * program, Tree * node) {
    AstNode * child = node->value;
    switch(child->type)
    {
        case AstNodeType_IF:{
            List_add(program->variables,Dict_new());
            executeIf(program, node);
            Dict_freeAllVariables(List_at(program->variables, List_count(program->variables)-1));
            Dict * dict = List_removeAt(program->variables, List_count(program->variables)-1);
            Dict_clear(dict);
            Dict_free(dict);
            if(program->error) return;
            break;
        }
        case AstNodeType_WHILE:{
            List_add(program->variables,Dict_new());
            executeWhile(program, node);
            Dict_freeAllVariables(List_at(program->variables, List_count(program->variables)-1));
            Dict * dict = List_removeAt(program->variables, List_count(program->variables)-1);
            Dict_clear(dict);
            Dict_free(dict);
            if(program->error) return;
            break;
        }
        case AstNodeType_BLOCK:{
            List_add(program->variables,Dict_new());
            executeBlock(program, node);
            Dict_freeAllVariables(List_at(program->variables, List_count(program->variables)-1));
            Dict * dict = List_removeAt(program->variables, List_count(program->variables)-1);
            Dict_clear(dict);
            Dict_free(dict);
            if(program->error) return;
            break;
        }
        default : { //expr
            Value * val = eval(program, node);
            if(program->error) return;
            //Value_print(val);
            //puts("");
            if(child->type != AstNodeType_DECLAREVAR)
                Value_free(val);
        }
    }

}

void executeIf(Program * program, Tree * node) {
    Tree * exprNode  = (Tree *)List_at(node->children, 0);
    Value * testValue = eval(program, exprNode);
    if(program->error) return;
    bool testBool = Value_asBool(testValue);
    Value_free(testValue);
    if(testBool) {
        executeStatement(program, List_at(node->children, 1));
    } else if(List_count(node->children) > 2) {
        executeStatement(program, List_at(node->children, 2));
    }
}
void executeWhile(Program * program, Tree * node) {
    Tree * exprNode  = (Tree *)List_at(node->children, 0);
    while(true)
    {
         Value * testValue = eval(program, exprNode);
        if(program->error) return;
        bool testBool = Value_asBool(testValue);
        Value_free(testValue);
        if(!testBool) break;
        //
        executeStatement(program, List_at(node->children, 1));
    }
   
}

void executeBlock(Program * program, Tree * blockTreeNode){
    for(int i = 0; i < List_count(blockTreeNode->children); i++)
    {
        Tree * childNode = List_at(blockTreeNode->children, i);
        AstNode * child = childNode->value;
        //
        executeStatement(program, childNode);
        if(program->error) break;
    }
}


static void Dict_freeAllVariables(Dict * self)
{
    List * keys = List_new();
    Dict_keys(self, keys);
    int count = List_count(keys);
    for(int i = 0; i < count; i++)
    {
        char * key = List_at(keys, 0);
        Value * val = (Value *)Dict_get(self, key);

        Dict_remove(self, key);
        if(val->type != ValueType_TABLE) Value_free(val);
        else Value_freeTable(val);
        List_removeAt(keys, 0);
        free(key);
    }
    List_free(keys);
}

static void Program_freeVars(Program * program)
{
    int len = List_count(program->variables);
    for(int i = 0; i < len; i++)
    {
        Dict * dict = List_at(program->variables, i);
        Dict_freeAllVariables(dict);
       // Dict_clear(dict);
        Dict_free(dict);
    }
    List_free(program->variables);
}

static void Dict_freeAllFunctions(Dict * self)
{
    List * keys = List_new();
    Dict_keys(self, keys);
    int count = List_count(keys);
    for(int i = 0; i < count; i++)
    {
        char * key = List_at(keys, 0);
        StdFunction * val = (StdFunction *)Dict_get(self, key);
        Dict_remove(self, key);
        StdFunction_free(val);
        List_removeAt(keys, 0);
        //free(key);
    }
    List_free(keys);
}

int Interpreter_execute(Tree * astTree)
{
    AstNode * astNode = astTree->value;
    assert(astNode->type == AstNodeType_PROGRAM);
    Program program = {
        .variables = List_new(),
        .functions = Dict_new(),
        .error = NULL
    };
    List_add(program.variables, Dict_new());
    Dict_add(program.functions, "print", StdFunction_new(std_print));
    Dict_add(program.functions, "strlen",StdFunction_new(std_strlen));
    Dict_add(program.functions, "substr",StdFunction_new(std_substr));
    Dict_add(program.functions, "newTable",StdFunction_new(std_newTable));
    Dict_add(program.functions, "push",StdFunction_new(std_push));
    Dict_add(program.functions, "at",StdFunction_new(std_at));
    Dict_add(program.functions, "scan",StdFunction_new(std_scan));
    Dict_add(program.functions, "strtonum",StdFunction_new(std_strtonum));
    Dict_add(program.functions, "numtostr",StdFunction_new(std_numtostr));
    Dict_add(program.functions, "count",StdFunction_new(std_count));
    Dict_add(program.functions, "sqrt",StdFunction_new(std_sqrt));
    Dict_add(program.functions, "pow",StdFunction_new(std_pow));
    //
    for(int i = 0; i < List_count(astTree->children); i++)
    {
        Tree * childNode = List_at(astTree->children, i);
        AstNode * child = childNode->value;
        switch(child->type)
        {
            case AstNodeType_DECLAREVAR: {
                Tree * fChildNode = List_at(childNode->children, 0);
                AstNode * fChild = fChildNode->value;
                Tree * sChildNode = List_at(childNode->children, 1);
                AstNode * sChild = sChildNode->value;
                //
                char * varName = ft_strdup((char *)fChild->name);
                Value * varValue = eval(&program, sChildNode);
                if(program.error) {
                    free(varName);
                    break;
                }
                //
                for(int i = 0; i < List_count(program.variables); i++)
                {

                    Dict * dict = List_at(program.variables, i);
                    if(Dict_contains(dict, varName)){    
                        program.error = ft_strdup("Duplicate variable id");
                        Value_free(varValue);
                        break;
                    }
                }
                Dict * dict = List_at(program.variables, List_count(program.variables) - 1);
                Dict_add(dict, varName, varValue);
                break;
            }
            case AstNodeType_IF:{
                List_add(program.variables,Dict_new());
                executeIf(&program, childNode);
                Dict_freeAllVariables(List_at(program.variables, List_count(program.variables)-1));
                Dict * dict = List_removeAt(program.variables, List_count(program.variables)-1);
                Dict_clear(dict);
                Dict_free(dict);
                if(program.error) break;
                break;
            }
            case AstNodeType_WHILE:{
                List_add(program.variables,Dict_new());
                executeWhile(&program, childNode);
                Dict_freeAllVariables(List_at(program.variables, List_count(program.variables)-1));
                Dict * dict = List_removeAt(program.variables, List_count(program.variables)-1);
                Dict_clear(dict);
                Dict_free(dict);
                if(program.error) break;
                break;
            }
            case AstNodeType_BLOCK:{
                List_add(program.variables,Dict_new());
                executeBlock(&program, childNode);
                Dict_freeAllVariables(List_at(program.variables, List_count(program.variables)-1));
                Dict * dict = List_removeAt(program.variables, List_count(program.variables)-1);
                Dict_clear(dict);
                Dict_free(dict);
                if(program.error) break;
                break;
            }
            default : { //expr
                Value * val = eval(&program, childNode);
                if(program.error) break;
               // Value_print(val);
               // puts("");
                Value_free(val);
            }
        }
    }

    Program_freeVars(&program);
    Dict_freeAllFunctions(program.functions);
    //List_free(keys);
    // @todo free all dict values.
    Dict_clear(program.functions);
    Dict_free(program.functions);
    if(program.error)
    {
        fprintf(stderr, "Run-time error: %s\n", program.error);
        free(program.error);
        return 1;
    }
    //
    return 0;
}