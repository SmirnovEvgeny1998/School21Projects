#!/bin/bash

passsed_tests=0
failed_tests=0
counter=0
equals=""

s21_cat=(
    "./s21_cat"
    )
cat=(
    "cat"
    )

tests=(
    "FLAGS test_files/test_case_cat.txt"
    "FLAGS test_files/test_case_cat.txt test_files/1_test_cat.txt"
)
flags=(
    "b"
    "e"
    "n"
    "s"
    "t"
    "v"
)
manual=(
    " test_files/1_test_cat.txt"
    "-n test_files/3_test_cat.txt"
    "-z test_files/1_test_cat.txt"
    "-s test_files/dont_exist.txt"
    "-s test_files/1_test_cat.txt"
    "-b -e -n -s -t -v test_files/1_test_cat.txt"
    "-n test_files/2_test_cat.txt"
    "-n -b test_files/1_test_cat.txt"
    "-n test_files/1_test_cat.txt test_files/2_test_cat.txt"
)

manual_long=(
    "--number-nonblank test_files/1_test_cat.txt"
    "-E test_files/test_case_cat.txt"
    "--number test_files/2_test_cat.txt"
    "--squeeze-blank test_files/1_test_cat.txt"
    "-T test_files/test_case_cat.txt"
)

run_test() {
    param=$(echo "$@" | sed "s/FLAGS/$temp/")
    "${s21_cat[@]}" $param > "${s21_cat[@]}".log
    "${cat[@]}" $param > "${cat[@]}".log
    equals="$(diff -s "${s21_cat[@]}".log "${cat[@]}".log)"
    let "counter++"
    if [ "$equals" == "Files "${s21_cat[@]}".log and "${cat[@]}".log are identical" ]
    then
        let "passsed_tests++"
        echo "$counter - Success $param"
    else
        let "failed_tests++"
        echo "$counter - Fail $param"
    fi
    rm -f "${s21_cat[@]}".log "${cat[@]}".log
}

run_long_flag_test() {
    param=$(echo "$@" | sed "s/FLAGS/$temp/")
    printf "\n"
    echo "Used flags/operands: $param"
    "${s21_cat[@]}" $param
}

echo "***********************"
echo "Ручные тесты"
echo "***********************"
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
echo "-----------------------"
echo "3 флага"
echo "-----------------------"
printf "\n"
for temp1 in "${flags[@]}"
do
    for temp2 in "${flags[@]}"
    do
        for temp3 in "${flags[@]}"
        do
            if [ $temp1 != $temp2 ] && [ $temp2 != $temp3 ] && [ $temp1 != $temp3 ]
            then
                for i in "${tests[@]}"
                do
                    temp="-$temp1 -$temp2 -$temp3"
                    run_test "$i"
                done
            fi
        done
    done
done
printf "\n"
echo "-----------------------"
echo "4 флага"
echo "-----------------------"
printf "\n"
for temp1 in "${flags[@]}"
do
    for temp2 in "${flags[@]}"
    do
        for temp3 in "${flags[@]}"
        do
            for temp4 in "${flags[@]}"
            do
                if [ $temp1 != $temp2 ] && [ $temp2 != $temp3 ] \
                && [ $temp1 != $temp3 ] && [ $temp1 != $temp4 ] \
                && [ $temp2 != $temp4 ] && [ $temp3 != $temp4 ]
                then
                    for i in "${tests[@]}"
                    do
                        temp="-$temp1 -$temp2 -$temp3 -$temp4"
                        run_test "$i"
                    done
                fi
            done
        done
    done
done
printf "\n"
echo "-----------------------"
echo "Парные флаги"
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
                temp="-$temp1$temp2"
                run_test "$i"
            done
        fi
    done
done
printf "\n"
echo "-----------------------"
echo "Строенные флаги"
echo "-----------------------"
printf "\n"
for temp1 in "${flags[@]}"
do
    for temp2 in "${flags[@]}"
    do
        for temp3 in "${flags[@]}"
        do
            if [ $temp1 != $temp2 ] && [ $temp2 != $temp3 ] && [ $temp1 != $temp3 ]
            then
                for i in "${tests[@]}"
                do
                    temp="-$temp1$temp2$temp3"
                    run_test "$i"
                done
            fi
        done
    done
done
printf "\n"
printf "\n"
echo "-----------------------"
echo "GNU флаги(ручные)"
echo "-----------------------"
printf "\n"
printf "\n"
for i in "${manual_long[@]}"
do
    temp="-"
    run_long_flag_test "$i"
done
printf "\n"
printf "\n"
echo "FAILED: $failed_tests"
echo "SUCCESSFUL: $passsed_tests"
echo "ALL: $counter"
printf "\n"
