PROJECT_NAME	= 3DViewer_v2.0
CC    			= gcc
FL			    = -Wall -Wextra -Werror -lstdc++
TEST_FL         = -std=c++17 -lgtest 
TEST_FOLD		=./tests
TEST_NAME		= ${PROJECT_NAME}_tests
TEST_SRC		= $(TEST_NAME).cc
REPORT_FILES	= $(wildcard *.gcno) $(wildcard *.gcda)
UNAME_S 		:= $(shell uname -s)
EXEC_NAME       = 3DViewer_v2.0

ifeq ($(UNAME_S),Linux)
	OPEN_CMD = xdg-open
	ADD_LIB = -lm 
	APP_DIR = ./build
endif

ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB = 
	APP_DIR = ./build
	EXEC_NAME = 3DViewer_v2.0.app
endif

all: clear clean install gcov_report

install : 
	cd ./view && cmake -S . -B ../build && cd ../build && make install
	mv $(APP_DIR)/3D_Viewer.app ./$(EXEC_NAME)

launch: ./$(EXEC_NAME)
	open ./$(EXEC_NAME)

uninstall :
	rm -rf build
	rm -rf ./$(EXEC_NAME)

dvi : 
	doxygen doxyfile.cfg
	$(OPEN_CMD) ./generated-docs/html/index.html

dist : install
	tar -cf $(EXEC_NAME)_dist.tar ./$(EXEC_NAME)
	
clear:
	clear

clean:
	rm -rf $(TEST_NAME)
	rm -rf cov*
	rm -rf $(REPORT_FILES)
	rm -rf generated-docs

clang-check:
	clang-format --style=Google -n */*.h */*.cc

clang-format:
	clang-format --style=Google -i  */*.h */*.cc

set_debug_gcc:
	$(eval CC += -g)
	@echo 3DViewer_v2.0:Debug build

set_report_gcc:
	$(eval CC += -ftest-coverage -fprofile-arcs --coverage)
	@echo 3DViewer_v2.0:Check build

test: 
	$(CC) $(FL) $(TEST_FOLD)/$(TEST_SRC) ./model/*.cc -o $(TEST_NAME) $(TEST_FL) $(ADD_LIB)
	./$(TEST_NAME)

gcov_report: clean set_report_gcc test
	gcovr -r . --html --html-details -o cov-rep.html
	$(OPEN_CMD) cov-rep.html

valgrind_test: 
	g++ $(FL) $(TEST_FOLD)/$(TEST_SRC) ./model/*.cc -o $(TEST_NAME) $(TEST_FL) $(ADD_LIB)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -s ./$(TEST_NAME)
	 

.PHONY: clean install uninstall dvi clear test clang-format clang-check all set_debug_gcc set_report_gcc gcov_report
