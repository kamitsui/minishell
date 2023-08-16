/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:16:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 17:17:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

void execute_command(struct ASTNode* command_node) {
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        // Set up input/output redirection if needed
        // Execute the command using execvp or another suitable function
        execvp(command_node->value, /* argument array */);
        // Handle execvp error if it occurs
        exit(1);
    } else if (child_pid > 0) {
        // Parent process
        // Wait for the child process to complete
        waitpid(child_pid, NULL, 0);
    } else {
        // Forking error
        perror("Fork error");
    }
}
// Unfinish <compile, test>
