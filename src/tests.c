#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

// ТЕСТЫ ДЛЯ memchr

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

// ТЕСТЫ ДЛЯ memcmp

START_TEST(tc01_memcmp) {
  s21_size_t n = 12;
  void *str1 = "Hello there.";
  void *str2 = "Hello there.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(tc05_memcmp) {
  s21_size_t n = 8;
  void *str1 = "Don't underestimate my power!";
  void *str2 = "Don't try it.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

// ТЕСТЫ ДЛЯ memcpy

START_TEST(tc01_memcpy) {
  s21_size_t n = 12;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(tc02_memcpy) {
  s21_size_t n = 100;
  char str_1[256] = "Hello  there.";
  char str_2[256] = "I'm feeling \0good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(tc03_memcpy) {
  s21_size_t n = 1;
  char str_1[256] = "Hello \0 \n \t there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(tc04_memcpy) {
  s21_size_t n = 260;
  char str_1[256] = "Hello \0 \n \t there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memcpy(str_1, str_2, n), s21_memcpy(str_1, str_2, n));
}
END_TEST

// ТЕСТЫ ДЛЯ memmove

START_TEST(tc01_memmove) {
  s21_size_t n = 12;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

START_TEST(tc02_memmove) {
  s21_size_t n = 1;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

START_TEST(tc03_memmove) {
  s21_size_t n = 260;
  char str_1[256] = "Hello  \0 there.";
  char str_2[256] = "I'm feeling good almetate";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST
START_TEST(tc04_memmove) {
  s21_size_t n = 20;
  char str_1[100] = "0 dfjhk jdk gkdgf hjg f";
  char str_2[100] = "0 dfj bkdfb sb fjshf jhfs ";
  ck_assert_str_eq(memmove(str_1, str_2, n), s21_memmove(str_1, str_2, n));
}
END_TEST

// ТЕСТЫ ДЛЯ memset

START_TEST(tc01_memset) {
  s21_size_t n = 12;
  char ch = '\0';
  char str[100] = "sdsdf";
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str, ch, n));
}
END_TEST

START_TEST(tc02_memset) {
  s21_size_t n = 12;
  char ch = 'r';
  char str[100] = "sdsdf";
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str, ch, n));
}
END_TEST

START_TEST(tc03_memset) {
  s21_size_t n = 12;
  char ch = '\0';
  char str_1[100] = "sdsdf";
  char str_2[100] = "sdsdf";
  ck_assert_str_eq(memset(str_1, ch, n), s21_memset(str_2, ch, n));
  ck_assert_pstr_eq(memset(str_1, ch, n), s21_memset(str_2, ch, n));
}
END_TEST

// Функция создания набора тестов для 'memchr'
Suite *ts_s21_memchr() {
  Suite *suite = suite_create("ts_s21_memchr");
  TCase *test_case = tcase_create("tc_s21_memchr");

  tcase_add_test(test_case, tc01_memchr);
  tcase_add_test(test_case, tc02_memchr);
  tcase_add_test(test_case, tc03_memchr);
  suite_add_tcase(suite, test_case);

  return suite;
}

// Функция создания набора тестов для 'memcmp'
Suite *ts_s21_memcmp() {
  Suite *suite = suite_create("ts_s21_memcmp");
  TCase *test_case = tcase_create("tc_s21_memcmp");

  tcase_add_test(test_case, tc04_memcmp);
  tcase_add_test(test_case, tc05_memcmp);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memcpy() {
  Suite *suite = suite_create("ts_s21_memcpy");
  TCase *test_case = tcase_create("tc_s21_memcpy");

  tcase_add_test(test_case, tc06_memcpy);
  tcase_add_test(test_case, tc07_memcpy);
  tcase_add_test(test_case, tc08_memcpy);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memmove() {
  Suite *suite = suite_create("ts_s21_memmove");
  TCase *test_case = tcase_create("tc_s21_memmove");

  tcase_add_test(test_case, tc09_memmove);
  tcase_add_test(test_case, tc10_memmove);
  tcase_add_test(test_case, tc11_memmove);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memset() {
  Suite *suite = suite_create("ts_s21_memset");
  TCase *test_case = tcase_create("tc_s21_memset");

  tcase_add_test(test_case, tc01_memset);
  tcase_add_test(test_case, tc02_memset);
  tcase_add_test(test_case, tc03_memset);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main(void) {
  int failed = 0;
  Suite *test_suites[] = {
      ts_s21_memchr(),  ts_s21_memcmp(), ts_s21_memcpy(),
      ts_s21_memmove(), ts_s21_memset(), NULL,
  };

  for (Suite **s = test_suites; *s != NULL; s++) {
    SRunner *runner = srunner_create(*s);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed;
}
