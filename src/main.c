#include "s21_string.h"
#include <string.h>
#include <stdio.h>

void test_memchr();

int main() {
    test_memchr();
    return 0;
}

void test_memchr() {
    // исходная строка
    char src[15] = "1a234567890";
    printf("исходный:\n");
    // адрес ячейки типа char если есть символ 'а' в первых пяти ячейках то возвращет этот адрес
    // если нет то возвращает null
    char *sym = memchr(src, '3', 5);

    if (sym != NULL) {
        printf("%s\n", sym);
    } else {
        printf("%s\n", sym);
    }

   char sr[15] = "1а234567890";

    printf("созданный:\n");

    char *sy = s21_memchr(sr, 'а', 5);

    if (sy != NULL) {
        printf("%s\n", sy);
    } else {
        printf("%s\n", sy);
    }
}