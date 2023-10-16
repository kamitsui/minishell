/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:44:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 03:41:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_pipe_command.c
 * @brief \<pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

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
	t_ast	*pipe_node;
	t_ast	*node;
	char	*value;

	pipe_node = create_node(NODE_PIPE_COM, head_value);
	// ループの終了は要改良　is_connector()みたいな関数を実装か。。。
	while (is_end(**tokens) == false && is_connector(**tokens) == false)
	{
		if (ft_strcmp(**tokens, "|") == 0)
		{
			(*tokens)++;
			continue ;
		}
		value = get_simple_command_value(*tokens);
		node = parse_simple_command(tokens, value);
		if (node)
		{
			pipe_node->num_children++;
			pipe_node->children = (t_ast **)realloc(pipe_node->children,// use ft_realloc
					pipe_node->num_children * sizeof(t_ast *));
			pipe_node->children[pipe_node->num_children - 1] = node;
			//pipe_node->children[pipe_node->num_children - 1]->flag
			//	= BIT_COMMAND | BIT_SIMPLE_COM;
		}
	}
	return (pipe_node);
}
