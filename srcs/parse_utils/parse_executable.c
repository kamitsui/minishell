/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:39:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 01:38:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

static t_ast	*parse_argument(char ***tokens)
{
	if (is_string(**tokens) == true)
	{
		(*tokens)++;
		return (create_node(BIT_ARGUMENT, *(*tokens - 1)));
	}
	return (NULL);
}

t_ast	*parse_executable(char ***tokens)
{
	t_ast	*node;
	t_ast	*arg_node;

	node = create_node(BIT_EXECUTABLE, **tokens);
	(*tokens)++;
	while (is_connector(**tokens) == false && is_end(**tokens) == false
			&& is_pipe(**tokens) == false)
	{
		if (is_redirection(**tokens) == true)
		{
			(*tokens) += 2;//　エラーケースは未想定　例えば”>>"のみ
			continue ;
		}
		arg_node = parse_argument(tokens);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,// use ft_realloc
				node->num_children * sizeof(t_ast *));
		node->children[node->num_children - 1] = arg_node;
	}
	return (node);
}
