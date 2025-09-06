#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "cat_functions.h"
#include "cat_other_functions.h"

int main(int argc, char* argv[]) {
  const char* short_options = "bevEnstT";

  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

  int error = 1;
  int rez;
  int option_index;
  int flag_b = 0, flag_e = 0, flag_v = 0, flag_E = 0, flag_n = 0, flag_s = 0,
      flag_t = 0, flag_T = 0;
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    if (rez == 'b') {
      flag_b = 1;
    } else if (rez == 'e') {
      flag_e = 1;
    } else if (rez == 'v') {
      flag_v = 1;
    } else if (rez == 'E') {
      flag_E = 1;
    } else if (rez == 'n') {
      flag_n = 1;
    } else if (rez == 's') {
      flag_s = 1;
    } else if (rez == 't') {
      flag_t = 1;
    } else if (rez == 'T') {
      flag_T = 1;
    } else {
      error = 0;
    }
  };
  if (flag_b == 1 && flag_n == 1) {
    flag_n = 0;
  }
  if (flag_v == 1 && flag_e == 1) {
    flag_v = 0;
  }
  if (flag_v == 1 && flag_t == 1) {
    flag_v = 0;
  }
  if (error == 1) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        // use_cat(flag_b, flag_e, flag_v, flag_E, flag_n, flag_s, flag_t,
        // flag_T, argv[i]);
        all_cat(flag_b, flag_e, flag_n, flag_s, flag_t, flag_v, argv[i], flag_E,
                flag_T);
      }
    }
  } else {
    printf("Something gone wrong");
  }
}
