/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 18:42:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file traverse_ast.c
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 */
#include "parse.h"
#include "traverse.h"

/**
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 *
 * @param node 走査対象のノード（子ノードを再帰させる）
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status ノードの処理結果を終了ステータスとして返す
 */
int	traverse_ast(t_ast *node, t_envwrap *env_wrapper)
{
	enum e_NodeType			state;
	static t_handle_node	handle_node[3] = {
		handle_command, handle_argument, handle_operator};
	size_t					i;

	if (node == NULL)
		return (1);
	// Depth-First search (DFS) approach
	state = NODE_COMMAND;
	while (state != NODE_END)
	{
		if (node->type == state)
			env_wrapper->exit_code = handle_node[state](node, env_wrapper);
		state++;
	}
	// Traverse the children of the current node
	i = 0;
	while (i < node->num_children)
	{
		env_wrapper->exit_code = traverse_ast(node->children[i], env_wrapper);
		i++;
	}
	return (env_wrapper->exit_code);
}
