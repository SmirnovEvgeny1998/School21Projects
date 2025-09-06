#include "s21_string.h"

#include <getopt.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void s21_clear_string(char *massive) {
  int length = 0;
  if (massive != s21_NULL) {
    length = s21_strlen(massive);
    for (int i = 0; i < length; i++) {
      massive[i] = '\0';
    }
  }
}

s21_size_t s21_strlen(const char *massive) {
  s21_size_t counter = 0;
  while (massive[counter] != '\0') {
    counter++;
  }
  return counter;
}

void s21_strcpy(char *massive_1, char *massive_2) {
  int length_2 = 0;
  length_2 = s21_strlen(massive_2);
  s21_clear_string(massive_1);
  for (int i = 0; i < length_2; i++) {
    massive_1[i] = massive_2[i];
    if (i == length_2 - 1) {
      massive_1[i + 1] = '\0';
    }
  }
}

void s21_strcat(char *massive_1, char *massive_2) {
  int length_1 = 0, length_2 = 0;
  length_1 = s21_strlen(massive_1);
  length_2 = s21_strlen(massive_2);
  for (int i = 0; i < length_2; i++) {
    massive_1[length_1 + i] = massive_2[i];
    if (i == length_2 - 1) {
      massive_1[length_1 + i + 1] = '\0';
    }
  }
}

char *s21_strchr(const char *massive_1, int char_1) {
  char *result = s21_NULL;
  int length = 0;
  length = s21_strlen(massive_1);
  for (int i = 0; i < length; i++) {
    if (massive_1[i] == char_1 && result == s21_NULL) {
      result = (char *)massive_1 + i;
    }
  }
  return result;
}

char *s21_strstr(const char *massive_1, const char *massive_2) {
  char *result = s21_NULL;
  int length_1 = 0, length_2 = 0;
  length_1 = s21_strlen(massive_1);
  length_2 = s21_strlen(massive_2);
  if (length_2 == 0) {
    result = (char *)massive_1;
  } else {
    for (int i = 0; i < length_1; i++) {
      if (massive_1[i] == massive_2[0] && result == s21_NULL) {
        result = (char *)massive_1 + i;
        for (int j = 0; j < length_2; j++) {
          if (massive_1[i + j] == massive_2[j] && result != s21_NULL &&
              massive_1[i + j] != '\0') {
            continue;
          } else {
            result = s21_NULL;
          }
        }
      }
    }
  }
  return result;
}

char *s21_strtok(char *massive_1, const char *massive_2) {
  char *spanp = {'\0'};
  int c = 0, sc = 0;
  char *tok = s21_NULL;
  static char *last = s21_NULL;
  int stop = 0, up_stop = 0;
  if (massive_1 == s21_NULL && (massive_1 = last) == s21_NULL)
    return (s21_NULL);
  while (up_stop == 0) {
    c = *massive_1++;
    stop = 0;
    for (spanp = (char *)massive_2; (sc = *spanp++) != 0 && stop == 0;) {
      if (c == sc) {
        stop = 1;
      }
    }
    if (stop != 1) {
      up_stop = 1;
    }
  }
  if (c == 0) {
    last = s21_NULL;
    return (s21_NULL);
  }
  tok = massive_1 - 1;
  for (;;) {
    c = *massive_1++;
    spanp = (char *)massive_2;
    do {
      if ((sc = *spanp++) == c) {
        if (c == 0)
          massive_1 = s21_NULL;
        else {
          massive_1[-1] = 0;
        }
        last = massive_1;
        return (tok);
      }
    } while (sc != 0);
  }
}

void *s21_memchr(const void *massive_1, int char_1,
                 s21_size_t number_of_bytes) {
  char *result = s21_NULL;
  for (s21_size_t i = 0; i < number_of_bytes && result == s21_NULL; i++) {
    if (*((char *)massive_1 + i) == char_1) {
      result = ((char *)massive_1 + i);
    }
  }
  return result;
}

int s21_memcmp(const void *massive_1, const void *massive_2,
               s21_size_t number_of_bytes) {
  int result = 0, exit = 0;
  for (s21_size_t i = 0; i < number_of_bytes && exit == 0; i++) {
    if (*((char *)massive_1 + i) != *((char *)massive_2 + i)) {
      if (*((char *)massive_1 + i) > *((char *)massive_2 + i)) {
        result = 1;
      } else if (*((char *)massive_1 + i) < *((char *)massive_2 + i)) {
        result = -1;
      }
      exit = 1;
    }
  }
  return result;
}

void *s21_memcpy(void *massive_1, const void *massive_2,
                 s21_size_t number_of_bytes) {
  for (s21_size_t i = 0; i < number_of_bytes; i++) {
    *((char *)massive_1 + i) = *((char *)massive_2 + i);
  }
  return massive_1;
}

void *s21_memset(void *massive_1, int char_1, s21_size_t number_of_bytes) {
  for (s21_size_t i = 0; i < number_of_bytes; i++) {
    *((char *)massive_1 + i) = char_1;
  }
  return massive_1;
}

char *s21_strpbrk(const char *massive_1, const char *massive_2) {
  char *result = s21_NULL;
  int length_1 = 0, length_2 = 0;
  length_1 = s21_strlen(massive_1);
  length_2 = s21_strlen(massive_2);
  for (int i = 0; i < length_1; i++) {
    for (int j = 0; j < length_2; j++) {
      if (massive_1[i] == massive_2[j] && result == s21_NULL) {
        result = (char *)massive_1 + i;
      }
    }
  }
  return result;
}

char *s21_strrchr(const char *massive_1, int char_1) {
  char *result = s21_NULL;
  int length = 0;
  length = s21_strlen(massive_1);
  for (int i = 0; i < length; i++) {
    if (massive_1[i] == char_1) {
      result = (char *)massive_1 + i;
    }
  }
  return result;
}

char *s21_strerror(int number) {
  char *result = s21_NULL;
  char basic_error_1[100] = {'\0'}, basic_error_2[100] = {'\0'};
  if (number >= MAX_ERRNUM || number <= MIN_ERRNUM) {
    s21_strcpy(basic_error_1, BASIC_ERROR);
    s21_sprintf(basic_error_2, "%d", number);
    s21_strcat(basic_error_1, basic_error_2);
    result = basic_error_1;
  } else {
    result = maserror[number];
  }
  return result;
}

char *s21_strncat(char *massive_1, char *massive_2, int number) {
  int length_1 = 0;
  length_1 = s21_strlen(massive_1);
  for (int i = 0; i < number; i++) {
    massive_1[length_1 + i] = massive_2[i];
    if (i == number - 1) {
      massive_1[length_1 + i + 1] = '\0';
    }
  }
  return massive_1;
}

int s21_strncmp(char *massive_1, char *massive_2, int number) {
  int length_1 = -1, length_2 = -1;
  int result = 0;
  length_1 = s21_strlen(massive_1);
  length_2 = s21_strlen(massive_2);
  if (length_1 == 0 && length_2 == 0) {
    result = 0;
  } else if (length_1 == 0) {
    result = 0 - massive_2[0];
  } else if (length_2 == 0) {
    result = massive_1[0];
  } else {
    for (int i = 0; i < number; i++) {
      if (massive_1[i] == massive_2[i] && result == 0) {
        result = 0;
      } else if (massive_1[i] != massive_2[i] && result == 0) {
        result = massive_1[i] - massive_2[i];
      }
    }
  }
  return result;
}

char *s21_strncpy(char *massive_1, char *massive_2, int number) {
  for (int i = 0; i < number; i++) {
    massive_1[i] = massive_2[i];
  }
  return massive_1;
}

s21_size_t s21_strcspn(char *massive_1, char *massive_2) {
  int length_1 = 0, length_2 = 0, end = 0;
  s21_size_t result = -1;
  length_1 = s21_strlen(massive_1);
  length_2 = s21_strlen(massive_2);
  for (int i = 0; i < length_1 + 1 && end == 0; i++) {
    result++;
    for (int j = 0; j < length_2 && end == 0; j++) {
      if (massive_1[i] == massive_2[j]) {
        end = 1;
      }
    }
  }
  return result;
}

int s21_sprintf(char *buffer, char *format, ...) {
  specifier_parameters parameters = {0};
  va_list specifier_arg = {0};
  va_start(specifier_arg, format);
  long int chosen_number = 0, length_format = s21_strlen(format),
           unexpected_type = 0;
  char long_char[2] = {'\0'}, *buffer_pointer = buffer;
  long double chosen_float = 1.0, e_param = 1.0;
  for (int i = 0; i < length_format; i++) {
    if (format[i] == '%' && unexpected_type == 0) {
      s21_sprintf_branch_top(&parameters, format, &i, &unexpected_type);
      if (parameters.asterisk == 1 && parameters.point != 1)
        parameters.number = va_arg(specifier_arg, int);
      if (parameters.asterisk == 1 && parameters.point == 1)
        parameters.point_number = va_arg(specifier_arg, int);
      if (parameters.type == 'c') {
        buffer_pointer =
            s21_sprintf_c_branch(parameters, long_char, buffer_pointer,
                                 va_arg(specifier_arg, void *));
      } else if (parameters.type == 'd' || parameters.type == 'u' ||
                 parameters.type == 'x' || parameters.type == 'X' ||
                 parameters.type == 'o' || parameters.type == 'p') {
        buffer_pointer =
            s21_all_branches(buffer_pointer, chosen_number, parameters,
                             va_arg(specifier_arg, void *));
      } else if (parameters.type == 'f') {
        chosen_float = s21_check_L_parametr(parameters, specifier_arg);
        buffer_pointer =
            s21_sprintf_f_branch(parameters, chosen_float, buffer_pointer);
      } else if (parameters.type == 's') {
        void *string = va_arg(specifier_arg, void *);
        buffer_pointer =
            s21_sprintf_s_branch(parameters, string, buffer_pointer);
      } else if (parameters.type == 'e' || parameters.type == 'E') {
        e_param = s21_check_L_parametr(parameters, specifier_arg);
        buffer_pointer =
            s21_sprintf_eE_branch(parameters, e_param, buffer_pointer);
      } else if (parameters.type == 'g' || parameters.type == 'G') {
        chosen_float = s21_check_L_parametr(parameters, specifier_arg);
        buffer_pointer =
            s21_sprintf_gG_branch(parameters, chosen_float, buffer_pointer);
      }
    } else {
      *buffer_pointer = format[i];
      buffer_pointer++;
    }
  }
  va_end(specifier_arg);
  return s21_strlen(buffer);
}

void s21_search_parameters(specifier_parameters *parameters, char *format,
                           int *i) {
  int search = 1;
  s21_reset_parameters(parameters);
  while (search) {
    *i = *i + 1;
    if (format[*i] == '-') {
      parameters->minus = 1;
    } else if (format[*i] == '+') {
      parameters->plus = 1;
    } else if (format[*i] == ' ') {
      parameters->space = 1;
    } else if (format[*i] == '0') {
      parameters->zero = 1;
    } else if (format[*i] == '#') {
      parameters->hashtag = 1;
    } else if (format[*i] == '*') {
      parameters->asterisk = 1;
    } else if (format[*i] == '.') {
      parameters->point = 1;
      if (format[*i + 1] == '*') {
        parameters->asterisk = 1;
        *i = *i + 1;
      } else if (format[*i + 1] < '0' || format[*i + 1] > '9') {
        parameters->point_number = 0;
      } else {
        *i = *i + 1;
        parameters->point_number = s21_search_length(format, i);
      }
    } else if (format[*i] == 'h') {
      parameters->h = 1;
    } else if (format[*i] == 'L') {
      parameters->L = 1;
    } else if (format[*i] == 'l') {
      parameters->l = 1;
      if (format[*i + 1] == 'l') parameters->l = 2;
    } else {
      if (format[*i] >= '0' && format[*i] <= '9') {
        parameters->number = s21_search_length(format, i);
      } else {
        search = 0;
      }
    }
  }
}

int s21_search_specifier_type(char specifier_type,
                              specifier_parameters *parameters) {
  int unexpected_type = 0;
  if (specifier_type == 'c') {
    parameters->type = 'c';
  } else if (specifier_type == 'd') {
    parameters->type = 'd';
  } else if (specifier_type == 'f') {
    parameters->type = 'f';
  } else if (specifier_type == 's') {
    parameters->type = 's';
  } else if (specifier_type == 'u') {
    parameters->type = 'u';
  } else if (specifier_type == 'e') {
    parameters->type = 'e';
  } else if (specifier_type == 'E') {
    parameters->type = 'E';
  } else if (specifier_type == 'g') {
    parameters->type = 'g';
  } else if (specifier_type == 'G') {
    parameters->type = 'G';
  } else if (specifier_type == 'x') {
    parameters->type = 'x';
  } else if (specifier_type == 'X') {
    parameters->type = 'X';
  } else if (specifier_type == 'o') {
    parameters->type = 'o';
  } else if (specifier_type == 'p') {
    parameters->type = 'p';
  } else {
    unexpected_type = 1;
  }
  return unexpected_type;
}

int s21_search_length(char *format, int *i) {
  int length = 0;
  length = format[*i] - 48;
  while (format[*i + 1] >= '0' && format[*i + 1] <= '9') {
    length = length * 10 + (format[*i + 1] - 48);
    *i = *i + 1;
  }
  return length;
}

void s21_reset_parameters(specifier_parameters *parameters) {
  parameters->minus = -1;
  parameters->plus = -1;
  parameters->space = -1;
  parameters->hashtag = -1;
  parameters->zero = -1;
  parameters->number = -1;
  parameters->asterisk = -1;
  parameters->point = -1;
  parameters->point_number = 6;
  parameters->h = -1;
  parameters->l = -1;
  parameters->L = -1;
  parameters->type = ' ';
}

void s21_sprintf_int(char *massive, specifier_parameters flags,
                     long int number) {
  int number_length = s21_number_lenght(number);
  if (number_length < flags.number) {
    if (flags.minus != 1) {
      s21_sprintf_int_before_after(flags, massive, number, 1);
    } else {
      s21_sprintf_int_before_after(flags, massive, number, 2);
    }
  } else {
    s21_sprintf_int_before_after(flags, massive, number, 3);
  }
}

void s21_sprintf_int_before_after(specifier_parameters flags, char *massive,
                                  long int number, int before_after) {
  int number_length = s21_number_lenght(number);
  char *pointer = massive, string_number[21] = {'\0'};
  if (before_after == 1) {
    if (number < 0 || flags.plus == 1 || flags.space == 1) {
      flags.number = flags.number - 1;
    }
    pointer += s21_equalizer(flags, number_length, pointer);
    s21_int_to_string(number, string_number, number_length, -1);
    if (s21_before_number(flags.space, flags.plus, pointer, number) == 1) {
      pointer++;
    }
    for (int j = 0; j < number_length; j++) {
      *pointer = string_number[j];
      pointer++;
    }
  } else if (before_after == 2) {
    if (number < 0 || flags.plus == 1 || flags.space == 1) {
      flags.number = flags.number - 1;
    }
    if (s21_before_number(flags.space, flags.plus, pointer, number) == 1) {
      pointer++;
    }
    s21_int_to_string(number, string_number, number_length, -1);
    for (int j = 0; j < number_length; j++) {
      *pointer = string_number[j];
      pointer++;
    }
    pointer += s21_equalizer(flags, number_length, pointer);
  } else {
    if (number < 0 || flags.plus == 1 || flags.space == 1) {
      flags.number = flags.number - 1;
    }
    if (s21_before_number(flags.space, flags.plus, pointer, number) == 1) {
      pointer++;
    }
    s21_int_to_string(number, string_number, number_length, -1);
    pointer += s21_equalizer(flags, number_length, pointer);
    for (int j = 0; j < number_length; j++) {
      *pointer = string_number[j];
      pointer++;
    }
  }
}

int s21_number_lenght(long int number) {
  long int absolute_num = 0;
  int result = 1;
  if (number < 0)
    absolute_num = -number;
  else
    absolute_num = number;
  if (absolute_num >= 0 && absolute_num < 10)
    result = 1;
  else if (absolute_num >= 10 && absolute_num < 100)
    result = 2;
  else if (absolute_num >= 100 && absolute_num < 1000)
    result = 3;
  else if (absolute_num >= 1000 && absolute_num < 10000)
    result = 4;
  else if (absolute_num >= 10000 && absolute_num < 100000)
    result = 5;
  else if (absolute_num >= 100000 && absolute_num < 1000000)
    result = 6;
  else if (absolute_num >= 1000000 && absolute_num < 10000000)
    result = 7;
  else if (absolute_num >= 10000000 && absolute_num < 100000000)
    result = 8;
  else if (absolute_num >= 100000000 && absolute_num < 1000000000)
    result = 9;
  else if (absolute_num >= 1000000000 && absolute_num < 10000000000)
    result = 10;
  else if (absolute_num >= 10000000000 && absolute_num < 100000000000)
    result = 11;
  else if (absolute_num >= 100000000000 && absolute_num < 1000000000000)
    result = 12;
  else if (absolute_num >= 1000000000000 && absolute_num < 10000000000000)
    result = 13;
  else if (absolute_num >= 10000000000000 && absolute_num < 100000000000000)
    result = 14;
  else if (absolute_num >= 100000000000000 && absolute_num < 1000000000000000)
    result = 15;
  else if (absolute_num >= 1000000000000000 && absolute_num < 10000000000000000)
    result = 16;
  else if (absolute_num >= 10000000000000000 &&
           absolute_num < 100000000000000000)
    result = 17;
  else if (absolute_num >= 100000000000000000 &&
           absolute_num < 1000000000000000000)
    result = 18;
  else if (absolute_num >= 1000000000000000000)
    result = 19;
  return result;
}

void s21_int_to_string(long int number, char *massive, int number_length,
                       int decimal) {
  long int copy_number = number;
  if (copy_number < 0) {
    copy_number = -number;
  }
  for (int i = 0; i < number_length; i++) {
    if (number_length - i == number_length - decimal) {
      massive[number_length - 1 - i] = '.';
    } else {
      massive[number_length - 1 - i] = copy_number % 10 + '0';
      copy_number = copy_number / 10;
    }
  }
}

int s21_before_number(int spase, int plus_minus, char *pointer,
                      long int number) {
  int result = 0;
  if (plus_minus == 1 || number < 0) {
    if (number < 0) {
      *pointer = '-';
      result = 1;
    } else {
      *pointer = '+';
      result = 1;
    }
  } else if (spase == 1) {
    *pointer = ' ';
    result = 1;
  }
  return result;
}

void s21_sprintf_string(char *massive, specifier_parameters flags,
                        char *string) {
  int string_length = s21_strlen(string);
  if (string_length < flags.number) {
    if (flags.minus != 1) {
      s21_sprintf_str_before_after(flags, massive, string, 1);
    } else {
      s21_sprintf_str_before_after(flags, massive, string, 2);
    }
  } else {
    s21_sprintf_str_before_after(flags, massive, string, 3);
  }
}

int s21_equalizer(specifier_parameters flags, int number_length,
                  char *pointer) {
  int result = 0;
  if (flags.zero == 1 ||
      (flags.point == 1 && flags.hashtag != 1 &&
       (flags.type == 'd' || flags.type == 'i' || flags.type == 'o' ||
        flags.type == 'u' || flags.type == 'x' || flags.type == 'X'))) {
    if (flags.number < flags.point_number) {
      flags.number = flags.point_number;
    }
    for (int i = 0; i < (flags.number - number_length); i++) {
      *pointer = '0';
      pointer++;
      result++;
    }
  } else {
    for (int i = 0; i < flags.number - number_length; i++) {
      *pointer = ' ';
      pointer++;
      result++;
    }
  }
  return result;
}

void s21_sprintf_str_before_after(specifier_parameters flags, char *massive,
                                  char *string, int before_after) {
  char *pointer = massive;
  int string_length = s21_strlen(string);
  if (before_after == 1) {
    pointer += s21_equalizer(flags, string_length, pointer);
    for (int j = 0; j < string_length && j < flags.point_number; j++) {
      *pointer = string[j];
      pointer++;
    }
  } else if (before_after == 2) {
    for (int j = 0; j < string_length && j < flags.point_number; j++) {
      *pointer = string[j];
      pointer++;
    }
    pointer += s21_equalizer(flags, string_length, pointer);
  } else {
    for (int j = 0; j < string_length && j < flags.point_number; j++) {
      *pointer = string[j];
      pointer++;
    }
  }
}

void s21_sprintf_float(char *massive, specifier_parameters flags,
                       double number) {
  int break_w = 0;
  double copy_number = number;
  while (copy_number - floor(copy_number) > 0.000001 && break_w == 0) {
    copy_number *= 10;
    if (copy_number - floor(copy_number) > 0.999999) {
      break_w = 1;
    }
  }
  int number_length = s21_number_lenght((long int)copy_number) + 1;
  if (number_length < flags.number) {
    if (flags.minus != 1) {
      s21_sprintf_flo_before_after(flags, massive, number, 1);
    } else {
      s21_sprintf_flo_before_after(flags, massive, number, 2);
    }
  } else {
    s21_sprintf_flo_before_after(flags, massive, number, 3);
  }
}

void s21_sprintf_flo_before_after(specifier_parameters flags, char *massive,
                                  double number, int before_after) {
  int decimals = 0;
  double copy_number = number;
  if (number < 0) {
    copy_number = -number;
  }
  while (copy_number - (long int)copy_number > 0.000001) {
    copy_number *= 10;
    decimals++;
  }
  if (number < 0) {
    copy_number = -copy_number;
  }
  int number_length = s21_number_lenght((long int)copy_number) + 1;
  if (number < 1 && number > 0) {
    number_length++;
  }
  if (number > -1 && number < 0) {
    number_length++;
  }
  char *pointer = massive, string_number[21] = {'\0'};
  if (before_after == 1) {
    s21_sprintf_flo_before_after_branch_1(flags, pointer, number, copy_number,
                                          string_number, decimals,
                                          number_length);
  } else if (before_after == 2) {
    s21_sprintf_flo_before_after_branch_2(flags, pointer, number, copy_number,
                                          string_number, decimals,
                                          number_length);
  } else {
    s21_sprintf_flo_before_after_branch_3(flags, pointer, number, copy_number,
                                          string_number, decimals,
                                          number_length);
  }
}

void s21_if_previous_more_than_4(char *pointer, int number) {
  pointer--;
  if (*pointer == '9' && number > 0) {
    *pointer = '0';
    s21_if_previous_more_than_4(pointer, number - 1);
  } else if (*pointer == '.' && number > 0) {
    s21_if_previous_more_than_4(pointer, number - 1);
  } else if (number > 0) {
    *pointer += 1;
  }
  pointer++;
}

void s21_format_float_to_e(double decimal, specifier_parameters parametr,
                           char *result) {
  double abs_decimal = 0;
  long int copy_decimal = s21_float_to_int(decimal);
  char string_decimal[200] = {'\0'}, string_shift[200] = {'\0'},
       *pointer = result;
  int shift_number = 0;
  s21_int_to_string(copy_decimal, string_decimal,
                    s21_number_lenght(copy_decimal), -1);
  if (decimal >= 0) {
    abs_decimal = decimal;
    while (decimal < 1 || decimal >= 10) {
      if (decimal < 1) {
        decimal *= 10;
        shift_number++;
      } else {
        decimal /= 10;
        shift_number++;
      }
    }
  } else {
    abs_decimal = -decimal;
    shift_number = -shift_number;
    while (decimal > -1 || decimal <= -10) {
      if (decimal > -1) {
        decimal *= 10;
        shift_number++;
      } else {
        decimal /= 10;
        shift_number++;
      }
    }
  }
  if (decimal < 0 || parametr.plus == 1 || parametr.space == 1) {
    if (decimal < 0) {
      *pointer = '-';
    } else if (parametr.plus == 1) {
      *pointer = '+';
    } else if (parametr.space == 1) {
      *pointer = ' ';
    }
    pointer++;
  }
  s21_format_float_to_e_branch_1(abs_decimal, shift_number, parametr, pointer,
                                 string_decimal, string_shift, copy_decimal);
}

long int s21_float_to_int(double number) {
  double copy_number = number;
  int decimals = 0;
  if (number < 0) {
    copy_number = -number;
  }
  while (copy_number - (long int)copy_number > 0.000001) {
    copy_number *= 10;
    decimals++;
  }
  if (number < 0) {
    copy_number = -copy_number;
  }
  return (long int)copy_number;
}

void s21_int_to_sixteen(long int number, char *massive,
                        specifier_parameters parametr) {
  char reverse_transition[200] = {'\0'}, buffer[3] = {'\0'};
  int remainder = 15, transition_counter = 0;
  while (number != 0) {
    remainder = number % 16;
    number = number / 16;
    s21_int_to_string(remainder, buffer, s21_number_lenght(remainder), -1);
    if (s21_strlen(buffer) != 1) {
      s21_ten_to_A(buffer, parametr.type);
      reverse_transition[transition_counter] = buffer[0];
      transition_counter++;
    } else {
      reverse_transition[transition_counter] = buffer[0];
      transition_counter++;
    }
  }
  if (parametr.hashtag == 1) {
    massive += s21_hashtag(parametr, massive);
  }
  for (int i = 0; i < (int)s21_strlen(reverse_transition); i++) {
    transition_counter--;
    massive[i] = reverse_transition[transition_counter];
  }
}

void s21_ten_to_A(char *massive, char type) {
  int ascii_plus = 0;
  if (type == 'x') {
    ascii_plus = 32;
  }
  if (massive[1] == '0') {
    massive[0] = '\0';
    massive[1] = '\0';
    massive[0] = 'A' + ascii_plus;
  } else if (massive[1] == '1') {
    massive[0] = '\0';
    massive[1] = '\0';
    massive[0] = 'B' + ascii_plus;
  } else if (massive[1] == '2') {
    massive[0] = '\0';
    massive[1] = '\0';
    massive[0] = 'C' + ascii_plus;
  } else if (massive[1] == '3') {
    massive[0] = '\0';
    massive[1] = '\0';
    massive[0] = 'D' + ascii_plus;
  } else if (massive[1] == '4') {
    massive[0] = '\0';
    massive[1] = '\0';
    massive[0] = 'E' + ascii_plus;
  } else if (massive[1] == '5') {
    massive[0] = '\0';
    massive[1] = '\0';
    massive[0] = 'F' + ascii_plus;
  }
}

void s21_int_to_eight(long int number, char *massive,
                      specifier_parameters parameters) {
  char reverse_transition[200] = {'\0'}, buffer[3] = {'\0'};
  int remainder = 7, transition_counter = 0;
  while (number != 0) {
    remainder = number % 8;
    number = number / 8;
    s21_int_to_string(remainder, buffer, s21_number_lenght(remainder), -1);
    reverse_transition[transition_counter] = buffer[0];
    transition_counter++;
  }
  if (parameters.hashtag == 1) {
    massive += s21_hashtag(parameters, massive);
  }
  for (int i = 0; i < (int)s21_strlen(reverse_transition); i++) {
    transition_counter--;
    massive[i] = reverse_transition[transition_counter];
  }
}

void s21_pointer_to_string(char *massive, void *pointer) {
  intptr_t p = (intptr_t)pointer;
  char s[2 * sizeof(p)] = {'\0'}, copy_massive[200] = {'\0'};
  for (int i = 2 * sizeof(p) - 1; i >= 0; --i) {
    s[i] = "0123456789abcdef"[p & 0x0F];
    p >>= 4;
  }
  for (long unsigned int i = 0; i < 2 * sizeof(p); ++i) {
    copy_massive[i] = s[i];
  }
  massive[0] = '0';
  massive[1] = 'x';
  for (int i = 0; i < 12; i++) {
    massive[i + 2] = copy_massive[i + 4];
  }
}

int s21_hashtag(specifier_parameters parameters, char *massive) {
  int result = 0;
  if (parameters.type == 'o') {
    *massive = '0';
    result = 1;
  } else if (parameters.type == 'x') {
    *massive = '0';
    massive++;
    *massive = 'x';
    result = 2;
  } else if (parameters.type == 'X') {
    *massive = '0';
    massive++;
    *massive = 'X';
    result = 2;
  }
  return result;
}

int s21_check_next_n(char *massive, int number) {
  int result = 1;
  for (int i = 0; i < number; i++) {
    if (massive[i] != '0') {
      result = 0;
    }
  }
  return result;
}

void s21_trim_string(char *massive, specifier_parameters parameters) {
  int counter = 0, point_appeared = 0, after_pointer = 0;
  char temp = massive[0];
  while (temp != '\0') {
    if (temp != '.' && point_appeared == 0) {
      counter++;
      counter--;
    } else {
      point_appeared = 1;
    }
    if (point_appeared == 1) {
      if (parameters.point_number > after_pointer && massive[counter] == '.') {
        after_pointer++;
        after_pointer--;
      } else if (parameters.point_number > after_pointer) {
        after_pointer++;
      } else if (parameters.point_number == after_pointer &&
                 massive[counter] >= '5' && massive[counter] <= '9') {
        s21_if_previous_more_than_4(&massive[counter], s21_strlen(massive));
        char temp_string[1000] = "1";
        if (massive[0] == '0') {
          s21_strcat(temp_string, massive);
          s21_strcpy(massive, temp_string);
          counter++;
        }
        after_pointer++;
        massive[counter] = '\0';
      } else {
        after_pointer++;
        massive[counter] = '\0';
      }
    }
    counter++;
    temp = massive[counter];
  }
}

int s21_sscanf(char *buffer, char *format, ...) {
  specifier_parameters parameters = {0};
  va_list specifier_arg = {0};
  va_start(specifier_arg, format);
  int length_format = s21_strlen(format), unexpected_type = 0,
      *d_adress = s21_NULL, parameters_counter = 0;
  long double *f_adress = s21_NULL;
  double *d_f_adress = s21_NULL;
  float *s_f_adress = s21_NULL;
  void **p_adress = s21_NULL;
  char temp_string[10000] = {'\0'}, *buffer_pointer = buffer;
  for (int i = 0; i < length_format; i++) {
    if (format[i] == '%' && unexpected_type == 0) {
      s21_reset_parameters(&parameters);
      s21_clear_string(temp_string);
      s21_search_parameters(&parameters, format, &i);
      if (parameters.number == -1) parameters.number = 100000000;
      unexpected_type = s21_search_specifier_type(format[i], &parameters);
      buffer_pointer +=
          s21_get_buffer_string(parameters, buffer_pointer, temp_string);
      if ((parameters.type == 'c' || parameters.type == 's' ||
           parameters.type == 'd' || parameters.type == 'u' ||
           parameters.type == 'x' || parameters.type == 'X' ||
           parameters.type == 'o') &&
          parameters.asterisk != 1) {
        s21_sscanf_branch_sc(temp_string, d_adress, parameters,
                             va_arg(specifier_arg, void *));
      } else if ((parameters.type == 'f' || parameters.type == 'e' ||
                  parameters.type == 'E' || parameters.type == 'g' ||
                  parameters.type == 'G') &&
                 parameters.asterisk != 1) {
        if (parameters.L == 1) {
          f_adress = va_arg(specifier_arg, long double *);
          *f_adress = s21_string_to_float(temp_string);
        } else if (parameters.l == 1) {
          d_f_adress = va_arg(specifier_arg, double *);
          *d_f_adress = s21_string_to_float(temp_string);
        } else {
          s_f_adress = va_arg(specifier_arg, float *);
          *s_f_adress = s21_string_to_float(temp_string);
        }
      } else if (parameters.type == 'p' && parameters.asterisk != 1) {
        s21_sscanf_get_p_adress(p_adress, specifier_arg, temp_string);
      }
      if (parameters.asterisk != 1) parameters_counter++;
    }
  }
  va_end(specifier_arg);
  return parameters_counter;
}

void s21_sscanf_get_p_adress(void **p_adress, va_list specifier_arg,
                             char temp_string[10000]) {
  p_adress = va_arg(specifier_arg, void *);
  *p_adress = 0;
  if (temp_string[0] == '0' && temp_string[1] == 'x')
    *p_adress += s21_sixteen_to_int(temp_string + 2);
  else
    *p_adress += s21_sixteen_to_int(temp_string);
}

int s21_get_buffer_string(specifier_parameters parameters, char *pointer,
                          char *massive) {
  int result = 0;
  if (parameters.type == 'c' || parameters.type == 'd' ||
      parameters.type == 'u' || parameters.type == 'f' ||
      parameters.type == 'e' || parameters.type == 'E' ||
      parameters.type == 'g' || parameters.type == 'G' ||
      parameters.type == 's') {
    result =
        s21_get_buffer_string_branch_1(parameters, pointer, massive, result);
  } else {
    result =
        s21_get_buffer_string_branch_2(parameters, pointer, massive, result);
  }
  return result;
}

int s21_string_to_int(char *massive) {
  int length = s21_strlen(massive), result = 0, minus = 1;
  for (int i = 0; i < length; i++) {
    if (*massive != '-') {
      result += *massive - 48;
    } else {
      minus = -1;
    }
    if (i + 1 != length && *massive != '-') {
      result *= 10;
    }
    massive++;
  }
  result *= minus;
  return result;
}

long double s21_string_to_float(char *massive) {
  int length = s21_strlen(massive);
  long double result = 0.0, decimal = 1, minus = 1;
  for (int i = 0; i < length; i++) {
    if (*massive != '.' && *massive != '-') {
      result += (*massive - 48) * decimal;
      if (decimal != 1) {
        decimal *= 0.1;
      }
    } else if (*massive == '-') {
      minus = -1;
    } else {
      decimal *= 0.1;
    }
    if (i + 1 != length && decimal == 1 && *(massive + 1) != '.') {
      result *= 10;
    }
    massive++;
  }
  result *= minus;
  return result;
}

long unsigned int s21_sixteen_to_int(char *massive) {
  long unsigned int length = s21_strlen(massive), temp = 0;
  long unsigned int result = 0;
  for (int i = 0; i < (int)length; i++) {
    if (massive[i] >= '0' && massive[i] <= '9') {
      temp = massive[i] - 48;
    } else if (massive[i] >= 'A' && massive[i] <= 'F') {
      temp = massive[i] - 55;
    } else {
      temp = massive[i] - 87;
    }
    for (int j = 0; j < (int)length - 1 - i; j++) {
      temp *= 16;
    }
    result += temp;
  }
  return result;
}

long unsigned int s21_eight_to_int(char *massive) {
  long unsigned int length = s21_strlen(massive), temp = 0;
  long unsigned int result = 0;
  for (int i = 0; i < (int)length; i++) {
    if (massive[i] >= '0' && massive[i] <= '9') {
      temp = massive[i] - 48;
    } else if (massive[i] >= 'A' && massive[i] <= 'F') {
      temp = massive[i] - 55;
    } else {
      temp = massive[i] - 87;
    }
    for (int j = 0; j < (int)length - 1 - i; j++) {
      temp *= 8;
    }
    result += temp;
  }
  return result;
}

void *s21_to_upper(const char *str) {
  char *up_massive = s21_NULL;
  up_massive = malloc(10000 * sizeof(char));
  for (int i = 0; i < 10000; i++) {
    up_massive[i] = '\0';
  }
  for (int i = 0; i < (int)s21_strlen(str); i++) {
    up_massive[i] = str[i];
    if (i == (int)s21_strlen(str) - 1) {
      up_massive[i + 1] = '\0';
    }
  }
  for (int i = 0; i < (int)s21_strlen(str); i++) {
    if (up_massive[i] >= 'a' && up_massive[i] <= 'z') {
      up_massive[i] -= 32;
    }
  }
  return up_massive;
}

void *s21_to_lower(const char *str) {
  char *up_massive = s21_NULL;
  up_massive = malloc(10000 * sizeof(char));
  for (int i = 0; i < 10000; i++) {
    up_massive[i] = '\0';
  }
  for (int i = 0; i < (int)s21_strlen(str); i++) {
    up_massive[i] = str[i];
    if (i == (int)s21_strlen(str) - 1) {
      up_massive[i + 1] = '\0';
    }
  }
  for (int i = 0; i < (int)s21_strlen(str); i++) {
    if (up_massive[i] >= 'A' && up_massive[i] <= 'Z') {
      up_massive[i] += 32;
    }
  }
  return up_massive;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *up_massive = s21_NULL;
  up_massive = malloc(10000 * sizeof(char));
  for (int i = 0; i < 10000; i++) {
    up_massive[i] = '\0';
  }
  int string_len = 0;
  s21_clear_string(up_massive);
  for (int i = 0; i < (int)s21_strlen(src) + (int)s21_strlen(str); i++) {
    if (i >= (int)start_index && i < (int)s21_strlen(str) + (int)start_index) {
      up_massive[i] = str[string_len];
      string_len++;
    } else {
      up_massive[i] = src[i - string_len];
    }
  }
  return up_massive;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *up_massive = s21_NULL;
  up_massive = malloc(10000 * sizeof(char));
  for (int i = 0; i < 10000; i++) {
    up_massive[i] = '\0';
  }
  int error = 1, stop = 0, counter = 0;
  s21_clear_string(up_massive);
  for (int i = 0; i < (int)s21_strlen(src); i++) {
    error = 1;
    for (int j = 0; j < (int)s21_strlen(trim_chars) && stop == 0; j++) {
      if (src[i] == trim_chars[j]) {
        error = 0;
        counter++;
      }
    }
    if (error == 1) {
      stop = 1;
      up_massive[i - counter] = src[i];
      if (i == (int)s21_strlen(src) - 1) {
        up_massive[i + 1] = '\0';
      }
    }
  }
  counter = 0;
  stop = 0;
  int length = s21_strlen(up_massive);
  for (int i = 0; i < length && stop == 0; i++) {
    error = 1;
    for (int j = 0; j < (int)s21_strlen(trim_chars); j++) {
      if (up_massive[length - 1 - i] == trim_chars[j]) {
        error = 0;
        up_massive[length - 1 - i] = '\0';
      }
    }
    if (error == 1) {
      stop = 1;
    }
  }
  return up_massive;
}

char *s21_sprintf_c_branch(specifier_parameters parameters, char *long_char,
                           char *buffer_pointer, ...) {
  va_list specifier_arg = {0};
  va_start(specifier_arg, buffer_pointer);
  wchar_t randon = L'\0';
  if (parameters.l != 1) {
    long_char[0] = va_arg(specifier_arg, int);
  } else {
    randon = va_arg(specifier_arg, wchar_t);
    wctomb(long_char, randon);
  }
  s21_sprintf_string(buffer_pointer, parameters, long_char);
  buffer_pointer += 1;
  if (parameters.number != 1) {
    buffer_pointer += parameters.number - 1;
  }
  va_end(specifier_arg);
  return buffer_pointer;
}

char *s21_sprintf_d_branch(specifier_parameters parameters,
                           long int chosen_number, char *buffer_pointer, ...) {
  va_list specifier_arg = {0};
  va_start(specifier_arg, buffer_pointer);
  if (parameters.l == 1) {
    chosen_number = va_arg(specifier_arg, long int);
  } else if (parameters.h == 1) {
    chosen_number = va_arg(specifier_arg, int);
    chosen_number = (short int)chosen_number;
  } else {
    chosen_number = va_arg(specifier_arg, int);
  }
  s21_sprintf_int(buffer_pointer, parameters, chosen_number);
  buffer_pointer += s21_strlen(buffer_pointer);
  va_end(specifier_arg);
  return buffer_pointer;
}

char *s21_sprintf_f_branch(specifier_parameters parameters,
                           long double chosen_float, char *buffer_pointer) {
  s21_sprintf_float(buffer_pointer, parameters, chosen_float);
  double copy_float = chosen_float;
  if (copy_float < 0) {
    copy_float = -chosen_float;
  }
  while (copy_float - (long int)copy_float > 0.000001) {
    copy_float *= 10;
  }
  if (parameters.minus == 1 &&
      (int)s21_strlen(buffer_pointer) < parameters.number) {
    int temp = s21_strlen(buffer_pointer);
    buffer_pointer += temp;
    s21_equalizer(parameters, s21_strlen(buffer_pointer), buffer_pointer);
    buffer_pointer += parameters.number - temp;
  } else if (parameters.minus != 1 &&
             (int)s21_strlen(buffer_pointer) < parameters.number) {
    int temp = s21_strlen(buffer_pointer);
    s21_equalizer(parameters, s21_strlen(buffer_pointer), buffer_pointer);
    buffer_pointer += parameters.number - temp;
    s21_strcat(buffer_pointer, buffer_pointer);
    buffer_pointer += temp;
  } else {
    buffer_pointer += s21_strlen(buffer_pointer);
  }
  return buffer_pointer;
}

char *s21_sprintf_s_branch(specifier_parameters parameters, void *string,
                           char *buffer_pointer) {
  char *randon = s21_NULL, giant[100000] = {'\0'};
  wchar_t *randon_t = s21_NULL;
  if (parameters.point != 1) {
    parameters.point_number = 9223372036854775807;
  }
  if (parameters.l != 1) {
    randon = (char *)string;
  } else {
    randon_t = (wchar_t *)string;
    wcstombs(giant, randon_t, 80);
    randon = giant;
  }
  s21_sprintf_string(buffer_pointer, parameters, randon);
  if (parameters.point != 1) {
    parameters.point_number = 9223372036854775807;
    buffer_pointer += s21_strlen(buffer_pointer);
  } else {
    buffer_pointer += parameters.point_number;
  }
  return buffer_pointer;
}

char *s21_sprintf_u_branch(specifier_parameters parameters,
                           long int chosen_number, char *buffer_pointer, ...) {
  va_list specifier_arg = {0};
  va_start(specifier_arg, buffer_pointer);
  if (parameters.l == 1) {
    chosen_number = va_arg(specifier_arg, long int);
  } else if (parameters.h == 1) {
    chosen_number = va_arg(specifier_arg, int);
    chosen_number = (short int)chosen_number;
  } else {
    chosen_number = va_arg(specifier_arg, int);
  }
  s21_sprintf_int(buffer_pointer, parameters, chosen_number);
  buffer_pointer += s21_number_lenght(chosen_number);
  if (parameters.number > s21_number_lenght(chosen_number)) {
    buffer_pointer += parameters.number - s21_number_lenght(chosen_number);
  }
  va_end(specifier_arg);
  return buffer_pointer;
}

char *s21_sprintf_eE_branch(specifier_parameters parameters,
                            long double e_param, char *buffer_pointer) {
  char float_to_e[200] = {'\0'};
  s21_format_float_to_e(e_param, parameters, float_to_e);
  buffer_pointer +=
      s21_equalizer(parameters, s21_strlen(float_to_e), buffer_pointer);
  s21_format_float_to_e(e_param, parameters, buffer_pointer);
  buffer_pointer += s21_strlen(float_to_e);
  return buffer_pointer;
}

char *s21_sprintf_xX_branch(specifier_parameters parameters,
                            char *buffer_pointer, ...) {
  va_list specifier_arg;
  va_start(specifier_arg, buffer_pointer);
  long int sixteen_number = va_arg(specifier_arg, long int);
  char x_flag[200] = {'\0'};
  if (parameters.number > (int)s21_strlen(x_flag) && parameters.minus != 1 &&
      sixteen_number == 0) {
    buffer_pointer +=
        s21_equalizer(parameters, s21_strlen(x_flag), buffer_pointer);
    buffer_pointer--;
    *buffer_pointer = '0';
    buffer_pointer++;
  }
  if (parameters.point == 1) {
    parameters.number = parameters.point_number;
  }
  s21_int_to_sixteen(sixteen_number, x_flag, parameters);
  if (parameters.number > (int)s21_strlen(x_flag) && parameters.minus == 1 &&
      sixteen_number == 0) {
    *buffer_pointer = '0';
    buffer_pointer++;
    buffer_pointer +=
        s21_equalizer(parameters, s21_strlen(x_flag), buffer_pointer);
    buffer_pointer--;
    *buffer_pointer = '\0';
  }
  if (parameters.minus != 1 && sixteen_number != 0) {
    buffer_pointer +=
        s21_equalizer(parameters, s21_strlen(x_flag), buffer_pointer);
  }
  s21_int_to_sixteen(sixteen_number, buffer_pointer, parameters);
  buffer_pointer += s21_strlen(x_flag);
  if (parameters.minus == 1 && sixteen_number != 0) {
    buffer_pointer +=
        s21_equalizer(parameters, s21_strlen(x_flag), buffer_pointer);
  }
  va_end(specifier_arg);
  return buffer_pointer;
}

char *s21_sprintf_o_branch(specifier_parameters parameters,
                           char *buffer_pointer, ...) {
  va_list specifier_arg;
  va_start(specifier_arg, buffer_pointer);
  long int eight_number = va_arg(specifier_arg, long int);
  int eq_result = 0;
  char *eq_pointer = s21_NULL, o_flag[200] = {'\0'};
  s21_int_to_eight(eight_number, o_flag, parameters);
  if (parameters.number > (int)s21_strlen(o_flag) && parameters.minus != 1 &&
      eight_number == 0) {
    buffer_pointer +=
        s21_equalizer(parameters, s21_strlen(o_flag), buffer_pointer);
    buffer_pointer--;
    *buffer_pointer = '0';
    buffer_pointer++;
  }
  s21_int_to_eight(eight_number, buffer_pointer, parameters);
  if (parameters.number > (int)s21_strlen(o_flag) && parameters.minus == 1 &&
      eight_number == 0) {
    *buffer_pointer = '0';
    buffer_pointer++;
    buffer_pointer +=
        s21_equalizer(parameters, s21_strlen(o_flag), buffer_pointer);
    buffer_pointer--;
    *buffer_pointer = '\0';
  }
  if (eight_number != 0) {
    eq_result = s21_equalizer(parameters, s21_strlen(o_flag), buffer_pointer);
    eq_pointer = buffer_pointer + eq_result;
  }
  s21_int_to_eight(eight_number, eq_pointer, parameters);
  buffer_pointer += s21_strlen(o_flag);
  if (parameters.number > (int)s21_strlen(o_flag) && eight_number != 0) {
    buffer_pointer += parameters.number - s21_strlen(o_flag);
  }
  va_end(specifier_arg);
  return buffer_pointer;
}

char *s21_sprintf_p_branch(specifier_parameters parameters,
                           char *buffer_pointer, ...) {
  va_list specifier_arg = {0};
  va_start(specifier_arg, buffer_pointer);
  int eq_result = 0;
  char *eq_pointer = s21_NULL;
  eq_result = s21_equalizer(parameters, 14, buffer_pointer);
  eq_pointer = buffer_pointer;
  s21_pointer_to_string(eq_pointer, va_arg(specifier_arg, void *));
  buffer_pointer += 14 + eq_result;
  va_end(specifier_arg);
  return buffer_pointer;
}

char *s21_sprintf_gG_branch(specifier_parameters parameters,
                            long double chosen_float, char *buffer_pointer) {
  char f_test[200] = {'\0'}, e_test[200] = {'\0'}, temp = parameters.type;
  s21_format_float_to_e(chosen_float, parameters, e_test);
  s21_sprintf_float(f_test, parameters, chosen_float);
  parameters.type = temp;
  if (s21_strlen(f_test) >= s21_strlen(e_test)) {
    s21_format_float_to_e(chosen_float, parameters, buffer_pointer);
    buffer_pointer += s21_strlen(e_test);
  } else {
    s21_sprintf_float(buffer_pointer, parameters, chosen_float);
    double copy_float = chosen_float;
    if (copy_float < 0) {
      copy_float = -chosen_float;
    }
    while (copy_float - (long int)copy_float > 0.000001) {
      copy_float *= 10;
    }
    buffer_pointer += s21_strlen(f_test);
  }
  return buffer_pointer;
}

char *s21_all_branches(char *buffer_pointer, long int chosen_number,
                       specifier_parameters parameters, ...) {
  va_list specifier_arg;
  va_start(specifier_arg, parameters);
  if (parameters.type == 'd') {
    buffer_pointer =
        s21_sprintf_d_branch(parameters, chosen_number, buffer_pointer,
                             va_arg(specifier_arg, void *));
  } else if (parameters.type == 'u') {
    buffer_pointer =
        s21_sprintf_u_branch(parameters, chosen_number, buffer_pointer,
                             va_arg(specifier_arg, void *));
  } else if (parameters.type == 'x' || parameters.type == 'X') {
    buffer_pointer = s21_sprintf_xX_branch(parameters, buffer_pointer,
                                           va_arg(specifier_arg, void *));
  } else if (parameters.type == 'o') {
    buffer_pointer = s21_sprintf_o_branch(parameters, buffer_pointer,
                                          va_arg(specifier_arg, void *));
  } else if (parameters.type == 'p') {
    buffer_pointer = s21_sprintf_p_branch(parameters, buffer_pointer,
                                          va_arg(specifier_arg, void *));
  }
  va_end(specifier_arg);
  return buffer_pointer;
}

void s21_sprintf_flo_before_after_branch_1(specifier_parameters flags,
                                           char *pointer, double number,
                                           double copy_number,
                                           char *string_number, int decimals,
                                           int number_length) {
  if (number < 0 || flags.plus == 1 || flags.space == 1) {
    flags.number = flags.number - 1;
  }
  s21_int_to_string((long int)copy_number, string_number, number_length,
                    decimals);
  if (string_number[number_length - 1] == '.' && flags.type == 'g' &&
      flags.type == 'G') {
    string_number[number_length - 1] = '\0';
    number_length--;
  }
  if (flags.point_number > decimals && flags.type != 'g' && flags.type != 'G') {
    s21_null_adder(&string_number[number_length], flags, decimals);
    number_length += flags.point_number - decimals;
  }
  s21_trim_string(string_number, flags);
  pointer += s21_equalizer(flags, s21_strlen(string_number), pointer);
  if (s21_before_number(flags.space, flags.plus, pointer,
                        (long int)copy_number) == 1) {
    pointer++;
  }
  for (int j = 0; j < number_length; j++) {
    *pointer = string_number[j];
    pointer++;
  }
}

void s21_sprintf_flo_before_after_branch_2(specifier_parameters flags,
                                           char *pointer, double number,
                                           double copy_number,
                                           char *string_number, int decimals,
                                           int number_length) {
  if (number < 0 || flags.plus == 1 || flags.space == 1) {
    flags.number = flags.number - 1;
  }
  if (s21_before_number(flags.space, flags.plus, pointer,
                        (long int)copy_number) == 1) {
    pointer++;
  }
  s21_int_to_string((long int)copy_number, string_number, number_length,
                    decimals);
  if (string_number[number_length - 1] == '.' && flags.type == 'g' &&
      flags.type == 'G') {
    string_number[number_length - 1] = '\0';
    number_length--;
  }
  if (flags.point_number > decimals && flags.type != 'g' && flags.type != 'G') {
    s21_null_adder(&string_number[number_length], flags, decimals);
    number_length += flags.point_number - decimals;
  }
  for (int j = 0; j < number_length; j++) {
    *pointer = string_number[j];
    pointer++;
  }
  pointer += s21_equalizer(flags, number_length, pointer);
}

void s21_sprintf_flo_before_after_branch_3(specifier_parameters flags,
                                           char *pointer, double number,
                                           double copy_number,
                                           char *string_number, int decimals,
                                           int number_length) {
  if (number < 0 || flags.plus == 1 || flags.space == 1) {
    flags.number = flags.number - 1;
  }
  if (s21_before_number(flags.space, flags.plus, pointer,
                        (long int)copy_number) == 1) {
    pointer++;
  }
  s21_int_to_string((long int)copy_number, string_number, number_length,
                    decimals);
  int count_points = -2;
  for (int j = 0; j < number_length && count_points < flags.point_number; j++) {
    if ((string_number[j] == '.' && flags.point_number != 0) ||
        (string_number[j] == '.' && flags.hashtag == 1)) {
      *pointer = string_number[j];
      pointer++;
      count_points++;
    } else if (string_number[j] == '.' && flags.point_number == 0) {
      count_points = flags.point_number;
    } else {
      *pointer = string_number[j];
      pointer++;
    }
    if (count_points != -2) count_points++;
    if (count_points == flags.point_number && string_number[j + 1] >= '4' + 1 &&
        string_number[j + 1] <= '9') {
      s21_shorten_string(string_number, flags);
      s21_if_previous_more_than_4(pointer, s21_strlen(string_number));
      char temp_string[1000] = "1";
      pointer -= s21_strlen(string_number);
      if (*pointer == '0') {
        s21_strcat(temp_string, pointer);
        s21_strcpy(pointer, temp_string);
      }
      pointer += s21_strlen(string_number);
    }
  }
  for (int i = 0; i < flags.point_number - count_points; i++) {
    if ((flags.type == 'g' || flags.type == 'G') && flags.hashtag == 1) {
      *pointer = '0';
    } else if (flags.type != 'g' && flags.type != 'G') {
      *pointer = '0';
    }
    pointer++;
  }
}

void s21_format_float_to_e_branch_1(double abs_decimal, int shift_number,
                                    specifier_parameters parametr,
                                    char *pointer, char *string_decimal,
                                    char *string_shift, long int copy_decimal) {
  for (int i = 0; i < parametr.point_number + 1; i++) {
    char *check_pointer = &string_decimal[i];
    if (s21_check_next_n(check_pointer, s21_strlen(check_pointer)) == 1)
      if ((parametr.type == 'g' || parametr.type == 'G') &&
          parametr.hashtag != 1)
        i += s21_strlen(check_pointer);
    if (i == 1) {
      *pointer = '.';
      pointer++;
    }
    if (i < s21_number_lenght(copy_decimal)) {
      *pointer = string_decimal[i];
    } else {
      *pointer = '0';
    }
    pointer++;
  }
  if (parametr.point_number == 0 && parametr.hashtag == 1) {
    *pointer = '.';
    pointer++;
  }
  if (parametr.type == 'e' || parametr.type == 'g') {
    *pointer = 'e';
    pointer++;
  } else if (parametr.type == 'E' || parametr.type == 'G') {
    *pointer = 'E';
    pointer++;
  }
  if (abs_decimal >= 0 && abs_decimal < 1) {
    *pointer = '-';
  } else {
    *pointer = '+';
  }
  pointer++;
  s21_int_to_string(shift_number, string_shift, s21_number_lenght(shift_number),
                    -1);
  if (s21_strlen(string_shift) == 1) {
    *pointer = '0';
    pointer++;
    *pointer = string_shift[0];
  } else {
    *pointer = string_shift[0];
    pointer++;
    *pointer = string_shift[1];
  }
  pointer++;
}

int s21_get_buffer_string_branch_1(specifier_parameters parameters,
                                   char *pointer, char *massive, int result) {
  if (parameters.type == 'c' && parameters.number != 0) {
    *massive = *pointer;
    massive++;
    pointer++;
    result++;
  } else if (parameters.type == 'd' || parameters.type == 'u') {
    while (*pointer == ' ') {
      pointer++;
      result++;
    }
    while (((*pointer >= '0' && *pointer <= '9') || *pointer == '-') &&
           parameters.number - result > 0) {
      *massive = *pointer;
      massive++;
      pointer++;
      result++;
    }
  } else if (parameters.type == 'f' || parameters.type == 'e' ||
             parameters.type == 'E' || parameters.type == 'g' ||
             parameters.type == 'G') {
    while (*pointer == ' ') {
      pointer++;
      result++;
    }
    while (((*pointer >= '0' && *pointer <= '9') || *pointer == '.' ||
            *pointer == '-') &&
           parameters.number - result > 0) {
      *massive = *pointer;
      massive++;
      pointer++;
      result++;
    }
  } else if (parameters.type == 's') {
    while (*pointer == ' ') {
      pointer++;
      result++;
    }
    while (*pointer != ' ' && parameters.number - result > 0 &&
           *pointer != '\0') {
      *massive = *pointer;
      massive++;
      pointer++;
      result++;
    }
  }
  return result;
}

int s21_get_buffer_string_branch_2(specifier_parameters parameters,
                                   char *pointer, char *massive, int result) {
  if (parameters.type == 'x' || parameters.type == 'X') {
    while (*pointer == ' ') {
      pointer++;
      result++;
    }
    while (((*pointer >= '0' && *pointer <= '9') ||
            (*pointer >= 'A' && *pointer <= 'F') ||
            (*pointer >= 'a' && *pointer <= 'f')) &&
           parameters.number - result > 0) {
      *massive = *pointer;
      massive++;
      pointer++;
      result++;
    }
  } else if (parameters.type == 'o') {
    while (*pointer == ' ') {
      pointer++;
      result++;
    }
    while (*pointer >= '0' && *pointer <= '7' &&
           parameters.number - result > 0) {
      *massive = *pointer;
      massive++;
      pointer++;
      result++;
    }
  } else if (parameters.type == 'p') {
    while (*pointer == ' ') {
      pointer++;
      result++;
    }
    while (((*pointer >= '0' && *pointer <= '9') ||
            (*pointer >= 'A' && *pointer <= 'F') ||
            (*pointer >= 'a' && *pointer <= 'f') || *pointer == 'x') &&
           parameters.number - result > 0) {
      *massive = *pointer;
      massive++;
      pointer++;
      result++;
    }
  }
  return result;
}

void s21_sscanf_branch_sc(char *temp_string, int *d_adress,
                          specifier_parameters parameters, ...) {
  va_list specifier_arg = {0};
  va_start(specifier_arg, parameters);
  long int *l_d_adress = s21_NULL;
  short int *s_d_adress = s21_NULL;
  if (parameters.type == 'c' || parameters.type == 's') {
    char *c_adress = va_arg(specifier_arg, char *);
    if (parameters.type == 'c') {
      *c_adress = temp_string[0];
    } else {
      s21_strcpy(c_adress, temp_string);
    }
  } else if (parameters.type == 'd' || parameters.type == 'u') {
    if (parameters.h == 1) {
      s_d_adress = va_arg(specifier_arg, short int *);
      *s_d_adress = s21_string_to_int(temp_string);
    } else if (parameters.l == 1) {
      l_d_adress = va_arg(specifier_arg, long int *);
      *l_d_adress = s21_string_to_int(temp_string);
    } else {
      d_adress = va_arg(specifier_arg, int *);
      *d_adress = s21_string_to_int(temp_string);
    }
  } else if (parameters.type == 'x' || parameters.type == 'X') {
    d_adress = va_arg(specifier_arg, int *);
    *d_adress = s21_sixteen_to_int(temp_string);
  } else if (parameters.type == 'o') {
    if (parameters.h == 1) {
      s_d_adress = va_arg(specifier_arg, short int *);
      *s_d_adress = s21_eight_to_int(temp_string);
    } else if (parameters.l == 1) {
      l_d_adress = va_arg(specifier_arg, long int *);
      *l_d_adress = s21_eight_to_int(temp_string);
    } else {
      d_adress = va_arg(specifier_arg, int *);
      *d_adress = s21_eight_to_int(temp_string);
    }
  }
  va_end(specifier_arg);
}

void s21_sprintf_branch_top(specifier_parameters *parameters, char *format,
                            int *i, long int *unexpected_type) {
  s21_search_parameters(parameters, format, i);
  if (parameters->number == -1) {
    parameters->number = 1;
  }
  *unexpected_type = s21_search_specifier_type(format[*i], parameters);
  if (parameters->point != 1 && parameters->zero == 1 &&
      parameters->type != 'e' && parameters->type != 'E' &&
      parameters->type != 'f' && parameters->type != 'g' &&
      parameters->type != 'G') {
    parameters->point_number = 1;
  }
  if (parameters->type == 's' && parameters->point == -1) {
    parameters->point_number = 9223372036854775807;
  }
}

void s21_shorten_string(char *massive, specifier_parameters parameters) {
  long int len = s21_strlen(massive), counter = -1;
  for (int i = 0; i < len; i++) {
    if (massive[i] == '.') {
      counter++;
    } else if (counter < parameters.point_number && counter != -1) {
      counter++;
    } else if (counter == parameters.point_number) {
      massive[i] = '\0';
    }
  }
}

void s21_null_adder(char *massive, specifier_parameters parameters,
                    int decimals) {
  for (int i = 0; i < parameters.point_number - decimals; i++) {
    *massive = '0';
    massive++;
  }
  *massive = '\0';
}

long double s21_check_L_parametr(specifier_parameters parameters,
                                 va_list specifier_arg) {
  long double result = 1.0;
  if (parameters.L == 1) {
    result = va_arg(specifier_arg, long double);
  } else {
    result = va_arg(specifier_arg, double);
  }
  return result;
}
