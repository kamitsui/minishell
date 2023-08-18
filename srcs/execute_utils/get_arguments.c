/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:13:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 20:15:02 by kamitsui         ###   ########.fr       */
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
