#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "s21_decimal.h"

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

START_TEST(test_s21_is_equal_int_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(6, &decimal_1);
  for (int i = -6; i < 6; i++) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_equal(decimal_1, decimal_2))
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(6, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_int_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(-6, &decimal_1);
  for (int i = 6; i > -6; i--) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_equal(decimal_1, decimal_2))
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(-6, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_float_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(4.3, &decimal_1);
  s21_from_float_to_decimal(4.3, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_float_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(10000, &decimal_1);
  s21_from_float_to_decimal(1, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_float_3) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-7.5, &decimal_1);
  s21_from_float_to_decimal(-7.5, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_float_4) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-6.5, &decimal_1);
  s21_from_float_to_decimal(6.5, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_float_5) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(7.555, &decimal_1);
  s21_from_float_to_decimal(-7.555, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_float_6) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-10.101010, &decimal_1);
  s21_from_float_to_decimal(-10.1010, &decimal_2);
  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_int_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(6, &decimal_1);
  for (int i = -6; i < 6; i++) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_not_equal(decimal_1, decimal_2) == 0)
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(6, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_int_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(-6, &decimal_1);
  for (int i = 6; i > -6; i--) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_not_equal(decimal_1, decimal_2) == 0)
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(-6, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_float_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(4.3, &decimal_1);
  s21_from_float_to_decimal(4.3, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_float_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(10000, &decimal_1);
  s21_from_float_to_decimal(1, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_float_3) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-7.5, &decimal_1);
  s21_from_float_to_decimal(-7.5, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_float_4) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-6.5, &decimal_1);
  s21_from_float_to_decimal(6.5, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_float_5) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(7.555, &decimal_1);
  s21_from_float_to_decimal(-7.555, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_float_6) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-10.101010, &decimal_1);
  s21_from_float_to_decimal(-10.1010, &decimal_2);
  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_int_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(16, &decimal_1);
  for (int i = -15; i < 17; i++) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_less(decimal_1, decimal_2))
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(17, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_int_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(-16, &decimal_1);
  for (int i = 16; i > -16; i--) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_less(decimal_1, decimal_2) == 0)
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(-16, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_float_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(4.3, &decimal_1);
  s21_from_float_to_decimal(4.3, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_float_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(10000, &decimal_1);
  s21_from_float_to_decimal(1, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_float_3) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-7.5, &decimal_1);
  s21_from_float_to_decimal(-7.5, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_float_4) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-6.5, &decimal_1);
  s21_from_float_to_decimal(6.5, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_float_5) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(7.555, &decimal_1);
  s21_from_float_to_decimal(-7.555, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_float_6) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-10.101010, &decimal_1);
  s21_from_float_to_decimal(-10.1010, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_float_7) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-4.4, &decimal_1);
  s21_from_float_to_decimal(-5.5, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_float_8) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-5.499, &decimal_1);
  s21_from_float_to_decimal(-4.599, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_float_9) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-4, &decimal_1);
  s21_from_float_to_decimal(-5550.5, &decimal_2);
  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_int_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(16, &decimal_1);
  for (int i = -16; i > 16; i++) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_greater(decimal_1, decimal_2) == 0)
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(16, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_int_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(-16, &decimal_1);
  for (int i = 16; i > -17; i--) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_greater(decimal_1, decimal_2))
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(-17, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_float_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(4.3, &decimal_1);
  s21_from_float_to_decimal(4.3, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_float_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(10000, &decimal_1);
  s21_from_float_to_decimal(1, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_float_3) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-7.5, &decimal_1);
  s21_from_float_to_decimal(-7.5, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_float_4) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-6.5, &decimal_1);
  s21_from_float_to_decimal(6.5, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_float_5) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(7.555, &decimal_1);
  s21_from_float_to_decimal(-7.555, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_float_6) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-10.101010, &decimal_1);
  s21_from_float_to_decimal(-10.1010, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_float_7) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-4.4, &decimal_1);
  s21_from_float_to_decimal(-5.5, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_float_8) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-5.499, &decimal_1);
  s21_from_float_to_decimal(-4.599, &decimal_2);
  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_int_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(16, &decimal_1);
  for (int i = -15; i < 16; i++) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_less_or_equal(decimal_1, decimal_2))
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(16, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
  s21_from_int_to_decimal(17, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_int_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(-16, &decimal_1);
  for (int i = 16; i > -16; i--) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_less_or_equal(decimal_1, decimal_2) == 0)
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(-16, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
  s21_from_int_to_decimal(-17, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_float_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(4.3, &decimal_1);
  s21_from_float_to_decimal(4.3, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_float_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(10000, &decimal_1);
  s21_from_float_to_decimal(1, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_float_3) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-7.5, &decimal_1);
  s21_from_float_to_decimal(-7.5, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_less_or_equal_float_4) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-6.5, &decimal_1);
  s21_from_float_to_decimal(6.5, &decimal_2);
  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_int_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(16, &decimal_1);
  for (int i = -16; i > 16; i++) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_greater_or_equal(decimal_1, decimal_2) == 0)
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(16, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
  s21_from_int_to_decimal(17, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_int_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_int_to_decimal(-16, &decimal_1);
  for (int i = 16; i > -16; i--) {
    s21_from_int_to_decimal(i, &decimal_2);
    if (s21_is_greater_or_equal(decimal_1, decimal_2))
      ck_abort_msg("Failed with i = %d\n", i);
  }
  s21_from_int_to_decimal(-16, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
  s21_from_int_to_decimal(-17, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_float_1) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(4.3, &decimal_1);
  s21_from_float_to_decimal(4.3, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_float_2) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(10000, &decimal_1);
  s21_from_float_to_decimal(1, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_float_3) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-7.5, &decimal_1);
  s21_from_float_to_decimal(-7.5, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_float_4) {
  s21_decimal decimal_1 = {0}, decimal_2 = {0};
  s21_from_float_to_decimal(-6.5, &decimal_1);
  s21_from_float_to_decimal(6.5, &decimal_2);
  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_1) {
  int original = 5, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_int_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_2) {
  int original = -5, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_int_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_3) {
  int original = 2147483647, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_int_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_4) {
  int original = -20, transformed = 0;
  s21_decimal decimal_1 = {0};
  for (int i = 0; i < 40; i++) {
    original += i;
    s21_from_int_to_decimal(original, &decimal_1);
    s21_from_decimal_to_int(decimal_1, &transformed);
    ck_assert_int_eq(original, transformed);
  }
}
END_TEST

START_TEST(test_from_float_to_decimal_1) {
  float original = 4.66, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_2) {
  float original = -4.66, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_3) {
  float original = 13.4564564564564564564564564564566456, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_4) {
  float original = -13.4564564564564564564564564564566456, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_5) {
  float original = 79.32, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_6) {
  float original = 0, transformed = -1;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_7) {
  float original = 25.1, transformed = -1;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_add_1) {
  int original_1 = 7, original_2 = 45, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &transformed);
  ck_assert_int_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_2) {
  int original_1 = -7, original_2 = 45, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &transformed);
  ck_assert_int_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_3) {
  int original_1 = -7, original_2 = -45, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &transformed);
  ck_assert_int_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_4) {
  float original_1 = 25.8, transformed = 0;
  int original_2 = 7;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_5) {
  float original_1 = -25.8, transformed = 0;
  int original_2 = 7;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_6) {
  float original_1 = -25.8, transformed = 0;
  int original_2 = -7;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_7) {
  float original_1 = 25.8, original_2 = 945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_8) {
  float original_1 = 25.8, original_2 = -945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_9) {
  float original_1 = -25.8, original_2 = -945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_10) {
  float original_1 = -25.8, original_2 = 0, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_11) {
  float original_1 = 0, original_2 = 0, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_add_12) {
  float original_1 = 0, original_2 = -945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_add(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 + original_2, transformed);
}
END_TEST

START_TEST(test_sub_1) {
  int original_1 = 7, original_2 = 45, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &transformed);
  ck_assert_int_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_2) {
  int original_1 = -7, original_2 = 45, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &transformed);
  ck_assert_int_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_3) {
  int original_1 = -7, original_2 = -45, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &transformed);
  ck_assert_int_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_4) {
  float original_1 = 25.8, transformed = 0;
  int original_2 = 7;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_5) {
  float original_1 = -25.8, transformed = 0;
  int original_2 = 7;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_6) {
  float original_1 = -25.8, transformed = 0;
  int original_2 = -7;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_int_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_7) {
  float original_1 = 25.8, original_2 = 945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_8) {
  float original_1 = 25.8, original_2 = -945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_9) {
  float original_1 = -25.8, original_2 = -945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_10) {
  float original_1 = -25.8, original_2 = 0, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_11) {
  float original_1 = 0, original_2 = 0, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_sub_12) {
  float original_1 = 0, original_2 = -945.8, transformed = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(original_1, &decimal_1);
  s21_from_float_to_decimal(original_2, &decimal_2);
  s21_sub(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &transformed);
  ck_assert_float_eq(original_1 - original_2, transformed);
}
END_TEST

START_TEST(test_mul_int_1) {
  int int_in_1 = 3, int_in_2 = 2, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 * int_in_2, int_out);
}
END_TEST

START_TEST(test_mul_int_2) {
  int int_in_1 = -5, int_in_2 = 5, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 * int_in_2, int_out);
}
END_TEST

START_TEST(test_mul_int_3) {
  int int_in_1 = -9, int_in_2 = -2, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 * int_in_2, int_out);
}
END_TEST

START_TEST(test_mul_int_4) {
  int int_in_1 = 3000, int_in_2 = 0, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 * int_in_2, int_out);
}
END_TEST

START_TEST(test_mul_float_1) {
  float float_in_1 = 2.56, float_in_2 = 10, float_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(float_in_1, &decimal_1);
  s21_from_float_to_decimal(float_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &float_out);
  ck_assert_float_eq_tol(float_in_1 * float_in_2, float_out, 0.00001);
}
END_TEST

START_TEST(test_mul_float_2) {
  float float_in_1 = 2.5, float_in_2 = -10, float_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(float_in_1, &decimal_1);
  s21_from_float_to_decimal(float_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &float_out);
  ck_assert_float_eq(float_in_1 * float_in_2, float_out);
}
END_TEST

START_TEST(test_mul_float_3) {
  float float_in_1 = -30.3, float_in_2 = -0.1, float_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(float_in_1, &decimal_1);
  s21_from_float_to_decimal(float_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &float_out);
  ck_assert_float_eq(float_in_1 * float_in_2, float_out);
}
END_TEST

START_TEST(test_mul_float_4) {
  float float_in_1 = 0, float_in_2 = 30.3030, float_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(float_in_1, &decimal_1);
  s21_from_float_to_decimal(float_in_2, &decimal_2);
  s21_mul(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &float_out);
  ck_assert_float_eq(float_in_1 * float_in_2, float_out);
}
END_TEST

START_TEST(test_div_int_1) {
  int int_in_1 = 4, int_in_2 = 2, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_div(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 / int_in_2, int_out);
}
END_TEST

START_TEST(test_div_int_2) {
  int int_in_1 = -5, int_in_2 = 5, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_div(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 / int_in_2, int_out);
}
END_TEST

START_TEST(test_div_int_3) {
  int int_in_1 = -20, int_in_2 = -2, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_div(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 / int_in_2, int_out);
}
END_TEST

START_TEST(test_div_int_4) {
  int int_in_1 = 0, int_in_2 = 20, int_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_int_to_decimal(int_in_1, &decimal_1);
  s21_from_int_to_decimal(int_in_2, &decimal_2);
  s21_div(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_int(decimal_3, &int_out);
  ck_assert_int_eq(int_in_1 / int_in_2, int_out);
}
END_TEST

START_TEST(test_div_float_1) {
  float float_in_1 = 2.56, float_in_2 = 0.02, float_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(float_in_1, &decimal_1);
  s21_from_float_to_decimal(float_in_2, &decimal_2);
  s21_div(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &float_out);
  ck_assert_float_eq(float_in_1 / float_in_2, float_out);
}
END_TEST

START_TEST(test_div_float_2) {
  float float_in_1 = 25, float_in_2 = -10, float_out = 0;
  s21_decimal decimal_1 = {0}, decimal_2 = {0}, decimal_3 = {0};
  s21_from_float_to_decimal(float_in_1, &decimal_1);
  s21_from_float_to_decimal(float_in_2, &decimal_2);
  s21_div(decimal_1, decimal_2, &decimal_3);
  s21_from_decimal_to_float(decimal_3, &float_out);
  ck_assert_float_eq(float_in_1 / float_in_2, float_out);
}
END_TEST

START_TEST(test_s21_floor_1) {
  float float_in = 10.1, float_out = 0, expectation = 10;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_floor(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_floor_2) {
  float float_in = -3.5, float_out = 0, expectation = -4;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_floor(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_floor_3) {
  float float_in = 9999.9999, float_out = 0, expectation = 10000;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_floor(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_1) {
  float float_in = 10.1, float_out = 0, expectation = 10;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_2) {
  float float_in = 19.9, float_out = 0, expectation = 20;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_3) {
  float float_in = -19.99, float_out = 0, expectation = -20;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_4) {
  float float_in = 9999.9999, float_out = 0, expectation = 10000;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_5) {
  float float_in = -9999.9999, float_out = 0, expectation = -10000;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_6) {
  float float_in = 1, float_out = 0, expectation = 1;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_7) {
  float float_in = 0.000000999, float_out = 0, expectation = 0;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_round_8) {
  float float_in = 0.00000000000000000119, float_out = 0, expectation = 0;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_round(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_truncate_1) {
  float float_in = -3.5, float_out = 0, expectation = -3;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_truncate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  float float_in = 9999.8999, float_out = 0, expectation = 9999;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_truncate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_truncate_3) {
  float float_in = 10.1, float_out = 0, expectation = 10;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_truncate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_truncate_4) {
  float float_in = 19.9, float_out = 0, expectation = 19;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_truncate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_truncate_5) {
  float float_in = -19.99, float_out = 0, expectation = -19;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_truncate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_negate_1) {
  float float_in = 10.1, float_out = 0, expectation = -10.1;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_negate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_negate_2) {
  float float_in = 19.9, float_out = 0, expectation = -19.9;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_negate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_negate_3) {
  float float_in = -19.99, float_out = 0, expectation = 19.99;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_negate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

START_TEST(test_s21_negate_4) {
  float float_in = 0, float_out = 0, expectation = 0;
  s21_decimal decimal_in = {0}, decimal_out = {0};
  s21_from_float_to_decimal(float_in, &decimal_in);
  s21_negate(decimal_in, &decimal_out);
  s21_from_decimal_to_float(decimal_out, &float_out);
  ck_assert_float_eq(float_out, expectation);
}
END_TEST

Suite *decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Decimal");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_is_equal_int_1);
  tcase_add_test(tc_core, test_s21_is_equal_int_2);
  tcase_add_test(tc_core, test_s21_is_equal_float_1);
  tcase_add_test(tc_core, test_s21_is_equal_float_2);
  tcase_add_test(tc_core, test_s21_is_equal_float_3);
  tcase_add_test(tc_core, test_s21_is_equal_float_4);
  tcase_add_test(tc_core, test_s21_is_equal_float_5);
  tcase_add_test(tc_core, test_s21_is_equal_float_6);
  tcase_add_test(tc_core, test_s21_is_not_equal_int_1);
  tcase_add_test(tc_core, test_s21_is_not_equal_int_2);
  tcase_add_test(tc_core, test_s21_is_not_equal_float_1);
  tcase_add_test(tc_core, test_s21_is_not_equal_float_2);
  tcase_add_test(tc_core, test_s21_is_not_equal_float_3);
  tcase_add_test(tc_core, test_s21_is_not_equal_float_4);
  tcase_add_test(tc_core, test_s21_is_not_equal_float_5);
  tcase_add_test(tc_core, test_s21_is_not_equal_float_6);
  tcase_add_test(tc_core, test_s21_is_less_int_1);
  tcase_add_test(tc_core, test_s21_is_less_int_2);
  tcase_add_test(tc_core, test_s21_is_less_float_1);
  tcase_add_test(tc_core, test_s21_is_less_float_2);
  tcase_add_test(tc_core, test_s21_is_less_float_3);
  tcase_add_test(tc_core, test_s21_is_less_float_4);
  tcase_add_test(tc_core, test_s21_is_less_float_5);
  tcase_add_test(tc_core, test_s21_is_less_float_6);
  tcase_add_test(tc_core, test_s21_is_less_float_7);
  tcase_add_test(tc_core, test_s21_is_less_float_8);
  tcase_add_test(tc_core, test_s21_is_less_float_9);
  tcase_add_test(tc_core, test_s21_is_greater_int_1);
  tcase_add_test(tc_core, test_s21_is_greater_int_2);
  tcase_add_test(tc_core, test_s21_is_greater_float_1);
  tcase_add_test(tc_core, test_s21_is_greater_float_2);
  tcase_add_test(tc_core, test_s21_is_greater_float_3);
  tcase_add_test(tc_core, test_s21_is_greater_float_4);
  tcase_add_test(tc_core, test_s21_is_greater_float_5);
  tcase_add_test(tc_core, test_s21_is_greater_float_6);
  tcase_add_test(tc_core, test_s21_is_greater_float_7);
  tcase_add_test(tc_core, test_s21_is_greater_float_8);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_int_1);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_int_2);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_float_1);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_float_2);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_float_3);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_float_4);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_int_1);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_int_2);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_float_1);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_float_2);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_float_3);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_float_4);
  tcase_add_test(tc_core, test_from_int_to_decimal_1);
  tcase_add_test(tc_core, test_from_int_to_decimal_2);
  tcase_add_test(tc_core, test_from_int_to_decimal_3);
  tcase_add_test(tc_core, test_from_int_to_decimal_4);
  tcase_add_test(tc_core, test_from_float_to_decimal_1);
  tcase_add_test(tc_core, test_from_float_to_decimal_2);
  tcase_add_test(tc_core, test_from_float_to_decimal_3);
  tcase_add_test(tc_core, test_from_float_to_decimal_4);
  tcase_add_test(tc_core, test_from_float_to_decimal_5);
  tcase_add_test(tc_core, test_from_float_to_decimal_6);
  tcase_add_test(tc_core, test_from_float_to_decimal_7);
  tcase_add_test(tc_core, test_add_1);
  tcase_add_test(tc_core, test_add_2);
  tcase_add_test(tc_core, test_add_3);
  tcase_add_test(tc_core, test_add_4);
  tcase_add_test(tc_core, test_add_5);
  tcase_add_test(tc_core, test_add_6);
  tcase_add_test(tc_core, test_add_7);
  tcase_add_test(tc_core, test_add_8);
  tcase_add_test(tc_core, test_add_9);
  tcase_add_test(tc_core, test_add_10);
  tcase_add_test(tc_core, test_add_11);
  tcase_add_test(tc_core, test_add_12);
  tcase_add_test(tc_core, test_sub_1);
  tcase_add_test(tc_core, test_sub_2);
  tcase_add_test(tc_core, test_sub_3);
  tcase_add_test(tc_core, test_sub_4);
  tcase_add_test(tc_core, test_sub_5);
  tcase_add_test(tc_core, test_sub_6);
  tcase_add_test(tc_core, test_sub_7);
  tcase_add_test(tc_core, test_sub_8);
  tcase_add_test(tc_core, test_sub_9);
  tcase_add_test(tc_core, test_sub_10);
  tcase_add_test(tc_core, test_sub_11);
  tcase_add_test(tc_core, test_sub_12);
  tcase_add_test(tc_core, test_mul_int_1);
  tcase_add_test(tc_core, test_mul_int_2);
  tcase_add_test(tc_core, test_mul_int_3);
  tcase_add_test(tc_core, test_mul_int_4);
  tcase_add_test(tc_core, test_mul_float_1);
  tcase_add_test(tc_core, test_mul_float_2);
  tcase_add_test(tc_core, test_mul_float_3);
  tcase_add_test(tc_core, test_mul_float_4);
  tcase_add_test(tc_core, test_div_int_1);
  tcase_add_test(tc_core, test_div_int_2);
  tcase_add_test(tc_core, test_div_int_3);
  tcase_add_test(tc_core, test_div_int_4);
  tcase_add_test(tc_core, test_div_float_1);
  tcase_add_test(tc_core, test_div_float_2);

  tcase_add_test(tc_core, test_s21_floor_1);
  tcase_add_test(tc_core, test_s21_floor_2);
  tcase_add_test(tc_core, test_s21_floor_3);
  tcase_add_test(tc_core, test_s21_round_1);
  tcase_add_test(tc_core, test_s21_round_2);
  tcase_add_test(tc_core, test_s21_round_3);
  tcase_add_test(tc_core, test_s21_round_4);
  tcase_add_test(tc_core, test_s21_round_5);
  tcase_add_test(tc_core, test_s21_round_6);
  tcase_add_test(tc_core, test_s21_round_7);
  tcase_add_test(tc_core, test_s21_round_8);
  tcase_add_test(tc_core, test_s21_truncate_1);
  tcase_add_test(tc_core, test_s21_truncate_2);
  tcase_add_test(tc_core, test_s21_truncate_3);
  tcase_add_test(tc_core, test_s21_truncate_4);
  tcase_add_test(tc_core, test_s21_truncate_5);
  tcase_add_test(tc_core, test_s21_negate_1);
  tcase_add_test(tc_core, test_s21_negate_2);
  tcase_add_test(tc_core, test_s21_negate_3);
  tcase_add_test(tc_core, test_s21_negate_4);

  suite_add_tcase(s, tc_core);
  return s;
}
