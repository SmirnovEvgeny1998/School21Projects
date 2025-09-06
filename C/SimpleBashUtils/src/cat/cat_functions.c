#include "cat_functions.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "cat_other_functions.h"

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
