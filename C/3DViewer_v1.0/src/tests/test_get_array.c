#include "main_test.h"

START_TEST(test_1) {
  int res_v = 0;
  int tobe_v = 3;
  int res_a = 10;
  int tobe_a = 0;

  FILE *f = open_file(OBJ_FILE_4);
  if (f)
  {
    res_v = count_lines(f, "v");
    vertex_t *va = get_arr_of_vertices(f, res_v);
    if (va)
    {
        double cmp[] = {
             1.0,  2.0,  3.0,
            -1.0, -2.0, -3.0,
             0.0,  0.0,  0.0
        };
        res_a = memcmp(va, cmp, sizeof(double)*9);
        free(va);
    }
    fclose(f);
  }
  ck_assert_int_eq(res_v, tobe_v);
  ck_assert_int_eq(res_a, tobe_a);
}
END_TEST

START_TEST(test_2) {
  int res_v = 0;
  int tobe_v = 3;
  int res_a = 0;
  int tobe_a = 0;

  FILE *f = open_file(OBJ_FILE_4);
  if (f)
  {
    res_v = count_lines(f, "f");
    face_t *va = get_arr_of_faces(f, res_v);
    if (va)
    {
        int cmp_0[] = { 8, 9,11,10};
        int cmp_1[] = {10,11,15,14};
        int cmp_2[] = {14,15,13,12};

        int s_0 = 4;
        int s_1 = 4;
        int s_2 = 4;

        res_a += (va+0) -> size != s_0;
        res_a += (va+1) -> size != s_1;
        res_a += (va+2) -> size != s_2;

        res_a += memcmp((va+0) -> vertices, cmp_0, sizeof(int)*s_0);
        res_a += memcmp((va+1) -> vertices, cmp_1, sizeof(int)*s_1);
        res_a += memcmp((va+2) -> vertices, cmp_2, sizeof(int)*s_2);

        free_arr_of_faces(va, tobe_v);
    }
    fclose(f);
  }
  ck_assert_int_eq(res_v, tobe_v);
  ck_assert_int_eq(res_a, tobe_a);
}
END_TEST

Suite *get_array_suite(void) {
  Suite *s = suite_create("\e[0;36m get_array \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, test_1);
  tcase_add_test(tc_tv, test_2);

  suite_add_tcase(s, tc_tv);

  return s;
}