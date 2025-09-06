CFLAGS = -std=c++17 -Wall -Werror -Wextra -g

all : test

clean :
	rm -rf *.a *.out test *.o

test : test.o s21_matrix_oop.a
	g++ $(CFLAGS) test.o s21_matrix_oop.a -lgtest -lgmock -pthread -o test
	./test

test.o : test.cc
	g++ $(CFLAGS) -c test.cc -o test.o

s21_matrix_oop.a: s21_matrix_oop.o
	ar rc s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

s21_matrix_oop.o : s21_matrix_oop.cc
	g++ $(CFLAGS) -c s21_matrix_oop.cc -o s21_matrix_oop.o