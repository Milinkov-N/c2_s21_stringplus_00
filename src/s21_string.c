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
      res = (void *)ptr;
    } else {
      ptr++;
    }
  }
  return res;
}

/**
    2. Compares the first n bytes of str1 and str2.

    Implemented by: Tania Kiara
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

/**
    3. Copies n characters from src to dest.

    Implemented by: Tania Kiara
**/
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *to = dest;
  for (s21_size_t i = 0; i < n; i++) to[i] = ((unsigned char *)src)[i];
  return to;
}

/**
    4. Another function to copy n characters from src to dest.

    Implemented by: Tania Kiara
**/
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *to = dest;
  void *result = to;

  if (src != dest && n != 0) {
    if (dest > src && dest - src < (int)n) {
      for (int i = n - 1; i >= 0; i--) to[i] = ((unsigned char *)src)[i];
      result = dest;
    } else if (src > dest && src - dest < (int)n) {
      for (s21_size_t i = 0; i < n; i++) to[i] = ((unsigned char *)src)[i];
      result = dest;
    } else {
      s21_memcpy(dest, src, n);
    }
  }

  return result;
}

/**
    5. Copies the character c (an unsigned char) to the first n characters of
    the string pointed to, by the argument str.

    Implemented by: Almeta Terry
**/
void *s21_memset(void *str, int c, s21_size_t n) {
  char *ptr = str;
  for(s21_size_t i = 0; i < n; i++) {
    *(ptr + i) = c;
  }
  return ptr;
}
