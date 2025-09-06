#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "s21_smart_calc.h"

Suite *decimal_suite(void);

int main() {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;
  srand(time(NULL));

  s = decimal_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 0;
}

START_TEST(test_plus_1) {
  char string[100] = "123.45+34.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 158.42);
}
END_TEST

START_TEST(test_plus_2) {
  char string[100] = "123.45+-34.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 88.48);
}
END_TEST

START_TEST(test_plus_3) {
  char string[100] = "-123.45+-34.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -123.45 + -34.97);
}
END_TEST

START_TEST(test_plus_4) {
  char string[100] = "+123.45+-34.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 123.45 + -34.97);
}
END_TEST

START_TEST(test_minus_1) {
  char string[100] = "43534.6-354.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 43179.63);
}
END_TEST

START_TEST(test_minus_2) {
  char string[100] = "-43534.6-354.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -43889.57);
}
END_TEST

START_TEST(test_minus_3) {
  char string[100] = "-43534.6--354.97", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -43179.63);
}
END_TEST

START_TEST(test_mult_1) {
  char string[100] = "34.9*64.78", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 2260.822);
}
END_TEST

START_TEST(test_mult_2) {
  char string[100] = "34.9*-64.78", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -2260.822);
}
END_TEST

START_TEST(test_mult_3) {
  char string[100] = "-34.9*-64.78", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 2260.822);
}
END_TEST

START_TEST(test_mult_4) {
  char string[100] = "-34.9*0", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 0);
}
END_TEST

START_TEST(test_mult_5) {
  char string[100] = "-34.9*+11", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -34.9 * 11);
}
END_TEST

START_TEST(test_div_1) {
  char string[100] = "3543.78/345.87", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 10.2459883771359181);
}
END_TEST

START_TEST(test_div_2) {
  char string[100] = "3543.78/-345.87", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -10.2459883771359181);
}
END_TEST

START_TEST(test_div_3) {
  char string[100] = "-3543.78/-345.87", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 10.2459883771359181);
}
END_TEST

START_TEST(test_div_4) {
  char string[100] = "100/5", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 20);
}
END_TEST

START_TEST(test_div_5) {
  char string[100] = "3543.78/0", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), INFINITY);
}
END_TEST

START_TEST(test_pow_1) {
  char string[100] = "234.4^3", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 12878723.584);
}
END_TEST

START_TEST(test_pow_2) {
  char string[100] = "234.4^-1", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 0.0042662116040956);
}
END_TEST

START_TEST(test_pow_3) {
  char string[100] = "2^8", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 256);
}
END_TEST

START_TEST(test_mod_1) {
  char string[100] = "3245mod34.88", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), fmod(3245, 34.88));
}
END_TEST

START_TEST(test_mod_2) {
  char string[100] = "3245mod-34.88", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), fmod(3245, -34.88));
}
END_TEST

START_TEST(test_mod_3) {
  char string[100] = "-3245mod-34.88", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), fmod(-3245, -34.88));
}
END_TEST

START_TEST(test_mod_4) {
  char string[100] = "10mod2", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 10 % 2);
}
END_TEST

START_TEST(test_mod_5) {
  char string[100] = "100mod35mod2", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 100 % 35 % 2);
}
END_TEST

START_TEST(test_sin_1) {
  char string[100] = "sin(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 0.8414709848);
}
END_TEST

START_TEST(test_sin_2) {
  char string[100] = "sin(-0.7)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -0.64421768723);
}
END_TEST

START_TEST(test_sin_3) {
  char string[100] = "sin(355.98)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -0.83051416119);
}
END_TEST

START_TEST(test_cos_1) {
  char string[100] = "cos(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 0.54030230586);
}
END_TEST

START_TEST(test_cos_2) {
  char string[100] = "cos(-0.7)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), cos(-0.7));
}
END_TEST

START_TEST(test_cos_3) {
  char string[100] = "cos(355.98)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -0.5569975117);
}
END_TEST

START_TEST(test_cos_4) {
  char string[100] = "cos(30)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), cos(30));
}
END_TEST

START_TEST(test_tan_1) {
  char string[100] = "tan(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 1.55740772465);
}
END_TEST

START_TEST(test_tan_2) {
  char string[100] = "tan(-0.7)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), -0.84228838046);
}
END_TEST

START_TEST(test_tan_3) {
  char string[100] = "tan(355.98)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 1.49105542438);
}
END_TEST

START_TEST(test_asin_1) {
  char string[100] = "asin(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), asin(1));
}
END_TEST

START_TEST(test_asin_2) {
  char string[100] = "asin(-0.7)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), asin(-0.7));
}
END_TEST

START_TEST(test_asin_3) {
  char string[100] = "asin(355.98)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_ne(s21_calculation(result), asin(355.98));
}
END_TEST

START_TEST(test_acos_1) {
  char string[100] = "acos(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), acos(1));
}
END_TEST

START_TEST(test_acos_2) {
  char string[100] = "acos(-0.7)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), acos(-0.7));
}
END_TEST

START_TEST(test_acos_3) {
  char string[100] = "acos(355.98)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_ne(s21_calculation(result), acos(355.98));
}
END_TEST

START_TEST(test_atan_1) {
  char string[100] = "atan(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), atan(1));
}
END_TEST

START_TEST(test_atan_2) {
  char string[100] = "atan(-0.7)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), atan(-0.7));
}
END_TEST

START_TEST(test_atan_3) {
  char string[100] = "atan(355.98)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), atan(355.98));
}
END_TEST

START_TEST(test_sqrt_1) {
  char string[100] = "sqrt(1)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), sqrt(1));
}
END_TEST

START_TEST(test_sqrt_2) {
  char string[100] = "sqrt(151.29)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), sqrt(151.29));
}
END_TEST

START_TEST(test_sqrt_3) {
  char string[100] = "sqrt(551.29)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), sqrt(551.29));
}
END_TEST

START_TEST(test_nat_log_1) {
  char string[100] = "ln(3)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), log(3));
}
END_TEST

START_TEST(test_nat_log_2) {
  char string[100] = "ln(45.3)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), log(45.3));
}
END_TEST

START_TEST(test_nat_log_3) {
  char string[100] = "ln(0)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), log(0));
}
END_TEST

START_TEST(test_common_log_1) {
  char string[100] = "log(3)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), log10(3));
}
END_TEST

START_TEST(test_common_log_2) {
  char string[100] = "log(45.3)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), log10(45.3));
}
END_TEST

START_TEST(test_common_log_3) {
  char string[100] = "log(0)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), log10(0));
}
END_TEST

START_TEST(test_x_1) {
  char string[100] = "log(x)";
  ck_assert_float_eq(s21_calculate_x(string, "1"), log10(1));
}
END_TEST

START_TEST(test_x_2) {
  char string[100] = "log(1)";
  ck_assert_float_eq(s21_calculate_x(string, "1"), log10(1));
}
END_TEST

START_TEST(test_num_len_1) {
  long unsigned int num = 1;
  for (int i = 1; i <= 19; i++) {
    ck_assert_int_eq(i, s21_number_lenght(num));
    num *= 10;
  }
}
END_TEST

START_TEST(test_num_len_2) {
  long unsigned int num = -1;
  for (int i = 1; i <= 19; i++) {
    ck_assert_int_eq(i, s21_number_lenght(num));
    num *= 10;
  }
}
END_TEST

START_TEST(test_complecsity_two_1) {
  char string[100] = "cos(sin(1))", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), cos(sin(1)));
}
END_TEST

START_TEST(test_complecsity_two_2) {
  char string[100] = "34.6-5*5", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 34.6 - 5 * 5);
}
END_TEST

START_TEST(test_complecsity_n_1) {
  char string[100] = "(4*(12.3-7.8+(-2.5+23423.6))/2^4)mod2",
       result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result),
                     fmod(4 * (12.3 - 7.8 + (-2.5 + 23423.6)) / pow(2, 4), 2));
}
END_TEST

START_TEST(test_complecsity_n_2) {
  char string[100] = "sin(cos(tan(ln(log(sqrt(4))))))", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result),
                     sin(cos(tan(log(log10(sqrt(4)))))));
}
END_TEST

START_TEST(test_complecsity_n_3) {
  char string[100] = "asin(acos(atan(ln(log(sqrt(4))))))", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(isnan(s21_calculation(result)),
                     isnan(asin(acos(atan(log(log10(sqrt(4))))))));
}
END_TEST

START_TEST(test_complecsity_n_4) {
  char string[100] = "asin(acos(atan(ln(log(sqrt(4)))))-1.638886)",
       result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result),
                     asin(acos(atan(log(log10(sqrt(4))))) - 1.638886));
}
END_TEST

START_TEST(test_complecsity_n_5) {
  char string[100] = "(3.33-1)^(5-3)", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), pow(3.33 - 1, 5 - 3));
}
END_TEST

START_TEST(test_complecsity_n_6) {
  char string[100] = "acos(atan(ln(log(sqrt(4)))))", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), acos(atan(log(log10(sqrt(4))))));
}
END_TEST

START_TEST(test_complecsity_n_7) {
  char string[100] = "1.56*0.094*89.56", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 1.56 * 0.094 * 89.56);
}
END_TEST

START_TEST(test_complecsity_n_8) {
  char string[100] = "234234mod10mod2", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 234234 % 10 % 2);
}
END_TEST

START_TEST(test_complecsity_n_9) {
  char string[100] = "+345++34", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), +345 + 34);
}
END_TEST

START_TEST(test_complecsity_n_10) {
  char string[100] = "sqrt(sqrt(81))", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), sqrt(sqrt(81)));
}
END_TEST

START_TEST(test_complecsity_n_11) {
  char string[100] = "45", result[500] = {'\0'};
  s21_string_to_djicstra(string, result);
  ck_assert_float_eq(s21_calculation(result), 45);
}
END_TEST

START_TEST(test_brackets_error_1) {
  char string[100] = "123+23-((5+0)";
  ck_assert_float_eq(s21_error_in_brackets(string), 1);
}
END_TEST

START_TEST(test_brackets_error_2) {
  char string[100] = "123+23-)5+0)";
  ck_assert_float_eq(s21_error_in_brackets(string), 1);
}
END_TEST

START_TEST(test_brackets_error_3) {
  char string[100] = "123+23-(5+0))";
  ck_assert_float_eq(s21_error_in_brackets(string), 1);
}
END_TEST

START_TEST(test_brackets_error_4) {
  char string[100] = "123+23-(5+0(";
  ck_assert_float_eq(s21_error_in_brackets(string), 1);
}
END_TEST

START_TEST(test_brackets_error_5) {
  char string[100] = "123+23-5+0";
  ck_assert_float_eq(s21_error_in_brackets(string), 0);
}
END_TEST

START_TEST(test_brackets_error_6) {
  char string[100] = "123+23-5+0-()";
  ck_assert_float_eq(s21_error_in_brackets(string), 1);
}
END_TEST

START_TEST(test_correctness_error_1) {
  char string[100] = "123+23-x*-1";
  ck_assert_float_eq(s21_correctness(string), 0);
}
END_TEST

START_TEST(test_correctness_error_2) {
  char string[100] = "123+23-1*/1";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_3) {
  char string[100] = "123+23-x--x";
  ck_assert_float_eq(s21_correctness(string), 0);
}
END_TEST

START_TEST(test_correctness_error_4) {
  char string[100] = "1.2.3+23-x--x";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_5) {
  char string[100] = "1.2(.3+23)-x--x";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_6) {
  char string[100] = "1*-+3";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_7) {
  char string[100] = "sqrt(cos(1))";
  ck_assert_float_eq(s21_correctness(string), 0);
}
END_TEST

START_TEST(test_correctness_error_8) {
  char string[100] = "5mod-2";
  ck_assert_float_eq(s21_correctness(string), 0);
}
END_TEST

START_TEST(test_correctness_error_9) {
  char string[100] = "0atan(56858)";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_10) {
  char string[100] = "ln(1)";
  ck_assert_float_eq(s21_correctness(string), 0);
}
END_TEST

START_TEST(test_correctness_error_11) {
  char string[100] = "ln(mod1)";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_12) {
  char string[100] = "sin(mod1)";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_13) {
  char string[100] = "-(1+2)";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_14) {
  char string[100] = "sqrt(mod1)";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_correctness_error_15) {
  char string[100] = "1+4*-(1+2)";
  ck_assert_float_eq(s21_correctness(string), 1);
}
END_TEST

START_TEST(test_one_number_1) {
  char string[100] = "234.67";
  ck_assert_float_eq(s21_only_number(string), 1);
}
END_TEST

START_TEST(test_one_number_2) {
  char string[100] = "x";
  ck_assert_float_eq(s21_only_number(string), 0);
}
END_TEST

START_TEST(test_one_number_3) {
  char string[100] = "";
  ck_assert_float_eq(s21_only_number(string), 0);
}
END_TEST

START_TEST(test_one_number_4) {
  char string[100] = "234234.6";
  ck_assert_float_eq(s21_calculation_one_number(string), 234234.6);
}
END_TEST

START_TEST(test_one_number_5) {
  char string[100] = "-0.000234234";
  ck_assert_float_eq(s21_calculation_one_number(string), -0.000234234);
}
END_TEST

START_TEST(test_one_number_6) {
  char string[100] = "0";
  ck_assert_float_eq(s21_calculation_one_number(string), 0);
}
END_TEST

START_TEST(test_znaks_1) {
  char string[100] = "+-1";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 1);
}
END_TEST

START_TEST(test_znaks_2) {
  char string[100] = "+";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 1);
}
END_TEST

START_TEST(test_znaks_3) {
  char string[100] = "+12+-23";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 0);
}
END_TEST

START_TEST(test_znaks_4) {
  char string[100] = "sin";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 0);
}
END_TEST

START_TEST(test_znaks_5) {
  char string[100] = "mod";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 1);
}
END_TEST

START_TEST(test_znaks_6) {
  char string[100] = "*5";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 1);
}
END_TEST

START_TEST(test_znaks_7) {
  char string[100] = "5*";
  ck_assert_float_eq(
      s21_check_if_only_znaks_and_not_pm_in_the_beginning(string), 0);
}
END_TEST

START_TEST(test_points_1) {
  char string[100] = ".9234+32";
  ck_assert_float_eq(s21_check_points(string), 1);
}
END_TEST

START_TEST(test_points_2) {
  char string[100] = ".x+32";
  ck_assert_float_eq(s21_check_points(string), 1);
}
END_TEST

START_TEST(test_points_3) {
  char string[100] = "x.+32";
  ck_assert_float_eq(s21_check_points(string), 1);
}
END_TEST

START_TEST(test_points_4) {
  char string[100] = "x+32";
  ck_assert_float_eq(s21_check_points(string), 0);
}
END_TEST

START_TEST(test_points_5) {
  char string[100] = "x+32.";
  ck_assert_float_eq(s21_check_points(string), 1);
}
END_TEST

START_TEST(test_points_6) {
  char string[100] = "x+32..4";
  ck_assert_float_eq(s21_check_points(string), 1);
}
END_TEST

START_TEST(test_sin_brackets_1) {
  char string[100] = "sinx";
  ck_assert_float_eq(s21_check_bracket_after_sin(string), 1);
}
END_TEST

START_TEST(test_sin_brackets_2) {
  char string[100] = "sin(x";
  ck_assert_float_eq(s21_check_bracket_after_sin(string), 0);
}
END_TEST

START_TEST(test_sin_brackets_3) {
  char string[100] = "ln10";
  ck_assert_float_eq(s21_check_bracket_after_sin(string), 1);
}
END_TEST

START_TEST(test_sin_brackets_4) {
  char string[100] = "sqrt";
  ck_assert_float_eq(s21_check_bracket_after_sin(string), 1);
}
END_TEST

START_TEST(test_sin_brackets_5) {
  char string[100] = "sin(3)";
  ck_assert_float_eq(s21_check_bracket_after_sin(string), 0);
}
END_TEST

START_TEST(test_swh_1) {
  char string[100] = "-4-";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_swh_2) {
  char string[100] = ".4";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_swh_3) {
  char string[100] = "234234.234234.4";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_swh_4) {
  char string[100] = "2342342342344-";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_swh_5) {
  char string[100] = "-.2342342342344";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_swh_6) {
  char string[100] = "-2342342342b4";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_swh_7) {
  char string[100] = "";
  ck_assert_float_eq(s21_check_step_width_heigth(string), 1);
}
END_TEST

START_TEST(test_annuitent_payment_1) {
  ck_assert_float_eq_tol(s21_bank_annuitent_montly_payment(20000, 36, 12), 664,
                         1);
}
END_TEST

START_TEST(test_annuitent_payment_2) {
  ck_assert_float_eq_tol(s21_bank_annuitent_montly_payment(100000, 12, 13),
                         8931, 1);
}
END_TEST

START_TEST(test_annuitent_payment_3) {
  ck_assert_float_eq_tol(s21_bank_annuitent_montly_payment(5000000, 60, 23.5),
                         142392, 1);
}
END_TEST

START_TEST(test_annuitent_overpayment_1) {
  ck_assert_float_eq_tol(s21_bank_annuitent_overpayment(20000, 36, 12), 3914,
                         1);
}
END_TEST

START_TEST(test_annuitent_overpayment_2) {
  ck_assert_float_eq_tol(s21_bank_annuitent_overpayment(100000, 12, 13), 7180,
                         1);
}
END_TEST

START_TEST(test_annuitent_overpayment_3) {
  ck_assert_float_eq_tol(s21_bank_annuitent_overpayment(5000000, 60, 23.5),
                         3543544, 1);
}
END_TEST

START_TEST(test_annuitent_all_payment_1) {
  ck_assert_float_eq_tol(s21_bank_annuitent_all_payment(20000, 36, 12), 23914,
                         1);
}
END_TEST

START_TEST(test_annuitent_all_payment_2) {
  ck_assert_float_eq_tol(s21_bank_annuitent_all_payment(100000, 12, 13), 107180,
                         1);
}
END_TEST

START_TEST(test_annuitent_all_payment_3) {
  ck_assert_float_eq_tol(s21_bank_annuitent_all_payment(5000000, 60, 23.5),
                         8543544, 1);
}
END_TEST

START_TEST(test_annuitent_all_payment_4) {
  ck_assert_float_eq_tol(s21_bank_annuitent_all_payment(5000000, 64, 23.5),
                         8814270, 1);
}
END_TEST

START_TEST(test_differential_payment_1) {
  ck_assert_float_eq_tol(
      s21_bank_differential_montly_payment_first(20000, 36, 12), 755, 1);
  ck_assert_float_eq_tol(
      s21_bank_differential_montly_payment_last(20000, 36, 12), 561, 1);
}
END_TEST

START_TEST(test_differential_payment_2) {
  ck_assert_float_eq_tol(
      s21_bank_differential_montly_payment_first(100000, 12, 13), 9416, 1);
  ck_assert_float_eq_tol(
      s21_bank_differential_montly_payment_last(100000, 12, 13), 8423, 1);
}
END_TEST

START_TEST(test_differential_payment_3) {
  ck_assert_float_eq_tol(
      s21_bank_differential_montly_payment_first(5000000, 60, 23.5), 181250, 1);
  ck_assert_float_eq_tol(
      s21_bank_differential_montly_payment_last(5000000, 60, 23.5), 84965, 1);
}
END_TEST

START_TEST(test_differential_overpayment_1) {
  ck_assert_float_eq_tol(s21_bank_differential_overpayment(20000, 36, 12), 3700,
                         1);
}
END_TEST

START_TEST(test_differential_overpayment_2) {
  ck_assert_float_eq_tol(s21_bank_differential_overpayment(100000, 12, 13),
                         7041, 1);
}
END_TEST

START_TEST(test_differential_overpayment_3) {
  ck_assert_float_eq_tol(s21_bank_differential_overpayment(5000000, 60, 23.5),
                         2986458, 1);
}
END_TEST

START_TEST(test_differential_all_payment_1) {
  ck_assert_float_eq_tol(s21_bank_differential_all_payment(20000, 36, 12),
                         23700, 1);
}
END_TEST

START_TEST(test_differential_all_payment_2) {
  ck_assert_float_eq_tol(s21_bank_differential_all_payment(100000, 12, 13),
                         107041, 1);
}
END_TEST

START_TEST(test_differential_all_payment_3) {
  ck_assert_float_eq_tol(s21_bank_differential_all_payment(5000000, 60, 23.5),
                         7986458, 1);
}
END_TEST

START_TEST(test_differential_all_payment_4) {
  ck_assert_float_eq_tol(s21_bank_differential_all_payment(5000000, 64, 23.5),
                         8182291, 1);
}
END_TEST

START_TEST(test_simple_profitability_1) {
  ck_assert_float_eq_tol(s21_deposit_profitability_simple(10000, 12, 10, 13),
                         1000, 1);
}
END_TEST

START_TEST(test_simple_profitability_2) {
  ck_assert_float_eq_tol(s21_deposit_profitability_simple(1000000, 12, 10, 13),
                         96750, 1);
}
END_TEST

START_TEST(test_simple_profitability_3) {
  ck_assert_float_eq_tol(s21_deposit_profitability_simple(12345.34, 24, 20, 13),
                         4938, 1);
}
END_TEST

START_TEST(test_simple_profitability_4) {
  ck_assert_float_eq_tol(s21_deposit_profitability_simple(3000000, 24, 5, 13),
                         280500, 1);
}
END_TEST

START_TEST(test_simple_profitability_5) {
  ck_assert_float_eq_tol(s21_deposit_profitability_simple(0, 1, 5, 13), 0, 1);
}
END_TEST

START_TEST(test_complex_profitability_1) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 3000000, 12, 5, 13, 0, 1, rep, wid, 7.5),
                         153485, 1);
}
END_TEST

START_TEST(test_complex_profitability_2) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 2;
  rep[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 3000000, 12, 5, 13, 0, 1, rep, wid, 7.5),
                         200202, 1);
}
END_TEST

START_TEST(test_complex_profitability_3) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 2;
  rep[0].last = 1;
  wid[0].summ = 2000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 3000000, 12, 5, 13, 0, 1, rep, wid, 7.5),
                         157931, 1);
}
END_TEST

START_TEST(test_complex_profitability_4) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 2300000, 25, 3.7, 13, 1, 1, rep, wid, 7.5),
                         200971, 1);
}
END_TEST

START_TEST(test_complex_profitability_5) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1234567, 48, 3.7, 13, 1, 1, rep, wid, 7.5),
                         226294, 1);
}
END_TEST

START_TEST(test_complex_profitability_6) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1234567, 34, 3.7, 13, 2, 1, rep, wid, 7.5),
                         157392, 1);
}
END_TEST

START_TEST(test_complex_profitability_7) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1234567, 34, 3.7, 13, 3, 1, rep, wid, 7.5),
                         156064, 1);
}
END_TEST

START_TEST(test_complex_profitability_8) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1234567, 34, 3.7, 13, 4, 1, rep, wid, 7.5),
                         150648, 1);
}
END_TEST

START_TEST(test_complex_profitability_9) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(
      s21_deposit_profitability_complex(0, 0, 34, 3.7, 13, 4, 1, rep, wid, 7.5),
      0, 1);
}
END_TEST

START_TEST(test_complex_profitability_10) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1000000, 47, 3.7, 13, 2, 1, rep, wid, 8.5),
                         154374, 1);
}
END_TEST

START_TEST(test_complex_profitability_11) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1000000, 47, 3.7, 13, 1, 1, rep, wid, 8.5),
                         155117, 1);
}
END_TEST

START_TEST(test_complex_profitability_12) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 666666666660;
  wid[0].year = 0;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 1234567, 47, 3.7, 13, 1, 1, rep, wid, 8.5),
                         -1, 1);
}
END_TEST

START_TEST(test_complex_tax_amount_1) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 4234567, 34, 3.7, 13, 2, 1, rep, wid, 7.5),
                         33910, 1);
}
END_TEST

START_TEST(test_complex_tax_amount_2) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 4234567, 34, 3.7, 13, 3, 1, rep, wid, 7.5),
                         43106, 1);
}
END_TEST

START_TEST(test_complex_tax_amount_3) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 4234567, 34, 3.7, 13, 4, 1, rep, wid, 7.5),
                         50712, 1);
}
END_TEST

START_TEST(test_complex_tax_amount_4) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 4234567, 34, 3.7, 13, 1, 1, rep, wid, 7.5),
                         34197, 1);
}
END_TEST

START_TEST(test_complex_tax_amount_5) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 4234567, 34, 3.7, 13, 0, 1, rep, wid, 7.5),
                         34397, 1);
}
END_TEST

START_TEST(test_complex_tax_amount_6) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 4234567, 24, 3.7, 13, 3, 1, rep, wid, 7.5),
                         24155, 1);
}
END_TEST

START_TEST(test_end_amount_1) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 15000000, 11, 7.8, 13, 0, 1, rep, wid, 7.5),
                         1744265, 1);
}
END_TEST

START_TEST(test_end_amount_2) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 15000000, 11, 7.8, 13, 1, 1, rep, wid, 7.5),
                         1738722, 1);
}
END_TEST

START_TEST(test_end_amount_3) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 15000000, 11, 7.8, 13, 2, 1, rep, wid, 7.5),
                         1731227, 1);
}
END_TEST

START_TEST(test_end_amount_4) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 15000000, 11, 7.8, 13, 3, 1, rep, wid, 7.5),
                         1712257, 1);
}
END_TEST

START_TEST(test_end_amount_5) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 15000000, 22, 7.8, 13, 4, 1, rep, wid, 7.5),
                         1783846, 1);
}
END_TEST

START_TEST(test_end_amount_6) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 7000000, 17, 11, 13, 0, 0, rep, wid, 7.5),
                         3000000, 1);
}
END_TEST

START_TEST(test_end_amount_7) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 7000000, 17, 11, 13, 1, 0, rep, wid, 7.5),
                         3000000, 1);
}
END_TEST

START_TEST(test_end_amount_8) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 7000000, 17, 11, 13, 2, 0, rep, wid, 7.5),
                         3000000, 1);
}
END_TEST

START_TEST(test_end_amount_9) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 7000000, 17, 11, 13, 3, 0, rep, wid, 7.5),
                         3000000, 1);
}
END_TEST

START_TEST(test_end_amount_10) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 7000000, 17, 11, 13, 4, 0, rep, wid, 7.5),
                         3000000, 1);
}
END_TEST

START_TEST(test_visocosny_god_1) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 7000000, 53, 11, 13, 0, 1, rep, wid, 7.5),
                         2278082, 1);
}
END_TEST

START_TEST(test_visocosny_god_2) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 7000000, 48, 11, 13, 0, 1, rep, wid, 7.5),
                         2044316, 1);
}
END_TEST

START_TEST(test_all_deposit_1) {
  s21_repelishments rep[1] = {0};
  s21_widrawls wid[1] = {0};
  rep[0].summ = 454545;
  rep[0].year = 0;
  rep[0].month = 4;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 2;
  wid[0].month = 8;
  wid[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(0, 6666666, 6, 6, 13,
                                                           0, 0, rep, wid, 8.5),
                         205155, 1);
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(1, 6666666, 6, 6, 13,
                                                           0, 0, rep, wid, 8.5),
                         15620, 1);
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(2, 6666666, 6, 6, 13,
                                                           0, 0, rep, wid, 8.5),
                         7121211, 1);
}
END_TEST

START_TEST(test_all_deposit_2) {
  s21_repelishments rep[2] = {0};
  s21_widrawls wid[2] = {0};
  wid[0].summ = 666666;
  wid[0].year = 0;
  wid[0].month = 9;
  wid[0].last = 0;
  wid[0].summ = 1111111;
  wid[0].year = 2;
  wid[0].month = 4;
  wid[0].last = 1;
  rep[0].summ = 1000000;
  rep[0].year = 1;
  rep[0].month = 7;
  rep[0].last = 0;
  rep[0].summ = 500000;
  rep[0].year = 2;
  rep[0].month = 4;
  rep[0].last = 1;
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             0, 9876543210, 48, 7.6, 13, 1, 0, rep, wid, 8.5),
                         3002409076, 1000000);
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             1, 9876543210, 48, 7.6, 13, 1, 0, rep, wid, 8.5),
                         390257929, 1000000);
  ck_assert_float_eq_tol(s21_deposit_profitability_complex(
                             2, 9876543210, 48, 7.6, 13, 1, 0, rep, wid, 8.5),
                         9876265433, 1000000);
}
END_TEST

START_TEST(test_check_only_numbers_1) {
  ck_assert_int_eq(s21_check_if_only_numbers("342\0", 1), 0);
  ck_assert_int_eq(s21_check_if_only_numbers("342.\0", 2), 0);
  ck_assert_int_eq(s21_check_if_only_numbers("342.\0", 1), 1);
  ck_assert_int_eq(s21_check_if_only_numbers("342.df\0", 1), 1);
  ck_assert_int_eq(s21_check_if_only_numbers("34.2.\0", 2), 1);
}
END_TEST

Suite *decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Decimal");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_plus_1);
  tcase_add_test(tc_core, test_plus_2);
  tcase_add_test(tc_core, test_plus_3);
  tcase_add_test(tc_core, test_plus_4);
  tcase_add_test(tc_core, test_minus_1);
  tcase_add_test(tc_core, test_minus_2);
  tcase_add_test(tc_core, test_minus_3);
  tcase_add_test(tc_core, test_mult_1);
  tcase_add_test(tc_core, test_mult_2);
  tcase_add_test(tc_core, test_mult_3);
  tcase_add_test(tc_core, test_mult_4);
  tcase_add_test(tc_core, test_mult_5);
  tcase_add_test(tc_core, test_div_1);
  tcase_add_test(tc_core, test_div_2);
  tcase_add_test(tc_core, test_div_3);
  tcase_add_test(tc_core, test_div_4);
  tcase_add_test(tc_core, test_div_5);
  tcase_add_test(tc_core, test_pow_1);
  tcase_add_test(tc_core, test_pow_2);
  tcase_add_test(tc_core, test_pow_3);
  tcase_add_test(tc_core, test_mod_1);
  tcase_add_test(tc_core, test_mod_2);
  tcase_add_test(tc_core, test_mod_3);
  tcase_add_test(tc_core, test_mod_4);
  tcase_add_test(tc_core, test_mod_5);
  tcase_add_test(tc_core, test_sin_1);
  tcase_add_test(tc_core, test_sin_2);
  tcase_add_test(tc_core, test_sin_3);
  tcase_add_test(tc_core, test_cos_1);
  tcase_add_test(tc_core, test_cos_2);
  tcase_add_test(tc_core, test_cos_3);
  tcase_add_test(tc_core, test_cos_4);
  tcase_add_test(tc_core, test_tan_1);
  tcase_add_test(tc_core, test_tan_2);
  tcase_add_test(tc_core, test_tan_3);
  tcase_add_test(tc_core, test_asin_1);
  tcase_add_test(tc_core, test_asin_2);
  tcase_add_test(tc_core, test_asin_3);
  tcase_add_test(tc_core, test_acos_1);
  tcase_add_test(tc_core, test_acos_2);
  tcase_add_test(tc_core, test_acos_3);
  tcase_add_test(tc_core, test_atan_1);
  tcase_add_test(tc_core, test_atan_2);
  tcase_add_test(tc_core, test_atan_3);
  tcase_add_test(tc_core, test_sqrt_1);
  tcase_add_test(tc_core, test_sqrt_2);
  tcase_add_test(tc_core, test_sqrt_3);
  tcase_add_test(tc_core, test_nat_log_1);
  tcase_add_test(tc_core, test_nat_log_2);
  tcase_add_test(tc_core, test_nat_log_3);
  tcase_add_test(tc_core, test_common_log_1);
  tcase_add_test(tc_core, test_common_log_2);
  tcase_add_test(tc_core, test_common_log_3);
  tcase_add_test(tc_core, test_x_1);
  tcase_add_test(tc_core, test_x_2);
  tcase_add_test(tc_core, test_num_len_1);
  tcase_add_test(tc_core, test_num_len_2);
  tcase_add_test(tc_core, test_complecsity_two_1);
  tcase_add_test(tc_core, test_complecsity_two_2);
  tcase_add_test(tc_core, test_complecsity_n_1);
  tcase_add_test(tc_core, test_complecsity_n_2);
  tcase_add_test(tc_core, test_complecsity_n_3);
  tcase_add_test(tc_core, test_complecsity_n_4);
  tcase_add_test(tc_core, test_complecsity_n_5);
  tcase_add_test(tc_core, test_complecsity_n_6);
  tcase_add_test(tc_core, test_complecsity_n_7);
  tcase_add_test(tc_core, test_complecsity_n_8);
  tcase_add_test(tc_core, test_complecsity_n_9);
  tcase_add_test(tc_core, test_complecsity_n_10);
  tcase_add_test(tc_core, test_complecsity_n_11);
  tcase_add_test(tc_core, test_brackets_error_1);
  tcase_add_test(tc_core, test_brackets_error_2);
  tcase_add_test(tc_core, test_brackets_error_3);
  tcase_add_test(tc_core, test_brackets_error_4);
  tcase_add_test(tc_core, test_brackets_error_5);
  tcase_add_test(tc_core, test_brackets_error_6);
  tcase_add_test(tc_core, test_correctness_error_1);
  tcase_add_test(tc_core, test_correctness_error_2);
  tcase_add_test(tc_core, test_correctness_error_3);
  tcase_add_test(tc_core, test_correctness_error_4);
  tcase_add_test(tc_core, test_correctness_error_5);
  tcase_add_test(tc_core, test_correctness_error_6);
  tcase_add_test(tc_core, test_correctness_error_7);
  tcase_add_test(tc_core, test_correctness_error_8);
  tcase_add_test(tc_core, test_correctness_error_9);
  tcase_add_test(tc_core, test_correctness_error_10);
  tcase_add_test(tc_core, test_correctness_error_11);
  tcase_add_test(tc_core, test_correctness_error_12);
  tcase_add_test(tc_core, test_correctness_error_13);
  tcase_add_test(tc_core, test_correctness_error_14);
  tcase_add_test(tc_core, test_correctness_error_15);
  tcase_add_test(tc_core, test_one_number_1);
  tcase_add_test(tc_core, test_one_number_2);
  tcase_add_test(tc_core, test_one_number_3);
  tcase_add_test(tc_core, test_one_number_4);
  tcase_add_test(tc_core, test_one_number_5);
  tcase_add_test(tc_core, test_one_number_6);
  tcase_add_test(tc_core, test_znaks_1);
  tcase_add_test(tc_core, test_znaks_2);
  tcase_add_test(tc_core, test_znaks_3);
  tcase_add_test(tc_core, test_znaks_4);
  tcase_add_test(tc_core, test_znaks_5);
  tcase_add_test(tc_core, test_znaks_6);
  tcase_add_test(tc_core, test_znaks_7);
  tcase_add_test(tc_core, test_points_1);
  tcase_add_test(tc_core, test_points_2);
  tcase_add_test(tc_core, test_points_3);
  tcase_add_test(tc_core, test_points_4);
  tcase_add_test(tc_core, test_points_5);
  tcase_add_test(tc_core, test_points_6);
  tcase_add_test(tc_core, test_sin_brackets_1);
  tcase_add_test(tc_core, test_sin_brackets_2);
  tcase_add_test(tc_core, test_sin_brackets_3);
  tcase_add_test(tc_core, test_sin_brackets_4);
  tcase_add_test(tc_core, test_sin_brackets_5);
  tcase_add_test(tc_core, test_swh_1);
  tcase_add_test(tc_core, test_swh_2);
  tcase_add_test(tc_core, test_swh_3);
  tcase_add_test(tc_core, test_swh_4);
  tcase_add_test(tc_core, test_swh_5);
  tcase_add_test(tc_core, test_swh_6);
  tcase_add_test(tc_core, test_swh_7);
  tcase_add_test(tc_core, test_annuitent_payment_1);
  tcase_add_test(tc_core, test_annuitent_payment_2);
  tcase_add_test(tc_core, test_annuitent_payment_3);
  tcase_add_test(tc_core, test_annuitent_overpayment_1);
  tcase_add_test(tc_core, test_annuitent_overpayment_2);
  tcase_add_test(tc_core, test_annuitent_overpayment_3);
  tcase_add_test(tc_core, test_annuitent_all_payment_1);
  tcase_add_test(tc_core, test_annuitent_all_payment_2);
  tcase_add_test(tc_core, test_annuitent_all_payment_3);
  tcase_add_test(tc_core, test_annuitent_all_payment_4);
  tcase_add_test(tc_core, test_differential_payment_1);
  tcase_add_test(tc_core, test_differential_payment_2);
  tcase_add_test(tc_core, test_differential_payment_3);
  tcase_add_test(tc_core, test_differential_overpayment_1);
  tcase_add_test(tc_core, test_differential_overpayment_2);
  tcase_add_test(tc_core, test_differential_overpayment_3);
  tcase_add_test(tc_core, test_differential_all_payment_1);
  tcase_add_test(tc_core, test_differential_all_payment_2);
  tcase_add_test(tc_core, test_differential_all_payment_3);
  tcase_add_test(tc_core, test_differential_all_payment_4);
  tcase_add_test(tc_core, test_simple_profitability_1);
  tcase_add_test(tc_core, test_simple_profitability_2);
  tcase_add_test(tc_core, test_simple_profitability_3);
  tcase_add_test(tc_core, test_simple_profitability_4);
  tcase_add_test(tc_core, test_simple_profitability_5);
  tcase_add_test(tc_core, test_complex_profitability_1);
  tcase_add_test(tc_core, test_complex_profitability_2);
  tcase_add_test(tc_core, test_complex_profitability_3);
  tcase_add_test(tc_core, test_complex_profitability_4);
  tcase_add_test(tc_core, test_complex_profitability_5);
  tcase_add_test(tc_core, test_complex_profitability_6);
  tcase_add_test(tc_core, test_complex_profitability_7);
  tcase_add_test(tc_core, test_complex_profitability_8);
  tcase_add_test(tc_core, test_complex_profitability_9);
  tcase_add_test(tc_core, test_complex_profitability_10);
  tcase_add_test(tc_core, test_complex_profitability_11);
  tcase_add_test(tc_core, test_complex_profitability_12);
  tcase_add_test(tc_core, test_complex_tax_amount_1);
  tcase_add_test(tc_core, test_complex_tax_amount_2);
  tcase_add_test(tc_core, test_complex_tax_amount_3);
  tcase_add_test(tc_core, test_complex_tax_amount_4);
  tcase_add_test(tc_core, test_complex_tax_amount_5);
  tcase_add_test(tc_core, test_complex_tax_amount_6);
  tcase_add_test(tc_core, test_end_amount_1);
  tcase_add_test(tc_core, test_end_amount_2);
  tcase_add_test(tc_core, test_end_amount_3);
  tcase_add_test(tc_core, test_end_amount_4);
  tcase_add_test(tc_core, test_end_amount_5);
  tcase_add_test(tc_core, test_end_amount_6);
  tcase_add_test(tc_core, test_end_amount_7);
  tcase_add_test(tc_core, test_end_amount_8);
  tcase_add_test(tc_core, test_end_amount_9);
  tcase_add_test(tc_core, test_end_amount_10);
  tcase_add_test(tc_core, test_visocosny_god_1);
  tcase_add_test(tc_core, test_visocosny_god_2);
  tcase_add_test(tc_core, test_all_deposit_1);
  tcase_add_test(tc_core, test_all_deposit_2);
  tcase_add_test(tc_core, test_check_only_numbers_1);
  suite_add_tcase(s, tc_core);
  return s;
}
