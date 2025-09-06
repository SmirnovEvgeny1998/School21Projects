#include "main_test.h"

START_TEST(test_1) {
    Obj *o = load_obj_info(OBJ_FILE_5);

    // Assert after reading.
    double v[6] = {39.400002, -0.600000, 6.443201, 39.400002, 29.400000, 6.443201};
    int f1[4] = {0,1,3,2};
    int f2[4] = {2,3,7,6};
    int f3[4] = {6,7,5,4};

    ck_assert_int_eq(o->vert_number, 2);
    ck_assert_int_eq(o->faces_number, 3);

    int res = memcmp(o->vert_arr, v, sizeof(vertex_t)*2);
    ck_assert_int_eq(res, 0);

    res = memcmp(o->face_arr[0].vertices, f1, sizeof(int)*4);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(o->face_arr[0].size, 4);

    res = memcmp(o->face_arr[1].vertices, f2, sizeof(int)*4);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(o->face_arr[1].size, 4);

    res = memcmp(o->face_arr[2].vertices, f3, sizeof(int)*4);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(o->face_arr[2].size, 4);

    // Assert rotation.
    rotate(o->vert_arr, 2, 0, 0, 0);
    res = memcmp(o->vert_arr, v, sizeof(vertex_t)*2);
    ck_assert_int_eq(res, 0);

    // Assert scaling.
    double v2[6] = {39.400002 * 10, -0.600000 * 10, 6.443201 * 10, 39.400002 * 10, 29.400000 * 10, 6.443201 * 10};
    scaling(o->vert_arr, 2, 10);
    res = memcmp(o->vert_arr, v2, sizeof(vertex_t)*2);
    ck_assert_int_eq(res, 0);
    
    // Assert motion.
    double v3[6] = {
        39.400002 * 10 + 1,
        -0.600000 * 10 + 2,
        6.443201 * 10 + 3,
        39.400002 * 10 + 1,
        29.400000 * 10 + 2,
        6.443201 * 10 + 3
    };
    motion_vertex(1, 2, 3, 2, o->vert_arr);
    res = memcmp(o->vert_arr, v3, sizeof(vertex_t)*2);
    ck_assert_int_eq(res, 0);

    free_obj(o);
}
END_TEST

START_TEST(test_2) {
    Obj *o = load_obj_info(OBJ_FILE_4);

    // Assert after reading.
    double v[9] = {
         1,  2,  3,
        -1, -2, -3,
         0,  0,  0    
    };
    int f1[4] = {8,9,11,10};
    int f2[4] = {10,11,15,14};
    int f3[4] = {14,15,13,12};

    ck_assert_int_eq(o->vert_number, 3);
    ck_assert_int_eq(o->faces_number, 3);

    int res = memcmp(o->vert_arr, v, sizeof(vertex_t)*3);
    ck_assert_int_eq(res, 0);

    res = memcmp(o->face_arr[0].vertices, f1, sizeof(int)*4);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(o->face_arr[0].size, 4);

    res = memcmp(o->face_arr[1].vertices, f2, sizeof(int)*4);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(o->face_arr[1].size, 4);

    res = memcmp(o->face_arr[2].vertices, f3, sizeof(int)*4);
    ck_assert_int_eq(res, 0);
    ck_assert_int_eq(o->face_arr[2].size, 4);

    // Assert rotation.
    rotate(o->vert_arr, 3, 0, 0, 0);
    res = memcmp(o->vert_arr, v, sizeof(vertex_t)*3);
    ck_assert_int_eq(res, 0);

    // Assert scaling.
    double v2[9] = {
         1 * 0.1,  2 * 0.1,  3 * 0.1,
        -1 * 0.1, -2 * 0.1, -3 * 0.1,
         0,  0,  0    
    };
    scaling(o->vert_arr, 2, 0.1);
    res = memcmp(o->vert_arr, v2, sizeof(vertex_t)*3);
    ck_assert_int_eq(res, 0);
    
    // Assert motion.
    double v3[9] = {
         1 * 0.1 - 2,  2 * 0.1 - 3,  3 * 0.1 - 5,
        -1 * 0.1 - 2, -2 * 0.1 - 3, -3 * 0.1 - 5,
         0 - 2,  0 - 3,  0 - 5
    };
    motion_vertex(-2, -3, -5, 3, o->vert_arr);
    res = memcmp(o->vert_arr, v3, sizeof(vertex_t)*3);
    ck_assert_int_eq(res, 0);

    free_obj(o);
}
END_TEST

Suite *backend_suite(void) {
  Suite *s = suite_create("\e[0;36m backend \e[0m");
  TCase *tc_tv = tcase_create("\e[0;31m test_case \e[0m");

  tcase_add_test(tc_tv, test_1);
  tcase_add_test(tc_tv, test_2);

  suite_add_tcase(s, tc_tv);

  return s;
}