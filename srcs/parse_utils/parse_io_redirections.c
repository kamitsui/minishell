/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 19:44:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

// for debug
#include "debug.h"
#include "ft_printf.h"

static t_ast	*parse_one_redirection(char **tokens, char *value)
{
	t_ast	*node;
	t_ast	*redirection_node;
	t_ast	*file_node;

	node = create_node(NODE_COMMAND, value);
	redirection_node = create_node(NODE_REDIRECTION, *tokens);
	node->num_children++;
	node->children = (t_ast **)realloc(node->children,
			node->num_children * sizeof(t_ast *));// use ft_realloc
	node->children[node->num_children - 1] = redirection_node;
	tokens++;
	file_node = create_node(NODE_FILE, *tokens);
	ft_dprintf(g_fd_log, ">> in parse_one_redirection ... file[%s]\n", *tokens);
	node->num_children++;
	node->children = (t_ast **)realloc(node->children,
			node->num_children * sizeof(t_ast *));// use ft_realloc
	node->children[node->num_children - 1] = file_node;
	return (node);
}
// debug code
//	ft_dprintf(g_fd_log,
//			">> in parse_one_redirection ... redirection[%s]\n", *tokens);

t_ast	*parse_io_redirections(char **tokens, char *head_value)
{
	t_ast	*node;
	t_ast	*redirection_node;
	char	*value;

	node = create_node(NODE_IO_REDIRECTIONS, head_value);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == false)
		{
			tokens++;
			continue ;
		}
		value = get_one_redirection_value(tokens);
		redirection_node = parse_one_redirection(tokens, value);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,
				node->num_children * sizeof(t_ast *));// use ft_realloc
		node->children[node->num_children - 1] = redirection_node;
		tokens++;// ？ 連続してリダイレクションのトークンがきたら...
	}
	return (node);
}
// debug code
//	debug_parse("parse_io_redirections", node);// debug
