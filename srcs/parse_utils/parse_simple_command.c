/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:27:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 20:00:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_simple_command.c
 * @brief <simple-command>のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

#include "ft_printf.h"
#include "debug.h"

static void	call_parse_io_redirections(t_ast *node, char ***tokens)
{
	char	*value;
	t_ast	*redirection_node;

	value = get_redirection_value_in_simple_command(*tokens);
	redirection_node = parse_io_redirections(*tokens, value);
	node->num_children++;
	node->children = (t_ast **)realloc(node->children,
			node->num_children * sizeof(t_ast *));// use ft_realloc
	node->children[node->num_children - 1] = redirection_node;
	free(value);
}

static void	call_parse_executable(t_ast *node, char ***tokens)
{
	char	*value;
	t_ast	*executable_node;

	value = get_executable_value(*tokens);
	executable_node = parse_executable(tokens);
	node->num_children++;
	node->children = (t_ast **)realloc(node->children,
			node->num_children * sizeof(t_ast *));// use ft_realloc
	node->children[node->num_children - 1] = executable_node;
	free(value);
}

/**
 * @brief <simple-command>のノードを作る関数
 *
 * @param tokens トークンのアドレス
 *
 * @return 生成されたコマンドのノードを返す
 */
t_ast	*parse_simple_command(char ***tokens, char *head_value)
{
	t_ast	*node;

	node = create_node(NODE_SIMPLE_COM, head_value);
	if (is_include_redirection_in_simple_com(*tokens) == true)
		call_parse_io_redirections(node, tokens);
	while (is_end(**tokens) == false && is_connector(**tokens) == false
		&& is_pipe(**tokens) == false)
	{
		if (is_redirection(**tokens) == true)
		{
			(*tokens) += 2;// エラーケースは未想定　例えば">>"のみ
			continue ;
		}
		call_parse_executable(node, tokens);
	}
	return (node);
}
// debug code
//		ft_dprintf(g_fd_log,
//					">> in parse_simple_command ... redirection_value[%s]\n",
//					value);// debug
//		ft_dprintf(g_fd_log,
//					">> in parse_simple_command ... executable_value[%s]\n",
//					value);// debug
