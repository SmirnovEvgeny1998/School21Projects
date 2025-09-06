#include "main_test.h"

START_TEST(test_1) {
    vertex_t vertex[4] = {{ 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, { 1.0, 2.0, 3.0 }, { 2.0, 1.0, 0.0 }};

    motion_vertex(0, 0, 4, 4, vertex);
  double cmp[] = {0, 0, 4, 1.0, 1.0, 5.0, 1.0, 2.0, 7.0, 2.0, 1.0, 4.0};
    double res[12] = {0};
    memcpy(res, vertex, sizeof(vertex_t) * 4);
    int eq = memcmp(res, cmp, sizeof(vertex_t) * 4);
    ck_assert_int_eq(eq, 0);
}
END_TEST

START_TEST(test_2) {
    vertex_t vertex[4] = {{ 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, { 1.0, 2.0, 3.0 }, { 2.0, 1.0, 0.0 }};

    motion_vertex(0, -3, 4, 4, vertex);
  double cmp[] = {0, -3, 4, 1.0, -2.0, 5.0, 1.0, -1.0, 7.0, 2.0, -2.0, 4.0};
    double res[12] = {0};
    memcpy(res, vertex, sizeof(vertex_t) * 4);
    int eq = memcmp(res, cmp, sizeof(vertex_t) * 4);
    ck_assert_int_eq(eq, 0);
}
END_TEST

START_TEST(test_3) {
    vertex_t vertex[4] = {{ 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, { 1.0, 2.0, 3.0 }, { 2.0, 1.0, 0.0 }};

    motion_vertex(2.5, -3, 4, 4, vertex);
  double cmp[] = {2.5, -3, 4, 3.5, -2.0, 5.0, 3.5, -1.0, 7.0, 4.5, -2.0, 4.0};
    double res[12] = {0};
    memcpy(res, vertex, sizeof(vertex_t) * 4);
    int eq = memcmp(res, cmp, sizeof(vertex_t) * 4);
    ck_assert_int_eq(eq, 0);
}
END_TEST

Suite *motion_vertex_suite(void) {
  Suite *s = suite_create("\e[0;36m test_motion_vertex \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_motion_vertex \e[0m");

    tcase_add_test(tc_tv, test_1);
    tcase_add_test(tc_tv, test_2);
    tcase_add_test(tc_tv, test_3);

  suite_add_tcase(s, tc_tv);

  return s;
}

