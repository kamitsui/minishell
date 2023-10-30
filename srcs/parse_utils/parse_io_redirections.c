/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:59:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 14:07:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error_minishell.h"
#include <stdlib.h>

static t_ast	*parse_one_redirection(char ***tokens, char *value)
{
	t_ast	*node;

	node = create_node(NODE_COMMAND, value);
	add_node_children(node, NODE_REDIRECTION, **tokens);
	(*tokens)++;
	if (is_redirection(**tokens) == false && is_pipe(**tokens) == false
		&& is_end(**tokens) == false)
	{
		add_node_children(node, NODE_FILE, **tokens);
		(*tokens)++;
	}
	else
	{
		handle_syntax_error(**tokens);
		while (is_end(**tokens) == false)
			(*tokens)++;
	}
	return (node);
}

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
		redirection_node = parse_one_redirection(&tokens, value);
		node->num_children++;
		node->children = (t_ast **)ft_realloc_tentative(node->children,
				node->num_children * sizeof(t_ast *),
				(node->num_children - 1) * sizeof(t_ast *));
		node->children[node->num_children - 1] = redirection_node;
		free(value);
	}
	return (node);
}
