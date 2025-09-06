#include <check.h>
#include <getopt.h>
#include <math.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

Suite *string_suite(void);

int main() {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = string_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 0;
}

START_TEST(test_memchr_1) {
  char *original, *s21;
  original = memchr("adfsd fgdhgg dgf gdf dfgh", 'd', 50);
  s21 = s21_memchr("adfsd fgdhgg dgf gdf dfgh", 'd', 50);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_memchr_2) {
  char *original, *s21;
  original = memchr("adfsd fgdhgg dgf gdf dfgh", ' ', 50);
  s21 = s21_memchr("adfsd fgdhgg dgf gdf dfgh", ' ', 50);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_memchr_3) {
  char *original, *s21;
  original = memchr("adfsd fgdhgg dgf gdf dfgh", 102, 50);
  s21 = s21_memchr("adfsd fgdhgg dgf gdf dfgh", 102, 50);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_memchr_4) {
  char *original, *s21;
  original = memchr("adfsd fgdhgg dgf4 gdf dfgh", '4', 50);
  s21 = s21_memchr("adfsd fgdhgg dgf4 gdf dfgh", '4', 50);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_memchr_5) {
  char *original, *s21;
  original = memchr("adfsd fgdhgg dgf4 gdf dfgh", 'h', 5);
  s21 = s21_memchr("adfsd fgdhgg dgf4 gdf dfgh", 'h', 5);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_memchr_6) {
  char *original, *s21;
  original = memchr("adfsd fgdhgg dgf4 gdf dfgh", '\0', 28);
  s21 = s21_memchr("adfsd fgdhgg dgf4 gdf dfgh", '\0', 28);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_memcmp_1) {
  int original, s21;
  original = memcmp("adfsdftttttttty", "adfsd fgdhgg dgf gdf dfgh", 5);
  s21 = s21_memcmp("adfsdftttttttty", "adfsd fgdhgg dgf gdf dfgh", 5);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_memcmp_2) {
  int original, s21;
  original = memcmp("adfsdftttttttty", "adfsd fgdhgg dgf gdf dfgh", 10);
  s21 = s21_memcmp("adfsdftttttttty", "adfsd fgdhgg dgf gdf dfgh", 10);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_memcmp_3) {
  int original, s21;
  original = memcmp("adfs dftttttttty", "adfsdfgdhgg dgf gdf dfgh", 10);
  s21 = s21_memcmp("adfs dftttttttty", "adfsdfgdhgg dgf gdf dfgh", 10);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_memcmp_4) {
  int original, s21;
  original = memcmp("adfs dftttttttty", "adfsdfgdhgg dgf gdf dfgh", 0);
  s21 = s21_memcmp("adfs dftttttttty", "adfsdfgdhgg dgf gdf dfgh", 0);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_memcmp_5) {
  int original, s21;
  original = memcmp("adfs dftttttttty", "adfsdfgdhgg dgf gdf dfgh", 5);
  s21 = s21_memcmp("adfs dftttttttty", "adfsdfgdhgg dgf gdf dfgh", 5);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_memcmp_6) {
  int original, s21;
  original = memcmp("", "", 0);
  s21 = s21_memcmp("", "", 0);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_memcpy_1) {
  char original_case_1_1[26] = {'\0'};
  char original_case_1_2[] = "adfsd fgdhgg dgf gdf dfgh";
  char s21_case_1_1[26] = {'\0'};
  char s21_case_1_2[] = "adfsd fgdhgg dgf gdf dfgh";
  memcpy(original_case_1_1, original_case_1_2, 25);
  s21_memcpy(s21_case_1_1, s21_case_1_2, 25);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memcpy_2) {
  char original_case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char original_case_1_2[] = "Some text";
  char s21_case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char s21_case_1_2[] = "Some text";
  memcpy(original_case_1_1, original_case_1_2, 9);
  s21_memcpy(s21_case_1_1, s21_case_1_2, 9);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memcpy_3) {
  char original_case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char original_case_1_2[] = "d";
  char s21_case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char s21_case_1_2[] = "d";
  memcpy(original_case_1_1, original_case_1_2, 1);
  s21_memcpy(s21_case_1_1, s21_case_1_2, 1);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memcpy_4) {
  char original_case_1_1[] = "";
  char original_case_1_2[] = "dfff";
  char s21_case_1_1[] = "";
  char s21_case_1_2[] = "dfff";
  memcpy(original_case_1_1, original_case_1_2, 0);
  s21_memcpy(s21_case_1_1, s21_case_1_2, 0);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memcpy_5) {
  char original_case_1_1[] = "Some text";
  char original_case_1_2[] = "Some";
  char s21_case_1_1[] = "Some text";
  char s21_case_1_2[] = "Some";
  memcpy(original_case_1_1, original_case_1_2, 4);
  s21_memcpy(s21_case_1_1, s21_case_1_2, 4);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memset_1) {
  char original_case_1_1[30] = "0123456789";
  char original_case_1_2 = 'y';
  char s21_case_1_1[30] = "0123456789";
  char s21_case_1_2 = 'y';
  memset(original_case_1_1, original_case_1_2, 20);
  s21_memset(s21_case_1_1, s21_case_1_2, 20);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memset_2) {
  char original_case_1_1[30] = "0123456789";
  char original_case_1_2 = 'y';
  char s21_case_1_1[30] = "0123456789";
  char s21_case_1_2 = 'y';
  memset(original_case_1_1, original_case_1_2, 5);
  s21_memset(s21_case_1_1, s21_case_1_2, 5);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memset_3) {
  char original_case_1_1[30] = "0123456789";
  char original_case_1_2 = 'y';
  char s21_case_1_1[30] = "0123456789";
  char s21_case_1_2 = 'y';
  memset(original_case_1_1, original_case_1_2, 1);
  s21_memset(s21_case_1_1, s21_case_1_2, 1);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_memset_4) {
  char original_case_1_1[30] = "";
  char original_case_1_2 = 'y';
  char s21_case_1_1[30] = "";
  char s21_case_1_2 = 'y';
  memset(original_case_1_1, original_case_1_2, 1);
  s21_memset(s21_case_1_1, s21_case_1_2, 1);
  ck_assert_str_eq(original_case_1_1, s21_case_1_1);
}
END_TEST

START_TEST(test_strncat_1) {
  char case_1_1[20] = "To be ";
  char case_1_2[] = "or not to be";
  char case_2_1[20] = "To be ";
  char case_2_2[] = "or not to be";
  s21_strncat(case_1_1, case_1_2, 6);
  strncat(case_2_1, case_2_2, 6);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncat_2) {
  char case_1_1[20] = "To be ";
  char case_1_2[] = "or not to be";
  char case_2_1[20] = "To be ";
  char case_2_2[] = "or not to be";
  s21_strncat(case_1_1, case_1_2, 1);
  strncat(case_2_1, case_2_2, 1);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncat_3) {
  char case_1_1[20] = "To be ";
  char case_1_2[] = "To be ";
  char case_2_1[20] = "To be ";
  char case_2_2[] = "To be ";
  s21_strncat(case_1_1, case_1_2, 1);
  strncat(case_2_1, case_2_2, 1);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncat_4) {
  char case_1_1[20] = "To be ";
  char case_1_2[] = "\0";
  char case_2_1[20] = "To be ";
  char case_2_2[] = "\0";
  s21_strncat(case_1_1, case_1_2, 1);
  strncat(case_2_1, case_2_2, 1);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncat_5) {
  char case_1_1[20] = "To be ";
  char case_1_2[] = "";
  char case_2_1[20] = "To be ";
  char case_2_2[] = "";
  s21_strncat(case_1_1, case_1_2, 1);
  strncat(case_2_1, case_2_2, 1);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncat_6) {
  char case_1_1[20] = "";
  char case_1_2[] = "Ney man";
  char case_2_1[20] = "";
  char case_2_2[] = "Ney man";
  s21_strncat(case_1_1, case_1_2, 3);
  strncat(case_2_1, case_2_2, 3);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncat_7) {
  char case_1_1[20] = "";
  char case_1_2[20] = "";
  char case_2_1[20] = "";
  char case_2_2[20] = "";
  s21_strncat(case_1_1, case_1_2, 1);
  strncat(case_2_1, case_2_2, 1);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strchr_1) {
  char *original, *s21;
  char case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2 = 'd';
  original = strchr(case_1_1, case_1_2);
  s21 = s21_strchr(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strchr_2) {
  char *original, *s21;
  char case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2 = 'z';
  original = strchr(case_1_1, case_1_2);
  s21 = s21_strchr(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strchr_3) {
  char *original, *s21;
  char case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2 = 97;
  original = strchr(case_1_1, case_1_2);
  s21 = s21_strchr(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strncmp_1) {
  char case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2[] = "adfsd fgdhgg dgf gdf dfgh";
  int int_1 = 0, int_2 = 0;
  int_1 = s21_strncmp(case_1_1, case_1_2, 12);
  int_2 = strncmp(case_1_1, case_1_2, 12);
  ck_assert_int_eq(int_1, int_2);
}
END_TEST

START_TEST(test_strncmp_2) {
  char case_1_1[] = "";
  char case_1_2[] = "";
  int int_1 = 0, int_2 = 0;
  int_1 = s21_strncmp(case_1_1, case_1_2, 1);
  int_2 = strncmp(case_1_1, case_1_2, 1);
  ck_assert_int_eq(int_1, int_2);
}
END_TEST

START_TEST(test_strncmp_3) {
  char case_1_1[30] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2[30] = "";
  int int_1 = 0, int_2 = 0;
  int_1 = s21_strncmp(case_1_1, case_1_2, 12);
  int_2 = strncmp(case_1_1, case_1_2, 12);
  ck_assert_int_eq(int_1, int_2);
}
END_TEST

START_TEST(test_strncmp_4) {
  char case_1_1[30] = "";
  char case_1_2[30] = "adfsd fgdhgg dgf gdf dfgh";
  int int_1 = 0, int_2 = 0;
  int_1 = s21_strncmp(case_1_1, case_1_2, 12);
  int_2 = strncmp(case_1_1, case_1_2, 12);
  ck_assert_int_eq(int_1, int_2);
}
END_TEST

START_TEST(test_strncmp_5) {
  char case_1_1[30] = "random text yeasss";
  char case_1_2[30] = "adfsd fgdhgg dgf gdf dfgh";
  int int_1 = 0, int_2 = 0;
  int_1 = s21_strncmp(case_1_1, case_1_2, 12);
  int_2 = strncmp(case_1_1, case_1_2, 12);
  ck_assert_int_eq(int_1, int_2);
}
END_TEST

START_TEST(test_strncpy_1) {
  char case_1_1[80] = {'\0'};
  char case_1_2[] = "adfsd fgdhgg dgf gdf dfgh";
  char case_2_1[80] = {'\0'};
  char case_2_2[] = "adfsd fgdhgg dgf gdf dfgh";
  s21_strncpy(case_1_1, case_1_2, 21);
  strncpy(case_2_1, case_2_2, 21);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncpy_2) {
  char case_1_1[] = "dfasdfпрпрр";
  char case_1_2[] = "345 743 736 471";
  char case_2_1[] = "dfasdfпрпрр";
  char case_2_2[] = "345 743 736 471";
  s21_strncpy(case_1_1, case_1_2, 10);
  strncpy(case_2_1, case_2_2, 10);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strncpy_3) {
  char case_1_1[] = "";
  char case_1_2[] = "";
  char case_2_1[] = "";
  char case_2_2[] = "";
  s21_strncpy(case_1_1, case_1_2, 1);
  strncpy(case_2_1, case_2_2, 1);
  ck_assert_str_eq(case_1_1, case_2_1);
}
END_TEST

START_TEST(test_strcspn_1) {
  char case_1_1[] = "fcba73";
  char case_1_2[] = "1234567890";
  char case_2_1[] = "fcba73";
  char case_2_2[] = "1234567890";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strcspn_2) {
  char case_1_1[] = "fcba";
  char case_1_2[] = "1234567890";
  char case_2_1[] = "fcba";
  char case_2_2[] = "1234567890";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strcspn_3) {
  char case_1_1[] = "1234567890";
  char case_1_2[] = "fcba";
  char case_2_1[] = "1234567890";
  char case_2_2[] = "fcba";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strcspn_4) {
  char case_1_1[] = "1234567890";
  char case_1_2[] = "fcba73";
  char case_2_1[] = "1234567890";
  char case_2_2[] = "fcba73";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strcspn_5) {
  char case_1_1[] = "1234567890";
  char case_1_2[] = "";
  char case_2_1[] = "1234567890";
  char case_2_2[] = "";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strcspn_6) {
  char case_1_1[] = "";
  char case_1_2[] = "fcba73";
  char case_2_1[] = "";
  char case_2_2[] = "fcba73";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strcspn_7) {
  char case_1_1[] = "";
  char case_1_2[] = "";
  char case_2_1[] = "";
  char case_2_2[] = "";
  size_t result_1, result_2;
  result_1 = s21_strcspn(case_1_1, case_1_2);
  result_2 = strcspn(case_2_1, case_2_2);
  ck_assert_int_eq(result_1, result_2);
}
END_TEST

START_TEST(test_strerror_1) {
  char *case_1 = NULL;
  char *case_2 = NULL;
  if (case_1 != NULL) {
    printf("%s", maserror[5]);
  }
  case_1 = strerror(100);
  case_2 = s21_strerror(100);
  ck_assert_str_eq(case_1, case_2);
}
END_TEST

START_TEST(test_strerror_2) {
  char *case_1 = NULL;
  char *case_2 = NULL;
  if (case_1 != NULL) {
    printf("%s", maserror[5]);
  }
  case_1 = strerror(5);
  case_2 = s21_strerror(5);
  ck_assert_str_eq(case_1, case_2);
}
END_TEST

START_TEST(test_strerror_3) {
  char *case_1 = NULL;
  char *case_2 = NULL;
  if (case_1 != NULL) {
    printf("%s", maserror[5]);
  }
  for (int i = 0; i < 100; i++) {
    case_1 = strerror(i);
    case_2 = s21_strerror(i);
    ck_assert_str_eq(case_1, case_2);
  }
}
END_TEST

START_TEST(test_strlen_1) {
  int original, s21;
  char case_1[] = "adfsd fgdhgg dgf gdf dfgh";
  original = strlen(case_1);
  s21 = s21_strlen(case_1);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_strlen_2) {
  int original, s21;
  char case_1[] = "";
  original = strlen(case_1);
  s21 = s21_strlen(case_1);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_strlen_3) {
  int original, s21;
  char case_1[] = "\0fasdfasdf";
  original = strlen(case_1);
  s21 = s21_strlen(case_1);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_strpbrk_1) {
  char *original, *s21;
  char case_1_1[] = "Silmutaneous maverick Johnson";
  char case_1_2[] = "tek";
  original = strpbrk(case_1_1, case_1_2);
  s21 = s21_strpbrk(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strpbrk_2) {
  char *original, *s21;
  char case_1_1[] = "Silmutaneous maverick Johnson";
  char case_1_2[] = "Silmutaneous maverick Johnson";
  original = strpbrk(case_1_1, case_1_2);
  s21 = s21_strpbrk(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strpbrk_3) {
  char *original, *s21;
  char case_1_1[] = "Silmutaneous maverick Johnson1";
  char case_1_2[] = "1";
  original = strpbrk(case_1_1, case_1_2);
  s21 = s21_strpbrk(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strpbrk_4) {
  char *original, *s21;
  char case_1_1[] = "";
  char case_1_2[] = "1dfdf";
  original = strpbrk(case_1_1, case_1_2);
  s21 = s21_strpbrk(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strpbrk_5) {
  char *original, *s21;
  char case_1_1[] = "";
  char case_1_2[] = "";
  original = strpbrk(case_1_1, case_1_2);
  s21 = s21_strpbrk(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strpbrk_6) {
  char *original, *s21;
  char case_1_1[] = "\0Hey where is this";
  char case_1_2[] = "Hey";
  original = strpbrk(case_1_1, case_1_2);
  s21 = s21_strpbrk(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strrchr_1) {
  char *original, *s21;
  char case_1_1[] = "This is a first 9, this is a second 9";
  char case_1_2 = '9';
  original = strrchr(case_1_1, case_1_2);
  s21 = s21_strrchr(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strrchr_2) {
  char *original, *s21;
  char case_1_1[] = "This is a first 9, this is a second 9";
  char case_1_2 = '8';
  original = strrchr(case_1_1, case_1_2);
  s21 = s21_strrchr(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strrchr_3) {
  char *original, *s21;
  char case_1_1[] = "This is a first 9, this is a second 9";
  char case_1_2 = 97;
  original = strrchr(case_1_1, case_1_2);
  s21 = s21_strrchr(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strstr_1) {
  char *original, *s21;
  char case_1_1[] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2[] = "gg";
  original = strstr(case_1_1, case_1_2);
  s21 = s21_strstr(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strstr_2) {
  char *original, *s21;
  char case_1_1[40] = "adfsd fgdhgg dgf gdf dfgh";
  char case_1_2[40] = "gg45";
  original = strstr(case_1_1, case_1_2);
  s21 = s21_strstr(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strstr_3) {
  char *original, *s21;
  char case_1_1[] = "Ædfsd fgdhgg dgf gdf dfgh";
  char case_1_2[] = "";
  original = strstr(case_1_1, case_1_2);
  s21 = s21_strstr(case_1_1, case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strstr_4) {
  char *original, *s21;
  char case_1_1[] = "";
  char case_1_2[] = "gg45";
  original = strstr(case_1_1, case_1_2);
  s21 = s21_strstr(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strstr_5) {
  char *original, *s21;
  char case_1_1[] = "";
  char case_1_2[] = "";
  original = strstr(case_1_1, case_1_2);
  s21 = s21_strstr(case_1_1, case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_strtok_1) {
  char *original, *s21;
  char original_case_1_1[] = "The summer soldier, the sunshine patriot";
  char original_case_1_2[] = " ";
  char original_case_2_2[] = ",s ";
  char s21_case_1_1[] = "The summer soldier, the sunshine patriot";
  char s21_case_1_2[] = " ";
  char s21_case_2_2[] = ",s ";
  original = strtok(original_case_1_1, original_case_1_2);
  s21 = s21_strtok(s21_case_1_1, s21_case_1_2);
  ck_assert_str_eq(original, s21);
  while (original != NULL && s21 != NULL) {
    original = strtok('\0', original_case_2_2);
    s21 = s21_strtok('\0', s21_case_2_2);
    if (original != NULL && s21 != NULL) {
      ck_assert_str_eq(original, s21);
    }
  }
}
END_TEST

START_TEST(test_strtok_2) {
  char *original, *s21;
  char original_case_1_1[] = "The summer soldier, the sunshine patriot";
  char original_case_1_2[] = " ";
  char original_case_2_2[] = "";
  char s21_case_1_1[] = "The summer soldier, the sunshine patriot";
  char s21_case_1_2[] = " ";
  char s21_case_2_2[] = "";
  original = strtok(original_case_1_1, original_case_1_2);
  s21 = s21_strtok(s21_case_1_1, s21_case_1_2);
  ck_assert_str_eq(original, s21);
  while (original != NULL && s21 != NULL) {
    original = strtok('\0', original_case_2_2);
    s21 = s21_strtok('\0', s21_case_2_2);
    if (original != NULL && s21 != NULL) {
      ck_assert_str_eq(original, s21);
    }
  }
}
END_TEST

START_TEST(test_strtok_3) {
  char *original, *s21;
  char original_case_1_1[] = "Some-text";
  char original_case_1_2[] = "-";
  char s21_case_1_1[] = "Some-text";
  char s21_case_1_2[] = "-";
  original = strtok(original_case_1_1, original_case_1_2);
  s21 = s21_strtok(s21_case_1_1, s21_case_1_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_strtok_4) {
  char *original, *s21;
  char original_case_1_1[] = "";
  char original_case_1_2[] = "";
  char s21_case_1_1[] = "";
  char s21_case_1_2[] = "";
  original = strtok(original_case_1_1, original_case_1_2);
  s21 = s21_strtok(s21_case_1_1, s21_case_1_2);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_char_1) {
  char token_1[] = "a", token_2[] = "a";
  char s21 = ' ', original = ' ';
  s21_sscanf(token_2, "%c", &s21);
  sscanf(token_1, "%c", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_char_2) {
  char token_1[] = "0", token_2[] = "0";
  char s21 = ' ', original = ' ';
  s21_sscanf(token_2, "%c", &s21);
  sscanf(token_1, "%c", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_char_3) {
  char token_1[] = "9s", token_2[] = "9s";
  char s21_1 = ' ', original_1 = ' ', s21_2 = ' ', original_2 = ' ';
  s21_sscanf(token_2, "%c%c", &s21_1, &s21_2);
  sscanf(token_1, "%c%c", &original_1, &original_2);
  ck_assert_int_eq(original_1, s21_1);
  ck_assert_int_eq(original_2, s21_2);
}
END_TEST

START_TEST(test_sscanf_string_1) {
  char token[] = "12345678901234567890123456789012345678901234567890";
  char s21[81] = "";
  char original[81] = "";
  s21_sscanf(token, "%s", s21);
  sscanf(token, "%s", original);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_string_2) {
  char token[] = "15 12 14...";
  char s21[81] = "";
  char original[81] = "";
  s21_sscanf(token, "%80s", s21);
  sscanf(token, "%80s", original);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_string_3) {
  char token[] = "dog cat and frog\n";
  char s21[81] = "";
  char original[81] = "";
  s21_sscanf(token, "%1s", s21);
  sscanf(token, "%1s", original);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_string_4) {
  char token[] = " 111111 222222 333333\n";
  char s21[100] = "";
  char original[100] = "";
  s21_sscanf(token, "  %s is \n", s21);
  sscanf(token, "  %s is \n", original);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_int_1) {
  char token[] = "15 12 14...";
  int s21 = 0, original = 0;
  s21_sscanf(token, "%d", &s21);
  sscanf(token, "%d", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_int_2) {
  char token[] = "1234567890";
  long int s21 = 0, original = 0;
  s21_sscanf(token, "%3ld", &s21);
  sscanf(token, "%3ld", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_int_3) {
  char token[] = "15 12 14...";
  int s21_1 = 0, s21_2 = 0, original_1 = 0, original_2 = 0;
  s21_sscanf(token, "%d %d", &s21_1, &s21_2);
  sscanf(token, "%d %d", &original_1, &original_2);
  ck_assert_int_eq(original_1, s21_1);
  ck_assert_int_eq(original_2, s21_2);
}
END_TEST

START_TEST(test_sscanf_int_4) {
  char token[] = "-228228";
  short int s21 = 0, original = 0;
  s21_sscanf(token, "%3hd", &s21);
  sscanf(token, "%3hd", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_int_5) {
  char token[] = "11000";
  int s21 = 0, original = 0;
  s21_sscanf(token, "%d", &s21);
  sscanf(token, "%d", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_int_6) {
  char token[] = "-1";
  int s21 = 0, original = 0;
  s21_sscanf(token, "%d", &s21);
  sscanf(token, "%d", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_unsigned_1) {
  char token[] = "15 12 14...";
  unsigned s21 = 0, original = 0;
  s21_sscanf(token, "%u", &s21);
  sscanf(token, "%u", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_unsigned_2) {
  char token[] = "461522";
  long unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%lu", &s21);
  sscanf(token, "%lu", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_unsigned_3) {
  char token[] = "123";
  short unsigned s21 = 0, original = 0;
  s21_sscanf(token, "%hu", &s21);
  sscanf(token, "%hu", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_float_1) {
  char token[] = "1";
  float s21 = 0, original = 0;
  sscanf(token, "%f", &original);
  s21_sscanf(token, "%f", &s21);
  ck_assert_float_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_float_2) {
  char token[] = "31123.1222228";
  float s21 = 0, original = 0;
  s21_sscanf(token, "%3f", &s21);
  sscanf(token, "%3f", &original);
  ck_assert_float_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_float_3) {
  char token[] = "31123.1 999.23 0";
  float s21_1 = 0, s21_2 = 0, original_1 = 0, original_2 = 0;
  s21_sscanf(token, "%f %f", &s21_1, &s21_2);
  sscanf(token, "%f %f", &original_1, &original_2);
  ck_assert_float_eq(original_1, s21_1);
  ck_assert_float_eq(original_2, s21_2);
}
END_TEST

START_TEST(test_sscanf_float_4) {
  char token[] = "-1.2";
  float s21 = 0, original = 0;
  sscanf(token, "%f", &original);
  s21_sscanf(token, "%f", &s21);
  ck_assert_float_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_e_1) {
  char token[] = "1.1234567";
  double s21 = 0, original = 0;
  s21_sscanf(token, "%le", &s21);
  sscanf(token, "%le", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_e_2) {
  char token[] = "123.123";
  long double s21 = 0, original = 0;
  s21_sscanf(token, "%Le", &s21);
  sscanf(token, "%Le", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_e_3) {
  char token[] = "31123.1 999.23 0";
  double s21 = 0, original = 0;
  s21_sscanf(token, "%3le", &s21);
  sscanf(token, "%3le", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_e_4) {
  char token[] = "-2.34";
  double s21 = 0, original = 0;
  s21_sscanf(token, "%le", &s21);
  sscanf(token, "%le", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_g_1) {
  char token[] = "1.1234567";
  double s21 = 0, original = 0;
  s21_sscanf(token, "%lg", &s21);
  sscanf(token, "%lg", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_g_2) {
  char token[] = "123.123";
  double s21 = 0, original = 0;
  s21_sscanf(token, "%lg", &s21);
  sscanf(token, "%lg", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_g_3) {
  char token[] = "-3.45";
  double s21 = 0, original = 0;
  s21_sscanf(token, "%lg", &s21);
  sscanf(token, "%lg", &original);
  ck_assert_double_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_x_1) {
  char token[] = "1";
  unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%x", &s21);
  sscanf(token, "%x", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_x_2) {
  char token[] = "9191239";
  unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%1x", &s21);
  sscanf(token, "%1x", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_x_3) {
  char token[] = "15 16 14";
  unsigned int s21_1 = 0, s21_2 = 0, original_1 = 0, original_2 = 0;
  s21_sscanf(token, "%x %x", &s21_1, &s21_2);
  sscanf(token, "%x %x", &original_1, &original_2);
  ck_assert_int_eq(original_1, s21_1);
  ck_assert_int_eq(original_2, s21_2);
}
END_TEST

START_TEST(test_sscanf_o_1) {
  char token[] = "  1";
  long unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%lo", &s21);
  sscanf(token, "%lo", &original);
  ck_assert_uint_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_o_2) {
  char token[] = " 64";
  short unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%ho", &s21);
  sscanf(token, "%ho", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_o_3) {
  char token[] = "8";
  unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%o", &s21);
  sscanf(token, "%o", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_o_4) {
  char token[] = "AF";
  long unsigned int s21 = 0, original = 0;
  s21_sscanf(token, "%lo", &s21);
  sscanf(token, "%lo", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_p_1) {
  char token[] = "  cat";
  char *p = token;
  void **s21;
  void **original;
  s21_sscanf(p, "%p", &s21);
  sscanf(p, "%p", &original);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_p_2) {
  float token = 123.12356;
  char *p = (char *)&token;
  void **s21;
  void **original;
  s21_sscanf(p, "%p", &s21);
  sscanf(p, "%p", &original);
  ck_assert_ptr_eq(original, s21);
}
END_TEST

START_TEST(test_sscanf_asterisk_1) {
  char token[] = "15 14 13";
  int s21 = 0, original = 0;
  s21_sscanf(token, "%*d %d", &s21);
  sscanf(token, "%*d %d", &original);
  ck_assert_int_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_char_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  char c = '0';
  s21_sprintf(s21, "%c\n", c);
  sprintf(original, "%c\n", c);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_char_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  char c = 'c';
  s21_sprintf(s21, "%-5c\n", c);
  sprintf(original, "%-5c\n", c);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_char_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  char c_1 = '0', c_2 = '1', c_3 = '3';
  s21_sprintf(s21, "%c%5c%-2c\n", c_1, c_2, c_3);
  sprintf(original, "%c%5c%-2c\n", c_1, c_2, c_3);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_char_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  wchar_t c = L'0';
  s21_sprintf(s21, "%lc\n", c);
  sprintf(original, "%lc\n", c);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_int_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  short int i = 999;
  s21_sprintf(s21, "%+5hd\n", i);
  sprintf(original, "%+5hd\n", i);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_int_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long int i = 999999999999;
  s21_sprintf(s21, "%- ld\n", i);
  sprintf(original, "%- ld\n", i);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_int_3) {
  char original[70] = {'\0'}, s21[70] = {'\0'};
  int i_1 = 228, i_2 = -1703, i_3 = 666, i_4 = -1337, i_5 = 21;
  s21_sprintf(s21, "%d\n\t%.30d\n\t\t%-5d\n\t\t\t%-2.10d\n\t\t\t\t% 1d\n", i_1,
              i_2, i_3, i_4, i_5);
  sprintf(original, "%d\n\t%.30d\n\t\t%-5d\n\t\t\t%-2.10d\n\t\t\t\t% 1d\n", i_1,
          i_2, i_3, i_4, i_5);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_int_4) {
  char original[500] = {'\0'}, s21[500] = {'\0'};
  int i_1 = 10001, i_2 = 1000001, i_3 = 10000001, i_4 = 100000001,
      i_5 = 1000000001;
  long int i_6 = 10000000001, i_7 = 10000000000001, i_8 = 100000000000001,
           i_9 = 100000000000001, i_10 = 1000000000000001,
           i_11 = 100000000000000001, i_12 = 1000000000000000001;
  s21_sprintf(s21, "%d %d %d %d %d %ld %ld %ld %ld %ld %ld %ld", i_1, i_2, i_3,
              i_4, i_5, i_6, i_7, i_8, i_9, i_10, i_11, i_12);
  sprintf(original, "%d %d %d %d %d %ld %ld %ld %ld %ld %ld %ld", i_1, i_2, i_3,
          i_4, i_5, i_6, i_7, i_8, i_9, i_10, i_11, i_12);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_int_5) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  int i = 1;
  s21_sprintf(s21, "%-+10d\n", i);
  sprintf(original, "%-+10d\n", i);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_string_1) {
  char original[50] = {'\0'}, s21[50] = {'\0'};
  char string[] = "planet mars";
  s21_sprintf(s21, "   string: %s\n", string);
  sprintf(original, "   string: %s\n", string);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_string_2) {
  char original[50] = {'\0'}, s21[50] = {'\0'};
  char string[] = "a";
  s21_sprintf(s21, "%-5.1233s", string);
  sprintf(original, "%-5.1233s", string);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_string_3) {
  char original[200] = {'\0'}, s21[200] = {'\0'};
  char string_1[] = "aaaaaaaa", string_2[] = "bbbbbbbb";
  s21_sprintf(s21, "%12s != %s !!!\n", string_1, string_2);
  sprintf(original, "%12s != %s !!!\n", string_1, string_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_string_4) {
  char original[200] = {'\0'}, s21[200] = {'\0'};
  char string_1[] = "dog", string_2[] = "cat";
  s21_sprintf(s21, "This are %s not a %-5s!\n", string_1, string_2);
  sprintf(original, "This are %s not a %-5s!\n", string_1, string_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_string_5) {
  char original[200] = {'\0'}, s21[200] = {'\0'};
  char string_1[] = "dog", string_2[] = "cat", string_3[] = "rabbit",
       string_4[] = "elephant", string_5[] = "human\n";
  s21_sprintf(s21, "%s %-10s %10s %.3s %.20s", string_1, string_2, string_3,
              string_4, string_5);
  sprintf(original, "%s %-10s %10s %.3s %.20s", string_1, string_2, string_3,
          string_4, string_5);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_string_6) {
  char original[70] = {'\0'}, s21[70] = {'\0'};
  wchar_t string[] = L"abasfki";
  s21_sprintf(s21, "%ls", string);
  sprintf(original, "%ls", string);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_float_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  float f = -999.999;
  s21_sprintf(s21, "%f\n", f);
  sprintf(original, "%f\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_float_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double f = 123123123.123123123;
  s21_sprintf(s21, "%.3lf\n", f);
  sprintf(original, "%.3lf\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_float_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long double f = 0.11;
  s21_sprintf(s21, "%+5.0Lf\n", f);
  sprintf(original, "%+5.0Lf\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_float_4) {
  char original[70] = {'\0'}, s21[70] = {'\0'};
  float f_1 = 228.339, f_2 = -1703.0;
  s21_sprintf(s21, "%-15.1f %.30f \n", f_1, f_2);
  sprintf(original, "%-15.1f %.30f \n", f_1, f_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_float_5) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  float f = 1;
  s21_sprintf(s21, "%10f\n", f);
  sprintf(original, "%10f\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_float_6) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  float f = 2;
  s21_sprintf(s21, "%-5f\n", f);
  sprintf(original, "%-5f\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_unsigned_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned u = 1;
  s21_sprintf(s21, "%5u\n", u);
  sprintf(original, "%5u\n", u);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_unsigned_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long unsigned int u = 18446744073709;
  s21_sprintf(s21, "%lu\n", u);
  sprintf(original, "%lu\n", u);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_unsigned_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned u = 0;
  s21_sprintf(s21, "%hu\n", u);
  sprintf(original, "%hu\n", u);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_unsigned_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned u_1 = 1, u_2 = 100;
  s21_sprintf(s21, "ok %-2u %u not\n", u_1, u_2);
  sprintf(original, "ok %-2u %u not\n", u_1, u_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_unsigned_5) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned u_1 = 1, u_3 = 3;
  long unsigned u_2 = 2;
  s21_sprintf(s21, "%-2u\n%-19lu\n%u", u_1, u_2, u_3);
  sprintf(original, "%-2u\n%-19lu\n%u", u_1, u_2, u_3);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_notation_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double e = -0.9;
  s21_sprintf(s21, "%E\n", e);
  sprintf(original, "%E\n", e);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_notation_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double e = 10;
  s21_sprintf(s21, "%.3e\n", e);
  sprintf(original, "%.3e\n", e);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_notation_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long double e_1 = 1.00003;
  double e_2 = 3;
  s21_sprintf(s21, "% Le\n%+.3e\n", e_1, e_2);
  sprintf(original, "% Le\n%+.3e\n", e_1, e_2);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_notation_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double e = -100;
  s21_sprintf(s21, "%.3e\n", e);
  sprintf(original, "%.3e\n", e);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_g_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double g = -0.9;
  s21_sprintf(s21, "%g\n", g);
  sprintf(original, "%g\n", g);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_g_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long double g = 12321412412.1;
  s21_sprintf(s21, "%.LG\n", g);
  sprintf(original, "%.LG\n", g);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_g_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double g = -0.1;
  s21_sprintf(s21, "%5G\n", g);
  sprintf(original, "%5G\n", g);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_g_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double g = 0.1;
  s21_sprintf(s21, "%-+7G\n", g);
  sprintf(original, "%-+7G\n", g);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_g_5) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double g = 0.11;
  s21_sprintf(s21, "%G\n", g);
  sprintf(original, "%G\n", g);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_x_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = -1;
  s21_sprintf(s21, "In %-3x\n", x);
  sprintf(original, "In %-3x\n", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_x_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 32015;
  s21_sprintf(s21, "%.8X\n", x);
  sprintf(original, "%.8X\n", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_x_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 10;
  s21_sprintf(s21, "%X", x);
  sprintf(original, "%X", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_x_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 12;
  s21_sprintf(s21, "%X", x);
  sprintf(original, "%X", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_x_5) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 0;
  s21_sprintf(s21, "%x", x);
  sprintf(original, "%x", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_x_6) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 0;
  s21_sprintf(s21, "%-2x", x);
  sprintf(original, "%-2x", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_o_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  s21_sprintf(s21, "%5o\n", 1);
  sprintf(original, "%5o\n", 1);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_o_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  s21_sprintf(s21, "  %.4o\n dooo", 123456);
  sprintf(original, "  %.4o\n dooo", 123456);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_o_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  s21_sprintf(s21, " in %10o\n", (-100));
  sprintf(original, " in %10o\n", (-100));
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_o_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  s21_sprintf(s21, " in %5o\n", 0);
  sprintf(original, " in %5o\n", 0);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_o_5) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  s21_sprintf(s21, "%-2o", 0);
  sprintf(original, "%-2o", 0);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_p_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  int i = 300;
  void *p = &i;
  s21_sprintf(s21, " is %p is \n", p);
  sprintf(original, " is %p is \n", p);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_p_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long int li = 12345678901022;
  void *p = &li;
  s21_sprintf(s21, "%p\n", p);
  sprintf(original, "%p\n", p);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_p_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  char *str = "pim pam pom";
  void *p = &str;
  s21_sprintf(s21, "Ths is %p\n", p);
  sprintf(original, "Ths is %p\n", p);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_zero_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  int i = 999;
  s21_sprintf(s21, "\t%0d\n", i);
  sprintf(original, "\t%0d\n", i);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_zero_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  float f = 999.999;
  s21_sprintf(s21, "%0f\n", f);
  sprintf(original, "%0f\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_zero_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned u = 1;
  s21_sprintf(s21, " in here %0u!\n", u);
  sprintf(original, " in here %0u!\n", u);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_zero_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 564793;
  s21_sprintf(s21, "%#0X\n", x);
  sprintf(original, "%#0X\n", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_hashtage_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 1;
  s21_sprintf(s21, "In %#x\n", x);
  sprintf(original, "In %#x\n", x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_hashtage_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  float f = 999.999;
  s21_sprintf(s21, "1a2b3c != %#.1f\n", f);
  sprintf(original, "1a2b3c != %#.1f\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_hashtage_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double g = -0.9;
  s21_sprintf(s21, "%-#g\n", g);
  sprintf(original, "%-#g\n", g);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_asterisk_1) {
  char original[100] = {'\0'}, s21[100] = {'\0'};
  float f = 123.456;
  s21_sprintf(s21, "1a2b3c != %+20.*f\n", 2, f);
  sprintf(original, "1a2b3c != %+20.*f\n", 2, f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_asterisk_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  double e = 10;
  s21_sprintf(s21, "in the %.*e!\n", 3, e);
  sprintf(original, "in the %.*e!\n", 3, e);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_asterisk_3) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  unsigned int x = 1.1230210419239;
  s21_sprintf(s21, "In %-.*x\n", 0, x);
  sprintf(original, "In %-.*x\n", 0, x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_asterisk_4) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  int x = 1234;
  s21_sprintf(s21, "In %*d", 20, x);
  sprintf(original, "In %*d", 20, x);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_L_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long double f = 123.456;
  s21_sprintf(s21, "1a2b3c != %+.1Lf !!!\n", f);
  sprintf(original, "1a2b3c != %+.1Lf !!!\n", f);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_L_2) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long long unsigned int x = 1.1230210419239;
  long long unsigned int y = 111111.1123123112;
  s21_sprintf(s21, "In %-LX there is no %-.0LX\n", x, y);
  sprintf(original, "In %-LX there is no %-.0LX\n", x, y);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_to_upper_1) {
  char original[30] = " ABC ", s21[30] = " aBc ";
  char *s21_2 = s21_to_upper(s21);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_to_upper_2) {
  char original[35] = "ABCDEFG 2312 33 YES", s21[35] = "AbcdEfG 2312 33 yes";
  char *s21_2 = s21_to_upper(s21);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_to_upper_3) {
  char original[30] = "", s21[30] = "";
  char *s21_2 = s21_to_upper(s21);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_to_lower_1) {
  char original[30] = " mmm ", s21[30] = " MMM ";
  char *s21_2 = s21_to_lower(s21);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_to_lower_2) {
  char original[35] = "kira !kira ni! 222222228 13hhh37\n",
       s21[35] = "KIRA !kIRa NI! 222222228 13HHH37\n";
  char *s21_2 = s21_to_lower(s21);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_to_lower_3) {
  char original[30] = "!", s21[30] = "!";
  char *s21_2 = s21_to_lower(s21);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_insert_1) {
  char original[35] = "0123456789\n", s21[35] = "012356789\n";
  char s[] = "4";
  char *s21_2 = s21_insert(s21, s, 4);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_insert_2) {
  char original[35] = "ten tun tan ton tin\n", s21[35] = "tun tan ton tin\n";
  char s[] = "ten ";
  char *s21_2 = s21_insert(s21, s, 0);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_insert_3) {
  char original[35] = "bib bib biiiiiiiiiiiiiiiiiiiib\n", s21[35] = "bib bib ";
  char s[] = "biiiiiiiiiiiiiiiiiiiib\n";
  char *s21_2 = s21_insert(s21, s, 8);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_trim_1) {
  char original[35] = "0123456789", s21[35] = "\n\\0123456789\n\t";
  char trim[] = "\n\t\\";
  char *s21_2 = s21_trim(s21, trim);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_trim_2) {
  char original[35] = "\n", s21[35] = "\n";
  char trim[] = "1\t\'";
  char *s21_2 = s21_trim(s21, trim);
  ck_assert_str_eq(original, s21_2);
  if (s21_2 != NULL) {
    free(s21_2);
  }
}
END_TEST

START_TEST(test_complex_1) {
  char original[150] = {'\0'}, s21[150] = {'\0'};
  int d = -5;
  long long unsigned int x = 111.1123112;
  void *p = &d;
  char string_2[] = "bbbbbbbb";
  char string_1[100] = "aaaaaaaa";
  s21_strncat(string_1, string_2, 4);
  s21_sprintf(s21, "%d %Lx %p %6s %#6.1o\n", d, x, p, string_1, 7);
  sprintf(original, "%d %Lx %p %6s %#6.1o\n", d, x, p, string_1, 7);
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_empty_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  s21_sprintf(s21, "1a2b3c!!!\n");
  sprintf(original, "1a2b3c!!!\n");
  ck_assert_str_eq(original, s21);
}
END_TEST

START_TEST(test_sprintf_return_1) {
  char original[30] = {'\0'}, s21[30] = {'\0'};
  long long unsigned int x = 1.1230210419239;
  long long unsigned int y = 111111.1123123112;
  int s21_ret = s21_sprintf(s21, "In %-LX there is no %-.0LX\n", x, y);
  int original_ret = sprintf(original, "In %-LX there is no %-.0LX\n", x, y);
  ck_assert_int_eq(original_ret, s21_ret);
}
END_TEST

Suite *string_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("String");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_memchr_1);
  tcase_add_test(tc_core, test_memchr_2);
  tcase_add_test(tc_core, test_memchr_3);
  tcase_add_test(tc_core, test_memchr_4);
  tcase_add_test(tc_core, test_memchr_5);
  tcase_add_test(tc_core, test_memchr_6);
  tcase_add_test(tc_core, test_memcmp_1);
  tcase_add_test(tc_core, test_memcmp_2);
  tcase_add_test(tc_core, test_memcmp_3);
  tcase_add_test(tc_core, test_memcmp_4);
  tcase_add_test(tc_core, test_memcmp_5);
  tcase_add_test(tc_core, test_memcmp_6);
  tcase_add_test(tc_core, test_memcpy_1);
  tcase_add_test(tc_core, test_memcpy_2);
  tcase_add_test(tc_core, test_memcpy_3);
  tcase_add_test(tc_core, test_memcpy_4);
  tcase_add_test(tc_core, test_memcpy_5);
  tcase_add_test(tc_core, test_memset_1);
  tcase_add_test(tc_core, test_memset_2);
  tcase_add_test(tc_core, test_memset_3);
  tcase_add_test(tc_core, test_memset_4);
  tcase_add_test(tc_core, test_strncat_1);
  tcase_add_test(tc_core, test_strncat_2);
  tcase_add_test(tc_core, test_strncat_3);
  tcase_add_test(tc_core, test_strncat_4);
  tcase_add_test(tc_core, test_strncat_5);
  tcase_add_test(tc_core, test_strncat_6);
  tcase_add_test(tc_core, test_strncat_7);
  tcase_add_test(tc_core, test_strchr_1);
  tcase_add_test(tc_core, test_strchr_2);
  tcase_add_test(tc_core, test_strchr_3);
  tcase_add_test(tc_core, test_strncmp_1);
  tcase_add_test(tc_core, test_strncmp_2);
  tcase_add_test(tc_core, test_strncmp_3);
  tcase_add_test(tc_core, test_strncmp_4);
  tcase_add_test(tc_core, test_strncmp_5);
  tcase_add_test(tc_core, test_strncpy_1);
  tcase_add_test(tc_core, test_strncpy_2);
  tcase_add_test(tc_core, test_strncpy_3);
  tcase_add_test(tc_core, test_strcspn_1);
  tcase_add_test(tc_core, test_strcspn_2);
  tcase_add_test(tc_core, test_strcspn_3);
  tcase_add_test(tc_core, test_strcspn_4);
  tcase_add_test(tc_core, test_strcspn_5);
  tcase_add_test(tc_core, test_strcspn_6);
  tcase_add_test(tc_core, test_strcspn_7);
  tcase_add_test(tc_core, test_strerror_1);
  tcase_add_test(tc_core, test_strerror_2);
  tcase_add_test(tc_core, test_strerror_3);
  tcase_add_test(tc_core, test_strlen_1);
  tcase_add_test(tc_core, test_strlen_2);
  tcase_add_test(tc_core, test_strlen_3);
  tcase_add_test(tc_core, test_strpbrk_1);
  tcase_add_test(tc_core, test_strpbrk_2);
  tcase_add_test(tc_core, test_strpbrk_3);
  tcase_add_test(tc_core, test_strpbrk_4);
  tcase_add_test(tc_core, test_strpbrk_5);
  tcase_add_test(tc_core, test_strpbrk_6);
  tcase_add_test(tc_core, test_strrchr_1);
  tcase_add_test(tc_core, test_strrchr_2);
  tcase_add_test(tc_core, test_strrchr_3);
  tcase_add_test(tc_core, test_strstr_1);
  tcase_add_test(tc_core, test_strstr_2);
  tcase_add_test(tc_core, test_strstr_3);
  tcase_add_test(tc_core, test_strstr_4);
  tcase_add_test(tc_core, test_strstr_5);
  tcase_add_test(tc_core, test_strtok_1);
  tcase_add_test(tc_core, test_strtok_2);
  tcase_add_test(tc_core, test_strtok_3);
  tcase_add_test(tc_core, test_strtok_4);
  tcase_add_test(tc_core, test_sscanf_char_1);
  tcase_add_test(tc_core, test_sscanf_char_2);
  tcase_add_test(tc_core, test_sscanf_char_3);
  tcase_add_test(tc_core, test_sscanf_string_1);
  tcase_add_test(tc_core, test_sscanf_string_2);
  tcase_add_test(tc_core, test_sscanf_string_3);
  tcase_add_test(tc_core, test_sscanf_string_4);
  tcase_add_test(tc_core, test_sscanf_int_1);
  tcase_add_test(tc_core, test_sscanf_int_2);
  tcase_add_test(tc_core, test_sscanf_int_3);
  tcase_add_test(tc_core, test_sscanf_int_4);
  tcase_add_test(tc_core, test_sscanf_int_5);
  tcase_add_test(tc_core, test_sscanf_int_6);
  tcase_add_test(tc_core, test_sscanf_unsigned_1);
  tcase_add_test(tc_core, test_sscanf_unsigned_2);
  tcase_add_test(tc_core, test_sscanf_unsigned_3);
  tcase_add_test(tc_core, test_sscanf_float_1);
  tcase_add_test(tc_core, test_sscanf_float_2);
  tcase_add_test(tc_core, test_sscanf_float_3);
  tcase_add_test(tc_core, test_sscanf_float_4);
  tcase_add_test(tc_core, test_sscanf_e_1);
  tcase_add_test(tc_core, test_sscanf_e_2);
  tcase_add_test(tc_core, test_sscanf_e_3);
  tcase_add_test(tc_core, test_sscanf_e_4);
  tcase_add_test(tc_core, test_sscanf_g_1);
  tcase_add_test(tc_core, test_sscanf_g_2);
  tcase_add_test(tc_core, test_sscanf_g_3);
  tcase_add_test(tc_core, test_sscanf_x_1);
  tcase_add_test(tc_core, test_sscanf_x_2);
  tcase_add_test(tc_core, test_sscanf_x_3);
  tcase_add_test(tc_core, test_sscanf_o_1);
  tcase_add_test(tc_core, test_sscanf_o_2);
  tcase_add_test(tc_core, test_sscanf_o_3);
  tcase_add_test(tc_core, test_sscanf_o_4);
  tcase_add_test(tc_core, test_sscanf_p_1);
  tcase_add_test(tc_core, test_sscanf_p_2);
  tcase_add_test(tc_core, test_sscanf_asterisk_1);
  tcase_add_test(tc_core, test_sprintf_char_1);
  tcase_add_test(tc_core, test_sprintf_char_2);
  tcase_add_test(tc_core, test_sprintf_char_3);
  tcase_add_test(tc_core, test_sprintf_char_4);
  tcase_add_test(tc_core, test_sprintf_int_1);
  tcase_add_test(tc_core, test_sprintf_int_2);
  tcase_add_test(tc_core, test_sprintf_int_3);
  tcase_add_test(tc_core, test_sprintf_int_4);
  tcase_add_test(tc_core, test_sprintf_int_5);
  tcase_add_test(tc_core, test_sprintf_string_1);
  tcase_add_test(tc_core, test_sprintf_string_2);
  tcase_add_test(tc_core, test_sprintf_string_3);
  tcase_add_test(tc_core, test_sprintf_string_4);
  tcase_add_test(tc_core, test_sprintf_string_5);
  tcase_add_test(tc_core, test_sprintf_string_6);
  tcase_add_test(tc_core, test_sprintf_float_1);
  tcase_add_test(tc_core, test_sprintf_float_2);
  tcase_add_test(tc_core, test_sprintf_float_3);
  tcase_add_test(tc_core, test_sprintf_float_4);
  tcase_add_test(tc_core, test_sprintf_float_5);
  tcase_add_test(tc_core, test_sprintf_float_6);
  tcase_add_test(tc_core, test_sprintf_unsigned_1);
  tcase_add_test(tc_core, test_sprintf_unsigned_2);
  tcase_add_test(tc_core, test_sprintf_unsigned_3);
  tcase_add_test(tc_core, test_sprintf_unsigned_4);
  tcase_add_test(tc_core, test_sprintf_unsigned_5);
  tcase_add_test(tc_core, test_sprintf_notation_1);
  tcase_add_test(tc_core, test_sprintf_notation_2);
  tcase_add_test(tc_core, test_sprintf_notation_3);
  tcase_add_test(tc_core, test_sprintf_notation_4);
  tcase_add_test(tc_core, test_sprintf_g_1);
  tcase_add_test(tc_core, test_sprintf_g_2);
  tcase_add_test(tc_core, test_sprintf_g_3);
  tcase_add_test(tc_core, test_sprintf_g_4);
  tcase_add_test(tc_core, test_sprintf_g_5);
  tcase_add_test(tc_core, test_sprintf_x_1);
  tcase_add_test(tc_core, test_sprintf_x_2);
  tcase_add_test(tc_core, test_sprintf_x_3);
  tcase_add_test(tc_core, test_sprintf_x_4);
  tcase_add_test(tc_core, test_sprintf_x_5);
  tcase_add_test(tc_core, test_sprintf_x_6);
  tcase_add_test(tc_core, test_sprintf_o_1);
  tcase_add_test(tc_core, test_sprintf_o_2);
  tcase_add_test(tc_core, test_sprintf_o_3);
  tcase_add_test(tc_core, test_sprintf_o_4);
  tcase_add_test(tc_core, test_sprintf_o_5);
  tcase_add_test(tc_core, test_sprintf_p_1);
  tcase_add_test(tc_core, test_sprintf_p_2);
  tcase_add_test(tc_core, test_sprintf_p_3);
  tcase_add_test(tc_core, test_sprintf_zero_1);
  tcase_add_test(tc_core, test_sprintf_zero_2);
  tcase_add_test(tc_core, test_sprintf_zero_3);
  tcase_add_test(tc_core, test_sprintf_zero_4);
  tcase_add_test(tc_core, test_sprintf_hashtage_1);
  tcase_add_test(tc_core, test_sprintf_hashtage_2);
  tcase_add_test(tc_core, test_sprintf_hashtage_3);
  tcase_add_test(tc_core, test_sprintf_asterisk_1);
  tcase_add_test(tc_core, test_sprintf_asterisk_2);
  tcase_add_test(tc_core, test_sprintf_asterisk_3);
  tcase_add_test(tc_core, test_sprintf_asterisk_4);
  tcase_add_test(tc_core, test_sprintf_L_1);
  tcase_add_test(tc_core, test_sprintf_L_2);
  tcase_add_test(tc_core, test_to_upper_1);
  tcase_add_test(tc_core, test_to_upper_2);
  tcase_add_test(tc_core, test_to_upper_3);
  tcase_add_test(tc_core, test_to_lower_1);
  tcase_add_test(tc_core, test_to_lower_2);
  tcase_add_test(tc_core, test_to_lower_3);
  tcase_add_test(tc_core, test_insert_1);
  tcase_add_test(tc_core, test_insert_2);
  tcase_add_test(tc_core, test_insert_3);
  tcase_add_test(tc_core, test_trim_1);
  tcase_add_test(tc_core, test_trim_2);
  tcase_add_test(tc_core, test_complex_1);
  tcase_add_test(tc_core, test_sprintf_empty_1);
  tcase_add_test(tc_core, test_sprintf_return_1);
  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_core);
  return s;
}
