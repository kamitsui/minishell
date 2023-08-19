/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:39:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 15:21:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_printf.h"
#include "error_minishell.h"
#include "execute.h"
#include "parse.h"

static void	child_process(t_command command, int pipefd[2], int i, int num_commands)
{
	char	*file;

	file = command.args[0];
	close(pipefd[READ_END]);
	if (i < num_commands - 1)
	{
		if (dup2(pipefd[WRITE_END], STDOUT_FILENO) == -1)
		{
			close(pipefd[WRITE_END]);
			ft_errno_exit("dup2");
		}
	}
	close(pipefd[WRITE_END]);
	exec_file(file, command.args, command.env);
	ft_fprintf(STDERR_FILENO, "%s: %s: command not found\n", NAME, file);
	exit (127);
}

void	parent_process(int pipefd[2])
{
	close(pipefd[WRITE_END]);
	if (dup2(pipefd[READ_END], STDIN_FILENO) == -1)
	{
		close(pipefd[READ_END]);
		ft_errno_exit("dup2");
	}
	return ;
}

//// BUS ERROR
//static void	free_args(char **cmd_args)
//{
//	int		j;
//
//	j = 0;
//	while (cmd_args[j] != NULL)
//	{
//		free(cmd_args[j]);
//		j++;
//	}
//	free(cmd_args);
//}

// debug code
//#include "debug.h"//for debug
//		debug_token(cmd_args);// for debug (insert after cmd_args line)
int	execute_pipeline(t_ast **commands, size_t num_commands, char **env)
{
	int		pipefd[2];
	int		i;
	char	**cmd_args;
	pid_t	pid;
	t_cmdstack	cmdstack;

	set_cmd_stack(&cmdstack, commands, num_commands);
	set_environ(&cmdstack, env);
	i = 0;
	while (i < cmdstack.num_commands)
	{
		cmd_args = cmdstack.commands[i].args;
		if (cmdstack.commands[i].args == NULL)
			ft_perror_exit("ft_split");
		if (pipe(pipefd) == -1)
			ft_perror_exit("pipe");
		pid = fork();
		if (pid == -1)
			ft_perror_exit("fork");
		else if (pid == 0)
			child_process(cmdstack.commands[i], pipefd, i, cmdstack.num_commands);
		else
			parent_process(pipefd);
//		the below is BUS error
//		free_args(cmdstack.commands[i].args);
		i++;
	}
	return (wait_process(pid, cmdstack.num_commands));
}
// how to test this function
// |
// cd minishell/test/unit_function
// make 1
// make run1
