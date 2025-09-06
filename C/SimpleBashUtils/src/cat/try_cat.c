#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

void space_print(int number);
void all_cat(int flag_b, int flag_e, int flag_n, int flag_s, int flag_t,
             int flag_v, char *path, int flag_E, int flag_T);

int main(int argc, char *argv[]) {
  const char *short_options = "bevEnstT";

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

void space_print(int number) {
  if (number >= 0 && number < 10) {
    printf("     ");
    printf("%d", number);
  } else if (number >= 10 && number < 100) {
    printf("    ");
    printf("%d", number);
  } else if (number >= 100 && number < 1000) {
    printf("   ");
    printf("%d", number);
  } else if (number >= 1000 && number < 10000) {
    printf("  ");
    printf("%d", number);
  } else if (number >= 10000 && number < 100000) {
    printf(" ");
    printf("%d", number);
  } else if (number >= 100000 && number < 1000000) {
    printf("%d", number);
  }
}

void all_cat(int flag_b, int flag_e, int flag_n, int flag_s, int flag_t,
             int flag_v, char *path, int flag_E, int flag_T) {
  FILE *fp;
  char temp, tabulation = 9;
  ;
  int exist = 0, blanks = 0, counter = 1, first = 0;
  fp = fopen(path, "r");
  if (fp != NULL) {
    temp = getc(fp);
    if (flag_n == 1) {
      space_print(counter);
      printf("%c", tabulation);
      counter++;
    }
    if (flag_b == 1 && temp != 10 && temp != EOF) {
      space_print(counter);
      printf("%c", tabulation);
      counter++;
      first = 1;
    }
    while (temp != EOF) {
      if (flag_s == 1) {
        if (temp == 10) {
          first = 0;
          if (exist == 0) {
            if (blanks != 0) {
              blanks++;
              temp = getc(fp);
            } else {
              blanks++;
              if (flag_e == 1 || flag_E == 1) {
                if (temp == 10) {
                  printf("$");
                }
              }
              printf("%c", temp);
              if (flag_n == 1) {
                temp = getc(fp);
                if (temp != EOF) {
                  ungetc(temp, fp);
                  space_print(counter);
                  printf("%c", tabulation);
                  counter++;
                }
              }
              temp = getc(fp);
            }
          } else {
            if (flag_e == 1 || flag_E == 1) {
              if (temp == 10) {
                printf("$");
              }
            }
            printf("%c", temp);
            exist = 0;
            blanks = 0;
            if (flag_n == 1) {
              temp = getc(fp);
              if (temp != EOF) {
                ungetc(temp, fp);
                space_print(counter);
                printf("%c", tabulation);
                counter++;
              }
            }
            temp = getc(fp);
          }
        } else {
          if (flag_b == 1 && first == 0) {
            space_print(counter);
            printf("%c", tabulation);
            counter++;
            first = 1;
          }
          if (flag_e == 1) {
            if (temp < 32 && temp != 10 && temp != 9) {
              printf("^");
              temp += 64;
              printf("%c", temp);
              temp = getc(fp);
            }
            if (temp >= 127) {
              printf("^?");
              temp = getc(fp);
            }
          } else if (flag_v == 1) {
            if (temp < 32 && temp != 10 && temp != 9) {
              printf("^");
              temp += 64;
              printf("%c", temp);
              temp = getc(fp);
            }
            if (temp >= 127) {
              printf("^?");
              temp = getc(fp);
            }
          }
          exist = 1;
          while (temp != 10 && temp != EOF) {
            if (flag_T == 1 && flag_t == 0 && temp == 9) {
              printf("^");
              temp += 64;
              printf("%c", temp);
              temp = getc(fp);
            } else if (flag_t == 1 && temp < 32 && temp != 10) {
              printf("^");
              temp += 64;
              printf("%c", temp);
              temp = getc(fp);
            } else if (flag_t == 1 && temp >= 127) {
              printf("^?");
              temp = getc(fp);
            } else if (flag_e == 1 && temp < 32 && temp != 9) {
              if (temp < 32 && temp != 10 && temp != 9) {
                printf("^");
                temp += 64;
                printf("%c", temp);
                temp = getc(fp);
              }
            } else if (flag_e == 1 && temp >= 127) {
              printf("^?");
              temp = getc(fp);
            } else if (flag_v == 1 && temp < 32 && temp != 9 && temp != 10) {
              if (temp < 32 && temp != 10 && temp != 9) {
                printf("^");
                temp += 64;
                printf("%c", temp);
                temp = getc(fp);
              }
            } else if (flag_v == 1 && temp >= 127) {
              if (temp >= 127) {
                printf("^?");
                temp = getc(fp);
              }
            } else {
              printf("%c", temp);
              temp = getc(fp);
            }
          }
        }
      } else {
        if (flag_e == 1) {
          if (temp == 10) {
            printf("$");
          }
          if (temp < 32 && temp != 10 && temp != 9) {
            printf("^");
            temp += 64;
            printf("%c", temp);
            temp = getc(fp);
          }
          if (temp >= 127) {
            printf("^?");
            temp = getc(fp);
          }
        } else if (flag_v == 1) {
          if (temp < 32 && temp != 10 && temp != 9) {
            printf("^");
            temp += 64;
            printf("%c", temp);
            temp = getc(fp);
          }
          if (temp >= 127) {
            printf("^?");
            temp = getc(fp);
          }
        }
        if (flag_E == 1 && flag_e != 1) {
          if (temp == 10) {
            printf("$");
          }
        }
        if (flag_T == 1 && flag_t == 0 && temp == 9) {
          printf("^");
          temp += 64;
          printf("%c", temp);
          temp = getc(fp);
        } else if (flag_t == 1 && temp < 32 && temp != 10) {
          printf("^");
          temp += 64;
          printf("%c", temp);
          temp = getc(fp);
        } else if (flag_t == 1 && temp >= 127) {
          printf("^?");
          temp = getc(fp);
        } else {
          printf("%c", temp);
          if (flag_n == 1 && temp == 10) {
            temp = getc(fp);
            if (temp != EOF) {
              ungetc(temp, fp);
              space_print(counter);
              printf("%c", tabulation);
              counter++;
              temp = getc(fp);
            }
          } else if (flag_b == 1 && temp == 10) {
            while (temp == 10) {
              temp = getc(fp);
              if (temp == 10) {
                if (flag_e == 1 || flag_E == 1) {
                  printf("$");
                }
                printf("%c", temp);
              }
            }
            if (temp != EOF) {
              space_print(counter);
              printf("%c", tabulation);
              counter++;
            }
          } else {
            exist = 1;
            temp = getc(fp);
          }
        }
      }
    }
  } else {
    printf("\nError %s: No such file or directory\n", path);
  }
  fclose(fp);
}
