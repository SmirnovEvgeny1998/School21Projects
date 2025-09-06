#!/bin/bash
passed_tests=0
failed_tests=0
counter=0
equals=""



s21_command=(
    "./s21_grep"
    )
sys_command=(
    "grep"
    )

flags=(
    "i"
    "v"
    "c"
    "l"
    "n"
    "h"
    "s"
    "o"
)

tests=(
    "FLAGS cmp test_files/1_test_grep.txt"
    "FLAGS int test_files/1_test_grep.txt test_files/3_test_grep.txt"
    "FLAGS -f test_files/test_flags.txt test_files/2_test_grep.txt"
    "FLAGS -f test_files/test_flags.txt test_files/5_test_grep.txt test_files/4_test_grep.txt"
    "FLAGS -e cmp test_files/1_test_grep.txt"
    "FLAGS -e cmp test_files/1_test_grep.txt test_files/3_test_grep.txt"
)

manual=(
    "-z d test_files/1_test_grep.txt"
    "-n for test_files/1_test_grep.txt test_files/2_test_grep.txt"
    "-n -e ^\} test_files/1_test_grep.txt"
    "-ce ^int test_files/1_test_grep.txt test_files/2_test_grep.txt"
    "-nivh = test_files/1_test_grep.txt test_files/2_test_grep.txt"
    "-e"
    "-v test_files/1_test_grep.txt -e ank"
    "-noe ^? test_files/4_test_grep.txt"
    "-l for test_files/1_test_grep.txt test_files/2_test_grep.txt"
    "-o -e int test_files/3_test_grep.txt"
    "-e int -si no_file.txt s21_grep.c no_file2.txt s21_grep.h"
    "-si s21_grep.c -f no_pattern.txt"
)

solo_flags=(
    "int test_files/1_test_grep.txt"
    "-e int test_files/1_test_grep.txt"
    "-i echo test_files/4_test_grep.txt"
    "-v int test_files/1_test_grep.txt"
    "-c int test_files/1_test_grep.txt"
    "-l int test_files/1_test_grep.txt test_files/2_test_grep.txt"
    "-n int test_files/1_test_grep.txt"
    "-h int test_files/1_test_grep.txt test_files/2_test_grep.txt"
    "-s error test_files/dont_exist.txt"
    "-f test_files/test_flags.txt test_files/1_test_grep.txt"
    "-o int test_files/1_test_grep.txt"
)

run_test() {
    param=$(echo "$@" | sed "s/FLAGS/$temp/")
    valgrind --quiet "${s21_command[@]}" $param > "${s21_command[@]}".log
    "${sys_command[@]}" $param > "${sys_command[@]}".log
    equals="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
    let "counter++"
    if [ "$equals" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
    then
        let "passed_tests++"
        echo "$counter - Success $param"
    else
        let "failed_tests++"
        echo "$counter - Fail $param"
    fi
    rm -f "${s21_command[@]}".log "${sys_command[@]}".log
}

echo "***********************"
echo "Ручные тесты"
echo "***********************"
printf "\n"
printf "\n"
echo "-----------------------"
echo "1 флаг без комбинаций с -е -f"
echo "-----------------------"
printf "\n"

for i in "${solo_flags[@]}"
do
    temp="-"
    run_test "$i"
done

printf "\n"
echo "-----------------------"
echo "Ручной подбор"
echo "-----------------------"
printf "\n"

for i in "${manual[@]}"
do
    temp="-"
    run_test "$i"
done

printf "\n"
echo "***********************"
echo "Автотесты"
echo "***********************"
printf "\n"
echo "-----------------------"
echo "1 флаг"
echo "-----------------------"
printf "\n"

for temp1 in "${flags[@]}"
do
    for i in "${tests[@]}"
    do
        temp="-$temp1"
        run_test "$i"
    done
done
printf "\n"
echo "-----------------------"
echo "2 флага"
echo "-----------------------"
printf "\n"

for temp1 in "${flags[@]}"
do
    for temp2 in "${flags[@]}"
    do
        if [ $temp1 != $temp2 ]
        then
            for i in "${tests[@]}"
            do
                temp="-$temp1 -$temp2"
                run_test "$i"
            done
        fi
    done
done
printf "\n"
echo "FAILED: $failed_tests"
echo "SUCCESSFUL: $passed_tests"
echo "ALL: $counter"
echo "Failed pairs: -v -f(works as intended but not in original grep)"
echo "Failed pairs: -o -i(returns correct items in (somethimes) incorrect format)"
echo "Failed pairs: -l -c(works as intended but not in original grep)"
printf "\n"

