#
# test 8
#< file_in << eof0 cat >file_out0 | < file_in cat > file_out1 << eof2 << eof3 | cat  << eof1 > file_out3
TEST="./a.out debug_8.log < file_in << eof0 cat >file_out0 -e | < file_in cat > file_out1 << eof2 << eof3 | cat  << eof1 -e > file_out3"
printf -- "\n$BAR test8 $BAR\n"
printf "$TEST\n"
$TEST
