all : s21_cat s21_grep

s21_cat : ../cat/base_cat.o ../cat/cat_functions.o ../cat/cat_other_functions.o
	gcc ../cat/base_cat.o ../cat/cat_functions.o ../cat/cat_other_functions.o -o ../cat/s21_cat

s21_grep : try_grep.c
	gcc -Wall -Werror -Wextra try_grep.c -o s21_grep

base_cat.o : ../cat/base_cat.c
	gcc -Wall -Werror -Wextra -c ../cat/base_cat.c -o ../cat/base_cat.o

cat_functions.o : ../cat/cat_functions.c
	gcc -Wall -Werror -Wextra -c ../cat/cat_functions.c -o ../cat/cat_functions.o

cat_other_functions.o : ../cat/cat_other_functions.c
	gcc -Wall -Werror -Wextra -c ../cat/cat_other_functions.c -o ../cat/cat_other_functions.o

clean :
	rm ../cat/*.o ../cat/s21_cat *.o s21_grep