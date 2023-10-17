#!/bin/bash
BAR="----"
#
printf "\ntest1~4 using tkn_controller OK\n"
#
# test 1
TEST="./a.out debug_1.log > in"
printf -- "\n$BAR test1 $BAR\n"
printf "$TEST\n"
$TEST
#
# test 2
TEST="./a.out debug_2.log >> here_doc"
printf -- "\n$BAR test2 $BAR\n"
printf "$TEST\n"
$TEST
#
# test 3
TEST="./a.out debug_3.log < out"
printf -- "\n$BAR test3 $BAR\n"
printf "$TEST\n"
$TEST
#
# test 4
TEST="./a.out debug_4.log << append"
printf -- "\n$BAR test4 $BAR\n"
printf "$TEST\n"
$TEST
#
printf "\ntest5~6 using tkn_controller KO ... でもminishell全体で動かすと、きちんとトークナイズされている。（保留）\n"
#
# test 5
COMMAND="ls -l && < non_exist ls_zzz || ls -l | cat -e | grep Make"
TEST="./a.out debug_5.log $COMMAND"
printf -- "\n$BAR test5 $BAR\n"
printf "$TEST\n"
$TEST
#
# test 6
COMMAND='$VAR "42tokyo" && "ec""ho" '"'single_quoted'"
TEST='./a.out debug_6.log'
printf -- "\n$BAR test6 $BAR\n"
printf "$TEST $COMMAND\n"
$TEST $COMMAND
#
# test 7
TEST="./a.out debug_7.log ls | < file_in cat > file_out << eof1 << eof2 | cat"
printf -- "\n$BAR test7 $BAR\n"
printf "$TEST\n"
$TEST
