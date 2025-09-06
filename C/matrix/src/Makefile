CFLAGS = -std=c11 -Wall -Werror -Wextra -g

all : test

gcov_report :
	gcc --coverage $(CFLAGS) -c tests.c -o tests.o
	gcc --coverage $(CFLAGS) -c s21_matrix.c -o s21_matrix.o
	gcc --coverage $(CFLAGS) tests.o s21_matrix.o -lcheck -lm -lpthread  -o test
	./test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	open gcov/index.html
	rm -rf *.gcno *.gcda *.gcov

test : tests.o s21_matrix.a
	gcc $(CFLAGS) tests.o s21_matrix.a -lcheck -lm -lpthread -o test
	./test

tests.o : tests.c
	gcc $(CFLAGS) -c tests.c -o tests.o

s21_matrix.a: s21_matrix.o
	ar rc s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a

s21_matrix.o: s21_matrix.c
	gcc $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

clean :
	rm -rf *.out *.o *.a test *.gcno *.gcda *.gcov *.html *.info gcov

debug :
	gcc -Wall -Werror -Wextra s21_matrix.c && ./a.out