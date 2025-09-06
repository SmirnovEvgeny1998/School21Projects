#include <gtest/gtest.h>

#include "credit_model.h"
// credit tests
TEST(Annuitent_payment, Subtest_1) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_montly_payment(20000, 36, 12), 664, 1);
}

TEST(Annuitent_payment, Subtest_2) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_montly_payment(100000, 12, 13), 8931, 1);
}

TEST(Annuitent_payment, Subtest_3) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_montly_payment(5000000, 60, 23.5), 142392,
              1);
}

TEST(Annuitent_overpayment, Subtest_1) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_overpayment(20000, 36, 12), 3914, 1);
}

TEST(Annuitent_overpayment, Subtest_2) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_overpayment(100000, 12, 13), 7180, 1);
}

TEST(Annuitent_overpayment, Subtest_3) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_overpayment(5000000, 60, 23.5), 3543544,
              1);
}

TEST(Annuitent_allpayment, Subtest_1) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_all_payment(20000, 36, 12), 23914, 1);
}

TEST(Annuitent_allpayment, Subtest_2) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_all_payment(100000, 12, 13), 107180, 1);
}

TEST(Annuitent_allpayment, Subtest_3) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_all_payment(5000000, 60, 23.5), 8543544,
              1);
}

TEST(Annuitent_allpayment, Subtest_4) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_annuitent_all_payment(5000000, 64, 23.5), 8814270,
              1);
}

TEST(Differential_payment, Subtest_1) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_montly_payment_first(20000, 36, 12),
              755, 1);
  ASSERT_NEAR(temp.s21_bank_differential_montly_payment_last(20000, 36, 12),
              561, 1);
}

TEST(Differential_payment, Subtest_2) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_montly_payment_first(100000, 12, 13),
              9416, 1);
  ASSERT_NEAR(temp.s21_bank_differential_montly_payment_last(100000, 12, 13),
              8423, 1);
}

TEST(Differential_payment, Subtest_3) {
  s21::credit_controller temp;
  ASSERT_NEAR(
      temp.s21_bank_differential_montly_payment_first(5000000, 60, 23.5),
      181250, 1);
  ASSERT_NEAR(temp.s21_bank_differential_montly_payment_last(5000000, 60, 23.5),
              84965, 1);
}

TEST(Differential_overpayment, Subtest_1) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_overpayment(20000, 36, 12), 3700, 1);
}

TEST(Differential_overpayment, Subtest_2) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_overpayment(100000, 12, 13), 7041, 1);
}

TEST(Differential_overpayment, Subtest_3) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_overpayment(5000000, 60, 23.5),
              2986458, 1);
}

TEST(Differential_allpayment, Subtest_1) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_all_payment(20000, 36, 12), 23700, 1);
}

TEST(Differential_allpayment, Subtest_2) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_all_payment(100000, 12, 13), 107041,
              1);
}

TEST(Differential_allpayment, Subtest_3) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_all_payment(5000000, 60, 23.5),
              7986458, 1);
}

TEST(Differential_allpayment, Subtest_4) {
  s21::credit_controller temp;
  ASSERT_NEAR(temp.s21_bank_differential_all_payment(5000000, 64, 23.5),
              8182291, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
