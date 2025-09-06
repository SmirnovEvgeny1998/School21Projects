#include "main_test.h"

START_TEST(test_1) {
    vertex_t arrv[10] = {0};
    double arri[30] = {0};

    matrix_t A = {0};
    initialize_rotation_matrix(10,10,10,&A);
    transform_vertex_massive(arrv, 10, &A);

    int tobe = 0;
    int res = memcmp(arrv, arri, sizeof(vertex_t)*10);

    ck_assert_int_eq(tobe, res);
}
END_TEST

START_TEST(test_2) {
    vertex_t arrv[10] = {0};
    double arri[30] = {0};

    double v[3] = {1,1,1}; 
    for (int i = 0; i < 10; i++)
    {
        memcpy(arrv+i, v, sizeof(vertex_t));
    }

    for (int i = 0; i < 10; i++)
    {
        memcpy(arri+i*3, v, sizeof(vertex_t));
    }

    matrix_t A = {0};
    initialize_rotation_matrix(0,0,0,&A);
    transform_vertex_massive(arrv, 10, &A);

    int tobe = 0;
    int res = memcmp(arrv, arri, sizeof(vertex_t)*10);

    ck_assert_int_eq(tobe, res);
}
END_TEST

START_TEST(test_3) {
    vertex_t arrv[10] = {0};
    double arri[30] = {0};

    double v[3] = {1,1,1}; 
    for (int i = 0; i < 10; i++)
    {
        memcpy(arrv+i, v, sizeof(vertex_t));
    }

    double w[3] = {10,10,10};
    for (int i = 0; i < 10; i++)
    {
        memcpy(arri+i*3, w, sizeof(vertex_t));
    }

    matrix_t A = {0};
    initialize_scale_matrix(10,&A);
    transform_vertex_massive(arrv, 10, &A);

    int tobe = 0;
    int res = memcmp(arrv, arri, sizeof(vertex_t)*10);

    ck_assert_int_eq(tobe, res);
}
END_TEST


Suite *transform_vertex_massive_suite(void) {
  Suite *s = suite_create("\e[0;36m test_transform_massive \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, test_1);
  tcase_add_test(tc_tv, test_2);
  tcase_add_test(tc_tv, test_3);

  suite_add_tcase(s, tc_tv);

  return s;
}
