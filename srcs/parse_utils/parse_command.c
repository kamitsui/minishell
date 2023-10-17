/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 16:15:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_command.c
 * @brief <simple-command> or <pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

// for debug
#include "ft_printf.h"// debug
#include "debug.h"// debug


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
//	t_ast	*redirection_node;
	t_ast	*command_node;
	char	*value;

	node = create_node(NODE_COMMAND, head_value);
	ft_dprintf(g_fd_log,
				"is_include_redirection = [%d]  false[%d] true[%d]\n\n",
				is_include_redirection(*tokens), false, true);
//	if (is_include_redirection(*tokens) == true)
//	{
//		value = get_redirection_value(*tokens);
//		ft_dprintf(g_fd_log, "value_redirection [%s]\n", value);
//		redirection_node = parse_io_redirections(*tokens, value);
//		node->num_children++;
//		node->children = (t_ast **)realloc(node->children,// use ft_realloc
//				node->num_children * sizeof(t_ast *));
//		node->children[node->num_children - 1] = redirection_node;
//		free(value);
//	}
	if (is_include_pipe_command(*tokens) == true)
	{
		value = get_pipe_command_value(*tokens);
		ft_dprintf(g_fd_log, "value_pipe_command [%s]\n", value);
//		while (is_redirection(**tokens) == true)
//			(*tokens) += 2;//　エラーケースは未想定　例えば”>>"のみ
		command_node = parse_pipe_command(tokens, value);
		free(value);
	}
	else
	{
		value = get_simple_command_value(*tokens);
//		while (is_redirection(**tokens) == true)
//			(*tokens) += 2;//　エラーケースは未想定　例えば”>>"のみ
		command_node = parse_simple_command(tokens, value);
		free(value);
	}
	node->num_children++;
	node->children = (t_ast **)realloc(node->children,// use ft_realloc
			node->num_children * sizeof(t_ast *));
	node->children[node->num_children - 1] = command_node;
	return (node);
}
// debug code
//	debug_parse("parse_command", node);// debug
