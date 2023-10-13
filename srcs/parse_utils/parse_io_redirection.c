/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 06:00:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

#include "debug.h"// debug

t_ast	*parse_io_redirection(char ***tokens)
{
	t_ast	*node;
	t_ast	*file_node;
	bool	is_file_token;

	node = create_node(NODE_REDIRECTION, **tokens);
	(*tokens)++;
	is_file_token = is_string(**tokens);
	if (is_file_token == true)
	{
		file_node = parse_file(tokens);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,// use ft_realloc
				node->num_children * sizeof(t_ast *));
		node->children[node->num_children - 1] = file_node;
		is_file_token = is_string(**tokens);
	}
	return (node);
}
// debug code
//	debug_parse("parse_io_redirection", node);// debug
//		debug_parse("parse_file after", file_node);// debug
