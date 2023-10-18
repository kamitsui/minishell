/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:04:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 14:52:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_command.c
 * @brief <simple-command>のノードに対しての処理
 */
#include "parse.h"
#include "traverse.h"
#include "execute.h"

#include "debug.h"

int	handle_executable(t_ast *node, t_envwrap *env_wrapper)
{
//	if (node->flag & BIT_EXPANSION)
//		node = handle_expansion(node);
	return (execute_command(node, env_wrapper));
}
// debug code
//	int	status = execute_command(node, env_wrapper);// debug
//	debug_status("handle_executable", status);// debug
//	return (status);// debug

int	handle_io_redirections(t_ast *node, t_envwrap *env_wrapper)
{
//	if (node->flag & BIT_EXPANSION)
//		node = handle_expansion(node);
	// 未実装
	(void)node;// remove
	(void)env_wrapper;// remove
	return (EXIT_SUCCESS);
}

int	handle_simple_command(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;

	i = 0;
	if (node->children[i]->type == NODE_IO_REDIRECTIONS)
		if (handle_io_redirections(node->children[i], env_wrapper) == EXIT_SUCCESS)
		{
			i++;
			return (handle_executable(node->children[i], env_wrapper));
		}
		else
			return (EXIT_FAILURE);
	else
		return (handle_executable(node->children[i], env_wrapper));
}

/**
 * @brief <simple-command>のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env_wrapper構造体  (env、exit_code, pwd)
 *
 * @return ノードの処理結果を終了ステータスとして返す
 */
int	handle_command(t_ast *node, t_envwrap *env_wrapper)
{
	if (node->children[0]->type == NODE_PIPE_COM)
		return (handle_pipe_command(node->children[0], env_wrapper));
	else// NODE_SIMPLE_COM
		return (handle_simple_command(node->children[0], env_wrapper));
}
