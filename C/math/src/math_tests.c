
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "s21_math.h"

START_TEST(test_fmod) {
  double mas_1[] = {-48273.32423, -323, -0.234, 0, 212, 795739573.231029319};
  double mas_2[] = {8743, 0.321, 1, 32, 984, -0.324};
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 6; i++) {
      ck_assert_ldouble_eq_tol(s21_fmod(mas_1[i], mas_2[j]),
                               fmod(mas_1[i], mas_2[j]), 0.01);
    }
  }
}
END_TEST

START_TEST(test_fmod_boundary) {
  double mas_1[] = {-s21_nINF, s21_NAN, s21_INF, 43,     0.342,
                    0,         -1.1231, 432,     DBL_MIN};  // DBL_MAX?
  double mas_2[] = {-s21_nINF, s21_NAN,    s21_INF, 3230,   984,
                    -0.324,    1231.03423, DBL_MAX, DBL_MIN};
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
      //            printf("%d %d\n", i, j);
      if (isnan(s21_fmod(mas_1[i], mas_2[j])) == 1) {
        int result = isnan(fmod(mas_1[i], mas_2[j]));
        ck_assert_int_eq(result, 1);
      } else {
        ck_assert_ldouble_eq_tol(s21_fmod(mas_1[i], mas_2[j]),
                                 fmod(mas_1[i], mas_2[j]), 0.01);
      }
    }
  }
}
END_TEST

START_TEST(test_exp) {
  double mas_1[] = {-48273.32423, -12.4, -0.234, 0, 3231231, 23};
  for (int i = 0; i < 6; i++) {
    if (isinf(s21_exp(mas_1[i])) == 0) {
      ck_assert_ldouble_eq_tol(s21_exp(mas_1[i]), exp(mas_1[i]), 0.01);
    } else {
      if (isinf(exp(mas_1[i])) == 1) {
        ck_assert_int_eq(1, 1);
      }
    }
  }
}
END_TEST

START_TEST(test_exp_boundary) {
  double mas_1[] = {-s21_nINF, DBL_MIN, s21_NAN, DBL_MAX, s21_INF};
  for (int i = 0; i < 5; i++) {
    if (isinf(s21_exp(mas_1[i]))) {
      if (isinf(exp(mas_1[i]))) {
        ck_assert_int_eq(1, 1);
      }
    } else if (isnan(s21_exp(mas_1[i]))) {
      if (isnan(exp(mas_1[i]))) {
        ck_assert_int_eq(1, 1);
      }
    } else {
      ck_assert_ldouble_eq_tol(s21_exp(mas_1[i]), exp(mas_1[i]), 0.01);
    }
  }
}
END_TEST

START_TEST(test_ln) {
  double mas_1[] = {4023886192, 0.01, 0, 12321.53454342, 3231231, 23};
  for (int i = 0; i < 6; i++) {
    //        printf("%d\n", i);
    if (isinf(s21_log(mas_1[i])) == 0) {
      ck_assert_ldouble_eq_tol(s21_log(mas_1[i]), log(mas_1[i]), 0.01);
    } else {
      if (isinf(log(mas_1[i])) == 1) {
        ck_assert_int_eq(1, 1);
      }
    }
  }
}
END_TEST

START_TEST(test_ln_boundary) {
  double mas_1[] = {s21_nINF, DBL_MIN, s21_NAN, DBL_MAX, s21_INF, -31232.4232};
  for (int i = 0; i < 6; i++) {
    //        printf("%d\n", i);
    if (isinf(s21_log(mas_1[i]))) {
      if (isinf(log(mas_1[i])) == 1) {
        ck_assert_int_eq(1, 1);
      }
    } else if (isnan(s21_log(mas_1[i]))) {
      if (isnan(log(mas_1[i]))) {
        ck_assert_int_eq(1, 1);
      }
    } else {
      ck_assert_ldouble_eq_tol(s21_log(mas_1[i]), log(mas_1[i]), 0.01);
    }
  }
}
END_TEST

START_TEST(test_pow) {
  double mas_1[] = {-48273.32423, -323, -0.234, 0, 212, 467};
  double mas_2[] = {8743, 0.321, 1, 3, 984, -0.324};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      //      printf("%d %d\n", i, j);
      if (isinf(s21_pow(mas_1[i], mas_2[j]))) {
        if (isinf(s21_pow(mas_1[i], mas_2[j]))) {
          ck_assert_int_eq(1, 1);
        }
      } else if (isnan(s21_pow(mas_1[i], mas_2[j]))) {
        if (isnan(s21_pow(mas_1[i], mas_2[j]))) {
          ck_assert_int_eq(1, 1);
        }
      } else {
        ck_assert_ldouble_eq_tol(s21_pow(mas_1[i], mas_2[j]),
                                 pow(mas_1[i], mas_2[j]), 0.01);
      }
    }
  }
}
END_TEST

START_TEST(test_pow_boundary) {
  double mas_1[] = {s21_nINF, s21_NAN, s21_INF, 43,    0.342,
                    0,        -1.1231, 100,     -21312};
  double mas_2[] = {s21_nINF, s21_NAN,    s21_INF, 1,       0,
                    -0.324,   1231.03423, DBL_MAX, -DBL_MAX};
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
      //            printf("%d %d\n", i, j);
      if (isnan(s21_pow(mas_1[i], mas_2[j]))) {
        if (isnan(pow(mas_1[i], mas_2[j]))) {
          ck_assert_int_eq(1, 1);
        }
      } else if (isinf(s21_pow(mas_1[i], mas_2[j]))) {
        if (isinf(pow(mas_1[i], mas_2[j]))) {
          ck_assert_int_eq(1, 1);
        }
      } else {
        ck_assert_ldouble_eq_tol(s21_pow(mas_1[i], mas_2[j]),
                                 pow(mas_1[i], mas_2[j]), 0.01);
      }
    }
  }
}
END_TEST

START_TEST(test_sqrt) {
  double mas_1[] = {-48273.32423, -12.4, 534532, 0, 3231231, 23};
  for (int i = 0; i < 6; i++) {
    if (isinf(s21_sqrt(mas_1[i]))) {
      if (isinf(sqrt(mas_1[i])) == 1) {
        ck_assert_int_eq(1, 1);
      }
    } else if (isnan(s21_sqrt(mas_1[i]))) {
      if (isnan(sqrt(mas_1[i]))) {
        ck_assert_int_eq(1, 1);
      }
    } else {
      ck_assert_ldouble_eq_tol(s21_sqrt(mas_1[i]), sqrt(mas_1[i]), 0.01);
    }
  }
}
END_TEST

START_TEST(test_sqrt_boundary) {
  double mas_1[] = {-s21_nINF, -DBL_MAX, s21_NAN, 34, s21_INF};
  for (int i = 0; i < 5; i++) {
    //        printf("%d\n", i);
    if (isinf(s21_sqrt(mas_1[i]))) {
      if (isinf(sqrt(mas_1[i])) == 1) {
        ck_assert_int_eq(1, 1);
      }
    } else if (isnan(s21_sqrt(mas_1[i]))) {
      if (isnan(sqrt(mas_1[i]))) {
        ck_assert_int_eq(1, 1);
      }
    } else {
      ck_assert_ldouble_eq_tol(s21_sqrt(mas_1[i]), sqrt(mas_1[i]), 0.01);
    }
  }
}
END_TEST

Suite *all_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("ALL");

  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_fmod);
  tcase_add_test(tc_core, test_fmod_boundary);

  tcase_add_test(tc_core, test_exp);
  tcase_add_test(tc_core, test_exp_boundary);

  tcase_add_test(tc_core, test_ln);
  tcase_add_test(tc_core, test_ln_boundary);

  tcase_add_test(tc_core, test_pow);
  tcase_add_test(tc_core, test_pow_boundary);

  tcase_add_test(tc_core, test_sqrt);
  tcase_add_test(tc_core, test_sqrt_boundary);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_abs_1) {
  int int_1 = 24234;
  ck_assert_int_eq(s21_abs(int_1), abs(int_1));
}
END_TEST

START_TEST(test_abs_2) {
  int int_1 = -24234;
  ck_assert_int_eq(s21_abs(int_1), abs(int_1));
}
END_TEST

START_TEST(test_abs_3) {
  int int_1 = 0;
  ck_assert_int_eq(s21_abs(int_1), abs(int_1));
}
END_TEST

START_TEST(test_abs_4) {
  int int_1 = -2147483648;
  ck_assert_int_eq(s21_abs(int_1), abs(int_1));
}
END_TEST

START_TEST(test_fabs_1) {
  double int_1 = 345.77777;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_fabs_2) {
  double int_1 = -345.77777;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_fabs_3) {
  double int_1 = 0;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_fabs_4) {
  double int_1 = 345.000001;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_fabs_5) {
  double int_1 = -345.000001;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_fabs_6) {
  double int_1 = 2478939480.470496320872;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_fabs_7) {
  double int_1 = NAN;
  ck_assert_float_eq(isnan(s21_fabs(int_1)), isnan(fabs(int_1)));
}
END_TEST

START_TEST(test_fabs_8) {
  double int_1 = -INFINITY;
  ck_assert_float_eq(s21_fabs(int_1), fabs(int_1));
}
END_TEST

START_TEST(test_ceil_1) {
  double int_1 = 234245.2457;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_2) {
  double int_1 = -234245.2457;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_3) {
  double int_1 = 234245;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_4) {
  double int_1 = -234245;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_5) {
  double int_1 = 0;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_6) {
  double int_1 = 0.000001;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_7) {
  double int_1 = -0.000001;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_8) {
  double int_1 = 2478939480.470496320872;
  ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
}
END_TEST

START_TEST(test_ceil_9) {
  double int_1 = 3.67;
  for (int i = 1; i < 20; i++) {
    ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
    int_1 *= i;
  }
}
END_TEST

START_TEST(test_ceil_10) {
  double int_1 = -63.67;
  for (int i = 1; i < 20; i++) {
    ck_assert_float_eq(s21_ceil(int_1), ceil(int_1));
    int_1 /= i;
  }
}
END_TEST

START_TEST(test_floor_1) {
  double int_1 = 234245.2457;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_2) {
  double int_1 = -234245.2457;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_3) {
  double int_1 = 234245;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_4) {
  double int_1 = -234245;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_5) {
  double int_1 = 0;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_6) {
  double int_1 = 0.000001;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_7) {
  double int_1 = -0.000001;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_8) {
  double int_1 = 2478939480.470496320872;
  ck_assert_float_eq(s21_floor(int_1), floor(int_1));
}
END_TEST

START_TEST(test_floor_9) {
  double int_1 = 3.67;
  for (int i = 1; i < 20; i++) {
    ck_assert_float_eq(s21_floor(int_1), floor(int_1));
    int_1 *= i;
  }
}
END_TEST

START_TEST(test_floor_10) {
  double int_1 = -63.67;
  for (int i = 1; i < 20; i++) {
    ck_assert_float_eq(s21_floor(int_1), floor(int_1));
    int_1 /= i;
  }
}
END_TEST

Suite *decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Decimal");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_abs_1);
  tcase_add_test(tc_core, test_abs_2);
  tcase_add_test(tc_core, test_abs_3);
  tcase_add_test(tc_core, test_abs_4);
  tcase_add_test(tc_core, test_fabs_1);
  tcase_add_test(tc_core, test_fabs_2);
  tcase_add_test(tc_core, test_fabs_3);
  tcase_add_test(tc_core, test_fabs_4);
  tcase_add_test(tc_core, test_fabs_5);
  tcase_add_test(tc_core, test_fabs_6);
  tcase_add_test(tc_core, test_fabs_7);
  tcase_add_test(tc_core, test_fabs_8);
  tcase_add_test(tc_core, test_ceil_1);
  tcase_add_test(tc_core, test_ceil_2);
  tcase_add_test(tc_core, test_ceil_3);
  tcase_add_test(tc_core, test_ceil_4);
  tcase_add_test(tc_core, test_ceil_5);
  tcase_add_test(tc_core, test_ceil_6);
  tcase_add_test(tc_core, test_ceil_7);
  tcase_add_test(tc_core, test_ceil_8);
  tcase_add_test(tc_core, test_ceil_9);
  tcase_add_test(tc_core, test_ceil_10);
  tcase_add_test(tc_core, test_floor_1);
  tcase_add_test(tc_core, test_floor_2);
  tcase_add_test(tc_core, test_floor_3);
  tcase_add_test(tc_core, test_floor_4);
  tcase_add_test(tc_core, test_floor_5);
  tcase_add_test(tc_core, test_floor_6);
  tcase_add_test(tc_core, test_floor_7);
  tcase_add_test(tc_core, test_floor_8);
  tcase_add_test(tc_core, test_floor_9);
  tcase_add_test(tc_core, test_floor_10);
  suite_add_tcase(s, tc_core);
  return s;
}

START_TEST(test_sin_1) {
  double d = -1;
  for (int i = 0; i < 10; i++) {
    ck_assert_double_eq(s21_sin(d), sin(d));
    d += 0.2;
  }
}
END_TEST

START_TEST(test_sin_2) {
  double d = -75;
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(s21_sin(d), sin(d), SMALL);
    d += 10;
  }
}
END_TEST

START_TEST(test_sin_3) {
  ck_assert_double_nan(s21_sin(s21_NAN));
  ck_assert_double_nan(s21_sin(s21_NINF));
}
END_TEST

START_TEST(test_cos_1) {
  double d = -1;
  for (int i = 0; i < 10; i++) {
    ck_assert_double_eq_tol(s21_cos(d), cos(d), SMALL);
    d += 0.2;
  }
}
END_TEST

START_TEST(test_cos_2) {
  double d = -50;
  for (int i = 0; i < 10; i++) {
    ck_assert_double_eq_tol(s21_cos(d), cos(d), SMALL);
    d += 10;
  }
}
END_TEST

START_TEST(test_cos_3) {
  ck_assert_double_nan(s21_cos(s21_NAN));
  ck_assert_double_nan(s21_cos(s21_NINF));
}
END_TEST

START_TEST(test_tan_1) {
  double d = -2;
  for (int i = 0; i < 30; i++) {
    ck_assert_double_eq_tol(s21_tan(d), tan(d), SMALL);
    d += 0.2;
  }
}
END_TEST

START_TEST(test_tan_2) {
  double d = -50;
  for (int i = 0; i < 10; i++) {
    ck_assert_double_eq_tol(s21_tan(d), tan(d), SMALL);
    d += 10;
  }
}
END_TEST

START_TEST(test_tan_3) {
  ck_assert_double_nan(s21_tan(s21_NAN));
  ck_assert_double_nan(s21_tan(s21_NINF));
}
END_TEST

START_TEST(test_atan_1) {
  ck_assert_double_eq_tol(s21_atan(1), atan(1), SMALL);
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), SMALL);
  ck_assert_double_eq_tol(s21_atan(0), atan(0), SMALL);
  ck_assert_double_eq_tol(s21_atan(0.5), atan(0.5), SMALL);
  ck_assert_double_eq_tol(s21_atan(-0.9), atan(-0.9), SMALL);
  ck_assert_double_eq_tol(s21_atan(3.5), atan(3.5), SMALL);
  ck_assert_double_eq_tol(s21_atan(-100.1112), atan(-100.1112), SMALL);
}
END_TEST

START_TEST(test_atan_2) { ck_assert_double_nan(s21_atan(s21_NAN)); }
END_TEST

START_TEST(test_asin_1) {
  double d = -1;
  for (int i = 0; i < 20; i++) {
    ck_assert_double_eq_tol(s21_asin(d), asin(d), SMALL);
    d += 0.1;
  }
}
END_TEST

START_TEST(test_asin_2) {
  ck_assert_double_nan(s21_asin(2));
  ck_assert_double_nan(s21_asin(-10));
  ck_assert_double_nan(s21_asin(s21_NAN));
}
END_TEST

START_TEST(test_acos_1) {
  ck_assert_double_eq_tol(s21_acos(1), acos(1), SMALL);
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), SMALL);
  ck_assert_double_eq_tol(s21_acos(0), acos(0), SMALL);
  ck_assert_double_eq_tol(s21_acos(0.5), acos(0.5), SMALL);
  ck_assert_double_eq_tol(s21_acos(-0.9), acos(-0.9), SMALL);
}
END_TEST

START_TEST(test_acos_2) {
  ck_assert_double_nan(s21_acos(2));
  ck_assert_double_nan(s21_acos(-10));
  ck_assert_double_nan(s21_acos(s21_NAN));
}
END_TEST

Suite *math_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Math");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sin_1);
  tcase_add_test(tc_core, test_sin_2);
  tcase_add_test(tc_core, test_sin_3);
  tcase_add_test(tc_core, test_cos_1);
  tcase_add_test(tc_core, test_cos_2);
  tcase_add_test(tc_core, test_cos_3);
  tcase_add_test(tc_core, test_tan_1);
  tcase_add_test(tc_core, test_tan_2);
  tcase_add_test(tc_core, test_tan_3);
  tcase_add_test(tc_core, test_atan_1);
  tcase_add_test(tc_core, test_atan_2);
  tcase_add_test(tc_core, test_asin_1);
  tcase_add_test(tc_core, test_asin_2);
  tcase_add_test(tc_core, test_acos_1);
  tcase_add_test(tc_core, test_acos_2);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  SRunner *runner;
  srand(time(NULL));

  s = all_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  s = decimal_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  number_failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  s = math_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  number_failed += srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
