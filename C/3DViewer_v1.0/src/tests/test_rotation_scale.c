#include "main_test.h"

START_TEST(rotation_test_1) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  initialize_rotation_matrix(0,0,0,&matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {1, 2, 3};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(rotation_test_2) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  initialize_rotation_matrix(30,0,0,&matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {1, 3.272598, -1.513309};
    ck_assert_double_eq_tol(cmp[0], vertex.x, 1e6);
    ck_assert_double_eq_tol(cmp[1], vertex.y, 1e6);
    ck_assert_double_eq_tol(cmp[2], vertex.z, 1e6);
}
END_TEST

START_TEST(rotation_test_3) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  initialize_rotation_matrix(0,30,0,&matrix);

  transform_vertex(&vertex, &matrix);

    double cmp[] = {1, 3.272598, -1.513309};
      ck_assert_double_eq_tol(cmp[0], vertex.x, 1e6);
      ck_assert_double_eq_tol(cmp[1], vertex.y, 1e6);
      ck_assert_double_eq_tol(cmp[2], vertex.z, 1e6);
}
END_TEST

START_TEST(rotation_test_4) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  initialize_rotation_matrix(0,0,30,&matrix);

  transform_vertex(&vertex, &matrix);

  double cmp[] = {2.130315, -0.679529, 3.000000};
    ck_assert_double_eq_tol(cmp[0], vertex.x, 1e6);
    ck_assert_double_eq_tol(cmp[1], vertex.y, 1e6);
    ck_assert_double_eq_tol(cmp[2], vertex.z, 1e6);
}
END_TEST

START_TEST(rotation_test_5) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  initialize_rotation_matrix(50,50,50,&matrix);

  transform_vertex(&vertex, &matrix);
    
  double cmp[] = {0.650401, 2.471237, 2.733124};
    ck_assert_double_eq_tol(cmp[0], vertex.x, 1e6);
    ck_assert_double_eq_tol(cmp[1], vertex.y, 1e6);
    ck_assert_double_eq_tol(cmp[2], vertex.z, 1e6);
}
END_TEST

START_TEST(scale_test_1) {
  vertex_t vertex = {0};
  double v[] = VECTOR_2;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 2.0;
  initialize_rotation_matrix(0,0,0,&matrix);
  matrix_t matrix_2 = {0};
  initialize_scale_matrix(scale, &matrix_2);

  transform_vertex(&vertex, &matrix);
  transform_vertex(&vertex, &matrix_2);

  double cmp[] = {2, 4, 6};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(scale_test_2) {
  vertex_t vertex = {0};
  double v[] = VECTOR_3;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 3.0;
  initialize_rotation_matrix(0,0,0,&matrix);
  matrix_t matrix_2 = {0};
  initialize_scale_matrix(scale, &matrix_2);

  transform_vertex(&vertex, &matrix);
  transform_vertex(&vertex, &matrix_2);

    double cmp[] = {6, 3, 0};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(scale_test_3) {
  vertex_t vertex = {0};
  double v[] = VECTOR_1;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 0.0;
  initialize_rotation_matrix(0,0,0,&matrix);
  matrix_t matrix_2 = {0};
 initialize_scale_matrix(scale, &matrix_2);

  transform_vertex(&vertex, &matrix);
  transform_vertex(&vertex, &matrix_2);

  double cmp[] = {0, 0, 0};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

START_TEST(scale_test_4) {
  vertex_t vertex = {0};
  double v[] = VECTOR_0;
  memcpy(&vertex, v, sizeof(vertex_t));

  matrix_t matrix = {0};
  double scale = 10.0;
    initialize_rotation_matrix(0,0,0,&matrix);
    matrix_t matrix_2 = {0};
   initialize_scale_matrix(scale, &matrix_2);

  transform_vertex(&vertex, &matrix);
  transform_vertex(&vertex, &matrix_2);

  double cmp[] = {0, 0, 0};
  int res = memcmp(&vertex, cmp, sizeof(vertex_t));
  int tobe = 0;

  ck_assert_int_eq(res, tobe);
}
END_TEST

Suite *rotation_scale_suite(void) {
  Suite *s = suite_create("\e[0;36m test_rotation_scale \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_rotation_case \e[0m");

    tcase_add_test(tc_tv, rotation_test_1);
    tcase_add_test(tc_tv, rotation_test_2);
    tcase_add_test(tc_tv, rotation_test_3);
    tcase_add_test(tc_tv, rotation_test_4);
    tcase_add_test(tc_tv, rotation_test_5);
    tcase_add_test(tc_tv, scale_test_1);
    tcase_add_test(tc_tv, scale_test_2);
    tcase_add_test(tc_tv, scale_test_3);
    tcase_add_test(tc_tv, scale_test_4);

  suite_add_tcase(s, tc_tv);

  return s;
}
