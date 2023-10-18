/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 15:35:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file traverse_ast.c
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 */
#include "parse.h"
#include "traverse.h"

#include "debug.h"
#include "ft_printf.h"

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
	enum e_NodeType			current_type;
	static t_handle_node	handle_node[NODE_COMMAND + 1] = {
		handle_operator, handle_command};
	size_t					i;

	if (node->type > NODE_COMMAND)
		return (env_wrapper->exit_code);
	ft_dprintf(g_fd_log, "current node->value [%s]\n", node->value);
//	if (node->type == NODE_CONNECTOR
//		&& handle_connector(node, env_wrapper) == EXIT_FAILURE)
//		return (env_wrapper->exit_code);
	// Depth-First search (DFS) approach
	current_type = NODE_OPERATOR;
	while (current_type <= NODE_COMMAND)
	{
		if (node->type == current_type)
		{
			env_wrapper->exit_code = handle_node[current_type](node, env_wrapper);
			debug_status("traverse_ast", env_wrapper->exit_code);
		}
		current_type++;
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
// reference ... enum e_NodeType
//enum	e_NodeType
//{
//	NODE_OPERATOR,
//	NODE_COMMAND,
//	NODE_CONNECTOR,
//	NODE_PIPE_COM,
//	NODE_SIMPLE_COM,
//	NODE_EXECUTABLE,
//	NODE_ARGUMENT,
//	NODE_IO_REDIRECTIONS,
//	NODE_REDIRECTION,
//	NODE_FILE,
//	NODE_END
//};
