PROJECT_NAME	= 3D_Viewer
FULL_PROJECT_NAME = C8_3DViewer_v1.0-1
ODIR 			= ./obj
INC_PATH		= ./
LIB_SRC_DIR		= ./
BUILD_LIB		= ./
REPORT_DIR = report
UNAME 		:= $(shell uname -s)

# Colored output.
RED = \033[0;31m
GREEN =  \033[0;32m
BLUE = \033[1;34m
NC  = \033[0m

CC = gcc

CFLAGS = -Wall -Werror -Wextra -std=c11
ADD_FLAG = -g -lm
TEST_FLAG = -lcheck -lpthread -lgcov

TESTS = tests/test_transform_matrix.c\
		tests/main_test.c tests/test_scale_matrix.c\
		tests/test_count_lines.c tests/test_get_array.c\
		tests/test_transform_vertex_massive.c tests/test_backend.c\
		tests/test_rotation_scale.c tests/test_motion_vertex.c\
		tests/find_max_coord_of_vert.c

SRC = 3D_Viewer_core.c
GCOV_FILES = ./*.gc*
TMP_FILES = *.o *.a *.out test tmp*
APP_DIR = ./$(PROJECT_NAME)/build

# macOS
ifeq ($(UNAME),Darwin)
	GCOV_CMD = lcov -o report.info -c -d .
	APP_DIR = ./$(PROJECT_NAME)/build/$(PROJECT_NAME).app/Contents/MacOS

# Ubuntu
else ifneq (,$(wildcard /etc/lsb-release))
	TEST_FLAG += -lsubunit -lrt
	GCOV_CMD = lcov -c -d . -o report.info

# Other linux
else ifeq ($(UNAME),Linux)
	TEST_FLAG +=  -lrt
	GCOV_CMD = lcov -c -d . -o report.info
endif


all: clear $(PROJECT_NAME)_core.a install
	
clear:
	clear

clean:
	@echo "$(RED)Removing project files$(NC)"
	rm -rf $(GCOV_FILES) $(TMP_FILES)
	rm -rf $(REPORT_DIR)
	@echo "$(RED)Removing documentation$(NC)"
	rm -rf doxygen

style-check:
	@echo "$(GREEN)Checking style...$(NC)"
	clang-format --style=Google -n ${LIB_SRC_DIR}/*.h ${LIB_SRC_DIR}/*.c ./$(PROJECT_NAME)/*.h ./$(PROJECT_NAME)/*.cpp

style:
	@echo "$(GREEN)Making style with clang-format...$(NC)"
	clang-format --style=Google -i ${LIB_SRC_DIR}/*.h ${LIB_SRC_DIR}/*.c ./$(PROJECT_NAME)/*.h ./$(PROJECT_NAME)/*.cpp

before_push: clean style
	@echo "$(GREEN)Changes are ready to push$(NC)"

test: clean
	@echo "$(GREEN)Making tests...$(NC)"
	$(CC) $(CFLAGS) $(SRC) $(TESTS) $(ADD_FLAG) $(TEST_FLAG) -o test
	@echo "$(GREEN)Run test with $(BLUE)./test$(NC)"
	./test

dvi: clean
	@echo "$(GREEN)Making documentation...$(NC)"
	@doxygen Doxyfile
	@echo "$(GREEN)Watch documentation in $(BLUE)./doxygen/html/index.html$(NC)"
	open ./doxygen/html/index.html

gcov_report: clean add_coverage test
	@echo "$(GREEN)Running tests...$(NC)"
	./test
	@echo "$(GREEN)Making report...$(NC)"
	lcov -o report.info -c -d .
	genhtml -o $(REPORT_DIR) report.info
	mv $(GCOV_FILES) report.info $(REPORT_DIR)/
	@echo "$(GREEN)Watch report in $(BLUE)$(REPORT_DIR)/index.html$(NC)"
	open $(REPORT_DIR)/index.html

add_coverage:
	$(eval TEST_FLAG += --coverage)

dist:
	@echo "$(GREEN)Making tar archive...$(NC)"
	cd ../.. && tar -czf $(FULL_PROJECT_NAME).tar.gz $(FULL_PROJECT_NAME)

install :
	cd ./$(PROJECT_NAME) && cmake -S . -B ./build && cd ./build && make install
	mv $(APP_DIR)/$(PROJECT_NAME) ./$(PROJECT_NAME)_v1.0

uninstall :
	rm -rf ./$(PROJECT_NAME)/build
	rm -rf ./$(PROJECT_NAME)_v1.0

.PHONY: all clean install uninstall dvi clear obj $(BUILD_LIB)/$(PROJECT_NAME)_core.a test style style-check before_push $(PROJECT_NAME)_core.a set_debug_gcc set_report_gcc gcov_report install uninstall