all : s21_cat s21_grep

s21_cat : base_cat.o cat_functions.o cat_other_functions.o
	gcc base_cat.o cat_functions.o cat_other_functions.o -o s21_cat

s21_grep : ../grep/try_grep.c
	gcc -Wall -Werror -Wextra ../grep/try_grep.c -o ../grep/s21_grep

base_cat.o : base_cat.c
	gcc -Wall -Werror -Wextra -c base_cat.c -o base_cat.o

cat_functions.o : cat_functions.c
	gcc -Wall -Werror -Wextra -c cat_functions.c -o cat_functions.o

cat_other_functions.o : cat_other_functions.c
	gcc -Wall -Werror -Wextra -c cat_other_functions.c -o cat_other_functions.o

clean :
	rm *.o s21_cat ../grep/*.o ../grep/s21_grep