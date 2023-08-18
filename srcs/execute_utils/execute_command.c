/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:16:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 20:12:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include "parse.h"
#include "execute.h"
#include "ft_printf.h"
//#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>

void	child_process(t_command command)
{
	char	*file;

	file = command.args[0];
	exec_file(file, command.args, command.env);
	ft_fprintf(STDERR_FILENO, "%s: %s: command not found\n", NAME, file);
	exit (127);
}

int	execute_command(t_ASTNode *command_node, char **env)
{
	t_command	command;
	t_ASTNode	*argument_node;
	size_t		i;
	pid_t		pid;

	command.cmd_name = command_node->value;
	i = 0;
	while (i < command_node->num_children)
	{
		argument_node = command_node->children[i];
		get_arguments(&command, argument_node);
		i++;
	}
	command.env = env;
	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
	else
		child_process(command);
	return (wait_process(pid, 1));
}
// how to test this function
// |
// cd minishell/test/unit_function
// make 4
// make run4


//	if (pid == 0)
//	{
//		// Child process
//		// Set up input/output redirection
//		// Execute the command using execvp or another suitable function
//		execvp(command_node->value, /* argument array */);
//		// Handle execvp error if it occurs
//		exit(1);
//	}
//	else if (pid > 0)
//	{
//		// Parent process
//		// Wait for the child process to complete
//		waitpid(pid, NULL, 0);
//	}
//	else
//	{
//		// Forking error
//		perror("Fork error");
//	}
