#include <stdio.h>
#include <check.h>
#include <lexer.h>
#include <_list.h>
#include <parser.h>
#include <ast.h>
#include <preetyprint.h>

START_TEST (build_empty_empty)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  AstTree_prettyPrint(prog);
  ck_assert(prog != NULL);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (build_empty_checkIfProgram)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  AstTree_prettyPrint(prog);
  AstNode * progNode = prog->value;
  ck_assert(!strcmp(progNode->name, "program"));
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (build_varDeck_checkNumber)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("var a = 0; var b = 0; var c = 0;", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  AstTree_prettyPrint(prog);
  ck_assert_int_eq(List_count(prog->children), 3);
  Parser_freeAstTree(prog);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (build_if_checkExpr)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("if(<) shit;", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  ck_assert(prog == NULL);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (build_expr_InvalidExpr)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("var a = 10; a = a + 1", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  ck_assert(prog == NULL);
  Lexer_clearTokens(tokens);
  List_free(tokens);
}END_TEST

START_TEST (build_block_checkChild)
{
  List * tokens = List_new();
  int status = Lexer_splitTokens("{ var someVar = shit; }", tokens);
  ck_assert_int_eq(status, 0);
  Tree * prog = Parser_buildNewAstTree(tokens);
  AstTree_prettyPrint(prog);
  Tree * blockNode = List_at(prog->children, 0);
  ck_assert_int_eq(List_count(blockNode->children), 1);
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
 tcase_add_test(tc_sample, build_empty_empty);
 tcase_add_test(tc_sample, build_empty_checkIfProgram);
 tcase_add_test(tc_sample, build_varDeck_checkNumber);
 tcase_add_test(tc_sample, build_if_checkExpr);
 tcase_add_test(tc_sample, build_expr_InvalidExpr);
 tcase_add_test(tc_sample, build_block_checkChild);
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
