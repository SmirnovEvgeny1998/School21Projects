#ifndef S21_MATH_H
#define S21_MATH_H

#include <float.h>
#include <math.h>

#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_nINF -1.0 / 0.0
#define epsilon 1e-9

#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_NINF -1.0 / 0.0
#define s21_PI 3.14159265358979324
#define s21_EPS 1e-9
#define SMALL 0.000001

int s21_abs(int x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fabs(double x);

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);

#endif
