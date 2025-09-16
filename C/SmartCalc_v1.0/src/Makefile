CFLAGS = -std=c11 -Wall -Werror -Wextra
TFLAGS = -lcheck -lm -lpthread 
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	TFLAGS +=  -lsubunit
endif

all : style gcov_report test

test : tests.o s21_smart_calc.a
	gcc $(CFLAGS) tests.o s21_smart_calc.a $(TFLAGS) -o test
	./test

tests.o : tests.c
	gcc $(CFLAGS) -c tests.c -o tests.o

s21_smart_calc.o: s21_smart_calc.c s21_smart_calc.h
	gcc $(CFLAGS) -c s21_smart_calc.c -o s21_smart_calc.o

s21_smart_calc.a: s21_smart_calc.o
	ar rc s21_smart_calc.a s21_smart_calc.o
	ranlib s21_smart_calc.a

gcov_report:
	gcc --coverage $(CFLAGS) -c tests.c -o tests.o
	gcc --coverage $(CFLAGS) -c s21_smart_calc.c -o s21_smart_calc.o
	gcc --coverage $(CFLAGS) tests.o s21_smart_calc.o $(TFLAGS) -o test
	./test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	open gcov/index.html
	rm -rf *.gcno *.gcda *.gcov

style:
	clang-format -i *.c *.h
	clang-format -i SmartCalc/s21_smart_calc.c SmartCalc/s21_smart_calc.h

clean : 
	rm -rf *.o test *.gc* *.a *.html *.out gcov *.info build* *.tgz targz html latex Doxyfile

rebuild: clean all

debug : s21_smart_calc.c
	gcc -Wall -Werror -Wextra s21_smart_calc.c
	./a.out

install :
	rm -rf build
	mkdir build
	cd build; \
	  ls; \
	  qmake6 ../SmartCalc/SmartCalc.pro; \
	  make -j4

uninstall :
	rm -rf build
	
dvi :
	doxygen -g
	doxygen Doxyfile
	cd html; \
	  open s21__smart__calc_8h.html

dist :
	make clean
	doxygen -g
	doxygen Doxyfile
	mkdir targz
	cp -R html targz
	make install
	cp -R build/SmartCalc.app targz
	tar -czf build_tgz.tgz targz
	rm -rf targz
	
