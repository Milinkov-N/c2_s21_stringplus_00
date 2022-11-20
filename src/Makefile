CC=gcc
CFLAGS=-c -std=c11 -Wall -Werror -Wextra
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
CHECKFLAGS=-lcheck -lm -lpthread -lrt

# get example from: https://www.ccs.neu.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html

all: gcov_report.html

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) s21_string.c

tests.o: tests.c
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) tests.c

run: s21_string.o tests.o
	$(CC) s21_string.o tests.o $(CHECKFLAGS) -lgcov -coverage -o run

test: run
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
