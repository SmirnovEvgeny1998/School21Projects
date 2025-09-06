#include "calc_model.h"

#include <stdio.h>
#include <stdlib.h>

s21::calc_controller::calc_controller() {}

int s21::calc_controller::check_equation_line(std::string line, int check_x) {
  int no_error = 0;
  if (line.length() == 5) {
    no_error = 1;
  } else if (this->check_begining(line)) {
    no_error = 2;
  } else if (this->check_points(line)) {
    no_error = 3;
  } else if (this->check_brackets(line)) {
    no_error = 4;
  } else if (this->check_correctness(line)) {
    no_error = 5;
  } else if (this->check_only_number(line)) {
    no_error = 6;
  } else if (line.find("x") != std::string::npos && check_x == 1) {
    no_error = 7;
  } else if (this->check_sin_brackets(line)) {
    no_error = 8;
  }
  return no_error;
}

bool s21::calc_controller::check_begining(std::string string) {
  bool error = false;
  if ((string[0] <= '9' && string[0] >= '0') || string[0] == 'x' ||
      string[0] == '(') {
    error = false;
  } else if (string[0] <= 'z' && string[0] >= 'a' && string[0] != 'm') {
    error = false;
  } else if (string[0] == '-' || string[0] == '+') {
    if ((string[1] <= '9' && string[1] >= '0') || string[1] == 'x' ||
        string[1] == '(') {
      error = false;
    } else {
      error = true;
    }
  } else {
    error = true;
  }
  return error;
}

bool s21::calc_controller::check_correctness(std::string string) {
  int result = 0, current_char_is_num = 0, znak_counter = 0,
      there_was_a_point = 0, there_was_a_e = 0;
  if (string.find("xe") != std::string::npos ||
      string.find("ex") != std::string::npos) {
    result = 1;
  }
  for (long unsigned int i = 0; i < string.length() && result == 0; i++) {
    if (znak_counter >= 3) {
      result = 1;
    } else if (znak_counter == 2 && string[i - 1] != '-' &&
               string[i - 1] != '+' && string[i - 1] != '(') {
      result = 1;
    } else if ((string[i] >= '0' && string[i] <= '9') || string[i] == 'x') {
      current_char_is_num = 1;
      znak_counter = 0;
    } else if ((string[i] == '.' || string[i] == 'e') &&
               current_char_is_num == 0) {
      result = 1;
    } else if (string[i] == '.' &&
               (there_was_a_point != 0 || there_was_a_e != 0)) {
      result = 1;
    } else if (string[i] == 'e' && there_was_a_e != 0) {
      result = 1;
    } else if (string[i] == '.') {
      there_was_a_point = 1;
    } else if (string[i] == 'e') {
      there_was_a_e = 1;
    } else {
      current_char_is_num = 0;
      there_was_a_point = 0;
      there_was_a_e = 0;
      if (string[i] == ' ') {
        i += 10;
      } else if (string[i + 1] == 'n') {
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
  for (long unsigned int i = 0; i < string.length() && result == 0; i++) {
    if ((string[i] >= '0' && string[i] <= '9') || string[i] == 'x') {
      if ((string[i + 1] >= 'a' && string[i + 1] <= 'z' &&
           string[i + 1] != 'm' && string[i + 1] != 'e') ||
          string[i + 1] == '(') {
        result = 1;
      }
    }
  }
  if ((string[0] == '-' || string[0] == '+') && string[1] == '(') {
    result = 1;
  }
  for (long unsigned int i = 2; i < string.length() && result == 0; i++) {
    if (string[i] == '(' && (string[i - 1] == '-' || string[i - 1] == '+')) {
      if (!(string[i - 2] == ')' || string[i - 2] == 'x' ||
            (string[i - 2] >= '0' && string[i - 2] <= '9'))) {
        result = 1;
      }
    }
  }
  return (bool)result;
}

bool s21::calc_controller::check_points(std::string string) {
  bool error = false;
  if (string.find(".x") != std::string::npos ||
      string.find("x.") != std::string::npos ||
      string.find("..") != std::string::npos) {
    error = true;
  }
  for (long unsigned int i = 0; i < string.length() && error == false; i++) {
    if (string[i] == '.') {
      if (!(string[i + 1] >= '0' && string[i + 1] <= '9') ||
          !(string[i - 1] >= '0' && string[i - 1] <= '9')) {
        error = true;
      }
    }
  }
  return error;
}

bool s21::calc_controller::check_brackets(std::string string) {
  bool error = false;
  int left_br = 0, right_br = 0;
  for (long unsigned int i = 0; i < string.length() && error == false; i++) {
    if (string[i] == '(') {
      left_br += 1;
    } else if (string[i] == ')' && right_br >= left_br) {
      error = true;
    } else if (string[i] == ')') {
      right_br += 1;
    }
  }
  if (left_br != right_br) {
    error = true;
  }
  if (string.find("()") != std::string::npos) {
    error = true;
  }
  return error;
}

bool s21::calc_controller::check_only_number(std::string string) {
  bool error = true;
  std::string numbers("0123456789.");
  string = string.substr(0, string.length() - 5);
  for (long unsigned int i = 0; i < string.length() && error == true; i++) {
    if (!(numbers.find(string[i]) != std::string::npos)) {
      if (i != 0 || string[i] != '-') {
        error = false;
      }
    }
  }
  if (string.length() == 0) {
    error = false;
  }
  return error;
}

bool s21::calc_controller::check_sin_brackets(std::string string) {
  bool error = false;
  for (long unsigned int i = 0; i < string.length() && error == false; i++) {
    if ((string[i] == 's' && i != 0 && string[i - 1] == 'o') ||
        string[i] == 'n' ||
        (string[i] == 't' && i != 0 && string[i - 1] == 'r') ||
        string[i] == 'g') {
      if (string[i + 1] != '(') {
        error = true;
      }
    }
  }
  return error;
}

std::string *s21::calc_controller::break_string(std::string string,
                                                bool *no_error, int *length) {
  //выход за пределы массива проверить
  static std::string result[300];
  std::string numbers("0123456789."), short_signs("-+*/^()"),
      long_signs("sin cos tan sqrt ln log mod asin acos atan");
  int result_counter = 0;
  for (long unsigned int i = 0; i < string.length() && *no_error == true; i++) {
    if (long_signs.find(string[i]) != std::string::npos) {
      if (i + 3 >= string.length()) {
        *no_error = false;
      } else if (string.substr(i, 3) == "sin") {
        result[result_counter] = "sin";
        result_counter += 1;
        i += 2;
      } else if (string.substr(i, 3) == "cos") {
        result[result_counter] = "cos";
        result_counter += 1;
        i += 2;
      } else if (string.substr(i, 3) == "tan") {
        result[result_counter] = "tan";
        result_counter += 1;
        i += 2;
      } else if (string.substr(i, 4) == "sqrt") {
        result[result_counter] = "sqrt";
        result_counter += 1;
        i += 3;
      } else if (string.substr(i, 2) == "ln") {
        result[result_counter] = "ln";
        result_counter += 1;
        i += 1;
      } else if (string.substr(i, 3) == "log") {
        result[result_counter] = "log";
        result_counter += 1;
        i += 2;
      } else if (string.substr(i, 3) == "mod") {
        result[result_counter] = "mod";
        result_counter += 1;
        i += 2;
      } else if (string.substr(i, 4) == "asin") {
        result[result_counter] = "asin";
        result_counter += 1;
        i += 3;
      } else if (string.substr(i, 4) == "acos") {
        result[result_counter] = "acos";
        result_counter += 1;
        i += 3;
      } else if (string.substr(i, 4) == "atan") {
        result[result_counter] = "atan";
        result_counter += 1;
        i += 3;
      } else {
        *no_error = false;
      }
    } else if (short_signs.find(string[i]) != std::string::npos) {
      if (string[i] == '-') {
        if (i == 0 ||
            short_signs.substr(0, 6).find(string[i - 1]) != std::string::npos ||
            string[i - 1] == 'd') {
          string[i] = '~';
          result[result_counter] = "~";
          result_counter += 1;
        } else {
          result[result_counter] = "-";
          result_counter += 1;
        }
      } else if (string[i] == '+') {
        if (!(i == 0 ||
              short_signs.substr(0, 6).find(string[i - 1]) !=
                  std::string::npos ||
              string[i - 1] == 'd')) {
          result[result_counter] = "+";
          result_counter += 1;
        }
      } else {
        result[result_counter] = string[i];
        result_counter += 1;
      }
    } else if (numbers.find(string[i]) != std::string::npos) {
      while (i + 1 < string.length() &&
             numbers.find(string[i + 1]) != std::string::npos) {
        result[result_counter] += string[i];
        i += 1;
      }
      result[result_counter] += string[i];
      result_counter += 1;
    } else {
      *no_error = false;
    }
  }
  *length = result_counter;
  if (*no_error == false) {
    for (int i = 0; i < result_counter; i++) {
      result[i] = "";
    }
  }
  return result;
}

std::string *s21::calc_controller::string_to_djicstra(std::string *string,
                                                      int length) {
  std::string buffer[300], numbers("0123456789."), low_priority("+-"),
      mid_priority("*/ mod"),
      high_priority("sin cos tan sqrt ln log asin acos atan ^ ~"), result;
  static std::string equation[300];
  buffer[0] = "end";
  int equation_counter = 0, buffer_counter = 1;
  for (int i = 0; i < length; i++) {
    if (numbers.find(string[i][0]) != std::string::npos) {
      equation[equation_counter] = string[i];
      equation_counter += 1;
    } else if (string[i] == "(") {
      buffer[buffer_counter] = string[i];
      buffer_counter += 1;
    } else if (low_priority.find(string[i]) != std::string::npos) {
      if (buffer[buffer_counter - 1] == "end" ||
          buffer[buffer_counter - 1] == "(") {
        buffer[buffer_counter] = string[i];
        buffer_counter += 1;
      } else {
        equation[equation_counter] = buffer[buffer_counter - 1];
        equation_counter += 1;
        buffer[buffer_counter - 1] = "";
        buffer_counter -= 1;
        i -= 1;
      }
    } else if (mid_priority.find(string[i]) != std::string::npos) {
      if (buffer[buffer_counter - 1] == "end" ||
          low_priority.find(buffer[buffer_counter - 1]) != std::string::npos ||
          buffer[buffer_counter - 1] == "(") {
        buffer[buffer_counter] = string[i];
        buffer_counter += 1;
      } else {
        equation[equation_counter] = buffer[buffer_counter - 1];
        equation_counter += 1;
        buffer[buffer_counter - 1] = "";
        buffer_counter -= 1;
        i -= 1;
      }
    } else if (high_priority.find(string[i]) != std::string::npos) {
      if (buffer[buffer_counter - 1] == "end" ||
          low_priority.find(buffer[buffer_counter - 1]) != std::string::npos ||
          mid_priority.find(buffer[buffer_counter - 1]) != std::string::npos ||
          buffer[buffer_counter - 1] == "(" || string[i] != "^") {
        buffer[buffer_counter] = string[i];
        buffer_counter += 1;
      } else {
        equation[equation_counter] = buffer[buffer_counter - 1];
        equation_counter += 1;
        buffer[buffer_counter - 1] = "";
        buffer_counter -= 1;
        i -= 1;
      }
    } else if (string[i] == ")") {
      if (buffer[buffer_counter - 1] == "(") {
        buffer[buffer_counter - 1] = "";
        buffer_counter -= 1;
      } else {
        equation[equation_counter] = buffer[buffer_counter - 1];
        equation_counter += 1;
        buffer[buffer_counter - 1] = "";
        buffer_counter -= 1;
        i -= 1;
      }
    }
  }
  while (buffer_counter > 1) {
    equation[equation_counter] = buffer[buffer_counter - 1];
    buffer_counter -= 1;
    equation_counter += 1;
  }
  for (int i = 0; i < length; i++) {
    string[i] = "";
  }
  return equation;
}

double s21::calc_controller::calculation(std::string *string, int length) {
  int counter = 0;
  std::string numbers("0123456789."), two_variables("*/mod+-^"),
      one_variable("sin cos tan ln log asin acos atan sqrt ~");
  double precision_massive[300];
  for (int i = 0; i < length; i++) {
    for (long unsigned int j = 0; j < string[i].length(); j++) {
      if (numbers.find(string[i][j]) != std::string::npos) {
        precision_massive[i] = atof(string[i].c_str());
        string[i] = "]";
        break;
      }
    }
  }
  while (length != 1) {
    if (one_variable.find(string[counter]) != std::string::npos) {
      calculation_one_var(string, counter, precision_massive);
      pop(string, length, counter);
      pop(precision_massive, length, counter);
      counter -= 1;
      length -= 1;
    } else if (two_variables.find(string[counter]) != std::string::npos) {
      calculation_two_var(string, counter, precision_massive);
      pop(string, length, counter - 1);
      pop(string, length, counter - 1);
      pop(precision_massive, length, counter - 1);
      pop(precision_massive, length, counter - 1);
      counter -= 2;
      length -= 2;
    } else {
      counter += 1;
    }
  }
  // double result = atof(string[0].c_str());
  double result = precision_massive[0];
  string[0] = "";
  return result;
}

void s21::calc_controller::calculation_one_var(std::string *string, int pointer,
                                               double *precision_massive) {
  if (string[pointer] == "sin") {
    precision_massive[pointer - 1] = sin(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "cos") {
    precision_massive[pointer - 1] = cos(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "tan") {
    precision_massive[pointer - 1] = tan(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "asin") {
    precision_massive[pointer - 1] = asin(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "acos") {
    precision_massive[pointer - 1] = acos(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "atan") {
    precision_massive[pointer - 1] = atan(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "ln") {
    precision_massive[pointer - 1] = log(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "log") {
    precision_massive[pointer - 1] = log10(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  } else if (string[pointer] == "~") {
    precision_massive[pointer - 1] = precision_massive[pointer - 1] * -1;
    string[pointer - 1] = "]";
  } else if (string[pointer] == "sqrt") {
    precision_massive[pointer - 1] = sqrt(precision_massive[pointer - 1]);
    string[pointer - 1] = "]";
  }
}

void s21::calc_controller::calculation_two_var(std::string *string, int pointer,
                                               double *precision_massive) {
  if (string[pointer] == "+") {
    precision_massive[pointer - 2] =
        precision_massive[pointer - 2] + precision_massive[pointer - 1];
    string[pointer - 2] = "]";
  } else if (string[pointer] == "-") {
    precision_massive[pointer - 2] =
        precision_massive[pointer - 2] - precision_massive[pointer - 1];
    string[pointer - 2] = "]";
  } else if (string[pointer] == "*") {
    precision_massive[pointer - 2] =
        precision_massive[pointer - 2] * precision_massive[pointer - 1];
    string[pointer - 2] = "]";
  } else if (string[pointer] == "/") {
    precision_massive[pointer - 2] =
        precision_massive[pointer - 2] / precision_massive[pointer - 1];
    string[pointer - 2] = "]";
  } else if (string[pointer] == "^") {
    precision_massive[pointer - 2] =
        pow(precision_massive[pointer - 2], precision_massive[pointer - 1]);
    string[pointer - 2] = "]";
  } else if (string[pointer] == "mod") {
    precision_massive[pointer - 2] =
        fmod(precision_massive[pointer - 2], precision_massive[pointer - 1]);
    string[pointer - 2] = "]";
  }
}

void s21::calc_controller::pop(std::string *string, int length, int position) {
  while (position < length - 1) {
    string[position] = string[position + 1];
    position += 1;
  }
  string[position] = "";
}

void s21::calc_controller::pop(double *string, int length, int position) {
  while (position < length - 1) {
    string[position] = string[position + 1];
    position += 1;
  }
  string[position] = 0;
}

std::string s21::calc_controller::change_scientific_notation(
    std::string string) {
  long unsigned int start_index = 0, end_index = 0, e_index = 0;
  std::string science = "", numbers = "0123456789.";
  while (string.find("e") != std::string::npos) {
    e_index = string.find('e');
    for (int i = e_index - 1;
         i >= 0 && numbers.find(string[i]) != std::string::npos; i--) {
      start_index = i;
    }
    for (long unsigned int i = e_index + 1;
         i < string.length() &&
         (numbers.find(string[i]) != std::string::npos ||
          (i == e_index + 1 && (string[i] == '-' || string[i] == '+')));
         i++) {
      end_index = i;
    }
    science = string.substr(start_index, end_index - start_index + 1);
    string.replace(start_index, end_index - start_index + 1,
                   std::to_string(atof(science.c_str())));
  }
  return string;
}
