
CC = gcc
FLAGS = -Wall -Werror -Wextra -g -std=c11
TFLAGS = -lcheck -lm -lpthread 
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	TFLAGS +=  -lsubunit
endif

all: test

test: clean s21_math.a math_tests.o
	$(CC) $(FLAGS) math_tests.o s21_math.a $(TFLAGS) -o test
	./test

math_tests.o: math_tests.c
	$(CC) $(FLAGS) -c math_tests.c

gcov_report: clean
	gcc --coverage $(FLAGS) -c math_tests.c -o math_tests.o
	gcc --coverage $(FLAGS) -c s21_math.c -o s21_math.o
	gcc --coverage $(FLAGS) math_tests.o s21_math.o $(TFLAGS) -o test
	./test
	gcov math_tests.c
	gcov s21_math.c
		
s21_math.a: s21_math.o
	ar -rc s21_math.a s21_math.o
	ranlib s21_math.a
	
s21_math.o: s21_math.c
	$(CC) $(FLAGS) -c s21_math.c

style:
	clang-format -i -style=Google *.c *.h

clean :
	rm -f *.o
	rm -f test
	rm -f *.a
	rm -f *.gc*

rebuild:
	make clean
	make all
#gcc test.c -Wall -o test -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
