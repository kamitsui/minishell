/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:44:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 19:46:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_pipe_command.c
 * @brief \<pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

// for debug
#include "debug.h"
#include "ft_printf.h"

/**
 * @brief \<pipe-command> のノードを作る関数
 *
 * @param tokens トークンのアドレス
 * @param num_pipe パイプでつなげるコマンドの数
 *
 * @return 生成された<pipe-command>のノードを返す
 * @note 未完成
 * あと一部未実装。is_connector()関数　引数num_pipeは不要か。。。
 */
t_ast	*parse_pipe_command(char ***tokens, char *head_value)
{
	t_ast	*node;
	t_ast	*command_node;
	char	*value;

	node = create_node(NODE_PIPE_COM, head_value);
	while (is_end(**tokens) == false && is_connector(**tokens) == false)
	{
		if (is_pipe(**tokens) == true)
		{
			(*tokens)++;
			continue ;
		}
		value = get_simple_command_value(*tokens);
		command_node = parse_simple_command(tokens, value);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,
				node->num_children * sizeof(t_ast *));// use ft_realloc
		node->children[node->num_children - 1] = command_node;
	}
	return (node);
}
//debug code
//		ft_dprintf(g_fd_log,
//			">> in parse_pipe_command ... head_value[%s]\n", head_value);
//		ft_dprintf(g_fd_log,
//			">> in parse_pipe_command ... one_pipe_com_value[%s]\n", value);
