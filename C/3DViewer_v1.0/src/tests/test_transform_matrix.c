#include "main_test.h"

START_TEST(test_1) {
  vertex_t vertex = {0};
  double cmp[] = VECTOR_1;
  memcpy(&vertex, cmp, sizeof(vertex_t));

  matrix_t matrix = {0};
  double tmpmx[MX_SIZE][MX_SIZE] = IDENTITY;
  memcpy(&matrix, tmpmx, sizeof(matrix_t));

  transform_vertex(&vertex, &matrix);

  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_2) {
  vertex_t vertex = {0};
  double cmp[] = VECTOR_1;
  memcpy(&vertex, cmp, sizeof(vertex_t));

  matrix_t matrix = {0};
  double tmpmx[MX_SIZE][MX_SIZE] = PERMUTATION;
  memcpy(&matrix, tmpmx, sizeof(matrix_t));

  transform_vertex(&vertex, &matrix);

  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_3) {
  vertex_t vertex = {0};
  double cmp[] = VECTOR_0;
  memcpy(&vertex, cmp, sizeof(vertex_t));

  matrix_t matrix = {0};
  double tmpmx[MX_SIZE][MX_SIZE] = IDENTITY;
  memcpy(&matrix, tmpmx, sizeof(matrix_t));

  transform_vertex(&vertex, &matrix);

  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_4) {
  vertex_t vertex = {0};
  double cmp[] = VECTOR_0;
  memcpy(&vertex, cmp, sizeof(vertex_t));

  matrix_t matrix = {0};
  double tmpmx[MX_SIZE][MX_SIZE] = PERMUTATION;
  memcpy(&matrix, tmpmx, sizeof(matrix_t));

  transform_vertex(&vertex, &matrix);

  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_5) {
  vertex_t vertex = {0};
  double init[] = VECTOR_2;
  memcpy(&vertex, init, sizeof(vertex_t));

  matrix_t matrix = {0};
  double tmpmx[MX_SIZE][MX_SIZE] = PERMUTATION;
  memcpy(&matrix, tmpmx, sizeof(matrix_t));
  transform_vertex(&vertex, &matrix);
  double cmp[] = {3.0, 2.0, 1.0};

  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(test_6) {
  vertex_t vertex = {0};
  double init[] = VECTOR_2;
  memcpy(&vertex, init, sizeof(vertex_t));

  matrix_t matrix = {0};
  double tmpmx[MX_SIZE][MX_SIZE] = ONES;
  memcpy(&matrix, tmpmx, sizeof(matrix_t));
  transform_vertex(&vertex, &matrix);
  double cmp[] = {6.0, 6.0, 6.0};

  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

Suite *transform_vertex_suite(void) {
  Suite *s = suite_create("\n\e[0;36m  test_transform \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, test_1);
  tcase_add_test(tc_tv, test_2);
  tcase_add_test(tc_tv, test_3);
  tcase_add_test(tc_tv, test_4);
  tcase_add_test(tc_tv, test_5);
  tcase_add_test(tc_tv, test_6);

  suite_add_tcase(s, tc_tv);

  return s;
}
