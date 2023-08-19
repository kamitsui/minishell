/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:16:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 11:45:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include "parse.h"
#include "execute.h"
#include "ft_printf.h"
#include <unistd.h>

// debug code
//#include "debug.h"
//	debug_command(&command);

static void	child_process(t_command command)
{
	char	*file;

	file = command.args[0];
	exec_file(file, command.args, command.env);
	ft_fprintf(STDERR_FILENO, "%s: %s: command not found\n", NAME, file);
	exit (127);
}

int	execute_command(t_ASTNode *command_node, char **env, int status)
{
	t_command	command;
	size_t		i;
	pid_t		pid;

	(void)status;
	if (command_node->type != NODE_COMMAND)
		return (-1);
	command.cmd_name = command_node->value;
	i = 0;
	while (i < command_node->num_children)
	{
		get_arguments(&command, command_node);
		i++;
	}
	command.env = env;
	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
	if (pid == 0)
		child_process(command);
	return (wait_process(pid, 1));
}
// how to test this function
// |
// cd minishell/test/unit_function
// make 4
// make run4
