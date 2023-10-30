/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:39:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 13:37:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

static t_ast	*parse_argument(char ***tokens)
{
	if (is_end(**tokens) == false)
	{
		(*tokens)++;
		return (create_node(NODE_ARGUMENT, *(*tokens - 1)));
	}
	return (NULL);
}

t_ast	*parse_executable(char ***tokens)
{
	t_ast	*node;
	t_ast	*arg_node;

	node = create_node(NODE_EXECUTABLE, **tokens);
	(*tokens)++;
	while (is_connector(**tokens) == false && is_end(**tokens) == false
		&& is_pipe(**tokens) == false)
	{
		if (is_redirection(**tokens) == true)
		{
			(*tokens) += 2;
			continue ;
		}
		arg_node = parse_argument(tokens);
		node->num_children++;
		node->children = (t_ast **)ft_realloc_tentative(node->children,
				node->num_children * sizeof(t_ast *),
				(node->num_children - 1) * sizeof(t_ast *));
		node->children[node->num_children - 1] = arg_node;
	}
	return (node);
}
