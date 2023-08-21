/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:44:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 19:10:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_pipe_command.c
 * @brief \<pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>
#include <string.h>// for strcmp()

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
t_ast	*parse_pipe_command(char ***tokens, size_t num_pipe)
{
	t_ast	*pipe_node;
	t_ast	*command_node;

	(void)num_pipe;
	pipe_node = create_node(NODE_OPERATOR, "|");
	// ループの終了は要改良　is_connector()みたいな関数を実装か。。。
	while (**tokens && strcmp(**tokens, "&&") != 0)
	{
		command_node = parse_simple_command(tokens);
		if (command_node)
		{
			pipe_node->num_children++;
			pipe_node->children = (t_ast **)realloc(pipe_node->children,
					pipe_node->num_children * sizeof(t_ast *));
			pipe_node->children[pipe_node->num_children - 1] = command_node;
		}
	}
	return (pipe_node);
}
