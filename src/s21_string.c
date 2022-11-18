#include "s21_string.h"

/**
    1. Searches for the first occurrence of the character c (an unsigned char)
    in the first n bytes of the string pointed to, by the argument str.
    
    Implemented by: Almeta Terry
**/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  // приравниваем изначально к нашему s21_NULL
  unsigned char *res = s21_NULL;

  //создаем переменную ptr типа char которая хранит адрес начала строки
  const unsigned char *ptr = str;

  for (int i = 0; i < (int) n; i++) {
    if(*ptr == (unsigned char) c) {
      res = *ptr;
    } else {
      ptr++;
    }
  }
  return res;
}

/**
    2. Compares the first n bytes of str1 and str2.
**/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && !result; i++) {
    unsigned char ch1 = *(unsigned char *)(str1 + i);
    unsigned char ch2 = *(unsigned char *)(str2 + i);
    if (ch1 != ch2) result = ch1 - ch2;
  }
  return result;
}
