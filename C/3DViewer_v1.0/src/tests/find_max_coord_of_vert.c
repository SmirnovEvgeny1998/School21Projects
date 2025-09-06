#include "main_test.h"

START_TEST(max_coord_test_1) {
    vertex_t arrv[3];
    
    double vert_double[9];
    
    for (int i = 0; i < 9; i++) 
        vert_double[i] = (double)i;
    
    memcpy(arrv, vert_double, sizeof(double) * 9);

    double res = find_max_coord_of_vert(arrv, 3);
    ck_assert_double_eq_tol(res, 8.0, 1e-7);
}
END_TEST

START_TEST(max_coord_test_2) {
    vertex_t arrv[3] = {0};
    
    double vert_double[9];
    
    for (int i = 0; i < 9; i++) 
        vert_double[i] = (double)i*(-15);
    
    memcpy(arrv, vert_double, sizeof(double) * 9);

    double res = find_max_coord_of_vert(arrv, 3);
    ck_assert_double_eq_tol(res, 120.0, 1e-7);
}
END_TEST

START_TEST(max_coord_test_3) {
    vertex_t arrv[3] = {0};
    
    double vert_double[9];
    
    for (int i = 0; i < 9; i++) 
        vert_double[i] = (double)-i;
    
    memcpy(arrv, vert_double, sizeof(double) * 9);

    double res = find_max_coord_of_vert(arrv, 3);
    ck_assert_double_eq_tol(res, 8.0, 1e-7);
}
END_TEST


Suite *test_find_max_coord_of_vert(void) {
  Suite *s = suite_create("\e[0;36m find_max_coord_of_vert \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, max_coord_test_1);
  tcase_add_test(tc_tv, max_coord_test_2);
  tcase_add_test(tc_tv, max_coord_test_3);

  suite_add_tcase(s, tc_tv);

  return s;
}
