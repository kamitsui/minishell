#!/bin/bash

#location of executable
exe="../token"

#testcase as arg
testcase=$1

#var array to contain quote char
declare -a quotes=("\"" "'" "(")

#var array to contain metachar
declare -a metachars=(" " "\t" "\n" "|" "&" "<" ">")

#var array to contain redirection operator
declare -a redirections=("<" "<<" ">" ">>")

#var array to contain control operator
declare -a controls=("|" "||" "&&" "\n")



# for c in "${quotes[@]}"
# do
# 	tests="
# 	42 "$c"tokyo"$c"
# 	42"$c"tokyo"$c"
# 	"
# 	echo "$tests"
# done |

quotetests='
42 tokyo
42 "tokyo" gogo
42 "to k yo" gogo
42 "to'k'yo" gogo
42 "to(k)yo" gogo
42 "to( k )yo" gog"o"
42"tokyo"gogo
42"to k yo"gogo
42"to'k'yo"gogo
42"to(k)yo"gogo
42"to( k )yo"gog"o"
'

singlequote="
42 tokyo
42 'tokyo' gogo
42 'to k yo' gogo
42 'to'k'yo' gogo
42 'to(k)yo' gogo
42 'to( k )yo' gog'o'
42'tokyo'gogo
42'to k yo'gogo
42'to\"k\"yo'gogo
42'to(k)yo'gogo
42'to( k )yo'gog'o'
"

"$exe" <<eof
"$quotetests"
eof