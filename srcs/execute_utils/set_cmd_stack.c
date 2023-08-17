/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:17:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 10:09:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

void	get_arguments(t_command *commands, t_ASTNode *node)
{
	size_t	i;

	i = 0;
	commands->args = (char **)malloc(sizeof(char *) * (node->num_children + 2));
	commands->args[i] = node->value;
	while (i < node->num_children)
	{
		commands->args[i + 1] = node->children[i]->value;
		i++;
	}
	commands->args[i + 1] = NULL;
	commands->num_args = i + 1;
}

void	set_cmd_stack(t_cmdstack *cmdstack, t_ASTNode **commands, size_t num_commands)
{
	size_t	i;

	cmdstack->num_commands = num_commands;
	i = 0;
	while (i < num_commands)
	{
		cmdstack->commands[i].cmd_name = commands[i]->value;
		get_arguments(&(cmdstack->commands[i]), commands[i]);
		i++;
	}
//	;
}

void	set_environ(t_cmdstack *cmdstack, char **env)
{
	int	i;

	i = 0;
	while (i < cmdstack->num_commands)
	{
		cmdstack->commands[i].env = env;
		i++;
	}
}
