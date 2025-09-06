#include "s21_smart_calc.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

double s21_addition(double i_1, double i_2) {
  double result = 0;
  result = i_1 + i_2;
  return result;
}

double s21_substraction(double i_1, double i_2) {
  double result = 0;
  result = i_1 - i_2;
  return result;
}

double s21_multiplication(double i_1, double i_2) {
  double result = 0;
  result = i_1 * i_2;
  return result;
}

double s21_division(double i_1, double i_2) {
  double result = 0;
  if (i_2 != 0) {
    result = i_1 / i_2;
  } else {
    result = INFINITY;
  }
  return result;
}

double s21_power(double i_1, double i_2) {
  double result = 0;
  result = pow(i_1, i_2);
  return result;
}

double s21_module(double i_1, double i_2) {
  double result = 1;
  result = fmod(i_1, i_2);
  return result;
}

double s21_sinus(double i_1) {
  double result = 0;
  result = sin(i_1);
  return result;
}

double s21_cosinus(double i_1) {
  double result = 0;
  result = cos(i_1);
  return result;
}

double s21_tangience(double i_1) {
  double result = 0;
  result = tan(i_1);
  return result;
}

double s21_arcsinus(double i_1) {
  double result = 0;
  result = asin(i_1);
  return result;
}

double s21_arccosinus(double i_1) {
  double result = 0;
  result = acos(i_1);
  return result;
}

double s21_arctangience(double i_1) {
  double result = 0;
  result = atan(i_1);
  return result;
}

double s21_sqrt(double i_1) {
  double result = 0;
  result = sqrt(i_1);
  return result;
}

double s21_nat_log(double i_1) {
  double result = 0;
  result = log(i_1);
  return result;
}

double s21_common_log(double i_1) {
  double result = 0;
  result = log10(i_1);
  return result;
}

// 0 - no error 1 - error
int s21_error_in_brackets(char *string) {
  int left_br = 0, right_br = 0, result = 0;
  for (int i = 0; i < (int)strlen(string) && result == 0; i++) {
    if (string[i] == '(') {
      left_br += 1;
    } else if (string[i] == ')' && right_br >= left_br) {
      result = 1;
    } else if (string[i] == ')') {
      right_br += 1;
    }
  }
  if (left_br != right_br) {
    result = 1;
  }
  if (strstr(string, "()") != NULL) {
    result = 1;
  }
  return result;
}

void s21_string_to_djicstra(char *string, char *result) {
  int len_2 = 0;
  char djicstra[500] = {'\0'}, buffer[500] = {'\0'}, temp[500] = {'\0'};
  char *s = strstr(string, "--");
  if (s != NULL) {
    *s = '+';
    s += 1;
    *s = '+';
  }
  buffer[0] = 'z';
  temp[0] = ' ';
  for (int i = 0; i < (int)strlen(string);) {
    len_2 = strlen(buffer);
    if ((string[i] >= 48 && string[i] <= 57) || string[i] == '.' ||
        (string[i] == '-' && (string[i - 1] < 48 || string[i - 1] > 57) &&
         string[i - 1] != '.' && string[i - 1] != ')')) {
      s21_string_to_djicstra_branch_1(string, temp, djicstra, i);
      i++;
    } else if (string[i] == '+' && (string[i - 1] < 48 || string[i - 1] > 57) &&
               string[i - 1] != '.' && string[i - 1] != ')') {
      i++;
    } else if (string[i] == '(') {
      strcat(buffer, " (");
      i++;
    } else if (string[i] == ')') {
      if (buffer[len_2 - 1] == '(') {
        buffer[len_2 - 2] = '\0';
        i++;
      } else {
        s21_take_last_sign(djicstra, buffer);
      }
    } else if ((string[i] == '+' || string[i] == '-') &&
               ((string[i - 1] <= 57 && string[i - 1] >= 48) ||
                string[i - 1] == '.' || string[i - 1] == ')')) {
      temp[1] = string[i];
      if (buffer[len_2 - 1] == 'z' || buffer[len_2 - 1] == '(') {
        strcat(buffer, temp);
        i++;
      } else {
        s21_take_last_sign(djicstra, buffer);
      }
      temp[1] = '\0';
    } else if (string[i] == '*' || string[i] == '/' || string[i] == 'm') {
      s21_string_to_djicstra_branch_2(string, temp, djicstra, &i, len_2,
                                      buffer);
    } else {
      s21_string_to_djicstra_branch_3(string, temp, djicstra, &i, len_2,
                                      buffer);
    }
  }
  while (strlen(buffer) > 2) {
    s21_take_last_sign(djicstra, buffer);
  }
  strcpy(result, djicstra);
  strcat(result, " ");
}

void s21_string_to_djicstra_branch_1(char *string, char *temp, char *djicstra,
                                     int i) {
  if ((string[i - 1] >= 48 && string[i - 1] <= 57) || string[i - 1] == '.' ||
      (string[i - 1] == '-' && (string[i - 2] < 48 || string[i - 2] > 57) &&
       string[i - 2] != '.' && string[i - 2] != ')')) {
    temp[0] = string[i];
    strcat(djicstra, temp);
    temp[0] = ' ';
  } else {
    temp[1] = string[i];
    strcat(djicstra, temp);
    temp[1] = '\0';
  }
}

void s21_string_to_djicstra_branch_2(char *string, char *temp, char *djicstra,
                                     int *i, int len_2, char *buffer) {
  if (string[*i] == 'm') {
    temp[1] = string[*i];
    temp[2] = string[*i + 1];
    temp[3] = string[*i + 2];
  } else {
    temp[1] = string[*i];
  }
  if (buffer[len_2 - 1] == '*' || buffer[len_2 - 1] == '/' ||
      buffer[len_2 - 1] == 'm' || buffer[len_2 - 1] == '^' ||
      (buffer[len_2 - 1] >= 97 && buffer[len_2 - 1] < 122 &&
       buffer[len_2 - 1] != 109)) {
    s21_take_last_sign(djicstra, buffer);
  } else {
    strcat(buffer, temp);
    if (string[*i] == 'm') {
      *i += 2;
    }
    *i += 1;
  }
  temp[4] = '\0';
  temp[3] = '\0';
  temp[2] = '\0';
  temp[1] = '\0';
}

void s21_string_to_djicstra_branch_3(char *string, char *temp, char *djicstra,
                                     int *i, int len_2, char *buffer) {
  if (string[*i] == '^' || string[*i] == '-' || string[*i] == '+') {
    temp[1] = string[*i];
  } else if (string[*i] == 'l' && string[*i + 1] == 'n') {
    temp[1] = string[*i];
    temp[2] = string[*i + 1];
  } else if (string[*i] == 'c' || string[*i] == 't' || string[*i + 1] == 'i' ||
             string[*i] == 'l') {
    temp[1] = string[*i];
    temp[2] = string[*i + 1];
    temp[3] = string[*i + 2];
  } else {
    temp[1] = string[*i];
    temp[2] = string[*i + 1];
    temp[3] = string[*i + 2];
    temp[4] = string[*i + 3];
  }
  if (buffer[len_2 - 1] == '^' ||
      (buffer[len_2 - 1] >= 97 && buffer[len_2 - 1] < 122 &&
       buffer[len_2 - 1] != 109)) {
    s21_take_last_sign(djicstra, buffer);
  } else {
    strcat(buffer, temp);
    if (string[*i] == '^' || string[*i] == '-' || string[*i] == '+') {
      *i += 1;
    } else if (string[*i] == 'l' && string[*i + 1] == 'n') {
      *i += 2;
    } else if (string[*i] == 'c' || string[*i] == 't' ||
               string[*i + 1] == 'i' || string[*i] == 'l') {
      *i += 3;
    } else {
      *i += 4;
    }
  }
  temp[5] = '\0';
  temp[4] = '\0';
  temp[3] = '\0';
  temp[2] = '\0';
  temp[1] = '\0';
}

void s21_take_last_sign(char *string_1, char *string_2) {
  int len_2 = 0;
  char copy[500] = {'\0'}, *pointer = NULL;
  len_2 = strlen(string_2);
  if (string_2[len_2 - 1] == ' ') {
    string_2[len_2 - 1] = '\0';
    len_2 -= 1;
  }
  if (string_2[len_2 - 1] == '-' || string_2[len_2 - 1] == '+' ||
      string_2[len_2 - 1] == '*' || string_2[len_2 - 1] == '/' ||
      string_2[len_2 - 1] == '^') {
    copy[0] = string_2[len_2 - 1];
    strcat(string_1, " ");
    strcat(string_1, copy);
    string_2[len_2 - 1] = '\0';
  } else if (string_2[len_2 - 1] >= 97 && string_2[len_2 - 1] < 122) {
    pointer = &string_2[len_2 - 1];
    while (*pointer >= 97 && *pointer < 122) {
      pointer -= 1;
    }
    pointer += 1;
    strcat(string_1, " ");
    strcat(string_1, pointer);
    *pointer = '\0';
  }
}

double s21_calculation(char *string) {
  char *pointer = NULL, *end_pointer = NULL, *i_copy = NULL, temp[500] = {'\0'},
       end_string[500] = {'\0'}, copy[500] = {'\0'};
  double result[500] = {0}, f_one = 0, f_two = 0;
  int counter = 0;
  pointer = &string[0];
  if (s21_count_spaces(string) <= 2) {
    strcpy(copy, string);
    pointer = &string[1];
    for (int i = 0; i < (int)strlen(pointer); i++) {
      if (!((pointer[i] >= '0' && pointer[i] <= '9') || pointer[i] == '-' ||
            pointer[i] == '+' || pointer[i] == '.')) {
        pointer[i] = '\0';
      }
    }
    result[counter] = s21_string_to_float(pointer);
    counter += 1;
  }
  while (s21_count_spaces(string) > 2) {
    if (s21_three_numbers_in_row(pointer) == 1) {
      pointer += 1;
      pointer = strchr(pointer, ' ');
    } else if (s21_three_numbers_in_row(pointer) == -1) {
      strcpy(copy, pointer);
      i_copy = strtok(copy, " ");
      i_copy = strtok(NULL, " ");
      s21_calculation_branch_1(i_copy, copy, pointer, result, counter);
      end_pointer = pointer;
      end_pointer += 1;
      end_pointer = strchr(end_pointer, ' ');
      end_pointer += 1;
      end_pointer = strchr(end_pointer, ' ');
      if (end_pointer != NULL) {
        strcpy(end_string, end_pointer);
      }
      pointer += 1;
      *pointer = '\0';
      pointer -= 1;
      s21_int_to_string(counter, temp, s21_number_lenght(counter));
      strcat(pointer, ".");
      strcat(pointer, temp);
      strcat(pointer, ".");
      strcat(pointer, end_string);
      counter += 1;
      pointer = &string[0];
    } else if (s21_three_numbers_in_row(pointer) == -2) {
      strcpy(copy, pointer);
      i_copy = strtok(copy, " ");
      i_copy = strtok(NULL, " ");
      i_copy = strtok(NULL, " ");
      s21_calculation_branch_2(i_copy, copy, pointer, result, counter, &f_one,
                               &f_two);

      end_pointer = pointer;
      end_pointer += 1;
      end_pointer = strchr(end_pointer, ' ');
      end_pointer += 1;
      end_pointer = strchr(end_pointer, ' ');
      end_pointer += 1;
      end_pointer = strchr(end_pointer, ' ');
      if (end_pointer != NULL) {
        strcpy(end_string, end_pointer);
      }
      pointer += 1;
      *pointer = '\0';
      pointer -= 1;
      s21_int_to_string(counter, temp, s21_number_lenght(counter));
      strcat(pointer, ".");
      strcat(pointer, temp);
      strcat(pointer, ".");
      strcat(pointer, end_string);
      counter += 1;
      pointer = &string[0];
    }
  }
  return result[counter - 1];
}

void s21_calculation_branch_1(char *i_copy, char *copy, char *pointer,
                              double *result, int counter) {
  if (strstr(i_copy, "acos") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_arccosinus(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_arccosinus(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "asin") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_arcsinus(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_arcsinus(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "atan") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_arctangience(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_arctangience(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "sqrt") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_sqrt(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_sqrt(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "cos") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_cosinus(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_cosinus(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "sin") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_sinus(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_sinus(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "tan") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_tangience(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_tangience(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "log") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_common_log(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_common_log(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "ln") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_nat_log(s21_string_to_float(i_copy));
    } else {
      i_copy += 1;
      result[counter] = s21_nat_log(result[s21_point_number(i_copy)]);
    }
  } else if (strstr(i_copy, "+") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");

    if (*i_copy != '.') {
      result[counter] = s21_string_to_float(i_copy) * 1;
    } else {
      i_copy += 1;
      result[counter] = result[s21_point_number(i_copy)] * 1;
    }
  }
}

void s21_calculation_branch_2(char *i_copy, char *copy, char *pointer,
                              double *result, int counter, double *f_one,
                              double *f_two) {
  if (strstr(i_copy, "mod") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");
    if (*i_copy != '.') {
      *f_one = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_one = result[s21_point_number(i_copy)];
    }
    i_copy = strtok(NULL, " ");
    if (*i_copy != '.') {
      *f_two = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_two = result[s21_point_number(i_copy)];
    }
    result[counter] = s21_module(*f_one, *f_two);
  } else if (strstr(i_copy, "+") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");
    if (*i_copy != '.') {
      *f_one = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_one = result[s21_point_number(i_copy)];
    }
    i_copy = strtok(NULL, " ");
    if (*i_copy != '.') {
      *f_two = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_two = result[s21_point_number(i_copy)];
    }
    result[counter] = s21_addition(*f_one, *f_two);
  } else if (strstr(i_copy, "-") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");
    if (*i_copy != '.') {
      *f_one = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_one = result[s21_point_number(i_copy)];
    }
    i_copy = strtok(NULL, " ");
    if (*i_copy != '.') {
      *f_two = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_two = result[s21_point_number(i_copy)];
    }
    result[counter] = s21_substraction(*f_one, *f_two);
  } else if (strstr(i_copy, "*") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");
    if (*i_copy != '.') {
      *f_one = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_one = result[s21_point_number(i_copy)];
    }
    i_copy = strtok(NULL, " ");
    if (*i_copy != '.') {
      *f_two = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_two = result[s21_point_number(i_copy)];
    }
    result[counter] = s21_multiplication(*f_one, *f_two);
  } else if (strstr(i_copy, "/") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");
    if (*i_copy != '.') {
      *f_one = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_one = result[s21_point_number(i_copy)];
    }
    i_copy = strtok(NULL, " ");
    if (*i_copy != '.') {
      *f_two = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_two = result[s21_point_number(i_copy)];
    }
    result[counter] = s21_division(*f_one, *f_two);
  } else if (strstr(i_copy, "^") != NULL) {
    strcpy(copy, pointer);
    i_copy = strtok(copy, " ");
    if (*i_copy != '.') {
      *f_one = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_one = result[s21_point_number(i_copy)];
    }
    i_copy = strtok(NULL, " ");
    if (*i_copy != '.') {
      *f_two = s21_string_to_float(i_copy);
    } else {
      i_copy += 1;
      *f_two = result[s21_point_number(i_copy)];
    }
    result[counter] = s21_power(*f_one, *f_two);
  }
}

// 1 - yes 0 - no(0) -1 - no(1) -2 - no(2)
int s21_three_numbers_in_row(char *string) {
  int result = 1, count = 0;
  char temp = '\0';
  for (int i = 1; i < (int)strlen(string) && count < 3 && result == 1; i++) {
    if ((string[i] >= '0' && string[i] <= '9') || string[i] == '.' ||
        (string[i] == '-' && ((string[i + 1] >= '0' && string[i + 1] <= '9') ||
                              string[i + 1] == '.'))) {
      while ((string[i] >= '0' && string[i] <= '9') || string[i] == '.' ||
             (string[i] == '-' &&
              ((string[i + 1] >= '0' && string[i + 1] <= '9') ||
               string[i + 1] == '.'))) {
        i += 1;
      }
      count += 1;
    } else {
      result = 0;
      temp = string[i];
    }
  }
  if (result == 0 && count == 1) {
    result = -1;
  } else if (result == 0 && count == 2 && temp >= 'a' && temp <= 'z' &&
             temp != 'm') {
    result = 1;
  } else if (result == 0 && count == 2) {
    result = -2;
  }
  return result;
}

double s21_calculate_x(char *string, char *number) {
  char *begin_pointer = NULL, *end_pointer = NULL, end[500] = {'\0'},
       result_s[500] = {'\0'};
  double result = 0;
  begin_pointer = strchr(string, 'x');
  if (begin_pointer != NULL) {
    end_pointer = strchr(string, 'x');
    end_pointer += 1;
    strcpy(end, end_pointer);
    end_pointer -= 1;
    *end_pointer = '\0';
    strcat(string, number);
    strcat(string, end);
    s21_string_to_djicstra(string, result_s);
    result = s21_calculation(result_s);
  } else {
    s21_string_to_djicstra(string, result_s);
    result = s21_calculation(result_s);
  }
  return result;
}

int s21_count_spaces(char *string) {
  int result = 0;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (string[i] == ' ') {
      result += 1;
    }
  }
  return result;
}

int s21_point_number(char *string) {
  int result = 0;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (string[i] >= '0' && string[i] <= '9') {
      result *= 10;
      result += pow(string[i] - '0', i + 1);
    }
  }
  return result;
}

// 1 error 0 good
int s21_correctness(char *string) {
  int result = 0, current_char_is_num = 0, znak_counter = 0,
      there_was_a_point = 0;
  for (int i = 0; i < (int)strlen(string) && result == 0; i++) {
    if (znak_counter >= 3) {
      result = 1;
    } else if (znak_counter == 2 && string[i - 1] != '-' &&
               string[i - 1] != '+' && string[i - 1] != '(') {
      result = 1;
    } else if ((string[i] >= '0' && string[i] <= '9') || string[i] == 'x') {
      current_char_is_num = 1;
      znak_counter = 0;
    } else if (string[i] == '.' && current_char_is_num == 0) {
      result = 1;
    } else if (string[i] == '.' && there_was_a_point != 0) {
      result = 1;
    } else if (string[i] == '.') {
      there_was_a_point = 1;
    } else {
      current_char_is_num = 0;
      there_was_a_point = 0;
      if (string[i + 1] == 'n') {
        if (!(string[i + 3] == 'x' || string[i + 3] == '-' ||
              string[i + 3] == '+' ||
              (string[i + 3] >= '0' && string[i + 3] <= '9') ||
              (string[i + 3] >= 'a' && string[i + 3] <= 'z' &&
               string[i + 3] != 'm'))) {
          result = 1;
        }
        i += 1;
      } else if (string[i] == 'c' || string[i + 1] == 'i' || string[i] == 't' ||
                 string[i + 2] == 'g') {
        if (!(string[i + 4] == 'x' || string[i + 4] == '-' ||
              string[i + 4] == '+' ||
              (string[i + 4] >= '0' && string[i + 4] <= '9') ||
              (string[i + 4] >= 'a' && string[i + 4] <= 'z' &&
               string[i + 4] != 'm'))) {
          result = 1;
        }
        i += 2;
      } else if (string[i] == 'a' || string[i + 1] == 'q') {
        if (!(string[i + 5] == 'x' || string[i + 5] == '-' ||
              string[i + 5] == '+' ||
              (string[i + 5] >= '0' && string[i + 5] <= '9') ||
              (string[i + 5] >= 'a' && string[i + 5] <= 'z' &&
               string[i + 5] != 'm'))) {
          result = 1;
        }
        i += 3;
      } else if (string[i] == 'm') {
        i += 2;
        znak_counter += 1;
      } else if (string[i] != ')' && string[i] != '(') {
        znak_counter += 1;
      }
    }
  }
  if (znak_counter != 0) {
    result = 1;
  }
  for (int i = 0; i < (int)strlen(string) && result == 0; i++) {
    if ((string[i] >= '0' && string[i] <= '9') || string[i] == 'x') {
      if ((string[i + 1] >= 'a' && string[i + 1] <= 'z' &&
           string[i + 1] != 'm') ||
          string[i + 1] == '(') {
        result = 1;
      }
    }
  }
  if ((string[0] == '-' || string[0] == '+') && string[1] == '(') {
    result = 1;
  }
  for (int i = 2; i < (int)strlen(string) && result == 0; i++) {
    if (string[i] == '(' && (string[i - 1] == '-' || string[i - 1] == '+')) {
      if (!(string[i - 2] == ')' || string[i - 2] == 'x' ||
            (string[i - 2] >= '0' && string[i - 2] <= '9'))) {
        result = 1;
      }
    }
  }
  return result;
}

// 1 - there is number 0 -is not
int s21_only_number(char *string) {
  int result = 1;
  if (strlen(string) > 0) {
    for (int i = 0; i < (int)strlen(string) && result == 1; i++) {
      if (!(string[i] <= '9' && string[i] >= '0') && string[i] != '.') {
        result = 0;
      }
    }
  } else {
    result = 0;
  }
  return result;
}

double s21_calculation_one_number(char *string) {
  double result = 0;
  result = s21_string_to_float(string);
  return result;
}

// 0 - no error 1 - error 2 - no error
int s21_check_if_only_znaks_and_not_pm_in_the_beginning(char *string) {
  int error = 0;
  if ((string[0] <= '9' && string[0] >= '0') || string[0] == 'x' ||
      string[0] == '(') {
    error = 0;
  } else if (string[0] <= 'z' && string[0] >= 'a' && string[0] != 'm') {
    error = 0;
  } else if (string[0] == '-' || string[0] == '+') {
    if ((string[1] <= '9' && string[1] >= '0') || string[1] == 'x' ||
        string[1] == '(') {
      error = 0;
    } else {
      error = 1;
    }
  } else {
    error = 1;
  }
  return error;
}

// 0 - no error 1 - error
int s21_check_points(char *string) {
  int error = 0;
  char *pointer = NULL;
  pointer = strstr(string, ".x");
  if (pointer != NULL) {
    error = 1;
  }
  pointer = strstr(string, "x.");
  if (pointer != NULL) {
    error = 1;
  }
  pointer = strstr(string, "..");
  if (pointer != NULL) {
    error = 1;
  }
  for (int i = 0; i < (int)strlen(string) && error == 0; i++) {
    if (string[i] == '.') {
      if (!(string[i + 1] >= '0' && string[i + 1] <= '9') ||
          !(string[i - 1] >= '0' && string[i - 1] <= '9')) {
        error = 1;
      }
    }
  }
  return error;
}

// 1 - error 0 - good
int s21_check_bracket_after_sin(char *string) {
  int error = 0;
  for (int i = 0; i < (int)strlen(string) && error == 0; i++) {
    if ((string[i] == 's' && string[i - 1] == 'o') || string[i] == 'n' ||
        (string[i] == 't' && string[i - 1] == 'r') || string[i] == 'g') {
      if (string[i + 1] != '(') {
        error = 1;
      }
    }
  }
  return error;
}

// 1 - error 0 - good
int s21_check_step_width_heigth(char *string) {
  int error = 0, minus_beginning = 0, minus_counter = 0, point_counter = 0;
  for (int i = 0; i < (int)strlen(string) && error == 0; i++) {
    if (string[i] == '-' && i == 0) {
      minus_beginning = 1;
      minus_counter = 1;
    } else if (string[i] == '.' && i == 0) {
      error = 1;
    } else if (string[i] == '.' && i == 1 && string[0] == '-') {
      error = 1;
    } else if (string[i] == '-') {
      minus_counter += 1;
    } else if (string[i] == '.') {
      point_counter += 1;
    } else if (string[i] != '.' && string[i] != '-' &&
               !(string[i] >= '0' && string[i] <= '9')) {
      error = 1;
    }
  }
  if (minus_counter == 1 && minus_beginning == 0) {
    error = 1;
  } else if (minus_counter > 1) {
    error = 1;
  } else if (point_counter > 1) {
    error = 1;
  } else if (strlen(string) == 0) {
    error = 1;
  }
  return error;
}

double s21_bank_annuitent_montly_payment(double credit_summ, int length_month,
                                         double percent) {
  double result = 0, percent_stavka = 0;
  percent_stavka = percent / 1200;
  result = credit_summ *
           (percent_stavka / (1 - pow(1 + percent_stavka, length_month * -1)));
  return result;
}

double s21_bank_annuitent_overpayment(double credit_summ, int length_month,
                                      double percent) {
  double montly = 0, result = 0;
  montly =
      s21_bank_annuitent_montly_payment(credit_summ, length_month, percent);
  result = (montly * length_month) - credit_summ;
  return result;
}

double s21_bank_annuitent_all_payment(double credit_summ, int length_month,
                                      double percent) {
  double montly = 0, result = 0;
  montly =
      s21_bank_annuitent_montly_payment(credit_summ, length_month, percent);
  result = montly * length_month;
  return result;
}

double s21_bank_differential_montly_payment_first(double credit_summ,
                                                  int length_month,
                                                  double percent) {
  double result = 0, percent_stavka = 0;
  percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
  result = credit_summ / length_month + percent_stavka;
  return result;
}

double s21_bank_differential_montly_payment_last(double credit_summ,
                                                 int length_month,
                                                 double percent) {
  double result = 0, percent_stavka = 0, difference = 0;
  percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
  difference = credit_summ / length_month;
  result = difference + percent_stavka;
  credit_summ -= difference;
  for (int i = 1; i < length_month; i++) {
    percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
    result = difference + percent_stavka;
    credit_summ -= difference;
  }
  return result;
}

double s21_bank_differential_overpayment(double credit_summ, int length_month,
                                         double percent) {
  double result = 0, all = 0;
  all = s21_bank_differential_all_payment(credit_summ, length_month, percent);
  result = all - credit_summ;
  return result;
}

double s21_bank_differential_all_payment(double credit_summ, int length_month,
                                         double percent) {
  double result = 0, percent_stavka = 0, difference = 0;
  percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
  difference = credit_summ / length_month;
  result = difference + percent_stavka;
  credit_summ -= difference;
  for (int i = 1; i < length_month; i++) {
    percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
    result += difference + percent_stavka;
    credit_summ -= difference;
  }
  return result;
}

double s21_deposit_profitability_simple(double deposit_amount, int deposit_term,
                                        double interst, double tax) {
  double result = 0, tax_minus = 0;
  int nalogi = 0;
  result = (deposit_amount * interst * deposit_term * 30.416666 / 365) / 100;
  if (deposit_amount >= 1000000) {
    nalogi = deposit_term / 12;
    if (deposit_term % 12 != 0) {
      nalogi += 1;
    }
    tax_minus = 1000000 * 0.075;
    tax_minus = result / nalogi - tax_minus;
    while (tax_minus > 0 && nalogi > 0) {
      result -= tax_minus * tax / 100;
      nalogi -= 1;
    }
  }
  return result;
}

// what to return 0 - percent returns 1 - tax minus
// periodicity  0 - once in month 1 - in 3 months 2 - in 6 months 3 - in year 4
// - in the end of the term
double s21_deposit_profitability_complex(
    int what_to_return, double deposit_amount, int deposit_term, double interst,
    double tax, int periodicity, int capitalization,
    s21_repelishments *repelishments, s21_widrawls *partial_widrawal,
    double bank_key_deposit) {
  s21_date current_date = {0}, end_date = {0};
  current_date.day = 1, current_date.month = 1, current_date.year = 0;
  double result = 0, percents_this_year = 0, month_percents = 0,
         nalog_result = 0, last_year = 0;
  int repelishments_size = 0, widrawl_size = 0, month_counter = 0, error = 0;
  if (sizeof(repelishments) == 0) {
    repelishments_size = 0;
  } else {
    while (repelishments[repelishments_size].last != 1) {
      repelishments_size += 1;
    }
    repelishments_size += 1;
  }
  if (sizeof(partial_widrawal) == 0) {
    widrawl_size = 0;
  } else {
    while (partial_widrawal[widrawl_size].last != 1) {
      widrawl_size += 1;
    }
    widrawl_size += 1;
  }
  s21_fullfiil_monts(&current_date);
  s21_fullfiil_monts(&end_date);
  end_date.day = 1;
  end_date.month += deposit_term;
  end_date.year += end_date.month / 12;
  end_date.month = end_date.month % 12 + 1;
  while (current_date.month != end_date.month ||
         current_date.year != end_date.year) {
    for (int i = 0; i < repelishments_size; i++) {
      if (repelishments[i].month == current_date.month &&
          repelishments[i].year == current_date.year) {
        deposit_amount += repelishments[i].summ;
      }
    }
    for (int i = 0; i < widrawl_size; i++) {
      if (partial_widrawal[i].month == current_date.month &&
          partial_widrawal[i].year == current_date.year) {
        deposit_amount -= partial_widrawal[i].summ;
      }
      if (deposit_amount < 0) {
        error = -1;
      }
    }
    s21_deposit_profitability_complex_branch_1(
        periodicity, &month_percents, &percents_this_year, &result,
        &month_counter, &deposit_amount, interst, current_date, deposit_term,
        capitalization);
    s21_deposit_profitability_complex_branch_2(
        periodicity, month_counter, deposit_term, &nalog_result, tax, result,
        bank_key_deposit, current_date, end_date, &last_year,
        &percents_this_year);
    current_date.month += 1;
    if (current_date.month > 12) {
      current_date.month -= 12;
      current_date.year += 1;
    }
  }
  if (what_to_return == 1) {
    result = nalog_result;
  } else if (what_to_return == 2) {
    result = deposit_amount;
  }
  if (error == -1) {
    result = error;
  }
  return result;
}

void s21_deposit_profitability_complex_branch_1(
    int periodicity, double *month_percents, double *percents_this_year,
    double *result, int *month_counter, double *deposit_amount, double interst,
    s21_date current_date, double deposit_term, int capitalization) {
  if (periodicity == 0) {
    *month_percents = (*deposit_amount * interst *
                       current_date.month_days[current_date.month - 1] / 365) /
                      100;
    *percents_this_year += *month_percents;
    *result += *month_percents;
    *month_counter += 1;
  } else if (periodicity == 1) {
    *month_percents += (*deposit_amount * interst *
                        current_date.month_days[current_date.month - 1] / 365) /
                       100;
    *month_counter += 1;
    if (*month_counter % 3 == 0 || *month_counter == deposit_term) {
      *result += *month_percents;
      *percents_this_year += *month_percents;
      if (capitalization == 0) {
        *month_percents = 0;
      }
    }
  } else if (periodicity == 2) {
    *month_percents += (*deposit_amount * interst *
                        current_date.month_days[current_date.month - 1] / 365) /
                       100;
    *month_counter += 1;
    if (*month_counter % 6 == 0 || *month_counter == deposit_term) {
      *result += *month_percents;
      *percents_this_year += *month_percents;
      if (capitalization == 0) {
        *month_percents = 0;
      }
    }
  } else if (periodicity == 3) {
    *month_percents += (*deposit_amount * interst *
                        current_date.month_days[current_date.month - 1] / 365) /
                       100;
    *month_counter += 1;
    if (*month_counter % 12 == 0 || *month_counter == deposit_term) {
      *result += *month_percents;
      *percents_this_year = *month_percents;
      if (capitalization == 0) {
        *month_percents = 0;
      }
    }
  } else if (periodicity == 4) {
    *result += (*deposit_amount * interst *
                current_date.month_days[current_date.month - 1] / 365) /
               100;
    *month_counter += 1;
  }
  if (capitalization == 1 && periodicity == 0) {
    *deposit_amount += *month_percents;
  } else if (capitalization == 1 && periodicity == 1 &&
             (*month_counter % 3 == 0 || *month_counter == deposit_term)) {
    *deposit_amount += *month_percents;
    *month_percents = 0;
  } else if (capitalization == 1 && periodicity == 2 &&
             (*month_counter % 6 == 0 || *month_counter == deposit_term)) {
    *deposit_amount += *month_percents;
    *month_percents = 0;
  } else if (capitalization == 1 && periodicity == 3 &&
             (*month_counter % 12 == 0 || *month_counter == deposit_term)) {
    *deposit_amount += *month_percents;
    *month_percents = 0;
  } else if (capitalization == 1 && periodicity == 4 &&
             *month_counter == deposit_term) {
    *deposit_amount += *result;
  }
}

void s21_deposit_profitability_complex_branch_2(
    int periodicity, int month_counter, int deposit_term, double *nalog_result,
    double tax, double result, double bank_key_deposit, s21_date current_date,
    s21_date end_date, double *last_year, double *percents_this_year) {
  if (periodicity == 4 && month_counter == deposit_term) {
    *nalog_result = tax * (result - bank_key_deposit * 10000) / 100;
    if (*nalog_result < 0) {
      *nalog_result = 0;
    }
  } else if ((periodicity == 3 && current_date.month == 1) ||
             (periodicity == 3 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  } else if ((periodicity == 2 && current_date.month == 11) ||
             (periodicity == 2 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  } else if ((periodicity == 1 && current_date.month == 11) ||
             (periodicity == 1 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  } else if ((periodicity == 0 && current_date.month == 11) ||
             (periodicity == 0 && month_counter == deposit_term)) {
    if (current_date.year == end_date.year && month_counter != deposit_term) {
      *last_year = *percents_this_year;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
                   0 &&
               month_counter == deposit_term) {
      *nalog_result +=
          tax * (*percents_this_year + *last_year - bank_key_deposit * 10000) /
          100;
    } else if (tax * (*percents_this_year - bank_key_deposit * 10000) / 100 >
               0) {
      *nalog_result +=
          tax * (*percents_this_year - bank_key_deposit * 10000) / 100;
    }
    *percents_this_year = 0;
  }
}

void s21_fullfiil_monts(s21_date *months) {
  months->month_days[0] = 31;
  months->month_days[1] = 28;
  months->month_days[2] = 31;
  months->month_days[3] = 30;
  months->month_days[4] = 31;
  months->month_days[5] = 30;
  months->month_days[6] = 31;
  months->month_days[7] = 31;
  months->month_days[8] = 30;
  months->month_days[9] = 31;
  months->month_days[10] = 30;
  months->month_days[11] = 31;
}

// mode 1 - only int 2 - point
// 0 - good 1 - error
int s21_check_if_only_numbers(char *string, int mode) {
  int error = 0, counter = 0;
  for (int i = 0; i < (int)strlen(string) && error == 0; i++) {
    if (string[i] < '0' || string[i] > '9') {
      if (mode == 2 && string[i] == '.') {
        error = 0;
        counter += 1;
      } else {
        error = 1;
      }
    }
  }
  if (counter > 1 || string[0] == '.') {
    error = 1;
  }
  return error;
}

//--------------------------------------------------

long double s21_string_to_float(char *massive) {
  int length = strlen(massive), minus = 1;
  long double result = 0.0, decimal = 1;
  for (int i = 0; i < length; i++) {
    if (*massive == '-') {
      minus *= -1;
    } else if (*massive != '.') {
      result += (*massive - 48) * decimal;
      if (decimal != 1) {
        decimal *= 0.1;
      }
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

void s21_int_to_string(long int number, char *massive, int number_length) {
  long int copy_number = number;
  for (int i = 0; i < number_length; i++) {
    massive[number_length - 1 - i] = copy_number % 10 + '0';
    copy_number = copy_number / 10;
  }
}

int s21_number_lenght(long int number) {
  long unsigned int absolute_number = 0;
  int result = 1;
  if (number < 0) {
    absolute_number = -number;
  } else {
    absolute_number = number;
  }
  if (absolute_number < 10) {
    result = 1;
  } else if (absolute_number >= 10 && absolute_number < 100) {
    result = 2;
  } else if (absolute_number >= 100 && absolute_number < 1000) {
    result = 3;
  } else if (absolute_number >= 1000 && absolute_number < 10000) {
    result = 4;
  } else if (absolute_number >= 10000 && absolute_number < 100000) {
    result = 5;
  } else if (absolute_number >= 100000 && absolute_number < 1000000) {
    result = 6;
  } else if (absolute_number >= 1000000 && absolute_number < 10000000) {
    result = 7;
  } else if (absolute_number >= 10000000 && absolute_number < 100000000) {
    result = 8;
  } else if (absolute_number >= 100000000 && absolute_number < 1000000000) {
    result = 9;
  } else if (absolute_number >= 1000000000 && absolute_number < 10000000000) {
    result = 10;
  } else if (absolute_number >= 10000000000 && absolute_number < 100000000000) {
    result = 11;
  } else if (absolute_number >= 100000000000 &&
             absolute_number < 1000000000000) {
    result = 12;
  } else if (absolute_number >= 1000000000000 &&
             absolute_number < 10000000000000) {
    result = 13;
  } else if (absolute_number >= 10000000000000 &&
             absolute_number < 100000000000000) {
    result = 14;
  } else if (absolute_number >= 100000000000000 &&
             absolute_number < 1000000000000000) {
    result = 15;
  } else if (absolute_number >= 1000000000000000 &&
             absolute_number < 10000000000000000) {
    result = 16;
  } else if (absolute_number >= 10000000000000000 &&
             absolute_number < 100000000000000000) {
    result = 17;
  } else if (absolute_number >= 100000000000000000 &&
             absolute_number < 1000000000000000000) {
    result = 18;
  } else if (absolute_number >= 1000000000000000000) {
    result = 19;
  }
  return result;
}
