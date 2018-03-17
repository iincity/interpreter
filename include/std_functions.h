#pragma once
#include <_list.h>
#include <interpreter.h>


Value * std_print(Program * program, List * values);
Value * std_pow(Program * program, List * values);
Value * std_sqrt(Program * program, List * values);
Value * std_strlen(Program * program, List * values);
Value * std_substr(Program * program, List* values);
Value * std_newTable(Program * program, List* values);
Value * std_push(Program * program, List* values);
Value * std_at(Program * program, List* values);
Value * std_strtonum(Program * program, List* values);
Value * std_scan(Program * program, List* values);
Value * std_count(Program * program, List* values);
Value * std_numtostr(Program * program, List* values);