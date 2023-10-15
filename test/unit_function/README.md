Â### How to use

#### Compile check
```make``` : all target

```make N``` : chose target

chose N from the below
* ```1``` : make tester to link the below functions
> `handle_operator` / `execute_pipeline`
>
> test case :
> "ls -a -l | cat -e | grep Make"
* ```2``` : make travers tester to link the below functions
> `traverse_ast` / `execute_command` / `handle_operator` / `execute_pipeline`
>
> test case : \<pipe-command>
> >"ls -a -l | cat file.txt"
* ```3``` : make `parse` function tester
> test case : \<simple-command> \<connector> \<simple-command>
>
> > *tokens[] = { "ls", "-l", "file.txt", "&&", "cat", "file.txt", NULL }
* ```4``` : make `parse_pipe_command` function tester
> test case : \<pipe-command>
>
> > *tokens[] = { "ls", "-l", "-a", "|", "cat", "-e", "|", "grep", "Make", NULL }
* ```5``` : make the tester to link the below functions
> `parse` / `execute_command`
>
> test case1 : \<simple-command>
> > `ls -a -l` ... return(0)
>
> test case2 : \<simple-command> ... command not found
> > `hoge1 hoge2 hoge3` ... return (127)
* ```6``` : make the tester to link the below functions
> `parse` / `traverse_ast` / `execute_command` / `execute_pipeline`
>
> test case1 : \<simple-command>
> > `ls -l -a` ... (0)
> >
> > `hoge1 hoge2 hoge3` ... return (127)
>
> test case2 : \<pipe-command>
> > `ls -l -a | grep Make` ... return(0)
> >
> > `hoge1 -a | hoge2 -b | hoge3` ... return(???)


#### Run check
```make run``` : Run all test

```make runN``` : chose target

chose N from the below
* ```1``` : check tester to link `handle_operator` and `execute_pipeline`
* ```2``` : check tester to link the below functions
> `traverse_ast` / `execute_command` / `handle_operator` / `execute_pipeline`
* ```3``` : check `parse` tester
* ```4``` : check `parse_pipe_command` tester
* ```5``` : check tester to link the below functions
> `parse` / `execute_command`
* ```6``` : check `6-1` and `6-2` tester to link the below functions
> `parse` / `traverse_ast` / `execute_command` / `execute_pipeline`
* ```6-1``` : check \<simple-command>
* ```6-2``` : check \<pipe-command>
