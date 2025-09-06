#include <gtest/gtest.h>

#include "calc_model.h"

TEST(Sum, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "123.45+34.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 158.42);
}

TEST(Sum, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "123.45+-34.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 88.48);
}

TEST(Sum, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-123.45+-34.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -123.45 + -34.97);
}

TEST(Sum, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "+123.45+-34.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 123.45 + -34.97);
}

TEST(Minus, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "43534.6-354.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 43179.63);
}

TEST(Minus, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-43534.6-354.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -43889.57);
}

TEST(Minus, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-43534.6--354.97", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -43179.63);
}

TEST(Minus, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-435-+365", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -800);
}

TEST(Mult, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "34.9*64.78", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 2260.822);
}

TEST(Mult, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "34.9*-64.78", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -2260.822);
}

TEST(Mult, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-34.9*-64.78", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 2260.822);
}

TEST(Mult, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-34.9*0", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 0);
}

TEST(Mult, Subtest_5) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-34.9*+11", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -34.9 * 11);
}

TEST(Div, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "3543.78/345.87", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 3543.78 / 345.87);
}

TEST(Div, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "3543.78/-345.87", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 3543.78 / -345.87);
}

TEST(Div, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-3543.78/-345.87", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), -3543.78 / -345.87);
}

TEST(Div, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "100/5", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 20);
}

TEST(Div, Subtest_5) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "3543.78/0", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), INFINITY);
}

TEST(Pow, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "234.4^3", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 12878723.584);
}

TEST(Pow, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "234.4^-1", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), pow(234.4, -1));
}

TEST(Pow, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "2^8", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 256);
}

TEST(Mod, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "3245mod34.88", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), fmod(3245, 34.88));
}

TEST(Mod, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "3245mod-34.88", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), fmod(3245, -34.88));
}

TEST(Mod, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-3245mod-34.88", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), fmod(-3245, -34.88));
}

TEST(Mod, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "10mod2", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 10 % 2);
}

TEST(Mod, Subtest_5) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "100mod35mod2", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 100 % 35 % 2);
}

TEST(Sin, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sin(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sin(1));
}

TEST(Sin, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sin(-0.7)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sin(-0.7));
}

TEST(Sin, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sin(355.98)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sin(355.98));
}

TEST(Cos, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "cos(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), cos(1));
}

TEST(Cos, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "cos(-0.7)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), cos(-0.7));
}

TEST(Cos, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "cos(355.98)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), cos(355.98));
}

TEST(Cos, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "cos(30)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), cos(30));
}

TEST(Tan, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "tan(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), tan(1));
}

TEST(Tan, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "tan(-0.7)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), tan(-0.7));
}

TEST(Tan, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "tan(355.98)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), tan(355.98));
}

TEST(Asin, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "asin(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), asin(1));
}

TEST(Asin, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "asin(-0.7)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), asin(-0.7));
}

TEST(Asin, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "asin(355.98)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(isnan(temp.calculation(djicstra, length)),
                   isnan(asin(355.98)));
}

TEST(Acos, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "acos(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), acos(1));
}

TEST(Acos, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "acos(-0.7)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), acos(-0.7));
}

TEST(Acos, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "acos(355.98)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(isnan(temp.calculation(djicstra, length)),
                   isnan(acos(355.98)));
}

TEST(Atan, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "atan(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), atan(1));
}

TEST(Atan, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "atan(-0.7)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), atan(-0.7));
}

TEST(Atan, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "atan(355.98)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), atan(355.98));
}

TEST(Sqrt, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sqrt(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sqrt(1));
}

TEST(Sqrt, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sqrt(151.29)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sqrt(151.29));
}

TEST(Sqrt, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sqrt(551.29)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sqrt(551.29));
}

TEST(Nat_log, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "ln(3)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), log(3));
}

TEST(Nat_log, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "ln(45.3)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), log(45.3));
}

TEST(Nat_log, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "ln(0)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), log(0));
}

TEST(Common_log, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "log(3)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), log10(3));
}

TEST(Common_log, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "log(45.3)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), log10(45.3));
}

TEST(Common_log, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "log(0)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), log10(0));
}

TEST(Complexity_two, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "cos(sin(1))", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), cos(sin(1)));
}

TEST(Complexity_two, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "34.6-5*5", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 34.6 - 5 * 5);
}

TEST(Complexity_n, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "(4*(12.3-7.8+(-2.5+23423.6))/2^4)mod2", *broken,
              *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length),
                   fmod(4 * (12.3 - 7.8 + (-2.5 + 23423.6)) / pow(2, 4), 2));
}

TEST(Complexity_n, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sin(cos(tan(ln(log(sqrt(4))))))", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length),
                   sin(cos(tan(log(log10(sqrt(4)))))));
}

TEST(Complexity_n, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "asin(acos(atan(ln(log(sqrt(4))))))", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(isnan(temp.calculation(djicstra, length)),
                   isnan(asin(acos(atan(log(log10(sqrt(4))))))));
}

TEST(Complexity_n, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "asin(acos(atan(ln(log(sqrt(4)))))-1.638886)", *broken,
              *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length),
                   asin(acos(atan(log(log10(sqrt(4))))) - 1.638886));
}

TEST(Complexity_n, Subtest_5) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "(3.33-1)^(5-3)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), pow(3.33 - 1, 5 - 3));
}

TEST(Complexity_n, Subtest_6) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "acos(atan(ln(log(sqrt(4)))))", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length),
                   acos(atan(log(log10(sqrt(4))))));
}

TEST(Complexity_n, Subtest_7) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "1.56*0.094*89.56", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 1.56 * 0.094 * 89.56);
}

TEST(Complexity_n, Subtest_8) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "234234mod10mod2", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 234234 % 10 % 2);
}

TEST(Complexity_n, Subtest_9) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "+345++34", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), +345 + 34);
}

TEST(Complexity_n, Subtest_10) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sqrt(sqrt(81))", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), sqrt(sqrt(81)));
}

TEST(Complexity_n, Subtest_11) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "45", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 45);
}

TEST(Complexity_n, Subtest_12) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "1+2*3^sin(1)", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 1 + 2 * pow(3, sin(1)));
}

TEST(Complexity_n, Subtest_13) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "-1*-2*-3--4", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length),
                   (-1) * (-2) * (-3) - (-4));
}

TEST(Complexity_n, Subtest_14) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "1^2^3", *broken, *djicstra;
  broken = temp.break_string(string, &no_error, &length);
  djicstra = temp.string_to_djicstra(broken, length);
  ASSERT_DOUBLE_EQ(temp.calculation(djicstra, length), 1);
}

TEST(Brackets_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "123+23-((5+0)     ";
  ASSERT_EQ(temp.check_brackets(string), true);
}

TEST(Brackets_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "123+23-)5+0)     ";
  ASSERT_EQ(temp.check_brackets(string), true);
}

TEST(Brackets_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "123+23-(5+0))     ";
  ASSERT_EQ(temp.check_brackets(string), true);
}

TEST(Brackets_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "123+23-(5+0(     ";
  ASSERT_EQ(temp.check_brackets(string), true);
}

TEST(Brackets_error, Subtest_5) {
  s21::calc_controller temp;
  std::string string = "123+23-5+0     ";
  ASSERT_EQ(temp.check_brackets(string), false);
}

TEST(Brackets_error, Subtest_6) {
  s21::calc_controller temp;
  std::string string = "123+23-5+0-()     ";
  ASSERT_EQ(temp.check_brackets(string), true);
}

TEST(Correctness_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "123+23-x*-1     ";
  ASSERT_EQ(temp.check_correctness(string), false);
}

TEST(Correctness_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "123+23-1умножить/1     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "123+23-x--x     ";
  ASSERT_EQ(temp.check_correctness(string), false);
}

TEST(Correctness_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "1.2.3+23-x--x     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_5) {
  s21::calc_controller temp;
  std::string string = "1.2(.3+23)-x--x     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_6) {
  s21::calc_controller temp;
  std::string string = "1*-+3     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_7) {
  s21::calc_controller temp;
  std::string string = "sqrt(cos(1))     ";
  ASSERT_EQ(temp.check_correctness(string), false);
}

TEST(Correctness_error, Subtest_8) {
  s21::calc_controller temp;
  std::string string = "5mod-2     ";
  ASSERT_EQ(temp.check_correctness(string), false);
}

TEST(Correctness_error, Subtest_9) {
  s21::calc_controller temp;
  std::string string = "0atan(56858)     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_10) {
  s21::calc_controller temp;
  std::string string = "ln(1)     ";
  ASSERT_EQ(temp.check_correctness(string), false);
}

TEST(Correctness_error, Subtest_11) {
  s21::calc_controller temp;
  std::string string = "ln(mod1)     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_12) {
  s21::calc_controller temp;
  std::string string = "sin(mod1)     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_13) {
  s21::calc_controller temp;
  std::string string = "-(1+2)     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_14) {
  s21::calc_controller temp;
  std::string string = "sqrt(mod1)     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_15) {
  s21::calc_controller temp;
  std::string string = "1+4*-(1+2)     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_16) {
  s21::calc_controller temp;
  std::string string = "1e2     ";
  ASSERT_EQ(temp.check_correctness(string), false);
}

TEST(Correctness_error, Subtest_17) {
  s21::calc_controller temp;
  std::string string = "1e23e     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Correctness_error, Subtest_18) {
  s21::calc_controller temp;
  std::string string = "1e23.3     ";
  ASSERT_EQ(temp.check_correctness(string), true);
}

TEST(Only_number_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "234.67     ";
  ASSERT_EQ(temp.check_only_number(string), true);
}

TEST(Only_number_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "     ";
  ASSERT_EQ(temp.check_only_number(string), false);
}

TEST(Only_number_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "x     ";
  ASSERT_EQ(temp.check_only_number(string), false);
}

TEST(Only_number_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "-12.444     ";
  ASSERT_EQ(temp.check_only_number(string), true);
}

TEST(Beginning_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "+-1     ";
  ASSERT_EQ(temp.check_begining(string), true);
}

TEST(Beginning_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "+     ";
  ASSERT_EQ(temp.check_begining(string), true);
}

TEST(Beginning_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "+12+-23     ";
  ASSERT_EQ(temp.check_begining(string), false);
}

TEST(Beginning_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "sin     ";
  ASSERT_EQ(temp.check_begining(string), false);
}

TEST(Beginning_error, Subtest_5) {
  s21::calc_controller temp;
  std::string string = "mod     ";
  ASSERT_EQ(temp.check_begining(string), true);
}

TEST(Beginning_error, Subtest_6) {
  s21::calc_controller temp;
  std::string string = "*5     ";
  ASSERT_EQ(temp.check_begining(string), true);
}

TEST(Beginning_error, Subtest_7) {
  s21::calc_controller temp;
  std::string string = "5*     ";
  ASSERT_EQ(temp.check_begining(string), false);
}

TEST(Points_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = ".9234+32     ";
  ASSERT_EQ(temp.check_points(string), true);
}

TEST(Points_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = ".x+32     ";
  ASSERT_EQ(temp.check_points(string), true);
}

TEST(Points_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "x.+32     ";
  ASSERT_EQ(temp.check_points(string), true);
}

TEST(Points_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "x+32     ";
  ASSERT_EQ(temp.check_points(string), false);
}

TEST(Points_error, Subtest_5) {
  s21::calc_controller temp;
  std::string string = "x+32.     ";
  ASSERT_EQ(temp.check_points(string), true);
}

TEST(Points_error, Subtest_6) {
  s21::calc_controller temp;
  std::string string = "x+32..4     ";
  ASSERT_EQ(temp.check_points(string), true);
}

TEST(Func_brackets_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "sinx     ";
  ASSERT_EQ(temp.check_sin_brackets(string), true);
}

TEST(Func_brackets_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "sin(x     ";
  ASSERT_EQ(temp.check_sin_brackets(string), false);
}

TEST(Func_brackets_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "ln10     ";
  ASSERT_EQ(temp.check_sin_brackets(string), true);
}

TEST(Func_brackets_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "sqrt     ";
  ASSERT_EQ(temp.check_sin_brackets(string), true);
}

TEST(Func_brackets_error, Subtest_5) {
  s21::calc_controller temp;
  std::string string = "sin(3)     ";
  ASSERT_EQ(temp.check_sin_brackets(string), false);
}

TEST(All_error, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 1);
}

TEST(All_error, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "*5     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 2);
}

TEST(All_error, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "x.1*1     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 3);
}

TEST(All_error, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "10*(1+3))(     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 4);
}

TEST(All_error, Subtest_5) {
  s21::calc_controller temp;
  std::string string = "sqrt(xe)     ";
  ASSERT_EQ(temp.check_equation_line(string, 1), 5);
}

TEST(All_error, Subtest_6) {
  s21::calc_controller temp;
  std::string string = "10     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 6);
}

TEST(All_error, Subtest_7) {
  s21::calc_controller temp;
  std::string string = "x*10     ";
  ASSERT_EQ(temp.check_equation_line(string, 1), 7);
}

TEST(All_error, Subtest_8) {
  s21::calc_controller temp;
  std::string string = "sin 5     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 8);
}

TEST(All_error, Subtest_9) {
  s21::calc_controller temp;
  std::string string = "1+2*3^sin(1)     ";
  ASSERT_EQ(temp.check_equation_line(string, 0), 0);
}

TEST(Break, Subtest_1) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "si";
  temp.break_string(string, &no_error, &length);
  ASSERT_EQ(no_error, false);
}

TEST(Break, Subtest_2) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "yyy";
  temp.break_string(string, &no_error, &length);
  ASSERT_EQ(no_error, false);
}

TEST(Break, Subtest_3) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "qrt ";
  temp.break_string(string, &no_error, &length);
  ASSERT_EQ(no_error, false);
}

TEST(Break, Subtest_4) {
  s21::calc_controller temp;
  int length = 0;
  bool no_error = true;
  std::string string = "sin(1)*3+sqr";
  temp.break_string(string, &no_error, &length);
  ASSERT_EQ(no_error, false);
}

TEST(Change_notation, Subtest_1) {
  s21::calc_controller temp;
  std::string string = "1e5";
  ASSERT_EQ(temp.change_scientific_notation(string), "100000.000000");
}

TEST(Change_notation, Subtest_2) {
  s21::calc_controller temp;
  std::string string = "1e05";
  ASSERT_EQ(temp.change_scientific_notation(string), "100000.000000");
}

TEST(Change_notation, Subtest_3) {
  s21::calc_controller temp;
  std::string string = "1e+5";
  ASSERT_EQ(temp.change_scientific_notation(string), "100000.000000");
}

TEST(Change_notation, Subtest_4) {
  s21::calc_controller temp;
  std::string string = "1e-5";
  ASSERT_EQ(temp.change_scientific_notation(string), "0.000010");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
