#include "main_test.h"

START_TEST(test_1) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 2.0;
  initialize_scale_matrix(scale, &matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {2, 4, 6};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_2) {
  vertex_t vertex = {0};
  double v[] = VECTOR_3;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 3.0;
  initialize_scale_matrix(scale, &matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {6, 3, 0};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_3) {
  vertex_t vertex = {0};
  double v[] = VECTOR_1;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 0.0;
  initialize_scale_matrix(scale, &matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {0, 0, 0};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_4) {
  vertex_t vertex = {0};
  double v[] = VECTOR_0;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 10.0;
  initialize_scale_matrix(scale, &matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {0, 0, 0};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST



Suite *scale_vertex_suite(void) {
  Suite *s = suite_create("\e[0;36m test_scale \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, test_1);
  tcase_add_test(tc_tv, test_2);
  tcase_add_test(tc_tv, test_3);
  tcase_add_test(tc_tv, test_4);

  suite_add_tcase(s, tc_tv);

  return s;
}