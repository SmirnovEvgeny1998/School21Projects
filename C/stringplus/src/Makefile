CFLAGS = -std=c11 -Wall -Werror -Wextra
TFLAGS = -lcheck -lm -lpthread 
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	TFLAGS +=  -lsubunit
endif

all : gcov_report clean test

test : tests.o s21_string.a
	gcc $(CFLAGS) tests.o s21_string.a $(TFLAGS) -o test

tests.o : tests.c
	gcc $(CFLAGS) -c tests.c -o tests.o

gcov_report: clean 
	gcc $(CFLAGS) --coverage -c tests.c -o tests.o
	gcc $(CFLAGS) --coverage -c s21_string.c -o s21_string.o
	ar rcs s21_string.a s21_string.o
	gcc $(CFLAGS) --coverage tests.o s21_string.a $(TFLAGS) -o test
	./test
	gcov tests.c -m > tests.html
	gcov s21_string.c -m > s21_string.html

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o

s21_string.o : s21_string.c
	gcc $(CFLAGS) -c s21_string.c -o s21_string.o

clean :
	rm -rf *.o test *.gc* *.a

rebuild: clean all

