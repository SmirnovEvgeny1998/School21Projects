CC = g++  -Wall -Werror -Wextra -std=c++17  
SRC = ./s21_graph/s21_graph.cc ./s21_graph/s21_graph_algorithms.cc ./s21_graph/ant_algorythms/s21_ant_algorithm.cc
OBJ = $(patsubst %.cc, %.o, ${SRC})
LFLAGS =  -lpthread 
GCF = -lpthread  -lgtest
# -I/Users/margertf/goinfre/googletest/googletest/include -L/Users/margertf/goinfre/googletest/build/lib

DEBUG=true

ifeq (${DEBUG}, true)
	CC += -g
endif

OS_NAME = $(shell uname -s)

ifeq ($(shell uname -s), Linux)
	LFLAGS += -lrt -lsubunit -lm
endif

.PHONY: main clean all s21_graph test cli

main:
		$(CC)   $(SRC)  main.cc -o main.out -g
		./main.out

clean:
	rm -rf *.o  && rm -rf *.gcno
	rm -rf *.out
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.dSYM
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test.out && rm -rf ./gcov_report
	rm -rf s21_*.a && rm -rf s21_*.o

all: s21_graph_algorithm.a test

s21_ant_alg.o:
	$(CC)  -c ./s21_graph/ant_algorythms/*.cc -o s21_ant_algorytm.o $(GFC)

s21_graph_algorithm.a: s21_ant_alg.o
	$(CC)  -c ./s21_graph/s21_*.cc $(GCF)
	ar rcs s21_graph_algorithm.a s21_*.o
	ranlib s21_graph_algorithm.a
	mkdir -p libs && mv s21_graph_algorithm.a ./libs
	rm -rf *.o

cli:
	$(CC) ./cli/cli.cc ./libs/s21_graph_algorithm.a -o cli.out -lncurses
	./cli.out
	
test: s21_graph_algorithm.a
	$(CC)  ./tests/s21_graph_test.cc ./libs/s21_graph_algorithm.a -o test.out $(GCF) 
	./test.out -v

lint:
	clang-format -i ./cli/*.cc
	clang-format -i ./s21_graph/*.cc
	clang-format -i ./s21_graph/ant_algorythms/*.cc
