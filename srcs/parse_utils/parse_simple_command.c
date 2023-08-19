/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:27:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 19:29:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>
#include <string.h>

t_ast	*parse_simple_command(char ***tokens)
{
	t_ast	*node;
	t_ast	*arg_node;

	node = create_node(NODE_COMMAND, **tokens);
	(*tokens)++;
	while (**tokens && strcmp(**tokens, "&&") != 0)
	{
		arg_node = parse_argument(tokens);
		if (arg_node == NULL)
		{
			(*tokens)++;
			break ;
		}
		else
		{
			node->num_children++;
			node->children = (t_ast **)realloc(node->children,
					node->num_children * sizeof(t_ast *));
			node->children[node->num_children - 1] = arg_node;
		}
	}
	return (node);
}
