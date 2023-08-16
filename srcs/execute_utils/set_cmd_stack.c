/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:17:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 22:21:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

void	get_arguments(t_command commands, t_ASTNode *node)
{
	size_t	i;

	i = 0;
	commands.args[i] = node->children[i]->value;
	while (i < node->num_children)
	{
		i++;
		commands.args[i] = node->children[i]->value;
	}
}

void	set_cmd_stack(t_cmdstack *cmdstack, t_ASTNode **commands, size_t num_commands)
{
	size_t	i;

	i = 0;
	while (i < num_commands)
	{
		cmdstack->commands[i].cmd_name = commands[i]->value;
		get_arguments(cmdstack->commands[i], commands[i]);
		i++;
	}
//	;
}
