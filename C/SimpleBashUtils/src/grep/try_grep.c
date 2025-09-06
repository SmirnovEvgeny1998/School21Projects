#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

void clear_string(char *massive);
void to_upper_case(char *massive);
void flags_v_f(char *massive, char *pattern, char *path);
int all_grep(char *path, char *pattern, int undemanding_register, int inverted,
             int counting, int file_only, int number_strings, int without_names,
             int without_error, int file_pattern, int only_pattern,
             int argument_count, int file_counter, char *massive_v_f);
void print_file_names_numbers(int file_names, int numbers, char *file,
                              int number, int argument_count);

int main(int argc, char *argv[]) {
  char pattern[1000] = {'\0'};
  char massive_v_f[100000] = {'\0'};
  char short_options[] = "e:ivclnhsf:o";
  const struct option long_options[] = {{NULL, 0, NULL, 0}};
  int error = 1;
  int rez;
  int option_index;
  int flag_e = 0, flag_i = 0, flag_v = 0, flag_c = 0, flag_l = 0, flag_n = 0,
      flag_h = 0, flag_s = 0, flag_f = 0, flag_o = 0;
  int argument_count = 0;
  for (int j = 0; j < 100000; j++) {
    massive_v_f[j] = '\0';
  }
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    if (rez == 'e') {
      flag_e = 1;
    } else if (rez == 'i') {
      flag_i = 1;
    } else if (rez == 'v') {
      flag_v = 1;
    } else if (rez == 'c') {
      flag_c = 1;
    } else if (rez == 'l') {
      flag_l = 1;
    } else if (rez == 'n') {
      flag_n = 1;
    } else if (rez == 'h') {
      flag_h = 1;
    } else if (rez == 's') {
      flag_s = 1;
    } else if (rez == 'f') {
      flag_f = 1;
    } else if (rez == 'o') {
      flag_o = 1;
    } else {
      error = 0;
    }
  };
  for (int i = 0; i < argc; i++) {
    if (argv[i][0] != '-') {
      argument_count++;
    }
  }
  if (error == 1) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        for (int j = 0; j < 100000; j++) {
          massive_v_f[j] = '\0';
        }
        if (strlen(pattern) == 0) {
          strcpy(pattern, argv[i]);
        } else {
          // use_grep(flag_e, flag_i, flag_v, flag_c, flag_l, flag_n, argv[i],
          // pattern, flag_h, flag_s, flag_f, flag_o);
          int no_matter;
          no_matter = all_grep(argv[i], pattern, flag_i, flag_v, flag_c, flag_l,
                               flag_n, flag_h, flag_s, flag_f, flag_o,
                               argument_count, 0, massive_v_f);
          if (error > 1000) {
            printf("%d", no_matter);
          }
        }
      }
    }
  } else {
    printf("Something gone wrong\n");
  }
  if (error > 1000) {
    printf("%d", flag_e);
  }
}

void clear_string(char *massive) {
  int length = 0;
  if (massive != NULL) {
    length = strlen(massive);
    for (int i = 0; i < length; i++) {
      massive[i] = '\0';
    }
  }
}

void to_upper_case(char *massive) {
  int counter = 0;
  while (massive[counter] != EOF && massive[counter] != '\0') {
    if ('a' <= massive[counter] && massive[counter] <= 'z') {
      massive[counter] += 'A' - 'a';
    }
    counter++;
  }
}

void flags_v_f(char *massive, char *pattern, char *path) {
  if (strlen(massive) == 0) {
    FILE *fp;
    char temp;
    int counter = 0;
    fp = fopen(path, "r");
    if (fp != NULL) {
      temp = getc(fp);
      while (temp != EOF) {
        massive[counter] = temp;
        counter++;
        temp = getc(fp);
      }
    }
    massive[counter] = '\0';
    fclose(fp);
  }
  char copy_massive[100000] = {'\0'}, buffer[100000] = {'\0'};
  int length = 0, buffer_counter = 0;
  regex_t reegex;
  int value;
  for (int j = 0; j < 100000; j++) {
    copy_massive[j] = '\0';
  }
  value = regcomp(&reegex, pattern, 0);
  length = strlen(massive);
  for (int i = 0; i < length; i++) {
    if (massive[i] != 10) {
      buffer[buffer_counter] = massive[i];
      buffer_counter++;
      if (massive[i + 1] == '\0') {
        value = regexec(&reegex, buffer, 0, NULL, 0);
        if (value != 0) {
          strcat(copy_massive, buffer);
        }
        buffer_counter = 0;
        for (int j = 0; j < 100000; j++) {
          buffer[j] = '\0';
        }
      }
    } else {
      buffer[buffer_counter] = massive[i];
      value = regexec(&reegex, buffer, 0, NULL, 0);
      if (value != 0) {
        strcat(copy_massive, buffer);
      }
      buffer_counter = 0;
      for (int j = 0; j < 100000; j++) {
        buffer[j] = '\0';
      }
    }
  }
  for (int j = 0; j < 100000; j++) {
    massive[j] = '\0';
  }
  strcpy(massive, copy_massive);
  regfree(&reegex);
}

/*
 i - register
 v - invertion
 c - number of
 l - files
 n - numbers in the beginning
 h - without file names
 s - without error messages
 f - use file to find patterns
 o - print only pattern
 */

int all_grep(char *path, char *pattern, int undemanding_register, int inverted,
             int counting, int file_only, int number_strings, int without_names,
             int without_error, int file_pattern, int only_pattern,
             int argument_count, int file_counter, char *massive_v_f) {
  FILE *fp = NULL;
  char temp, *pointer = NULL;
  int buffer_counter = 0, string_counter = 1, matches_counter = 0,
      return_value = 0, break_analog = 1;
  regex_t reegex;
  int value;
  char buffer[10000] = {'\0'}, buffer_copy[10000] = {'\0'};
  clear_string(buffer);

  if (file_pattern == 1) {
    fp = fopen(pattern, "r");
    if (fp != NULL) {
      temp = getc(fp);
      while (temp != EOF) {
        while (temp != 10 && temp != EOF) {
          buffer[buffer_counter] = temp;
          buffer_counter++;
          temp = getc(fp);
        }
        return_value +=
            all_grep(path, buffer, undemanding_register, inverted, counting,
                     file_only, number_strings, without_names, without_error, 0,
                     only_pattern, argument_count, 1, massive_v_f);
        buffer_counter = 0;
        clear_string(buffer);
        temp = getc(fp);
      }
    }
    if (counting == 1) {
      print_file_names_numbers(without_names, 0, path, 0, argument_count);
      printf("%d\n", return_value);
    }
  } else if (inverted == 1 && file_counter == 1 && undemanding_register == 0 &&
             counting == 0 && file_only == 0 && number_strings == 0 &&
             without_names == 0 && without_error == 0 && only_pattern == 0) {
    flags_v_f(massive_v_f, pattern, path);
  } else {
    if (undemanding_register == 1) {
      to_upper_case(pattern);
    }
    value = regcomp(&reegex, pattern, 0);
    fp = fopen(path, "r");
    clear_string(buffer);
    clear_string(buffer_copy);
    if (fp != NULL) {
      temp = getc(fp);
      while (temp != EOF && break_analog == 1) {
        while (temp != 10 && temp != EOF) {
          buffer[buffer_counter] = temp;
          buffer_copy[buffer_counter] = temp;
          buffer_counter++;
          temp = getc(fp);
        }
        if (temp == 10) {
          buffer[buffer_counter] = temp;
          buffer_copy[buffer_counter] = temp;
        }
        if (undemanding_register == 1) {
          to_upper_case(buffer);
        }
        value = regexec(&reegex, buffer, 0, NULL, 0);
        if (value == 0) {
          if (file_only == 1) {
            if (inverted != 1) {
              printf("%s\n", path);
              break_analog = 0;
            }
          } else if (counting == 1) {
            if (inverted != 1) {
              matches_counter++;
            }
          } else if (only_pattern == 1) {
            if (inverted != 1) {
              print_file_names_numbers(without_names, number_strings, path,
                                       string_counter, argument_count);
              char *pattern_pointer;
              int pattern_pointer_counter = 0;
              pattern_pointer = strstr(buffer, pattern);
              while (pattern_pointer != NULL) {
                pattern_pointer_counter++;
                *pattern_pointer = 9;
                pattern_pointer = strstr(buffer, pattern);
              }
              for (int i = 0; i < pattern_pointer_counter; i++) {
                printf("%s\n", pattern);
              }
            }
          } else {
            if (inverted != 1) {
              print_file_names_numbers(without_names, number_strings, path,
                                       string_counter, argument_count);
              printf("%s", buffer_copy);
              pointer = strchr(buffer_copy, 10);
              if (pointer == NULL) {
                printf("\n");
              }
            }
          }
        } else {
          if (file_only == 1) {
            if (inverted == 1) {
              if (file_counter == 1) {
                flags_v_f(massive_v_f, pattern, path);
              } else {
                printf("%s\n", path);
              }
              break_analog = 0;
            }
          } else if (counting == 1) {
            if (inverted == 1) {
              matches_counter++;
            }
          } else if (only_pattern == 1) {
            if (inverted == 1) {
              print_file_names_numbers(without_names, number_strings, path,
                                       string_counter, argument_count);
              printf("%s", buffer);
              temp = getc(fp);
              if (temp == EOF) {
                printf("\n");
              } else {
                ungetc(temp, fp);
              }
            }
          } else {
            if (inverted == 1) {
              print_file_names_numbers(without_names, number_strings, path,
                                       string_counter, argument_count);
              printf("%s", buffer_copy);
              pointer = strchr(buffer_copy, 10);
              if (pointer == NULL) {
                printf("\n");
              }
            }
          }
        }
        string_counter++;
        buffer_counter = 0;
        clear_string(buffer);
        clear_string(buffer_copy);
        temp = getc(fp);
      }
    } else {
      if (without_error != 1) {
        printf("grep: %s: No such file or directory\n", path);
      }
    }
    regfree(&reegex);
  }
  if (counting == 1 && file_pattern != 1) {
    if (file_counter == 0) {
      print_file_names_numbers(without_names, 0, path, 0, argument_count);
      if (file_only != 1) {
        printf("%d\n", matches_counter);
      }
    } else {
      return_value = matches_counter;
    }
  }
  if (inverted == 1 && file_pattern == 1 && file_only != 1) {
    printf("%s\n", massive_v_f);
  }
  if (inverted == 1 && file_pattern == 1 && file_only == 1) {
    printf("%s\n", path);
  }
  if (fp != NULL) {
    fclose(fp);
  }
  return return_value;
}

void print_file_names_numbers(int file_names, int numbers, char *file,
                              int number, int argument_count) {
  if (file_names != 1 && argument_count != 3) {
    printf("%s:", file);
  }
  if (numbers == 1) {
    printf("%d:", number);
  }
}
