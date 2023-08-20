/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:44:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 23:01:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

t_ast	*parse_pipe_command(char ***tokens, size_t num_pipe)
{
	t_ast	*pipe_node;

	pipe_node = create_node(NODE_OPERATOR, "|");
	i = 0;
	while (**tokens && strcmp(**tokens, "&&") != 0)
	{
		command_node = parse_simple_command(tokens);
		if (command_node)
		{
			pipe_node->num_children++;
			pipe_node->children = (t_ast **)realloc(pipe_node->children,
					pipe_node->num_children * sizeof(t_ast *));
			pipe_node->children[pipe_node->num_children - 1] = command_node;
		}
	}

	return (pipe_node);
}
