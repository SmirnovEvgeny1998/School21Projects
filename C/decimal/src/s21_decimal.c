#include "s21_decimal.h"

int s21_getBit(s21_decimal d, int i) {
  unsigned int mask = 1u << (i % 32);
  return (d.bits[i / 32] & mask) >> (i % 32);
}

void s21_setBit(s21_decimal *d, int i, int value) {
  unsigned int mask = 1u << (i % 32);
  if (i / 32 < 4 && value) {
    d->bits[i / 32] |= mask;
  } else if (i / 32 < 4 && !value) {
    d->bits[i / 32] &= ~mask;
  }
}

int s21_getScale(const s21_decimal d) {
  return (char)((d.bits[3] & ~(1 << 30)) >> 16);
}

void s21_setScale(s21_decimal *d, int scale) {
  int step = 0;
  for (int i = s21_START_INFO + 16; i < s21_START_INFO + 24; i++) {
    s21_setBit(d, i, scale & (1 << step));
    step++;
  }
}

void s21_check_scale(s21_decimal *value1, s21_decimal *value2) {
  int scale_value1 = s21_getScale(*value1);
  int scale_value2 = s21_getScale(*value2);
  if (scale_value1 != scale_value2) {
    s21_scale_equalization(value1, value2, 0);
  }
}

int s21_getSign(const s21_decimal d) {
  unsigned int mask = 1u << 31;
  return !!(d.bits[3] & mask);
}

void s21_setSign(s21_decimal *d, int sign) { s21_setBit(d, 127, sign); }

void s21_init_decimal(s21_decimal *dec) {
  dec->bits[0] = dec->bits[1] = dec->bits[2] = dec->bits[3] = 0;
}

int s21_scale_equalization(s21_decimal *value_1, s21_decimal *value_2,
                           int err_num) {
  int res = err_num;
  s21_decimal *left = NULL;
  s21_decimal *right = NULL;
  s21_decimal remainder = {{0, 0, 0, 0}};
  if (s21_getScale(*value_1) > s21_getScale(*value_2)) {
    left = value_1;
    right = value_2;
  } else {
    left = value_2;
    right = value_1;
  }
  if (s21_getScale(*value_1) != s21_getScale(*value_2)) {
    int sign1 = s21_getSign(*left), sign2 = s21_getSign(*right);
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_setSign(left, 0);
    s21_setSign(right, 0);
    while (s21_getScale(*left) != s21_getScale(*right) &&
           s21_last_bit(*right) < 93 && s21_getScale(*right) <= 28) {
      res = OK;
      int scale_small = s21_getScale(*right);
      s21_setScale(right, 0);
      res = s21_mul(ten, *right, right);
      if (res != 0) break;
      s21_setScale(right, scale_small + 1);
    }
    while (s21_getScale(*right) != s21_getScale(*left)) {
      int res = OK;
      int scale_big = s21_getScale(*left);
      if (s21_getScale(*left) - s21_getScale(*right) == 1) {
        if (left->bits[0] >= 5 && left->bits[0] < 10) {
          left->bits[0] = 1;
          s21_setScale(left, scale_big - 1);
          break;
        }
      }
      res = s21_integer_division(*left, ten, left, &remainder, 1);
      if (res != 0) break;
      s21_setScale(left, scale_big - 1);
    }
    s21_setSign(left, sign1);
    s21_setSign(right, sign2);
  }
  return res;
}

void s21_decl_to_null(s21_decimal *decl) {
  for (int i = 0; i < 128; ++i) {
    s21_setBit(decl, i, 0);
  }
}

void s21_bits_copy(s21_decimal value, s21_decimal *dest) {
  for (int i = 0; i < 4; ++i) {
    dest->bits[i] = value.bits[i];
  }
}

int s21_last_bit(s21_decimal value) {
  int last_bit = 95;
  for (; last_bit >= 0 && s21_getBit(value, last_bit) == 0; last_bit--) {
  }
  return last_bit;
}

void s21_setting(s21_decimal tmp_buf, s21_decimal *tmp_del,
                 s21_decimal *tmp_mod, int *discharge) {
  s21_bits_copy(tmp_buf, tmp_del);
  s21_shift_left(tmp_del, 1);
  s21_getBit(*tmp_mod, *discharge - 1) == 1 ? s21_setBit(tmp_del, 0, 1)
                                            : s21_setBit(tmp_del, 0, 0);
  s21_setBit(tmp_mod, *discharge - 1, 0);
  (*discharge)--;
}

int s21_shift_left(s21_decimal *value, int num) {
  int res = OK;
  int lastbit = s21_last_bit(*value);
  if (lastbit + num > 95) {
    res = TOO_MUCH_OR_INF;
  }
  if (res == OK) {
    for (int i = 0; i < num; i++) {
      int value_31bit = s21_getBit(*value, 31);
      int value_63bit = s21_getBit(*value, 63);
      value->bits[0] <<= 1;
      value->bits[1] <<= 1;
      value->bits[2] <<= 1;
      if (value_31bit) s21_setBit(value, 32, 1);
      if (value_63bit) s21_setBit(value, 64, 1);
    }
  }
  return res;
}

int s21_shift_right(s21_decimal *first, int shift) {
  int res_val = 1;
  for (int i = 0; i < shift; i++) {
    int value_32bit = s21_getBit(*first, 32);
    int value_64bit = s21_getBit(*first, 64);
    first->bits[0] >>= 1;
    first->bits[1] >>= 1;
    first->bits[2] >>= 1;
    value_32bit ? s21_setBit(first, 31, 1) : s21_setBit(first, 31, 0);
    value_64bit ? s21_setBit(first, 63, 1) : s21_setBit(first, 63, 0);
    s21_setBit(first, 95, 0);
    res_val = 0;
  }
  return res_val;
}

int s21_integer_division(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result, s21_decimal *remainder,
                         int error_code) {
  s21_decimal tmp_div = {0};
  s21_decimal tmp_del = {0};
  s21_decimal tmp_mod = {0};
  s21_decimal tmp_res = {0};
  s21_decimal tmp_buf = {0};
  int scale_value1 = s21_getScale(value_1);
  int index_res = 95, res = 0, discharge = 1;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2);
  int scale1 = s21_getScale(value_1), scale2 = s21_getScale(value_2);
  s21_bits_copy(value_1, &tmp_div);
  s21_setScale(&tmp_div, 0);
  s21_setScale(&value_2, 0);
  s21_setSign(&tmp_div, 0);
  s21_setSign(&value_2, 0);
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    res = s21_NAN;
  } else if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 &&
              value_1.bits[2] == 0) ||
             scale1 > 28 || scale2 > 28) {
    res = TOO_FEW_OR_NEG_INF;
  } else {
    if (s21_is_greater_or_equal(tmp_div, value_2) && error_code) {
      s21_first_prepare(tmp_div, &tmp_mod, &tmp_del, value_2, &discharge);
    } else if (!error_code) {
      s21_first_step(&tmp_div, value_2, &scale_value1, &tmp_res, &index_res);
      s21_first_prepare(tmp_div, &tmp_mod, &tmp_del, value_2, &discharge);
    }
    while (discharge != -1 && index_res >= 0 && scale_value1 <= 28) {
      if (s21_is_greater_or_equal(tmp_del, value_2)) {
        res = s21_sub(tmp_del, value_2, &tmp_buf);
        s21_setBit(&tmp_res, index_res, 1);
        index_res--;
        s21_setting(tmp_buf, &tmp_del, &tmp_mod, &discharge);
      } else {
        s21_setting(tmp_del, &tmp_del, &tmp_mod, &discharge);
        s21_setBit(&tmp_res, index_res, 0);
        index_res--;
      }
    }
    s21_init_decimal(result);
    for (int i = 95; i > index_res; i--) {
      s21_getBit(tmp_res, i) == 1 ? s21_setBit(result, i - index_res - 1, 1)
                                  : s21_setBit(result, i - index_res - 1, 0);
    }
    (sign1 != sign2) ? s21_setSign(result, 1) : NULL;
    s21_setScale(result, scale_value1);
    s21_shift_right(&tmp_del, 1);
    *remainder = tmp_del;
  }
  if (res != 0) s21_init_decimal(result);
  return res;
}

void s21_first_prepare(s21_decimal tmp_div, s21_decimal *tmp_mod,
                       s21_decimal *tmp_del, s21_decimal value_2,
                       int *discharge) {
  *discharge = 0;
  int shift = s21_last_bit(tmp_div) - s21_last_bit(value_2);
  int n = 0;
  int flag = 0;
  while (tmp_mod && flag != 1) {
    s21_bits_copy(tmp_div, tmp_del);
    s21_shift_right(tmp_del, shift - n);
    if (s21_is_greater_or_equal(*tmp_del, value_2) == 1) {
      flag = 1;
    } else {
      n++;
    }
  }
  s21_bits_copy(tmp_div, tmp_mod);
  *discharge = s21_last_bit(tmp_div) - s21_last_bit(*tmp_del);
  for (int i = 95; i > *discharge - 1; i--) {
    s21_setBit(tmp_mod, i, 0);
  }
}

void s21_first_step(s21_decimal *tmp_div, s21_decimal value_2,
                    int *scale_value1, s21_decimal *tmp_res, int *index_res) {
  s21_decimal ten = {{10, 0, 0, 0}};
  int x = s21_is_greater_or_equal(*tmp_div, value_2);
  while (x != 1) {
    s21_setBit(tmp_res, *index_res, 0);
    (*index_res)--;
    s21_mul(*tmp_div, ten, tmp_div);
    (*scale_value1)++;
    x = s21_is_greater_or_equal(*tmp_div, value_2);
  }
}

int count_src(float src, char *str_src) {
  int count_str = 0, k = 1;
  char str[100];

  snprintf(str, sizeof(str), "%f", src);
  for (int i = (int)strlen(str) - 1; i >= 0; i--) {
    if (str[i] == '0' && k == 1) {
      str[i] = '\0';
      continue;
    } else {
      k = -1;
    }
    if (str[i] == '.') {
      break;
    }
    count_str++;
  }

  strncpy(str_src, str, strlen(str) + 1);

  return count_str;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  s21_setSign(result, !s21_getSign(value));
  return 0;
}

int int_get_bit(unsigned int number, int byte) {
  return (number & 1 << byte) ? 1 : 0;
}

void int_shift_left(unsigned int *num, int shift, int n) { *num ^= shift << n; }

void int_set_bit(unsigned int *number, int byte, int n) {
  if (int_get_bit(*number, byte) != n) int_shift_left(number, 1, byte);
}

int div_ten(s21_decimal *number) {
  unsigned int buffer = 0;
  int scale_of_number = s21_getScale(*number);
  s21_decimal result = {{0, 0, 0, 0}};
  int highest_bit_pos = s21_last_bit(*number);
  for (int i = 0; i < highest_bit_pos + 2; i++) {
    if (buffer >= 10) {
      s21_shift_left(&result, 1);
      s21_setBit(&result, 0, 1);
      buffer -= 10;
      int new_bit = s21_getBit(*number, highest_bit_pos - i);
      buffer = buffer << 1;
      int_set_bit(&buffer, 0, new_bit);
    } else {
      s21_shift_left(&result, 1);
      s21_setBit(&result, 0, 0);
      int new_bit = s21_getBit(*number, highest_bit_pos - i);
      buffer = buffer << 1;
      int_set_bit(&buffer, 0, new_bit);
    }
  }
  buffer = buffer << 1;
  *number = result;
  s21_setScale(number, scale_of_number);
  return buffer;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result) {
    int scale = s21_getScale(value);
    int sign = s21_getBit(value, 127);

    for (int i = 0; i < scale; i++) {
      div_ten(&value);
    }

    *result = value;
    s21_setBit(result, 127, sign);
    s21_setScale(result, 0);
  } else {
    res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result) {
    int is_less_than_zero = 0;
    s21_decimal zero = {{0, 0, 0, 0}};
    s21_decimal half;
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal value_int;
    s21_decimal mantissa;
    s21_from_float_to_decimal(0.5, &half);
    if (s21_is_less(value, zero)) {
      is_less_than_zero = 1;
      s21_negate(value, &value);
    }
    s21_truncate(value, &value_int);
    s21_sub(value, value_int, &mantissa);

    float mantissa_fl, half_fl;
    s21_from_decimal_to_float(mantissa, &mantissa_fl);
    s21_from_decimal_to_float(half, &half_fl);
    if (mantissa_fl >= half_fl) {
      s21_add(value_int, one, result);
    } else {
      *result = value_int;
    }

    if (is_less_than_zero) {
      s21_negate(*result, result);
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result) {
    s21_decimal zero = {{0, 0, 0, 0}};
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal value_int;
    s21_truncate(value, result);
    s21_truncate(value, &value_int);
    if (s21_is_less(value, zero) && s21_is_not_equal(value, value_int)) {
      s21_sub(*result, one, result);
    }
  } else {
    res = 1;
  }
  return res;
}

int add(s21_decimal left, s21_decimal right, s21_decimal *result) {
  int res = 0;
  int tmp = 0;
  for (int i = 0; i <= 96; i++) {
    int tmp1 = s21_getBit(left, i);
    int tmp2 = s21_getBit(right, i);
    int tmp_res = tmp1 + tmp2 + tmp;
    if (tmp_res == 0) {
      s21_setBit(result, i, 0);
      tmp = 0;
    } else if (tmp_res == 1) {
      s21_setBit(result, i, 1);
      tmp = 0;
    } else if (tmp_res == 2 || tmp_res == 3) {
      if (i == 95) {
        res = 1;
        break;
      }
      s21_setBit(result, i, tmp_res == 2 ? 0 : 1);
      tmp = 1;
    }
  }

  s21_setScale(result, s21_getScale(left));
  int setSingn = (s21_getSign(left) + s21_getSign(right) + tmp) % 2;
  s21_setSign(result, setSingn);
  if (setSingn == 1) {
    result->bits[0] = ~result->bits[0];
    result->bits[1] = ~result->bits[1];
    result->bits[2] = ~result->bits[2];
    int tmp = 1;
    for (int i = 0; i <= 96; i++) {
      int tmp1 = s21_getBit(*result, i);
      int tmp_res = tmp1 + tmp;
      if (tmp_res == 0) {
        s21_setBit(result, i, 0);
        tmp = 0;
      } else if (tmp_res == 1) {
        s21_setBit(result, i, 1);
        tmp = 0;
      } else if (tmp_res == 2 || tmp_res == 3) {
        s21_setBit(result, i, tmp_res == 2 ? 0 : 1);
        tmp = 1;
      }
    }
  }
  return res;
}

void inverse(s21_decimal *value) {
  value->bits[0] = ~value->bits[0];
  value->bits[1] = ~value->bits[1];
  value->bits[2] = ~value->bits[2];
  int tmp = 1;
  for (int i = 0; i <= 96; i++) {
    int tmp1 = s21_getBit(*value, i);
    int tmp_res = tmp1 + tmp;
    if (tmp_res == 0) {
      s21_setBit(value, i, 0);
      tmp = 0;
    } else if (tmp_res == 1) {
      s21_setBit(value, i, 1);
      tmp = 0;
    } else if (tmp_res == 2 || tmp_res == 3) {
      s21_setBit(value, i, tmp_res == 2 ? 0 : 1);
      tmp = 1;
    }
  }
  s21_setSign(value, (s21_getSign(*value) + tmp) % 2);
}

s21_decimal s21_div_only_bits(s21_decimal value1, s21_decimal value2,
                              s21_decimal *buf) {
  s21_init_decimal(buf);
  s21_decimal result = {{0, 0, 0, 0}};
  for (int i = s21_last_bit(value1); i >= 0; i--) {
    if (s21_getBit(value1, i)) s21_setBit(buf, 0, 1);
    if (s21_is_greater_or_equal(*buf, value2) == 1) {
      s21_sub(*buf, value2, buf);
      if (i != 0) s21_shift_left(buf, 1);
      if (s21_getBit(value1, i - 1)) s21_setBit(buf, 0, 1);
      s21_shift_left(&result, 1);
      s21_setBit(&result, 0, 1);
    } else {
      s21_shift_left(&result, 1);
      if (i != 0) s21_shift_left(buf, 1);
      if ((i - 1) >= 0 && s21_getBit(value1, i - 1)) s21_setBit(buf, 0, 1);
    }
  }
  return result;
}

int s21_zero_check(s21_decimal value1, s21_decimal value2) {
  int zero = 1;
  s21_decimal *tmp1 = &value1;
  s21_decimal *tmp2 = &value2;
  if (tmp1 && tmp2) {
    if (!value1.bits[0] && !value2.bits[0] && !value1.bits[1] &&
        !value2.bits[1] && !value1.bits[2] && !value2.bits[2])
      zero = 0;
  }
  return zero;
}

int s21_bit_addition(s21_decimal *value1, s21_decimal *value2,
                     s21_decimal *result) {
  int buf = 0, res = OK;
  for (int i = 0; i < 96; i++) {
    int bit1 = s21_getBit(*value1, i);
    int bit2 = s21_getBit(*value2, i);
    if (bit1 && bit2) {
      if (buf) {
        s21_setBit(result, i, 1);
      } else {
        s21_setBit(result, i, 0);
        buf = 1;
      }
    } else if (!bit1 && !bit2) {
      if (buf) {
        s21_setBit(result, i, 1);
        buf = 0;
      } else {
        s21_setBit(result, i, 0);
      }
    } else if (bit1 != bit2) {
      if (buf) {
        s21_setBit(result, i, 0);
      } else {
        s21_setBit(result, i, 1);
      }
    }
    if (i == 95 && buf == 1) res = TOO_MUCH_OR_INF;
  }
  return res;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;
  s21_decimal right = value_1;
  s21_decimal left = value_2;
  s21_init_decimal(result);
  s21_scale_equalization(&right, &left, 0);
  if (s21_getSign(right) == s21_getSign(left)) {
    res = add(left, right, result);
  } else if (s21_getSign(right) != s21_getSign(left)) {
    if (s21_getSign(right) == 1) {
      inverse(&right);
      res = add(left, right, result);
    } else if (s21_getSign(left) == 1) {
      inverse(&left);
      res = add(left, right, result);
    }
  }
  if ((s21_getSign(right) == 1) && (s21_getSign(left) == 1)) {
    s21_negate(*result, result);
  }
  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0, flag = 0;
  s21_init_decimal(result);
  s21_scale_equalization(&value_1, &value_2, 0);
  int sign1 = s21_getBit(value_1, 127);
  int sign2 = s21_getSign(value_2);
  if (sign1 != sign2) {
    if (sign1 == 0) flag = 1;
    if (sign2 == 0) flag = 2;
  }
  if (flag == 0) {
    if (sign1 == 0) {
      if (s21_is_less(value_1, value_2)) {
        s21_setSign(result, 1);
        s21_decimal hold = value_1;
        value_1 = value_2;
        value_2 = hold;
      }
      for (int i = 0; i < 96; i++) {
        int tmp1 = s21_getBit(value_1, i);
        int tmp2 = s21_getBit(value_2, i);
        int tmp_res = tmp1 - tmp2;
        if (tmp_res == 0) {
          s21_setBit(result, i, 0);
          continue;
        } else if (tmp_res == 1) {
          s21_setBit(result, i, 1);
        } else if (tmp_res == -1) {
          int n = i + 1;
          while (s21_getBit(value_1, n) != 1) {
            s21_setBit(&value_1, n, 1);
            n++;
          }
          s21_setBit(&value_1, n, 0);
          s21_setBit(result, i, 1);
        }
      }
      s21_setScale(result, s21_getScale(value_1));
    } else if (sign1 == 1) {
      s21_setBit(&value_1, 127, 0);
      s21_setBit(&value_2, 127, 0);
      res = s21_sub(value_2, value_1, result);
    }
  } else if (flag == 1) {
    s21_setBit(&value_2, 127, 0);
    res = s21_add(value_1, value_2, result);
  } else if (flag == 2) {
    s21_setBit(&value_2, 127, 1);
    res = s21_add(value_1, value_2, result);
  }
  if (s21_getScale(*result) > 28 ||
      (s21_getScale(*result) == 28 && result->bits[0] == 0 &&
       result->bits[1] == 0 && result->bits[2] == 0))
    res = 2;
  if (res != 0) s21_init_decimal(result);
  return res;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  int sign_result = 0;
  s21_init_decimal(result);
  if (s21_getSign(value_1) != s21_getSign(value_2)) {
    sign_result = 1;
  } else {
    sign_result = 0;
  }
  int last_bit_1 = s21_last_bit(value_1);
  s21_decimal tmp_res = {{0, 0, 0, 0}};
  for (int i = 0; i <= last_bit_1; i++) {
    s21_init_decimal(&tmp_res);
    int value_bit_1 = s21_getBit(value_1, i);
    if (value_bit_1) {
      tmp_res = value_2;
      if ((95 - last_bit_1 - 1) == i && sign_result == 0) {
        res = TOO_MUCH_OR_INF;
        break;
      } else if ((95 - last_bit_1 - 1) == i && sign_result == 1) {
        res = TOO_FEW_OR_NEG_INF;
        break;
      }
      s21_shift_left(&tmp_res, i);
      res = s21_bit_addition(result, &tmp_res, result);
    }
  }
  while (res != OK &&
         (s21_getScale(value_1) > 0 || s21_getScale(value_2) > 0)) {
    s21_decimal *chosen_num = NULL, *other_num = NULL;
    if (s21_last_bit(value_1) > s21_last_bit(value_2) &&
        s21_getScale(value_1) > 0) {
      chosen_num = &value_1;
      other_num = &value_2;
    } else if (s21_last_bit(value_2) > s21_last_bit(value_1) &&
               s21_getScale(value_2) > 0) {
      chosen_num = &value_2;
      other_num = &value_1;
    } else {
      break;
    }
    int chosen_num_scale = s21_getScale(*chosen_num);
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    s21_decimal tmp_div = s21_div_only_bits(*chosen_num, ten, &remainder);
    s21_decimal zero = {{0, 0, 0, 0}};
    if (s21_zero_check(tmp_div, zero) == 1) {
      s21_bits_copy(tmp_div, chosen_num);
    } else {
      s21_bits_copy(remainder, chosen_num);
    }
    s21_setScale(chosen_num, --chosen_num_scale);
    res = s21_mul(*chosen_num, *other_num, result);
  }
  int scale = s21_getScale(value_1) + s21_getScale(value_2);
  s21_setScale(result, scale);
  s21_setSign(result, sign_result);
  if ((res != OK) || scale > 28) {
    s21_init_decimal(result);
  }
  return res;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal remainder = {{1, 0, 0, 0}};
  s21_decimal tmp_res = {{0, 0, 0, 0}};
  s21_decimal zero = {{0, 0, 0, 0}};
  int res = 0, count = 0;
  int scale1 = s21_getScale(value_1), scale2 = s21_getScale(value_2), scale = 0;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2);
  s21_setSign(&value_1, 0);
  s21_setSign(&value_2, 0);
  (scale1 >= scale2) ? scale = (scale1 - scale2)
                     : s21_scale_equalization(&value_1, &value_2, 0);
  if (s21_is_equal(value_2, zero)) res = s21_NAN;
  if (s21_is_greater(value_2, value_1) && scale == 0) {
    s21_decimal ten = {{10, 0, 0, 0}};
    while (s21_is_greater(value_2, value_1)) {
      s21_mul(value_1, ten, &value_1);
      scale++;
      if (scale == 28) break;
    }
  }
  s21_setScale(&value_1, scale);
  while (count < 10) {
    *result = tmp_res;
    res = s21_integer_division(value_1, value_2, &tmp_res, &remainder, 0);
    if (s21_getScale(tmp_res) == 0 && s21_last_bit(tmp_res) > 93) {
      res = TOO_MUCH_OR_INF;
      break;
    }
    s21_add(tmp_res, *result, &tmp_res);
    if (remainder.bits[0] == 0 && remainder.bits[1] == 0 &&
        remainder.bits[2] == 0)
      break;
    value_1 = remainder;
    s21_setScale(&value_1, scale + count);
    count++;
  }
  *result = tmp_res;
  (sign1 != sign2) ? s21_setSign(result, 1) : NULL;
  if (res != 0) s21_init_decimal(result);
  return res;
  s21_setScale(&value_1, scale);
  while (count < 10) {
    *result = tmp_res;
    res = s21_integer_division(value_1, value_2, &tmp_res, &remainder, 0);
    if (s21_getScale(tmp_res) == 0 && s21_last_bit(tmp_res) > 93) {
      res = TOO_MUCH_OR_INF;
      break;
    }
    s21_add(tmp_res, *result, &tmp_res);
    if (remainder.bits[0] == 0 && remainder.bits[1] == 0 &&
        remainder.bits[2] == 0)
      break;
    value_1 = remainder;
    s21_setScale(&value_1, scale + count);
    count++;
  }
  *result = tmp_res;
  (sign1 != sign2) ? s21_setSign(result, 1) : NULL;
  if (res != 0) s21_init_decimal(result);
  return res;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal tmp = {{0, 0, 0, 0}};
  int res = OK;
  res = s21_div(value_1, value_2, &tmp);
  if (res == OK) res = s21_truncate(tmp, &tmp);
  if (res == OK) res = s21_mul(tmp, value_2, &tmp);
  if (res == OK) res = s21_sub(value_1, tmp, result);
  return res;
}

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  return s21_is_greater(value2, value1);
}

int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_less(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = OK;
  s21_check_scale(&value_1, &value_2);
  int num1 = 0, num2 = 0;
  int sign1 = s21_getSign(value_1), sign2 = s21_getSign(value_2);
  int i = 95;
  while (i >= 0) {
    num1 = s21_getBit(value_1, i);
    num2 = s21_getBit(value_2, i);
    if (num1 > num2) {
      res = 1;
      i = 0;
    }
    if (num1 < num2) {
      res = 0;
      i = 0;
    }

    i--;
  }
  if (sign1 && !sign2)
    res = 0;
  else if (!sign1 && sign2)
    res = 1;
  else if (sign1 && sign2)
    res = !res;
  return s21_is_equal(value_1, value_2) ? 0 : res;
}

int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2) {
  return (s21_is_greater(value1, value2) || s21_is_equal(value1, value2));
}

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  s21_check_scale(&value1, &value2);
  int res = 1;
  int sign1 = s21_getSign(value1), sign2 = s21_getSign(value2);
  int i = 95;
  while (i >= 0) {
    if (s21_getBit(value1, i) != s21_getBit(value2, i)) {
      res = 0;
      i = 0;
    }
    i--;
  }
  if (sign1 != sign2) res = 0;
  return res;
}

int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  return (!s21_is_equal(value1, value2));
}

void s21_simple_sub(s21_decimal value1, s21_decimal value2,
                    s21_decimal *result) {
  s21_decl_to_null(result);
  for (int i = 0; i < 96; i++) {
    int bit_dec1 = s21_getBit(value1, i);
    int bit_dec2 = s21_getBit(value2, i);

    s21_setBit(result, i, bit_dec1 ^ bit_dec2);

    if (!bit_dec1 && bit_dec2) {
      int k = i + 1;
      while ((bit_dec1 = s21_getBit(value1, k)) != 1) {
        s21_setBit(&value1, k, 1);
        k++;
      }
      s21_setBit(&value1, k, 0);
    }
  }
}

int s21_simple_add(s21_decimal value1, s21_decimal value2,
                   s21_decimal *result) {
  s21_decl_to_null(result);
  int rank = 0;
  for (int i = 0; i < 96; i++) {
    int bit_dec1 = s21_getBit(value1, i);
    int bit_dec2 = s21_getBit(value2, i);

    s21_setBit(result, i, bit_dec1 ^ bit_dec2 ^ rank);

    rank = (bit_dec1 && bit_dec2) || (bit_dec1 && rank) || (bit_dec2 && rank);
  }
  return rank;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(&(dst->bits), 0, sizeof(dst->bits));

  if (src < 0) {
    dst->bits[3] = dst->bits[3] | (1u << 31);
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;
  s21_decimal ten;
  s21_decimal add;
  s21_init_decimal(dst);
  if (fabsl(src) < 1e-28 && fabsl(src) < 0) {
    flag = 1;
  }
  char str_src[1024];
  int count = count_src(src, str_src);

  s21_from_int_to_decimal(10, &ten);
  for (size_t i = 0; i < strlen(str_src); i++) {
    if (str_src[i] != '.' && str_src[i] != '-') {
      s21_from_int_to_decimal(str_src[i] - '0', &add);
      s21_mul(*dst, ten, dst);
      s21_simple_add(*dst, add, dst);
    }
  }

  s21_setSign(dst, src < 0);
  s21_setScale(dst, count);

  return flag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  int data = 0;
  int scale = s21_getScale(src);

  if (scale + 31 < 95) {
    for (int i = scale + 31; i <= 95; ++i) {
      if (s21_getBit(src, i)) {
        flag = 1;
      }
    }
  }

  if (!flag) {
    for (int i = scale + 30; i >= scale; --i) {
      data <<= 1;
      data |= s21_getBit(src, i);
    }
    if (s21_getSign(src)) {
      data = -data;
    }
    *dst = data;
  }
  return flag;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  if (dst) {
    long int exp = s21_getScale(src);
    long double temp = (src.bits[0] * pow(10, -exp));
    *dst = temp;
    if (s21_getSign(src)) {
      *dst *= -1;
    }
  } else {
    flag = 1;
  }
  return flag;
}
