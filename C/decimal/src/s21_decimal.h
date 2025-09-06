#ifndef SRC_S21_DECIMAL_H
#define SRC_S21_DECIMAL_H

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_SIZE 4

typedef struct {
  int bits[BITS_SIZE];
} s21_decimal;

#define OK 0
#define s21_START_INFO 96
#define s21_NAN 3
#define TOO_MUCH_OR_INF 1
#define TOO_FEW_OR_NEG_INF 2
#define division_by_0 3
#define S21_MAX_UINT 4294967295

int s21_getBit(s21_decimal d, int i);
void s21_setBit(s21_decimal *d, int i, int value);
int s21_getScale(const s21_decimal d);
void s21_setScale(s21_decimal *d, int scale);
void s21_check_scale(s21_decimal *value1, s21_decimal *value2);
int s21_getSign(const s21_decimal d);
void s21_setSign(s21_decimal *d, int sign);

void s21_init_decimal(s21_decimal *dec);
int s21_scale_equalization(s21_decimal *value_1, s21_decimal *value_2,
                           int err_num);

void s21_decl_to_null(s21_decimal *decl);
void s21_bits_copy(s21_decimal value, s21_decimal *dest);
int s21_last_bit(s21_decimal value);
void s21_setting(s21_decimal tmp_buf, s21_decimal *tmp_del,
                 s21_decimal *tmp_mod, int *discharge);
int s21_shift_left(s21_decimal *value, int num);
int s21_shift_right(s21_decimal *first, int shift);

int s21_integer_division(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result, s21_decimal *remainder,
                         int error_code);
void s21_first_prepare(s21_decimal tmp_div, s21_decimal *tmp_mod,
                       s21_decimal *tmp_del, s21_decimal value_2,
                       int *discharge);
void s21_first_step(s21_decimal *tmp_div, s21_decimal value_2,
                    int *scale_value1, s21_decimal *tmp_res, int *index_res);
int count_src(float src, char *str_src);

int add(s21_decimal left, s21_decimal right, s21_decimal *result);
void inverse(s21_decimal *value);
s21_decimal s21_div_only_bits(s21_decimal value1, s21_decimal value2,
                              s21_decimal *buf);
int s21_zero_check(s21_decimal value1, s21_decimal value2);
int s21_bit_addition(s21_decimal *value1, s21_decimal *value2,
                     s21_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal, s21_decimal);

void s21_simple_sub(s21_decimal value1, s21_decimal value2,
                    s21_decimal *result);
int s21_simple_add(s21_decimal value1, s21_decimal value2, s21_decimal *result);
s21_decimal s21_simple_div(s21_decimal value1, s21_decimal value2,
                           s21_decimal *result);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int int_get_bit(unsigned int number, int byte);
void int_shift_left(unsigned int *num, int shift, int n);
void int_set_bit(unsigned int *number, int byte, int n);
int div_ten(s21_decimal *number);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

#endif  // SRC_S21_DECIMAL
