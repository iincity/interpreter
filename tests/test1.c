#include <stdio.h>
#include <check.h>
#include <lexer.h>
#include <_list.h>


START_TEST (split_empty_empty)
{
   List * tokens = List_new();
   int status = Lexer_splitTokens("", tokens);
   ck_assert_int_eq(status, 0);
   ck_assert_int_eq(List_count(tokens), 0);
   List_free(tokens);
}
END_TEST

START_TEST (split_oneNumber_oneNumberToken)
{
   List * tokens = List_new();
   int status = Lexer_splitTokens("13", tokens);
   ck_assert_int_eq(status, 0);
   ck_assert_int_eq(List_count(tokens), 1);
   Token * firstToken = (Token *)List_at(tokens, 0);
   Token testToken = { TokenType_NUMBER, "13" };
   ck_assert(Token_equals(firstToken, &testToken));
   Lexer_clearTokens(tokens);
   List_free(tokens);
}
END_TEST

START_TEST (split_indentifier_Token)
{
   List * tokens = List_new();
   int status = Lexer_splitTokens("var a", tokens);
   ck_assert_int_eq(status, 0);
   ck_assert_int_eq(List_count(tokens), 2);
   Token * firstToken = (Token *)List_at(tokens, 0);
   Token testToken = { TokenType_VARDECL, "var" };
   ck_assert(Token_equals(firstToken, &testToken));
   Lexer_clearTokens(tokens);
   List_free(tokens);
}
END_TEST

START_TEST (split_indentifierWhile_Token)
{
   List * tokens = List_new();
   int status = Lexer_splitTokens("while()", tokens);
   ck_assert_int_eq(status, 0);
   ck_assert_int_eq(List_count(tokens), 3);
   Token * firstToken = (Token *)List_at(tokens, 0);
   Token testToken = { TokenType_WHILE, "while" };
   ck_assert(Token_equals(firstToken, &testToken));
   Lexer_clearTokens(tokens);
   List_free(tokens);
}
END_TEST

START_TEST (split_BoolOp_BoolOPToken)
{
   List * tokens = List_new();
   int status = Lexer_splitTokens("> == =", tokens);
   ck_assert_int_eq(status, 0);
   ck_assert_int_eq(List_count(tokens), 3);
   Token * firstToken = (Token *)List_at(tokens, 1);
   Token testToken = { TokenType_EQUALITY, "==" };
   ck_assert(Token_equals(firstToken, &testToken));
   Lexer_clearTokens(tokens);
   List_free(tokens);
}
END_TEST


START_TEST (split_invalidChar_errorCode)
{
   List * tokens = List_new();
   int status = Lexer_splitTokens(".", tokens);
   ck_assert_int_eq(status, 1);
   ck_assert_int_eq(List_count(tokens), 0);
   List_free(tokens);
}
END_TEST

/*
  @todo test other cases
*/
Suite *test_suite() {
 Suite *s = suite_create("Lexer");
 TCase *tc_sample = tcase_create("SplitTest");
 //
 tcase_add_test(tc_sample, split_empty_empty);
 tcase_add_test(tc_sample, split_oneNumber_oneNumberToken);
 tcase_add_test(tc_sample, split_indentifierWhile_Token);
 tcase_add_test(tc_sample, split_indentifier_Token);
 tcase_add_test(tc_sample, split_invalidChar_errorCode);
 tcase_add_test(tc_sample, split_BoolOp_BoolOPToken);
 //
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
