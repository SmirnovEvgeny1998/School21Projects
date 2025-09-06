#include <gtest/gtest.h>

#include "deposit_model.h"

TEST(Profitability, Subtest_1) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1] = {0};
  s21::deposit_controller::s21_widrawls wid[1] = {0};
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 2;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 0;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 3000000, 12, 5, 13, 0,
                                                     1, rep, wid, 7.5),
              153485, 1);
}

TEST(Profitability, Subtest_2) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1] = {0};
  s21::deposit_controller::s21_widrawls wid[1] = {0};
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 2;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 0;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 3000000, 12, 5, 13, 0,
                                                     1, rep, wid, 7.5),
              200202, 1);
}

TEST(Profitability, Subtest_3) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 2;
  rep[0].last = 1;
  wid[0].summ = 2000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 3000000, 12, 5, 13, 0,
                                                     1, rep, wid, 7.5),
              157931, 1);
}

TEST(Profitability, Subtest_4) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 2300000, 25, 3.7, 13, 1,
                                                     1, rep, wid, 7.5),
              200971, 1);
}

TEST(Profitability, Subtest_5) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1234567, 48, 3.7, 13, 1,
                                                     1, rep, wid, 7.5),
              226294, 1);
}

TEST(Profitability, Subtest_6) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1234567, 34, 3.7, 13, 2,
                                                     1, rep, wid, 7.5),
              157392, 1);
}

TEST(Profitability, Subtest_7) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1234567, 34, 3.7, 13, 3,
                                                     1, rep, wid, 7.5),
              156064, 1);
}

TEST(Profitability, Subtest_8) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1234567, 34, 3.7, 13, 4,
                                                     1, rep, wid, 7.5),
              150648, 1);
}

TEST(Profitability, Subtest_9) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 0, 34, 3.7, 13, 4, 1,
                                                     rep, wid, 7.5),
              0, 1);
}

TEST(Profitability, Subtest_10) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1000000, 47, 3.7, 13, 2,
                                                     1, rep, wid, 8.5),
              154374, 1);
}

TEST(Profitability, Subtest_11) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1000000, 47, 3.7, 13, 1,
                                                     1, rep, wid, 8.5),
              155117, 1);
}

TEST(Profitability, Subtest_12) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 0;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 666666666660;
  wid[0].year = 0;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 1234567, 47, 3.7, 13, 1,
                                                     1, rep, wid, 8.5),
              -1, 1);
}

TEST(Tax, Subtest_1) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 4234567, 34, 3.7, 13, 2,
                                                     1, rep, wid, 7.5),
              33910, 1);
}

TEST(Tax, Subtest_2) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 4234567, 34, 3.7, 13, 3,
                                                     1, rep, wid, 7.5),
              43106, 1);
}

TEST(Tax, Subtest_3) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 4234567, 34, 3.7, 13, 4,
                                                     1, rep, wid, 7.5),
              50712, 1);
}

TEST(Tax, Subtest_4) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 4234567, 34, 3.7, 13, 1,
                                                     1, rep, wid, 7.5),
              34197, 1);
}

TEST(Tax, Subtest_5) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 4234567, 34, 3.7, 13, 0,
                                                     1, rep, wid, 7.5),
              34397, 1);
}

TEST(Tax, Subtest_6) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 500000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 340000;
  wid[0].year = 1;
  wid[0].month = 2;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 4234567, 24, 3.7, 13, 3,
                                                     1, rep, wid, 7.5),
              24155, 1);
}

TEST(Final_amount, Subtest_1) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 15000000, 11, 7.8, 13,
                                                     0, 1, rep, wid, 7.5),
              1744265, 1);
}

TEST(Final_amount, Subtest_2) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 15000000, 11, 7.8, 13,
                                                     1, 1, rep, wid, 7.5),
              1738722, 1);
}

TEST(Final_amount, Subtest_3) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 15000000, 11, 7.8, 13,
                                                     2, 1, rep, wid, 7.5),
              1731227, 1);
}

TEST(Final_amount, Subtest_4) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 15000000, 11, 7.8, 13,
                                                     3, 1, rep, wid, 7.5),
              1712257, 1);
}

TEST(Final_amount, Subtest_5) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 15000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 15000000, 22, 7.8, 13,
                                                     4, 1, rep, wid, 7.5),
              1783846, 1);
}

TEST(Final_amount, Subtest_6) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 7000000, 17, 11, 13, 0,
                                                     0, rep, wid, 7.5),
              3000000, 1);
}

TEST(Final_amount, Subtest_7) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 7000000, 17, 11, 13, 1,
                                                     0, rep, wid, 7.5),
              3000000, 1);
}

TEST(Final_amount, Subtest_8) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 7000000, 17, 11, 13, 2,
                                                     0, rep, wid, 7.5),
              3000000, 1);
}

TEST(Final_amount, Subtest_9) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 7000000, 17, 11, 13, 3,
                                                     0, rep, wid, 7.5),
              3000000, 1);
}

TEST(Final_amount, Subtest_10) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 7000000, 17, 11, 13, 4,
                                                     0, rep, wid, 7.5),
              3000000, 1);
}

TEST(Visocosny_god, Subtest_1) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 7000000, 53, 11, 13, 0,
                                                     1, rep, wid, 7.5),
              2278082, 1);
}

TEST(Visocosny_god, Subtest_2) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 1000000;
  rep[0].year = 0;
  rep[0].month = 7;
  rep[0].last = 1;
  wid[0].summ = 5000000;
  wid[0].year = 0;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 7000000, 48, 11, 13, 0,
                                                     1, rep, wid, 7.5),
              2044316, 1);
}

TEST(All, Subtest_1) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[1];
  s21::deposit_controller::s21_widrawls wid[1];
  rep[0].summ = 454545;
  rep[0].year = 0;
  rep[0].month = 4;
  rep[0].last = 1;
  wid[0].summ = 0;
  wid[0].year = 2;
  wid[0].month = 8;
  wid[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 6666666, 6, 6, 13, 0, 0,
                                                     rep, wid, 8.5),
              205155, 1);
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 6666666, 6, 6, 13, 0, 0,
                                                     rep, wid, 8.5),
              15620, 1);
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 6666666, 6, 6, 13, 0, 0,
                                                     rep, wid, 8.5),
              7121211, 1);
}

TEST(All, Subtest_2) {
  s21::deposit_controller temp;
  s21::deposit_controller::s21_repelishments rep[2];
  s21::deposit_controller::s21_widrawls wid[2];
  wid[0].summ = 666666;
  wid[0].year = 0;
  wid[0].month = 9;
  wid[0].last = 0;
  wid[0].summ = 1111111;
  wid[0].year = 2;
  wid[0].month = 4;
  wid[0].last = 1;
  rep[0].summ = 1000000;
  rep[0].year = 1;
  rep[0].month = 7;
  rep[0].last = 0;
  rep[0].summ = 500000;
  rep[0].year = 2;
  rep[0].month = 4;
  rep[0].last = 1;
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(0, 9876543210, 48, 7.6, 13,
                                                     1, 0, rep, wid, 8.5),
              3002409076, 1000000);
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(1, 9876543210, 48, 7.6, 13,
                                                     1, 0, rep, wid, 8.5),
              390257929, 1000000);
  ASSERT_NEAR(temp.s21_deposit_profitability_complex(2, 9876543210, 48, 7.6, 13,
                                                     1, 0, rep, wid, 8.5),
              9876265433, 1000000);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
