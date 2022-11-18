CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
CHECKFLAGS=-lcheck -lm -lpthread
LDFLAGS=
SOURCES=s21_string.c tests.c

all: s21_string.a gcov_report

s21_string.a:
	$(CC) $(CFLAGS) $(LDFLAGS) s21_string.c -c -o s21_string.a

test: s21_string.a tests.o
	$(CC) $(CFLAGS) $(CHECKFLAGS) $(LDFLAGS) s21_string.a tests.o -o run
	./run

gcov_report:
	gcc --coverage -lcheck $(SOURCES) -o ./gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

rebuild: clean all

clean:
	rm -rf *.o \
		*.a \
		*.so \
		*.gcno \
		*gcda \
		*.gcov \
		run \
		gcov \
		report/ \
		report.info
