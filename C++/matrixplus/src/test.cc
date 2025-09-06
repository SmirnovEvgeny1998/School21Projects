#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

using namespace std;

TEST(Create_matrix, Subtest_1) {
  S21Matrix test_1;
  int rows = test_1.GetRows();
  int cols = test_1.GetCols();
  double unit = test_1.GetMatrix(0, 0);
  ASSERT_EQ(rows, 1);
  ASSERT_EQ(cols, 1);
  ASSERT_EQ(unit, 0);
  test_1.~S21Matrix();
}
TEST(Create_matrix, Subtest_2) {
  S21Matrix test_2(4, 3);
  int rows = test_2.GetRows();
  int cols = test_2.GetCols();
  double unit = test_2.GetMatrix(0, 0);
  ASSERT_EQ(rows, 4);
  ASSERT_EQ(cols, 3);
  ASSERT_EQ(unit, 0);
  test_2.~S21Matrix();
}
TEST(Create_matrix, Subtest_3) {
  S21Matrix test_2(4, 3);
  test_2.SetRows(5);
  test_2.SetCols(5);
  test_2.SetMatrix(0, 0, 5);
  S21Matrix test_3(test_2);
  int rows = test_3.GetRows();
  int cols = test_3.GetCols();
  double unit = test_3.GetMatrix(0, 0);
  ASSERT_EQ(rows, 5);
  ASSERT_EQ(cols, 5);
  ASSERT_EQ(unit, 5);
  test_2.~S21Matrix();
  test_3.~S21Matrix();
}
TEST(Create_matrix, Subtest_4) {
  S21Matrix test_2(4, 3);
  test_2.SetRows(5);
  test_2.SetCols(5);
  test_2.SetMatrix(0, 0, 5);
  S21Matrix test_4 = test_2;
  int rows = test_4.GetRows();
  int cols = test_4.GetCols();
  double unit = test_4.GetMatrix(0, 0);
  ASSERT_EQ(rows, 5);
  ASSERT_EQ(cols, 5);
  ASSERT_EQ(unit, 5);
  test_2.~S21Matrix();
  test_4.~S21Matrix();
}

TEST(Remove_matrix, Subtest_1) {
  S21Matrix test(4, 3);
  test.~S21Matrix();
  ASSERT_EQ(test.GetAddress(), nullptr);
}

TEST(Eq_matrix, Subtest_1) {
  S21Matrix matrix_1(2, 5);
  S21Matrix matrix_2(2, 5);
  matrix_1.SetMatrix(1, 4, 9);
  matrix_2.SetMatrix(1, 4, 9);
  ASSERT_EQ(matrix_1.EqMatrix(matrix_2), true);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Eq_matrix, Subtest_2) {
  S21Matrix matrix_1(2, 5);
  S21Matrix matrix_2(2, 5);
  matrix_1.SetMatrix(1, 4, 9);
  matrix_2.SetMatrix(1, 4, 7);
  ASSERT_EQ(matrix_1.EqMatrix(matrix_2), false);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Eq_matrix, Subtest_3) {
  S21Matrix matrix_1(2, 5);
  S21Matrix matrix_2(2, 5);
  ASSERT_EQ(matrix_1.EqMatrix(matrix_2), true);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Eq_matrix, Subtest_4) {
  S21Matrix matrix_1(2, 6);
  S21Matrix matrix_2(2, 5);
  matrix_1.SetMatrix(1, 4, 9);
  matrix_2.SetMatrix(1, 4, 9);
  ASSERT_EQ(matrix_1.EqMatrix(matrix_2), false);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Sum_matrix, Subtest_1) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.SetMatrix(i, j, i + j);
      matrix_2.SetMatrix(i, j, i + j);
    }
  }
  matrix_1.SumMatrix(matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(matrix_1.GetMatrix(i, j), (i + j) * 2);
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Sum_matrix, Subtest_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  int counter = 0;
  double answers[9] = {73.64, 20, 9, 10, 17.58, 5.23, 62, 80, 5};
  matrix_1.SetMatrix(0, 0, 6.64);
  matrix_1.SetMatrix(0, 1, 13);
  matrix_1.SetMatrix(0, 2, 6);
  matrix_1.SetMatrix(1, 0, 7);
  matrix_1.SetMatrix(1, 1, 9.6);
  matrix_1.SetMatrix(1, 2, 8);
  matrix_1.SetMatrix(2, 0, 55);
  matrix_1.SetMatrix(2, 1, 3);
  matrix_1.SetMatrix(2, 2, 2);
  matrix_2.SetMatrix(0, 0, 67);
  matrix_2.SetMatrix(0, 1, 7);
  matrix_2.SetMatrix(0, 2, 3);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 7.98);
  matrix_2.SetMatrix(1, 2, -2.77);
  matrix_2.SetMatrix(2, 0, 7);
  matrix_2.SetMatrix(2, 1, 77);
  matrix_2.SetMatrix(2, 2, 3);
  matrix_1.SumMatrix(matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Sub_matrix, Subtest_1) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.SetMatrix(i, j, i + j);
      matrix_2.SetMatrix(i, j, i + j);
    }
  }
  matrix_1.SubMatrix(matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(matrix_1.GetMatrix(i, j), 0);
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Sub_matrix, Subtest_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  int counter = 0;
  double answers[9] = {-60.36, 6, 3, 4, 1.62, 10.77, 48, -74, -1};
  matrix_1.SetMatrix(0, 0, 6.64);
  matrix_1.SetMatrix(0, 1, 13);
  matrix_1.SetMatrix(0, 2, 6);
  matrix_1.SetMatrix(1, 0, 7);
  matrix_1.SetMatrix(1, 1, 9.6);
  matrix_1.SetMatrix(1, 2, 8);
  matrix_1.SetMatrix(2, 0, 55);
  matrix_1.SetMatrix(2, 1, 3);
  matrix_1.SetMatrix(2, 2, 2);
  matrix_2.SetMatrix(0, 0, 67);
  matrix_2.SetMatrix(0, 1, 7);
  matrix_2.SetMatrix(0, 2, 3);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 7.98);
  matrix_2.SetMatrix(1, 2, -2.77);
  matrix_2.SetMatrix(2, 0, 7);
  matrix_2.SetMatrix(2, 1, 77);
  matrix_2.SetMatrix(2, 2, 3);
  matrix_1.SubMatrix(matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Mul_number, Subtest_1) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 6.64);
  matrix_1.SetMatrix(0, 1, 13);
  matrix_1.SetMatrix(0, 2, 6);
  matrix_1.SetMatrix(1, 0, 7);
  matrix_1.SetMatrix(1, 1, 9.6);
  matrix_1.SetMatrix(1, 2, 8);
  matrix_1.SetMatrix(2, 0, 55);
  matrix_1.SetMatrix(2, 1, 3);
  matrix_1.SetMatrix(2, 2, 2);
  matrix_2.SetMatrix(0, 0, 6.64);
  matrix_2.SetMatrix(0, 1, 13);
  matrix_2.SetMatrix(0, 2, 6);
  matrix_2.SetMatrix(1, 0, 7);
  matrix_2.SetMatrix(1, 1, 9.6);
  matrix_2.SetMatrix(1, 2, 8);
  matrix_2.SetMatrix(2, 0, 55);
  matrix_2.SetMatrix(2, 1, 3);
  matrix_2.SetMatrix(2, 2, 2);
  matrix_1.MulNumber(-5.7);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j),
                       matrix_2.GetMatrix(i, j) * -5.7);
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Mul_matrix, Subtest_1) {
  int counter = 0;
  double answers[9] = {525.88, 612.22, 1.91,   553.8, 741.608,
                       18.408, 3708,   562.94, 162.69};
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 6.64);
  matrix_1.SetMatrix(0, 1, 13);
  matrix_1.SetMatrix(0, 2, 6);
  matrix_1.SetMatrix(1, 0, 7);
  matrix_1.SetMatrix(1, 1, 9.6);
  matrix_1.SetMatrix(1, 2, 8);
  matrix_1.SetMatrix(2, 0, 55);
  matrix_1.SetMatrix(2, 1, 3);
  matrix_1.SetMatrix(2, 2, 2);
  matrix_2.SetMatrix(0, 0, 67);
  matrix_2.SetMatrix(0, 1, 7);
  matrix_2.SetMatrix(0, 2, 3);
  matrix_2.SetMatrix(1, 0, 3);
  matrix_2.SetMatrix(1, 1, 7.98);
  matrix_2.SetMatrix(1, 2, -2.77);
  matrix_2.SetMatrix(2, 0, 7);
  matrix_2.SetMatrix(2, 1, 77);
  matrix_2.SetMatrix(2, 2, 3);
  matrix_1.MulMatrix(matrix_2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Transpose, Subtest_1) {
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 6.64);
  matrix_1.SetMatrix(0, 1, 13);
  matrix_1.SetMatrix(0, 2, 6);
  matrix_1.SetMatrix(1, 0, 7);
  matrix_1.SetMatrix(1, 1, 9.6);
  matrix_1.SetMatrix(1, 2, 8);
  matrix_1.SetMatrix(2, 0, 55);
  matrix_1.SetMatrix(2, 1, 3);
  matrix_1.SetMatrix(2, 2, 2);
  S21Matrix matrix_2 = matrix_1.Transpose();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), matrix_2.GetMatrix(j, i));
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Complement, Subtest_1) {
  double answers[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  int counter = 0;
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 1);
  matrix_1.SetMatrix(0, 1, 2);
  matrix_1.SetMatrix(0, 2, 3);
  matrix_1.SetMatrix(1, 0, 0);
  matrix_1.SetMatrix(1, 1, 4);
  matrix_1.SetMatrix(1, 2, 2);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, 2);
  matrix_1.SetMatrix(2, 2, 1);
  S21Matrix matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_2.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Complement, Subtest_2) {
  double answers[9] = {3, 12, -2, -21, 13, 14, -1, -4, 33};
  int counter = 0;
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 5);
  matrix_1.SetMatrix(0, 1, 7);
  matrix_1.SetMatrix(0, 2, 1);
  matrix_1.SetMatrix(1, 0, -4);
  matrix_1.SetMatrix(1, 1, 1);
  matrix_1.SetMatrix(1, 2, 0);
  matrix_1.SetMatrix(2, 0, 2);
  matrix_1.SetMatrix(2, 1, 0);
  matrix_1.SetMatrix(2, 2, 3);
  S21Matrix matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_2.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Complement, Subtest_3) {
  double answers[4] = {0, 1, -3, 2};
  int counter = 0;
  S21Matrix matrix_1(2, 2);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 3);
  matrix_1.SetMatrix(1, 0, -1);
  matrix_1.SetMatrix(1, 1, 0);
  S21Matrix matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrix_2.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Complement, Subtest_4) {
  double answers[16] = {-6154, -12104, -7570, 2170, 5208, -722, 1856, 40,
                        -2271, -579,   -61,   232,  3795, 2779, 1103, -54};
  int counter = 0;
  S21Matrix matrix_1(4, 4);
  matrix_1.SetMatrix(0, 0, 1);
  matrix_1.SetMatrix(0, 1, 0);
  matrix_1.SetMatrix(0, 2, -3);
  matrix_1.SetMatrix(0, 3, 9);
  matrix_1.SetMatrix(1, 0, 2);
  matrix_1.SetMatrix(1, 1, -7);
  matrix_1.SetMatrix(1, 2, 11);
  matrix_1.SetMatrix(1, 3, 5);
  matrix_1.SetMatrix(2, 0, -9);
  matrix_1.SetMatrix(2, 1, 4);
  matrix_1.SetMatrix(2, 2, 25);
  matrix_1.SetMatrix(2, 3, 84);
  matrix_1.SetMatrix(3, 0, 3);
  matrix_1.SetMatrix(3, 1, 12);
  matrix_1.SetMatrix(3, 2, -5);
  matrix_1.SetMatrix(3, 3, 58);
  S21Matrix matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(matrix_2.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Determinant, Subtest_1) {
  S21Matrix matrix_1(4, 4);
  matrix_1.SetMatrix(0, 0, 4);
  matrix_1.SetMatrix(0, 1, 3);
  matrix_1.SetMatrix(0, 2, 2);
  matrix_1.SetMatrix(0, 3, 2);
  matrix_1.SetMatrix(1, 0, 0);
  matrix_1.SetMatrix(1, 1, 1);
  matrix_1.SetMatrix(1, 2, -3);
  matrix_1.SetMatrix(1, 3, 3);
  matrix_1.SetMatrix(2, 0, 0);
  matrix_1.SetMatrix(2, 1, -1);
  matrix_1.SetMatrix(2, 2, 3);
  matrix_1.SetMatrix(2, 3, 3);
  matrix_1.SetMatrix(3, 0, 0);
  matrix_1.SetMatrix(3, 1, 3);
  matrix_1.SetMatrix(3, 2, 1);
  matrix_1.SetMatrix(3, 3, 1);
  ASSERT_DOUBLE_EQ(matrix_1.Determinant(), -240);
  matrix_1.~S21Matrix();
}

TEST(Determinant, Subtest_2) {
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 6.64);
  matrix_1.SetMatrix(0, 1, 13);
  matrix_1.SetMatrix(0, 2, 6);
  matrix_1.SetMatrix(1, 0, 7);
  matrix_1.SetMatrix(1, 1, 9.6);
  matrix_1.SetMatrix(1, 2, 8);
  matrix_1.SetMatrix(2, 0, 55);
  matrix_1.SetMatrix(2, 1, 3);
  matrix_1.SetMatrix(2, 2, 2);
  ASSERT_DOUBLE_EQ(matrix_1.Determinant(), 2464.128);
  matrix_1.~S21Matrix();
}

TEST(Determinant, Subtest_3) {
  S21Matrix matrix_1(2, 2);
  matrix_1.SetMatrix(0, 0, 3);
  matrix_1.SetMatrix(0, 1, 8);
  matrix_1.SetMatrix(1, 0, 4);
  matrix_1.SetMatrix(1, 1, 6);
  ASSERT_DOUBLE_EQ(matrix_1.Determinant(), -14);
  matrix_1.~S21Matrix();
}

TEST(Inverse, Subtest_1) {
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
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 1);
  matrix_1.SetMatrix(0, 1, 2);
  matrix_1.SetMatrix(0, 2, 3);
  matrix_1.SetMatrix(1, 0, 4);
  matrix_1.SetMatrix(1, 1, 5);
  matrix_1.SetMatrix(1, 2, 6);
  matrix_1.SetMatrix(2, 0, 7);
  matrix_1.SetMatrix(2, 1, 2);
  matrix_1.SetMatrix(2, 2, 9);
  S21Matrix matrix_2 = matrix_1.InverseMatrix();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_2.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Inverse, Subtest_2) {
  double answers[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  int counter = 0;
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  S21Matrix matrix_2 = matrix_1.InverseMatrix();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_2.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_1) {
  int counter = 0;
  double answers[9] = {4, 10, 14, 12, 6, 8, 10, -4, -6};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  S21Matrix matrix_3 = matrix_1 + matrix_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_3.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
  matrix_3.~S21Matrix();
}

TEST(Signs, Subtest_2) {
  int counter = 0;
  double answers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  S21Matrix matrix_3 = matrix_1 - matrix_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_3.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
  matrix_3.~S21Matrix();
}

TEST(Signs, Subtest_3) {
  int counter = 0;
  double answers[9] = {69, 11, 13, 50, 31, 42, -17, 25, 36};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  S21Matrix matrix_3 = matrix_1 * matrix_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_3.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
  matrix_3.~S21Matrix();
}

TEST(Signs, Subtest_4) {
  int counter = 0;
  double answers[9] = {4, 10, 14, 12, 6, 8, 10, -4, -6};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  S21Matrix matrix_3 = matrix_1 * 2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_3.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
  matrix_3.~S21Matrix();
}

TEST(Signs, Subtest_5) {
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  bool result = matrix_1 == matrix_2;
  ASSERT_EQ(result, true);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_6) {
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 23);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  bool result = matrix_1 == matrix_2;
  ASSERT_EQ(result, false);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_7) {
  S21Matrix matrix_1(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  S21Matrix matrix_2 = matrix_1;
  bool result = matrix_1 == matrix_2;
  ASSERT_EQ(result, true);
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_8) {
  int counter = 0;
  double answers[9] = {4, 10, 14, 12, 6, 8, 10, -4, -6};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  matrix_1 += matrix_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_9) {
  int counter = 0;
  double answers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  matrix_1 -= matrix_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_10) {
  int counter = 0;
  double answers[9] = {69, 11, 13, 50, 31, 42, -17, 25, 36};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_2.SetMatrix(0, 0, 2);
  matrix_2.SetMatrix(0, 1, 5);
  matrix_2.SetMatrix(0, 2, 7);
  matrix_2.SetMatrix(1, 0, 6);
  matrix_2.SetMatrix(1, 1, 3);
  matrix_2.SetMatrix(1, 2, 4);
  matrix_2.SetMatrix(2, 0, 5);
  matrix_2.SetMatrix(2, 1, -2);
  matrix_2.SetMatrix(2, 2, -3);
  matrix_1 *= matrix_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
  matrix_2.~S21Matrix();
}

TEST(Signs, Subtest_11) {
  int counter = 0;
  double answers[9] = {4, 10, 14, 12, 6, 8, 10, -4, -6};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_1 *= 2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1.GetMatrix(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
}

TEST(Signs, Subtest_12) {
  int counter = 0;
  double answers[9] = {4, 10, 14, 12, 6, 8, 10, -4, -6};
  S21Matrix matrix_1(3, 3), matrix_2(3, 3);
  matrix_1.SetMatrix(0, 0, 2);
  matrix_1.SetMatrix(0, 1, 5);
  matrix_1.SetMatrix(0, 2, 7);
  matrix_1.SetMatrix(1, 0, 6);
  matrix_1.SetMatrix(1, 1, 3);
  matrix_1.SetMatrix(1, 2, 4);
  matrix_1.SetMatrix(2, 0, 5);
  matrix_1.SetMatrix(2, 1, -2);
  matrix_1.SetMatrix(2, 2, -3);
  matrix_1 *= 2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), answers[counter]);
      counter += 1;
    }
  }
  matrix_1.~S21Matrix();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
