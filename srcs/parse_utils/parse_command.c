/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 20:35:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_command.c
 * @brief <simple-command> or <pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

/**
 * @brief \<command>のノードを作る関数
 * ::= <simple-command> or <pipe-command>
 *
 * @param ast 親のノード
 * @param tokens トークンのアドレス
 *
 * @return 生成された<command>のノードを返す
 */
t_ast	*parse_command(char ***tokens, char *head_value)
{
	t_ast	*node;
	t_ast	*command_node;
	char	*value;

	node = create_node(NODE_COMMAND, head_value);
	if (is_include_pipe_command(*tokens) == true)
	{
		value = get_pipe_command_value(*tokens);
		command_node = parse_pipe_command(tokens, value);
		free(value);
	}
	else
	{
		value = get_simple_command_value(*tokens);
		command_node = parse_simple_command(tokens, value);
		free(value);
	}
	node->num_children++;
	node->children = (t_ast **)ft_realloc_tentative(node->children,
			node->num_children * sizeof(t_ast *),
			(node->num_children - 1) * sizeof(t_ast *));
	node->children[node->num_children - 1] = command_node;
	return (node);
}
