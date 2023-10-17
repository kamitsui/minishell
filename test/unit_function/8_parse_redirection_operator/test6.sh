#
# test 6
COMMAND='$VAR "42tokyo" && "ec""ho" '"'single_quoted'"
TEST='./a.out debug_6.log'
printf -- "\n$BAR test6 $BAR\n"
printf "$TEST $COMMAND\n"
$TEST $COMMAND
