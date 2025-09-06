#include "main_test.h"

START_TEST(test_1) {
  int res_v = 0;
  int res_f = 0;
  int tobe_v = 8;
  int tobe_f = 12;

  FILE *f = open_file(OBJ_FILE_1);
  if (f)
  {
    res_v = count_lines(f, "v");
    res_f = count_lines(f, "f");
    fclose(f);
  }

  ck_assert_int_eq(res_v, tobe_v);
  ck_assert_int_eq(res_f, tobe_f);
}
END_TEST

START_TEST(test_2) {
  int res_v = 0;
  int res_f = 0;
  int tobe_v = 3194;
  int tobe_f = 1825;

  FILE *f = open_file(OBJ_FILE_2);
  if (f)
  {
    res_v = count_lines(f, "v");
    res_f = count_lines(f, "f");
    fclose(f);
  }

  ck_assert_int_eq(res_v, tobe_v);
  ck_assert_int_eq(res_f, tobe_f);
}
END_TEST

START_TEST(test_3) {
  int res_v = 0;
  int res_f = 0;
  int tobe_v = 3;
  int tobe_f = 3;

  FILE *f = open_file(OBJ_FILE_4);
  if (f)
  {
    res_v = count_lines(f, "v");
    res_f = count_lines(f, "f");
    fclose(f);
  }

  ck_assert_int_eq(res_v, tobe_v);
  ck_assert_int_eq(res_f, tobe_f);
}
END_TEST

START_TEST(test_4) {
  int res_v = 10;
  int res_f = 10;
  int tobe_v = 0;
  int tobe_f = 0;

  FILE *f = open_file(OBJ_FILE_3);
  if (f)
  {
    res_v = count_lines(f, "v");
    res_f = count_lines(f, "f");
    fclose(f);
  }

  ck_assert_int_eq(res_v, tobe_v);
  ck_assert_int_eq(res_f, tobe_f);
}
END_TEST


Suite *count_lines_suite(void) {
  Suite *s = suite_create("\e[0;36m test_count_lines \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, test_1);
  tcase_add_test(tc_tv, test_2);
  tcase_add_test(tc_tv, test_3);
  tcase_add_test(tc_tv, test_4);

  suite_add_tcase(s, tc_tv);

  return s;
}