printf "\033[32m---- parsing test start ----\033[0m\n"
printf -- "-------\n"
# <command-line> ::= <command> [ <connector> <command> ]*
printf "<command-line> ::= <command> [ <connector> <command> ]*\n"
printf "ls -l|grep a\t\033[32mOK\033[0m\n"
ls -l | grep a
printf "exit($?)\n\n"
printf "ls -l|grep a>file.txt\t\033[32mOK\033[0m\n"
ls -l | grep a>file.txt
printf "exit($?)\n\n"

# <command> ::= <simple-command> | <io-redirection> | <pipe-command>

# <connector> ::= ';' | '&&' | '||'

# <simple-command> ::= <executable> [ <argument> ]*
printf "<simple-command>\n"
printf "ls -l\t\t\033[32mOK\033[0m\n"
ls -l
printf "exit($?)\n\n"
printf -- "-------\n"
printf "<simple-command>\n"
printf "？？？\n"
printf -- "-------\n"
# <executable> ::= <string>

# <argument> ::= <string>

# <io-redirection> ::= <input-redirection> | <output-redirection> | <output-append-redirection>
printf "<io-redirection> ::= <input-redirection> | <output-redirection> | <output-append-redirection>\n"

# <input-redirection> ::= '<' <file>
printf "<input-redirection>\n"
printf "< file.txt\t\033[32mOK\033[0m\n"
< file.txt
printf "exit($?)\n\n"
printf "<file.txt\t\033[32mOK\033[0m\n"
<file.txt
printf "exit($?)\n\n"
printf "< ls\t\t\033[32mOK\033[0m\n"
< ls
printf "exit($?)\n\n"
printf -- "-------\n"
printf "<input-redirection>\n"
printf "<\t\t\033[31mNG\033[0m\t\tOutput error message and exit without passing to exec\n"
printf "bash: syntax error near unexpected token 'newline'\n"
#<# <-check This !!

# <output-redirection> ::= '>' <file>
printf "<output-redirection>\n"
printf "> file\n"
> file

# <output-append-redirection> ::= '>>' <file>

# <pipe-command> ::= <command> '|' <command>

# <string> ::= <word> | <quoted-string> | <variable-expansion>

# <word> ::= any sequence of non-whitespace characters without special characters or quotes

# <quoted-string> ::= '"' <characters> '"' | "'" <characters> "'"

# <characters> ::= any sequence of characters except the matching quote character

# <variable-expansion> ::= '$' <variable-name>

# <variable-name> ::= any valid environment variable name

# <file> ::= <word> | <quoted-string>

printf "\n\n---- \"42\"\"tokyo\" ---- \033[32m\"\"が連続するトークン\033[0m\n"
printf "\n> echo \"42\" \"tokyo\"\n"
echo "42" "tokyo"
printf "\n> echo \"42\"\"tokyo\"\n"
echo "42""tokyo"
printf "\n> ls \"-a\" \"l\"\n"
ls "-a" "l"
printf "\n> ls \"-a\"\"l\"\n"
ls "-a""l"

printf "\n\n---- \033[32m変数展開\033[0m ---- 複数続いた時も展開を忘れずに\n"
printf "\n> hoge\n"
printf "> expr \$? + \$?\n"
hoge
expr $? + $?
printf "\n> hoge\n"
printf "> echo \$? \$?\n"
hoge
echo $? $?
