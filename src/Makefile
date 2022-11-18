CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LDFLAGS=

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(CFLAGS) $(LDFLAGS) s21_string.c -c -o s21_string.a



main: main.o
	$(CC) main.o s21_string.a -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

test:

gcov_report:

rebuild: clean all

clean:
	rm -rf *.o *.a *.so
