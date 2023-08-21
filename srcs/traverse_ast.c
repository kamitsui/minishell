/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 17:39:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file traverse_ast.c
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 */
#include "parse.h"
#include "traverse.h"
#include "execute.h"

/**
 * @brief シンプルコマンドのノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status ノードの処理結果を終了ステータスとして返す
 */
int	process_command(t_ast *node, char **env, int status)
{
	status = execute_command(node, env, status);
	return (status);
}

/**
 * @brief コマンド引数のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status コマンドのノードから受け取った終了ステータスをそのまま返す
 */
int	process_argument(t_ast *node, char **env, int status)
{
	(void)env;
	(void)node;
	return (status);
}

/**
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 *
 * @param node 走査対象のノード（子ノードを再帰させる）
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status ノードの処理結果を終了ステータスとして返す
 */
int	traverse_ast(t_ast *node, char **env, int status)
{
	int						i;
	enum e_NodeType			state;
	static t_handle_node	handle_node[3] = {
		process_command, process_argument, handle_operator};
	size_t					j;

	if (node == NULL)
		return (1);
	// Depth-First search (DFS) approach
	i = 0;
	state = NODE_COMMAND;
	while (state != NODE_END)
	{
		if (node->type == state)
			status = handle_node[i](node, env, status);
		state++;
	}
	// Traverse the children of the current node
	j = 0;
	while (j < node->num_children)
	{
		status = traverse_ast(node->children[j], env, status);
		j++;
	}
	return (status);
}
