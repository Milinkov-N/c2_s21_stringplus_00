#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

// 1. ТЕСТЫ ДЛЯ memchr

START_TEST(tc01_memchr) {
  s21_size_t n = 12;
  void *str = "Hello there.";
  char ch = 'l';
  ck_assert_pstr_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(tc02_memchr) {
  s21_size_t n = 2;
  void *str = "Hello there.";
  char ch = 't';
  ck_assert_pstr_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(tc03_memchr) {
  s21_size_t n = 20;
  void *str = "Hello there.";
  char ch = 'u';
  ck_assert_pstr_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

// 2. ТЕСТЫ ДЛЯ memcmp

START_TEST(tc04_memcmp) {
  s21_size_t n = 12;
  void *str1 = "Hello there.";
  void *str2 = "Hello there.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(tc05_memcmp) {
  s21_size_t n = 5;
  void *str1 = "Your move.";
  void *str2 = "You fool. I've been trained in your Jedi arts by Count Dooku.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(tc06_memcmp) {
  s21_size_t n = 8;
  void *str1 = "Don't underestimate my power!";
  void *str2 = "Don't try it.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

// 3. ТЕСТЫ ДЛЯ memcpy

START_TEST(tc07_memcpy) {
  s21_size_t n = 12;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(tc08_memcpy) {
  s21_size_t n = 100;
  char str_1[256] = "Hello  there.";
  char str_2[256] = "I'm feeling \0good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(tc09_memcpy) {
  s21_size_t n = 1;
  char str_1[256] = "Hello \0 \n \t there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(tc10_memcpy) {
  s21_size_t n = 260;
  char str_1[256] = "Hello \0 \n \t there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

// 4. ТЕСТЫ ДЛЯ memmove

START_TEST(tc11_memmove) {
  s21_size_t n = 12;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

START_TEST(tc12_memmove) {
  s21_size_t n = 1;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

START_TEST(tc13_memmove) {
  s21_size_t n = 260;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

START_TEST(tc14_memmove) {
  s21_size_t n = 20;
  char str_1[100] = "0 dfjhk jdk gkdgf hjg f";
  char str_2[100] = "0 dfj bkdfb sb fjshf jhfs ";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

// 5. ТЕСТЫ ДЛЯ memset

START_TEST(tc15_memset) {
  s21_size_t n = 12;
  char ch = '\0';
  char str[100] = "sdsdf";
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str, ch, n));
}
END_TEST

START_TEST(tc16_memset) {
  s21_size_t n = 12;
  char ch = 'r';
  char str[100] = "sdsdf";
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str, ch, n));
}
END_TEST

START_TEST(tc17_memset) {
  s21_size_t n = 12;
  char ch = '\0';
  char str_1[100] = "sdsdf";
  char str_2[100] = "sdsdf";
  ck_assert_str_eq(memset(str_1, ch, n), s21_memset(str_2, ch, n));
  ck_assert_pstr_eq(memset(str_1, ch, n), s21_memset(str_2, ch, n));
}
END_TEST

// 6. ТЕСТЫ ДЛЯ strcat

START_TEST(tc18_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "world!";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

START_TEST(tc19_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "world!";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

START_TEST(tc20_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "wor\n\tld!";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

START_TEST(tc21_strcat) {
  char dest[100]= "Hello ";
  char str[100] = "";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

// 7. ТЕСТЫ ДЛЯ strcnat

START_TEST(tc22_strncat) {
  s21_size_t n = 2;
  char dest[100] = "Hello ";
  char str[100] = "world!";
  char dest1[100] = "Hello ";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(tc23_strncat) {
  s21_size_t n = 3;
  char dest[100] = "Hello ";
  char str[100] = "world!";
  char dest1[100] = "Hello ";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(tc24_strncat) {
 s21_size_t n = 3;
  char dest[100] = "";
  char str[100] = "world!";
  char dest1[100] = "";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(tc25_strncat) {
   s21_size_t n = 3;
  char dest[100] = "";
  char str[100] = "HELLo";
  char dest1[100] = "";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

// 8. ТЕСТЫ ДЛЯ strchr

START_TEST(tc26_strchr) {
  char chr = 'o';
  char str[100] = "HELLo";
  ck_assert_pstr_eq(strchr(str, chr), s21_strchr(str, chr));
}
END_TEST

START_TEST(tc27_strchr) {
  char chr = '1';
  char str[100] = "HELLo";
  ck_assert_pstr_eq(strchr(str, chr), s21_strchr(str, chr));
}
END_TEST

START_TEST(tc28_strchr) {
  char chr = '\0';
  char str[] = "HELLo";
  ck_assert_pstr_eq(strchr(str, chr), s21_strchr(str, chr));
}
END_TEST

// 9. Тесты для strcmp

START_TEST(tc29_strcmp) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(tc30_strcmp) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SChool";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(tc31_strcmp) {
  char str1[30] = "S21_\nSCHOOL";
  char str2[30] = "S21_\nSCHOOL";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

// 10. Тесты для strncmp

START_TEST(tc32_strncmp) {
  s21_size_t n = 5;
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST


START_TEST(tc33_strncmp) {
  s21_size_t n = 5;
  char str1[30] = "S21_SCHOOL   ";
  char str2[30] = "S21 _SCHOOL";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST


START_TEST(tc34_strncmp) {
  s21_size_t n = 5;
  char str1[30] = "S21 _SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *ts_s21_suite_insert(void) {
  Suite *suite = suite_create("ts_s21_suite_insert");
  TCase *test_case = tcase_create("tc_s21_insert");

  tcase_add_test(test_case, tc01_memchr);
  tcase_add_test(test_case, tc02_memchr);
  tcase_add_test(test_case, tc03_memchr);

  tcase_add_test(test_case, tc04_memcmp);
  tcase_add_test(test_case, tc05_memcmp);
  tcase_add_test(test_case, tc06_memcmp);

  tcase_add_test(test_case, tc07_memcpy);
  tcase_add_test(test_case, tc08_memcpy);
  tcase_add_test(test_case, tc09_memcpy);
  tcase_add_test(test_case, tc10_memcpy);

  tcase_add_test(test_case, tc11_memmove);
  tcase_add_test(test_case, tc12_memmove);
  tcase_add_test(test_case, tc13_memmove);
  tcase_add_test(test_case, tc14_memmove);

  tcase_add_test(test_case, tc15_memset);
  tcase_add_test(test_case, tc16_memset);
  tcase_add_test(test_case, tc17_memset);

  tcase_add_test(test_case, tc18_strcat);
  tcase_add_test(test_case, tc19_strcat);
  tcase_add_test(test_case, tc20_strcat);
  tcase_add_test(test_case, tc21_strcat);

  tcase_add_test(test_case, tc22_strncat);
  tcase_add_test(test_case, tc23_strncat);
  tcase_add_test(test_case, tc24_strncat);
  tcase_add_test(test_case, tc25_strncat);

  tcase_add_test(test_case, tc26_strchr);
  tcase_add_test(test_case, tc27_strchr);
  tcase_add_test(test_case, tc28_strchr);

  tcase_add_test(test_case, tc29_strcmp);
  tcase_add_test(test_case, tc30_strcmp);
  tcase_add_test(test_case, tc31_strcmp);

  tcase_add_test(test_case, tc32_strncmp);
  tcase_add_test(test_case, tc33_strncmp);
  tcase_add_test(test_case, tc34_strncmp);


  suite_add_tcase(suite, test_case);

  return suite;
}

int main(void) {

  int failed = 0;
  Suite *s1;
  SRunner *sr;
  s1 = ts_s21_suite_insert();
  sr = srunner_create(s1);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return failed == 0 ? 0 : 1;
}
