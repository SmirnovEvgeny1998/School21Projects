#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "s21_matrix.h"

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

START_TEST(test_create_matrix_1) {
  matrix_t matrix = {0};
  s21_create_matrix(2, 5, &matrix);
  matrix.matrix[1][4] = 9;
  ck_assert_int_eq(matrix.rows, 2);
  ck_assert_int_eq(matrix.matrix[1][4], 9);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_remove_matrix_1) {
  matrix_t matrix = {0};
  s21_create_matrix(2, 5, &matrix);
  matrix.matrix[1][4] = 9;
  s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
}
END_TEST

START_TEST(test_eq_matrix_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(2, 5, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  matrix_1.matrix[1][4] = 9;
  matrix_2.matrix[1][4] = 9;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_eq_matrix_2) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(2, 5, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  matrix_1.matrix[1][4] = 9;
  matrix_2.matrix[1][4] = 7;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_eq_matrix_3) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(2, 5, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_eq_matrix_4) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(2, 6, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  matrix_1.matrix[1][4] = 9;
  matrix_2.matrix[1][4] = 7;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_sum_matrix_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0}, matrix_3 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  s21_sum_matrix(&matrix_1, &matrix_2, &matrix_3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_3.matrix[i][j], (i + j) * 2);
    }
  }

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_3);
}
END_TEST

START_TEST(test_sum_matrix_2) {
  int counter = 0;
  double answers[9] = {73.64, 20, 9, 10, 17.58, 5.23, 62, 80, 5};
  matrix_t matrix_1 = {0}, matrix_2 = {0}, matrix_3 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  matrix_2.matrix[0][0] = 67;
  matrix_2.matrix[0][1] = 7;
  matrix_2.matrix[0][2] = 3;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 7.98;
  matrix_2.matrix[1][2] = -2.77;
  matrix_2.matrix[2][0] = 7;
  matrix_2.matrix[2][1] = 77;
  matrix_2.matrix[2][2] = 3;
  s21_sum_matrix(&matrix_1, &matrix_2, &matrix_3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_3.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_3);
}
END_TEST

START_TEST(test_sub_matrix_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0}, matrix_3 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  s21_sub_matrix(&matrix_1, &matrix_2, &matrix_3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_3.matrix[i][j], 0);
    }
  }

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_3);
}
END_TEST

START_TEST(test_sub_matrix_2) {
  int counter = 0;
  double answers[9] = {-60.36, 6, 3, 4, 1.62, 10.77, 48, -74, -1};
  matrix_t matrix_1 = {0}, matrix_2 = {0}, matrix_3 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  matrix_2.matrix[0][0] = 67;
  matrix_2.matrix[0][1] = 7;
  matrix_2.matrix[0][2] = 3;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 7.98;
  matrix_2.matrix[1][2] = -2.77;
  matrix_2.matrix[2][0] = 7;
  matrix_2.matrix[2][1] = 77;
  matrix_2.matrix[2][2] = 3;
  s21_sub_matrix(&matrix_1, &matrix_2, &matrix_3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_3.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_3);
}
END_TEST

START_TEST(test_mult_number_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  s21_mult_number(&matrix_1, -5.7, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_1.matrix[i][j] * -5.7, matrix_2.matrix[i][j]);
    }
  }

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_mult_matrix_1) {
  int counter = 0;
  double answers[9] = {525.88, 612.22, 1.91,   553.8, 741.608,
                       18.408, 3708,   562.94, 162.69};
  matrix_t matrix_1 = {0}, matrix_2 = {0}, matrix_3 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  matrix_2.matrix[0][0] = 67;
  matrix_2.matrix[0][1] = 7;
  matrix_2.matrix[0][2] = 3;
  matrix_2.matrix[1][0] = 3;
  matrix_2.matrix[1][1] = 7.98;
  matrix_2.matrix[1][2] = -2.77;
  matrix_2.matrix[2][0] = 7;
  matrix_2.matrix[2][1] = 77;
  matrix_2.matrix[2][2] = 3;
  s21_mult_matrix(&matrix_1, &matrix_2, &matrix_3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_3.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_3);
}
END_TEST

START_TEST(test_transpose_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  s21_transpose(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_1.matrix[i][j], matrix_2.matrix[j][i]);
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_transpose_2) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  s21_transpose(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_2.rows, 3);
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_transpose_3) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(4, 3, &matrix_1);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  s21_transpose(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_1.matrix[i][j], matrix_2.matrix[j][i]);
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_complement_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  double answers[9] = {3, 12, -2, -21, 13, 14, -1, -4, 33};
  int counter = 0;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 5;
  matrix_1.matrix[0][1] = 7;
  matrix_1.matrix[0][2] = 1;
  matrix_1.matrix[1][0] = -4;
  matrix_1.matrix[1][1] = 1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][0] = 2;
  matrix_1.matrix[2][1] = 0;
  matrix_1.matrix[2][2] = 3;
  s21_calc_complements(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_2.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_complement_2) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  double answers[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  int counter = 0;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 0;
  matrix_1.matrix[1][1] = 4;
  matrix_1.matrix[1][2] = 2;
  matrix_1.matrix[2][0] = 5;
  matrix_1.matrix[2][1] = 2;
  matrix_1.matrix[2][2] = 1;
  s21_calc_complements(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_2.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_complement_3) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  double answers[4] = {0, 1, -3, 2};
  int counter = 0;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 3;
  matrix_1.matrix[1][0] = -1;
  matrix_1.matrix[1][1] = 0;
  s21_calc_complements(&matrix_1, &matrix_2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_float_eq(matrix_2.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_complement_4) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  // 838 - 6992
  double answers[16] = {-6154, -12104, -7570, 2170, 5208, -722, 1856, 40,
                        -2271, -579,   -61,   232,  3795, 2779, 1103, -54};
  int counter = 0;
  s21_create_matrix(4, 4, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 0;
  matrix_1.matrix[0][2] = -3;
  matrix_1.matrix[0][3] = 9;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = -7;
  matrix_1.matrix[1][2] = 11;
  matrix_1.matrix[1][3] = 5;
  matrix_1.matrix[2][0] = -9;
  matrix_1.matrix[2][1] = 4;
  matrix_1.matrix[2][2] = 25;
  matrix_1.matrix[2][3] = 84;
  matrix_1.matrix[3][0] = 3;
  matrix_1.matrix[3][1] = 12;
  matrix_1.matrix[3][2] = -5;
  matrix_1.matrix[3][3] = 58;
  s21_calc_complements(&matrix_1, &matrix_2);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq(matrix_2.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_complement_5) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(2, 3, &matrix_1);
  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 3;
  matrix_1.matrix[1][0] = -1;
  matrix_1.matrix[1][1] = 0;
  s21_calc_complements(&matrix_1, &matrix_2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_float_eq(matrix_2.rows, 0);
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_determinant_1) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(4, 4, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[0][3] = 6;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 7;
  matrix_1.matrix[1][2] = 3;
  matrix_1.matrix[1][3] = 2;
  matrix_1.matrix[2][0] = 0;
  matrix_1.matrix[2][1] = 0;
  matrix_1.matrix[2][2] = 0;
  matrix_1.matrix[2][3] = 0;
  matrix_1.matrix[3][0] = 1;
  matrix_1.matrix[3][1] = 2;
  matrix_1.matrix[3][2] = 2;
  matrix_1.matrix[3][3] = 9;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, 0);
    }
  }
  s21_remove_matrix(&matrix_1);
}

START_TEST(test_determinant_2) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(4, 4, &matrix_1);
  matrix_1.matrix[0][0] = 4;
  matrix_1.matrix[0][1] = 3;
  matrix_1.matrix[0][2] = 2;
  matrix_1.matrix[0][3] = 2;
  matrix_1.matrix[1][0] = 0;
  matrix_1.matrix[1][1] = 1;
  matrix_1.matrix[1][2] = -3;
  matrix_1.matrix[1][3] = 3;
  matrix_1.matrix[2][0] = 0;
  matrix_1.matrix[2][1] = -1;
  matrix_1.matrix[2][2] = 3;
  matrix_1.matrix[2][3] = 3;
  matrix_1.matrix[3][0] = 0;
  matrix_1.matrix[3][1] = 3;
  matrix_1.matrix[3][2] = 1;
  matrix_1.matrix[3][3] = 1;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, -240);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_determinant_3) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 6.64;
  matrix_1.matrix[0][1] = 13;
  matrix_1.matrix[0][2] = 6;
  matrix_1.matrix[1][0] = 7;
  matrix_1.matrix[1][1] = 9.6;
  matrix_1.matrix[1][2] = 8;
  matrix_1.matrix[2][0] = 55;
  matrix_1.matrix[2][1] = 3;
  matrix_1.matrix[2][2] = 2;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, 2464.128);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_determinant_4) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.matrix[0][0] = 3;
  matrix_1.matrix[0][1] = 8;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 6;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, -14);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_determinant_5) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(2, 3, &matrix_1);
  matrix_1.matrix[0][0] = 3;
  matrix_1.matrix[0][1] = 8;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 6;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, -1);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_inverse_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  double answers[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  int counter = 0;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 5;
  matrix_1.matrix[0][2] = 7;
  matrix_1.matrix[1][0] = 6;
  matrix_1.matrix[1][1] = 3;
  matrix_1.matrix[1][2] = 4;
  matrix_1.matrix[2][0] = 5;
  matrix_1.matrix[2][1] = -2;
  matrix_1.matrix[2][2] = -3;
  s21_inverse_matrix(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_2.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_inverse_2) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  double answers[9] = {-0.9166666666666666666,
                       0.33333333333333333333,
                       0.083333333333333333333,
                       -0.1666666666666666667,
                       0.33333333333333333333,
                       -0.16666666666666666666,
                       0.75,
                       -0.33333333333333333333,
                       0.083333333333333333333};
  int counter = 0;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 2;
  matrix_1.matrix[2][2] = 9;
  s21_inverse_matrix(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_2.matrix[i][j], answers[counter]);
      counter += 1;
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_inverse_3) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(3, 4, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 2;
  matrix_1.matrix[2][2] = 9;
  s21_inverse_matrix(&matrix_1, &matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(matrix_2.rows, 0);
    }
  }
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_new_eq_matrix_1) {
  matrix_t matrix_1 = {0}, matrix_2 = {0};
  s21_create_matrix(2, 5, &matrix_1);
  s21_create_matrix(2, 5, &matrix_2);
  matrix_1.matrix[1][4] = 9.0000001;
  matrix_2.matrix[1][4] = 9;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_new_determinant_1) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.matrix[0][0] = 45.6;
  matrix_1.matrix[0][1] = 45.3;
  matrix_1.matrix[1][0] = 33;
  matrix_1.matrix[1][1] = 23;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_float_eq(result, -446.1);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_new_determinant_2) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 12;
  matrix_1.matrix[0][1] = 22;
  matrix_1.matrix[0][2] = 42;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 67;
  matrix_1.matrix[1][2] = 2;
  matrix_1.matrix[2][0] = 56;
  matrix_1.matrix[2][1] = 23;
  matrix_1.matrix[2][2] = 5;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, -148228);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_new_determinant_3) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(3, 3, &matrix_1);
  matrix_1.matrix[0][0] = 0;
  matrix_1.matrix[0][1] = 0;
  matrix_1.matrix[0][2] = 0;
  matrix_1.matrix[1][0] = 0;
  matrix_1.matrix[1][1] = 0;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][0] = 0;
  matrix_1.matrix[2][1] = 0;
  matrix_1.matrix[2][2] = 0;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq(result, 0);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_new_determinant_4) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(5, 5, &matrix_1);
  matrix_1.matrix[0][0] = 10;
  matrix_1.matrix[0][1] = 20;
  matrix_1.matrix[0][2] = 30;
  matrix_1.matrix[0][3] = 40;
  matrix_1.matrix[0][4] = 50;
  matrix_1.matrix[1][0] = -5;
  matrix_1.matrix[1][1] = -15;
  matrix_1.matrix[1][2] = -25;
  matrix_1.matrix[1][3] = -15;
  matrix_1.matrix[1][4] = -5;
  matrix_1.matrix[2][0] = 1.33;
  matrix_1.matrix[2][1] = 1.25;
  matrix_1.matrix[2][2] = 5.78;
  matrix_1.matrix[2][3] = 3.45;
  matrix_1.matrix[2][4] = 4.78;
  matrix_1.matrix[3][0] = 11;
  matrix_1.matrix[3][1] = 111;
  matrix_1.matrix[3][2] = 1111;
  matrix_1.matrix[3][3] = 5;
  matrix_1.matrix[3][4] = 6;
  matrix_1.matrix[4][0] = -1;
  matrix_1.matrix[4][1] = -0.5;
  matrix_1.matrix[4][2] = -7;
  matrix_1.matrix[4][3] = 7;
  matrix_1.matrix[4][4] = -8;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_float_eq_tol(result, 4410532.75, 1);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_new_determinant_5) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[1][0] = 3;
  matrix_1.matrix[1][1] = 4;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_float_eq(result, -2);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_new_determinant_6) {
  matrix_t matrix_1 = {0};
  double result = -1;
  s21_create_matrix(1, 1, &matrix_1);
  matrix_1.matrix[0][0] = 453425;
  s21_determinant(&matrix_1, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_float_eq(result, 453425);
    }
  }
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_errors_1) {
  double num = 0;
  matrix_t matrix_1 = {0}, matrix_2 = {0}, matrix_3 = {0};
  ck_assert_int_eq(s21_create_matrix(-1, -1, &matrix_1), 1);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, NULL), 0);
  matrix_2.matrix = NULL;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  ck_assert_int_eq(s21_sum_matrix(&matrix_1, NULL, &matrix_3), 1);
  ck_assert_int_eq(s21_sum_matrix(&matrix_1, &matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_sub_matrix(&matrix_1, NULL, &matrix_3), 1);
  ck_assert_int_eq(s21_sub_matrix(&matrix_1, &matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_mult_number(NULL, 5, &matrix_3), 1);
  ck_assert_int_eq(s21_mult_number(&matrix_2, 5, &matrix_3), 1);
  ck_assert_int_eq(s21_mult_matrix(NULL, &matrix_1, &matrix_3), 1);
  ck_assert_int_eq(s21_mult_matrix(&matrix_2, &matrix_1, &matrix_3), 1);
  ck_assert_int_eq(s21_transpose(NULL, &matrix_3), 1);
  ck_assert_int_eq(s21_transpose(&matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_calc_complements(NULL, &matrix_3), 1);
  ck_assert_int_eq(s21_calc_complements(&matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_determinant(NULL, &num), 1);
  ck_assert_int_eq(s21_determinant(&matrix_2, &num), 1);
  ck_assert_int_eq(s21_inverse_matrix(NULL, &matrix_3), 1);
  ck_assert_int_eq(s21_inverse_matrix(&matrix_2, &matrix_3), 1);
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &matrix_2);
  matrix_2.rows = -1;
  ck_assert_int_eq(s21_sum_matrix(&matrix_1, &matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_sub_matrix(&matrix_1, &matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_mult_number(&matrix_2, INFINITY, &matrix_3), 1);
  ck_assert_int_eq(s21_mult_matrix(&matrix_2, &matrix_1, &matrix_3), 1);
  ck_assert_int_eq(s21_transpose(&matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_calc_complements(&matrix_2, &matrix_3), 1);
  ck_assert_int_eq(s21_determinant(&matrix_2, &num), 1);
  ck_assert_int_eq(s21_inverse_matrix(&matrix_2, &matrix_3), 1);
  matrix_2.rows = 2;
  ck_assert_int_eq(s21_sum_matrix(&matrix_1, &matrix_2, &matrix_3), 2);
  ck_assert_int_eq(s21_sub_matrix(&matrix_1, &matrix_2, &matrix_3), 2);
  ck_assert_int_eq(s21_mult_matrix(&matrix_2, &matrix_1, &matrix_3), 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(s21_new_mult_matrix_1) {
  matrix_t a, b, result, comp_res;

  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  s21_create_matrix(2, 2, &comp_res);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 2;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 1;
  b.matrix[2][0] = 1;
  b.matrix[2][1] = 1;

  comp_res.matrix[0][0] = 2;
  comp_res.matrix[0][1] = 3;
  comp_res.matrix[1][0] = 2;
  comp_res.matrix[1][1] = 3;

  int err_detector = s21_mult_matrix(&a, &b, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_int_eq(eq_detector, 1);
}
END_TEST

START_TEST(s21_new_mult_matrix_2) {
  matrix_t a, b, result, comp_res;

  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  s21_create_matrix(3, 3, &comp_res);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 2;

  b.matrix[0][0] = 1;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 1;
  b.matrix[2][0] = 1;
  b.matrix[2][1] = 1;

  comp_res.matrix[0][0] = 1;
  comp_res.matrix[0][1] = 2;
  comp_res.matrix[0][2] = 1;
  comp_res.matrix[1][0] = 0;
  comp_res.matrix[1][1] = 1;
  comp_res.matrix[1][2] = 2;
  comp_res.matrix[2][0] = 1;
  comp_res.matrix[2][1] = 3;
  comp_res.matrix[2][2] = 3;

  int err_detector = s21_mult_matrix(&b, &a, &result);
  int eq_detector = s21_eq_matrix(&result, &comp_res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&comp_res);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_int_eq(eq_detector, 1);
}
END_TEST

START_TEST(s21_new_mult_matrix_3) {
  matrix_t a, b, result;

  s21_create_matrix(2, 4, &a);
  s21_create_matrix(3, 2, &b);

  int err_detector = s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, 2);
}
END_TEST

START_TEST(s21_new_mult_matrix_4) {
  matrix_t a, b, result;

  s21_create_matrix(2, 4, &a);
  s21_create_matrix(4, 3, &b);

  int err_detector = s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  ck_assert_int_eq(err_detector, 2);
}
END_TEST

START_TEST(s21_new_determinant_1) {
  matrix_t a;
  double result = 0.0, result_to_compare = -12.0;

  s21_create_matrix(3, 3, &a);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 3;
  a.matrix[0][2] = 4;

  a.matrix[1][0] = 0;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 1;

  a.matrix[2][0] = 1;
  a.matrix[2][1] = 5;
  a.matrix[2][2] = -1;

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_double_eq(result, result_to_compare);
}
END_TEST

START_TEST(s21_new_determinant_2) {
  matrix_t a;
  double result = 0.0, result_to_compare = -1926.0;

  s21_create_matrix(4, 4, &a);

  a.matrix[0][0] = -4;
  a.matrix[0][1] = -2;
  a.matrix[0][2] = -7;
  a.matrix[0][3] = 8;

  a.matrix[1][0] = 2;
  a.matrix[1][1] = 7;
  a.matrix[1][2] = 4;
  a.matrix[1][3] = 9;

  a.matrix[2][0] = 2;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 6;
  a.matrix[2][3] = -3;

  a.matrix[3][0] = 6;
  a.matrix[3][1] = 4;
  a.matrix[3][2] = -10;
  a.matrix[3][3] = -4;

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_double_eq(result, result_to_compare);
}
END_TEST

START_TEST(s21_new_determinant_3) {
  matrix_t a;
  double result = 0.0, result_to_compare = 64.0;

  s21_create_matrix(5, 5, &a);

  a.matrix[0][0] = 4;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 1;
  a.matrix[0][3] = 2;
  a.matrix[0][4] = 1;

  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = -1;
  a.matrix[1][3] = 1;
  a.matrix[1][4] = 1;

  a.matrix[2][0] = 3;
  a.matrix[2][1] = 1;
  a.matrix[2][2] = 1;
  a.matrix[2][3] = 1;
  a.matrix[2][4] = 1;

  a.matrix[3][0] = 2;
  a.matrix[3][1] = 1;
  a.matrix[3][2] = 1;
  a.matrix[3][3] = 4;
  a.matrix[3][4] = 1;

  a.matrix[4][0] = 2;
  a.matrix[4][1] = -1;
  a.matrix[4][2] = 1;
  a.matrix[4][3] = 1;
  a.matrix[4][4] = 5;

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_double_eq(result, result_to_compare);
}
END_TEST

START_TEST(s21_new_determinant_4) {
  matrix_t a;
  double result = 0.0;

  s21_create_matrix(3, 4, &a);

  int err_detector = s21_determinant(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, 2);
}
END_TEST

START_TEST(s21_inverse_1) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 3;
  a.matrix[0][1] = 4;

  a.matrix[1][0] = 5;
  a.matrix[1][1] = 7;

  s21_create_matrix(2, 2, &result_to_compare);
  result_to_compare.matrix[0][0] = 7;
  result_to_compare.matrix[0][1] = -4;

  result_to_compare.matrix[1][0] = -5;
  result_to_compare.matrix[1][1] = 3;

  int err_detector = s21_inverse_matrix(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_int_eq(eq_detector, 1);
}
END_TEST

START_TEST(s21_inverse_2) {
  matrix_t a, result, result_to_compare;

  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 0;
  a.matrix[0][3] = 0;

  a.matrix[1][0] = 3;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 0;
  a.matrix[1][3] = 0;

  a.matrix[2][0] = 1;
  a.matrix[2][1] = 1;
  a.matrix[2][2] = 3;
  a.matrix[2][3] = 4;

  a.matrix[3][0] = 2;
  a.matrix[3][1] = -1;
  a.matrix[3][2] = 2;
  a.matrix[3][3] = 3;

  s21_create_matrix(4, 4, &result_to_compare);
  result_to_compare.matrix[0][0] = 2;
  result_to_compare.matrix[0][1] = -1;
  result_to_compare.matrix[0][2] = 0;
  result_to_compare.matrix[0][3] = 0;

  result_to_compare.matrix[1][0] = -3;
  result_to_compare.matrix[1][1] = 2;
  result_to_compare.matrix[1][2] = 0;
  result_to_compare.matrix[1][3] = 0;

  result_to_compare.matrix[2][0] = 31;
  result_to_compare.matrix[2][1] = -19;
  result_to_compare.matrix[2][2] = 3;
  result_to_compare.matrix[2][3] = -4;

  result_to_compare.matrix[3][0] = -23;
  result_to_compare.matrix[3][1] = 14;
  result_to_compare.matrix[3][2] = -2;
  result_to_compare.matrix[3][3] = 3;

  int err_detector = s21_inverse_matrix(&a, &result);
  int eq_detector = s21_eq_matrix(&result, &result_to_compare);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_to_compare);

  ck_assert_int_eq(err_detector, 0);
  ck_assert_int_eq(eq_detector, 1);
}
END_TEST

START_TEST(s21_inverse_3) {
  matrix_t a, result;

  s21_create_matrix(3, 4, &a);

  int err_detector = s21_inverse_matrix(&a, &result);

  s21_remove_matrix(&a);

  ck_assert_int_eq(err_detector, 2);
}
END_TEST

Suite *decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_create_matrix_1);
  tcase_add_test(tc_core, test_remove_matrix_1);
  tcase_add_test(tc_core, test_eq_matrix_1);
  tcase_add_test(tc_core, test_eq_matrix_2);
  tcase_add_test(tc_core, test_eq_matrix_3);
  tcase_add_test(tc_core, test_eq_matrix_4);
  tcase_add_test(tc_core, test_sum_matrix_1);
  tcase_add_test(tc_core, test_sum_matrix_2);
  tcase_add_test(tc_core, test_sub_matrix_1);
  tcase_add_test(tc_core, test_sub_matrix_2);
  tcase_add_test(tc_core, test_mult_number_1);
  tcase_add_test(tc_core, test_mult_matrix_1);
  tcase_add_test(tc_core, test_transpose_1);
  tcase_add_test(tc_core, test_transpose_2);
  tcase_add_test(tc_core, test_transpose_3);
  tcase_add_test(tc_core, test_complement_1);
  tcase_add_test(tc_core, test_complement_2);
  tcase_add_test(tc_core, test_complement_3);
  tcase_add_test(tc_core, test_complement_4);
  tcase_add_test(tc_core, test_complement_5);
  tcase_add_test(tc_core, test_determinant_1);
  tcase_add_test(tc_core, test_determinant_2);
  tcase_add_test(tc_core, test_determinant_3);
  tcase_add_test(tc_core, test_determinant_4);
  tcase_add_test(tc_core, test_determinant_5);
  tcase_add_test(tc_core, test_inverse_1);
  tcase_add_test(tc_core, test_inverse_2);
  tcase_add_test(tc_core, test_inverse_3);
  tcase_add_test(tc_core, test_new_eq_matrix_1);
  tcase_add_test(tc_core, test_new_determinant_1);
  tcase_add_test(tc_core, test_new_determinant_2);
  tcase_add_test(tc_core, test_new_determinant_3);
  tcase_add_test(tc_core, test_new_determinant_4);
  tcase_add_test(tc_core, test_new_determinant_5);
  tcase_add_test(tc_core, test_new_determinant_6);
  tcase_add_test(tc_core, test_errors_1);
  tcase_add_test(tc_core, s21_new_mult_matrix_1);
  tcase_add_test(tc_core, s21_new_mult_matrix_2);
  tcase_add_test(tc_core, s21_new_mult_matrix_3);
  tcase_add_test(tc_core, s21_new_mult_matrix_4);
  tcase_add_test(tc_core, s21_new_determinant_1);
  tcase_add_test(tc_core, s21_new_determinant_2);
  tcase_add_test(tc_core, s21_new_determinant_3);
  tcase_add_test(tc_core, s21_new_determinant_4);
  tcase_add_test(tc_core, s21_inverse_1);
  tcase_add_test(tc_core, s21_inverse_2);
  tcase_add_test(tc_core, s21_inverse_3);
  suite_add_tcase(s, tc_core);
  return s;
}
