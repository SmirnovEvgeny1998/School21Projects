#include "cat_other_functions.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

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
