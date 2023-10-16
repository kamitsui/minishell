/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 03:42:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

static t_ast	*parse_one_redirection(char **tokens)
{
	t_ast	*node;
	t_ast	*file_node;

	node = create_node(NODE_REDIRECTION, *tokens);
	tokens++;
	if (is_string(*tokens) == true)
	{
		file_node = create_node(NODE_FILE, *tokens);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,// use ft_realloc
				node->num_children * sizeof(t_ast *));
		node->children[node->num_children - 1] = file_node;
	}
	return (node);
}

t_ast	*parse_io_redirections(char **tokens, char *head_value)
{
	t_ast	*node;
	t_ast	*redirection_node;

	node = create_node(NODE_IO_REDIRECTIONS, head_value);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
			&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == false)
		{
			tokens++;
			continue ;
		}
		redirection_node = parse_one_redirection(tokens);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,// use ft_realloc
				node->num_children * sizeof(t_ast *));
		node->children[node->num_children - 1] = redirection_node;
		tokens++;// ？ 連続してリダイレクションのトークンがきたら...
	}
	return (node);
}
// debug code
//	debug_parse("parse_io_redirection", node);// debug
//		debug_parse("parse_file after", file_node);// debug
