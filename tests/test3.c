#include <stdio.h>
#include <check.h>
#include <lexer.h>
#include <_list.h>
#include <parser.h>
#include <interpreter.h>
#include <ast.h>
#include <preetyprint.h>

START_TEST (interprate_empty_succes)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  status = Interpreter_execute(prog);
  ck_assert_int_eq(status, 0);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (interprate_unknownVar_fail)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("var a = b;", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  status = Interpreter_execute(prog);
  ck_assert_int_eq(status, 1);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (interprate_varDecl_succes)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("var b = 4; var a = b;", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  status = Interpreter_execute(prog);
  ck_assert_int_eq(status, 0);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (interprate_table_atInvalidIndex)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("var b = newTable(); var c = at(b, 10);", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  status = Interpreter_execute(prog);
  ck_assert_int_eq(status, 1);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST


START_TEST (interprate_tableIndex_succes)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("var b = newTable(); push(b, \"Some text\"); var c = at(b, 0); print(c, \"\");", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  status = Interpreter_execute(prog);
  ck_assert_int_eq(status, 0);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST


/*
  @todo test other cases
*/
Suite *test_suite() {
 Suite *s = suite_create("Parser");
 TCase *tc_sample = tcase_create("ParseTest");
 //
 tcase_add_test(tc_sample, interprate_empty_succes);
 tcase_add_test(tc_sample, interprate_unknownVar_fail);
 tcase_add_test(tc_sample, interprate_varDecl_succes);
 tcase_add_test(tc_sample, interprate_table_atInvalidIndex);
 tcase_add_test(tc_sample, interprate_tableIndex_succes);
 suite_add_tcase(s, tc_sample);
 return s;
}

int main(void) {
 Suite *s = test_suite();
 SRunner *sr = srunner_create(s);
 srunner_set_fork_status(sr, CK_NOFORK);  // important for debugging!
 srunner_run_all(sr, CK_VERBOSE);

 int num_tests_failed = srunner_ntests_failed(sr);
 srunner_free(sr);
 return num_tests_failed;
}
