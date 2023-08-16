/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 22:12:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "execute.h"
#include "debug.h"

//void execute_pipeline(t_ASTNode** commands, size_t num_commands) {
//    int num_pipes = num_commands - 1;
//    int pipes[num_pipes][2]; // Create pipes for communication between commands
//
//    // Create pipes
//    for (int i = 0; i < num_pipes; i++) {
//        if (pipe(pipes[i]) == -1) {
//            perror("Pipe creation error");
//            exit(EXIT_FAILURE);
//        }
//    }
//
//    for (int i = 0; i < num_commands; i++) {
//        pid_t pid = fork();
//        if (pid == 0) {
//            // Child process
//
//            if (i > 0) {
//                // Redirect input from the previous pipe
//                dup2(pipes[i - 1][0], STDIN_FILENO);
//                close(pipes[i - 1][0]);
//                close(pipes[i - 1][1]);
//            }
//
//            if (i < num_pipes) {
//                // Redirect output to the next pipe
//                dup2(pipes[i][1], STDOUT_FILENO);
//                close(pipes[i][0]);
//                close(pipes[i][1]);
//            }
//
//            // Execute the command
//            //execvp(commands[i]->value, /* argument array */);
//            perror("Execution error");
//            exit(EXIT_FAILURE);
//        } else if (pid > 0) {
//            // Parent process
//            if (i > 0) {
//                close(pipes[i - 1][0]);
//                close(pipes[i - 1][1]);
//            }
//            if (i == num_pipes) {
//                close(pipes[i][0]);
//                close(pipes[i][1]);
//            }
//            waitpid(pid, NULL, 0); // Wait for the child process to complete
//        } else {
//            perror("Fork error");
//            exit(EXIT_FAILURE);
//        }
//    }
//}

#include "ft_printf.h"//for debug
int	handle_operator(t_ASTNode* operator_node) {
	if (operator_node->type != NODE_OPERATOR)
		return (1);
	ft_printf("\tOPERATOR\t[%s]\n", operator_node->value);
    if (strcmp(operator_node->value, "|") == 0) {
        size_t num_commands = operator_node->num_children;
        t_ASTNode** commands = operator_node->children;

        // Execute the pipeline
		int status;
        status = execute_pipeline(commands, num_commands);
		exit(status);
    } else if (strcmp(operator_node->value, "&") == 0) {
        // Implement background execution logic
        // ...
    } else {
        // Handle other operators if needed
        // ...
    }
	return (0);
}
