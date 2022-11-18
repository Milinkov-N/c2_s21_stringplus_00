#include "s21_string.h"

/**
    1. Searches for the first occurrence of the character c (an unsigned char)
    in the first n bytes of the string pointed to, by the argument str.
**/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  (void)str;
  (void)c;
  (void)n;
  return s21_NULL;
}

/**
    2. Compares the first n bytes of str1 and str2.
**/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  (void)str1;
  (void)str2;
  (void)n;
  return 0;
}
