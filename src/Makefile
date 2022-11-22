CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LDFLAGS=
PROFILE_FLAGS=-fprofile-arcs -ftest-coverage
SOURCES=s21_string.c tests.c
OS:=$(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS=-lcheck -lm -lpthread -lrt -lsubunit
else
	CHECKFLAGS=-lcheck -lm -lpthread
endif

# get example from: https://www.ccs.neu.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html

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

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) s21_string.c

tests.o: tests.c
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) tests.c

ltests_run: s21_string.o tests.o
	$(CC) s21_string.o tests.o $(CHECKFLAGS) -lgcov -coverage -o run
	./run

gcov_report.html: test
	gcovr -r . --html --html-details -o gcov_report.html

rebuild: clean all

clean:
	rm -rf *.o \
		*.a \
		*.so \
		*.gcno \
		*gcda \
		*.gcov \
		gcov_report.* \
		run \
		gcov \
		report/ \
		report.info
