CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LDFLAGS=

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(CFLAGS) $(LDFLAGS) s21_string.c -c -o s21_string.a

main:
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -c -o main.a

test:

gcov_report:

clean:
	rm -rf *.o *.a *.so
