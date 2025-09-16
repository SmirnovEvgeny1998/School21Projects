CFLAGS = -std=c11 -Wall -Werror -Wextra
TFLAGS = -lcheck -lm -lpthread 
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	TFLAGS +=  -lsubunit
endif

all : style gcov_report

test : clean tests.o s21_decimal.a
	gcc $(CFLAGS) tests.o s21_decimal.a $(TFLAGS)  -o test
	./test
	rm -rf *.o

tests.o : tests.c
	gcc $(CFLAGS) -c tests.c -o tests.o

s21_decimal.o: s21_decimal.c s21_decimal.h
	gcc $(CFLAGS) -c s21_decimal.c -o s21_decimal.o

s21_decimal.a: s21_decimal.o
	ar rc s21_decimal.a s21_decimal.o
	ranlib s21_decimal.a

gcov_flag:
	$(eval CFLAGS += --coverage)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	open gcov/index.html
	rm -rf *.gcno *.gcda *.gcov

style:
	clang-format -i -style=Google *.c *.h

clean :
	rm -rf *.o test *.gc* *.a *.info gcov

rebuild: clean all
