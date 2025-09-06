CFLAGS = -std=c++17 -Wall -Werror -Wextra -g
TESTS = calc_tests credit_tests deposit_tests
FUNCS = calc_model credit_model deposit_model
NAMES = calc credit deposit

all : test

test :
	for TEST in $(TESTS); do \
		g++ $(CFLAGS) -c $$TEST.cc -o $$TEST.o; \
	done
	for FUNC in $(FUNCS); do \
		g++ $(CFLAGS) -c $$FUNC.cc -o $$FUNC.o; \
	done
	for NAME in $(NAMES); do \
		g++ $(CFLAGS) $$NAME*.o -lgtest -pthread -o $$NAME; \
		./$$NAME; \
	done

gcov_report :
	for TEST in $(TESTS); do \
		g++ --coverage -c $$TEST.cc -o $$TEST.o; \
	done
	for FUNC in $(FUNCS); do \
		g++ --coverage -c $$FUNC.cc -o $$FUNC.o; \
	done
	for NAME in $(NAMES); do \
		g++ --coverage $$NAME*.o -lgtest -lm -lpthread -o $$NAME; \
		./$$NAME; \
		gcovr -r . --html --html-details -o cov-rep.html; \
		open cov-rep.html; \
	done

install :
	rm -rf build
	mkdir build
	cd build; \
	  ls; \
	  qmake6 ../calc_pp.pro; \
	  make -j4

uninstall :
	rm -rf build

dvi :
	doxygen -g
	doxygen Doxyfile
	cd html; \
	  open index.html

dist :
	make clean
	doxygen -g
	doxygen Doxyfile
	mkdir targz
	cp -R html targz
	make install
	cp -R build/calc_pp.app targz
	tar -czf build_tgz.tgz targz
	rm -rf targz

docker :
	./docker_run.sh

calc_valgrind :
	make test
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -s ./calc

credit_valgrind :
	make test
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -s ./credit

deposit_valgrind :
	make test
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -s ./deposit

clean :
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.css *.html *.tgz credit deposit calc html latex targz Doxyfile