CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
OS := $(shell uname)
CHECK_FLAGS = $(shell pkg-config --cflags --libs check)

all: clean s21_decimal.a test

s21_decimal.a: s21_decimal.o
	ar rcs s21_decimal.a s21_decimal.o

s21_decimal.o: s21_decimal.c 
	$(CC) $(CFLAGS) -c s21_decimal.c -o s21_decimal.o

test: test.o s21_decimal.a
	$(CC) $(CFLAGS) test.o s21_decimal.a -o test $(CHECK_FLAGS)
	./test

test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

test.c:
	checkmk clean_mode=1 ./tests/include.file ./tests/bonus_test/*.check ./tests/task_test/*.check > test.c
	clang-format -i -style=google test.c

gcov_report: test.c
	$(CC) -fprofile-arcs -ftest-coverage test.c s21_decimal.c -o gcov_report $(CHECK_FLAGS)
	./gcov_report
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

clean:
	rm -rf *.o *.a *.out *.info *.log *.html *.gc* test gcov_report s21_decimal report test.c

open:
ifeq ($(OS),Darwin)
	open -a "Google Chrome" report/src/index.html
else
	xdg-open report/src/index.html
endif

clang:
	clang-format -n -style=google *.c *.h

clangI:
	clang-format -i -style=google *.c *.h

leak: test
ifeq ($(OS),Darwin)
	CK_FORK=no leaks -atExit -- ./test
else
	CK_FORK=no valgrind --leak-check=full -s --track-origins=yes --log-file=leak.log ./test
endif	

rebuild: all

.PHONY: all rebuild leak clang clangI clean open