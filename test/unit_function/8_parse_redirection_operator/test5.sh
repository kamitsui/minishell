#
# test 5
COMMAND="ls -l && < non_exist ls_zzz || ls -l | cat -e | grep Make"
TEST="./a.out debug_5.log $COMMAND"
printf -- "\n$BAR test5 $BAR\n"
printf "$TEST\n"
$TEST
