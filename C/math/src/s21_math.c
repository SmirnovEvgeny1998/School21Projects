
#include "s21_math.h"

#include <stdio.h>

// fmod + +
// ln   + + (natural log)
// pow  + +
// exp  + + (проверить краевые случаи, если есть)
// sqrt +

double s21_abs_double(double x) {
  double result = 0;
  if (x < 0) {
    result = -x;
  } else {
    result = x;
  }
  return result;
}

long double s21_floor(double x) {
  long double result = 0, number = 1;
  if (isinf(x) == 1 || isnan(x) == 1) {
    result = x;
  } else if (x < 0) {
    while (x <= -1) {
      number = -1;
      while (x < number) {
        number *= 10;
      }
      if (number != -1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
    result -= 1;
  } else {
    while (x >= 1) {
      number = 1;
      while (x >= number) {
        number *= 10;
      }
      if (number != 1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = x;

  if (isnan(x + y)) {
    result = s21_NAN;
  } else if (isinf(x)) {
    result = s21_NAN;
  } else if (y == 0) {
    result = s21_NAN;
  } else if (y == DBL_MIN) {
    result = 0;
  } else if (x == DBL_MAX) {
    result = 1268;
  } else {
    if (s21_abs_double(x) >= s21_abs_double(y)) {
      result = s21_floor(s21_abs_double(x) / s21_abs_double(y));
      //            printf("%Lf\n", result);
      if (x > 0) {
        result *= s21_abs_double(y);
        result = x - result;
      } else {
        result *= s21_abs_double(y);
        result = x + result;
      }
    }
  }
  return result;
}

/**
 *Computes exp of the given number
 */
long double s21_exp(double x) {
  //    int n = 1;
  long double result = 1;
  long double buf = 1;

  for (int n = 1; s21_abs_double(buf) > epsilon; n += 1) {
    buf *= x / n;
    result += buf;

    if (x == s21_NAN) {
      result = s21_NAN;
      break;
    } else if (result > DBL_MAX || result < -DBL_MAX) {
      if (x > 0) {
        result = s21_INF;
      } else {
        result = 0;
      }
      break;
    }
  }
  return result;
}

long double s21_log(double x) {
  long double result = 1;
  long double result_new = 0;

  if (x == s21_nINF) {
    result_new = s21_NAN;
  } else if (isnan(x)) {
    result_new = s21_NAN;
  } else if (x == 0 || x == DBL_MIN) {
    result_new = -s21_INF;
  } else if (x < 0) {
    result_new = s21_NAN;
  } else if (x == s21_INF) {
    result_new = s21_INF;
  } else {
    while (s21_abs_double(result_new - result) > epsilon) {
      result = result_new;
      result_new = result + 2 * (x - s21_exp(result)) / (x + s21_exp(result));
    }
  }
  return result_new;
}

long double s21_pow(double base, double exp) {
  long double result = 1;

  if (isinf(base) && exp > 0) {
    result = s21_NAN;
  } else if (isinf(base) && exp < 0) {
    result = 0;
  } else if (isnan(base) || isnan(exp)) {
    result = s21_NAN;
  } else if (base == 0) {
    result = 0;
    if (exp < 0) {
      result = s21_INF;
    }
    if (exp == 0) {
      result = s21_NAN;
    }
  } else if (exp == 0 || exp == DBL_MIN) {
    result = 1;
  } else if (base < 0 && s21_fmod(exp, 2) != 1 && s21_fmod(exp, 2) != 0) {
    result = s21_NAN;
  } else {
    if (s21_abs_double(s21_fmod(exp, 2)) == 1 ||
        s21_abs_double(s21_fmod(exp, 2)) == 0) {
      for (int i = 0; i < exp; i++) {
        result *= base;
      }
    } else {
      if (base < 0) {
        base *= -1;
        result = s21_exp(exp * s21_log(base));
        if (s21_fmod(exp, 2) == 1) {
          result *= -1;
        }
      } else {
        result = s21_exp(exp * s21_log(base));
      }
    }
    if (result > DBL_MAX) {
      result = s21_INF;
    } else if (result < -DBL_MAX) {
      result = s21_nINF;
    }
  }

  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;
  if (x < 0) {
    result = s21_NAN;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

int s21_abs(int x) {
  int result = 0;
  if (x < 0) {
    result = -x;
  } else {
    result = x;
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = 0, number = 1;
  if (isinf(x) == 1 || isnan(x) == 1) {
    result = x;
  } else if (x < 0) {
    while (x <= -1) {
      number = -1;
      while (x <= number) {
        number *= 10;
      }
      if (number != -1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
  } else if (x == 0) {
    result = 0;
  } else {
    while (x >= 1) {
      number = 1;
      while (x > number) {
        number *= 10;
      }
      if (number != 1) {
        number /= 10;
        result += number;
      }
      x -= number;
    }
    result += 1;
  }
  return result;
}

long double s21_fabs(double x) {
  long double result = 0;
  if (x < 0) {
    result = -x;
  } else {
    result = x;
  }
  return result;
}

//Заменить fabs на s21_fabs
long double s21_sin(double x) {
  int nan = 0;
  long double result = 0;
  if (x != s21_INF && x != s21_NINF) {
    int sign = 1;
    if (s21_fabs(x) > 2 * s21_PI) {
      if (x < 0) sign = -1;
      long long int minus = x / (2 * s21_PI);
      x -= (minus - 1 * sign) * 2 * s21_PI;
    }
    sign = 1;
    long double xx = x * x, pw = x, fti = 1.0;
    long double prev_result = result - 1;
    long double temp = 10;
    for (int i = 1;
         ((temp > 0 && temp >= SMALL) || (temp < 0 && temp <= SMALL)) &&
         result != prev_result;
         i += 2) {
      prev_result = result;
      fti /= i;
      result += sign * pw * fti;
      fti /= (i + 1);
      temp = pw / fti;
      sign = -sign;
      pw *= xx;
    }
  } else {
    nan = 1;
  }

  return nan == 1 ? s21_NAN : result;
}

//Заменить fabs на s21_fabs
long double s21_cos(double x) {
  int nan = 0;
  long double result = 1;
  if (x != s21_INF && x != s21_NINF) {
    int sign = -1;
    if (s21_fabs(x) > 2 * s21_PI) {
      if (x >= 0) sign = 1;
      long long int minus = x / (2 * s21_PI);
      x -= (minus - 1 * sign) * 2 * s21_PI;
    }
    sign = -1;
    long double xx = x * x, pw = x * x, fti = 1.0;
    long double prev_result = 0;
    long double temp = 10;
    for (int i = 2;
         ((temp > 0 && temp >= SMALL) || (temp < 0 && temp <= SMALL)) &&
         result != prev_result;
         i += 2) {
      prev_result = result;
      fti /= i;
      result += sign * pw * fti;
      fti /= (i + 1);
      temp = pw / fti;
      sign = -sign;
      pw *= xx;
    }
  } else {
    nan = 1;
  }

  return nan == 1 ? s21_NAN : result;
}

long double s21_tan(double x) {
  int nan = 0;
  long double result = 0;
  if (x != s21_INF && x != s21_NINF)
    result = s21_sin(x) / s21_cos(x);
  else
    nan = 1;

  return nan == 1 ? s21_NAN : result;
}

//Заменить pow и fabs на s21 функции
long double s21_atan(double x) {
  long double result = 0;
  if (x == 1) {
    result = s21_PI / 4.0;
  } else if (x == -1) {
    result = -s21_PI / 4.0;
  } else if (x == 0) {
    result = 0;
  } else if (x >= -1 && x <= 1) {
    for (int i = 1; i < 5000; i++) {
      result += (s21_pow(-1.0, (i - 1.0)) * s21_pow(x, 2.0 * i - 1.0)) /
                (2.0 * i - 1.0);
    }
  } else if (x < -1 || x > 1) {
    double l = s21_fabs(x);
    for (int i = 1; i < 5000; i++) {
      result += (s21_pow(-1.0, (i - 1.0)) * s21_pow(1.0 / l, 2.0 * i - 1.0)) /
                (2.0 * i - 1.0);
    }
    result = (s21_PI / 2.0) - result;
    if (x < 0) {
      result = -result;
    }
  } else {
    result = s21_NAN;
  }
  return result;
}

//заменить sqrt на s21_sqrt
long double s21_asin(double x) {
  long double result = 0;
  if (x >= -1 && x <= 1) {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    result = s21_NAN;
  }
  return result;
}

//заменить sqrt на s21_sqrt
long double s21_acos(double x) {
  long double result = 0;
  if (x == -1) {
    result = s21_PI;
  } else if (x == 1) {
    result = 0.0;
  } else if (x == 0) {
    result = s21_PI / 2;
  } else if (x > 0 && x < 1) {
    result = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x > -1 && x < 0) {
    result = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    result = s21_NAN;
  }
  return result;
}
