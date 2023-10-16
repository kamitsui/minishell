/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:04:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 02:24:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_command.c
 * @brief <simple-command>のノードに対しての処理
 */
#include "parse.h"
#include "traverse.h"
#include "execute.h"

//int	hanlde_simple_command(t_ast *node, t_envwrap *env_wrapper)
//{
//}

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
	if (node->flag & BIT_PIPE_COM)
	{
		//expansion(...);
		return (handle_pipe_command(node, env_wrapper));
	}
	else
		return (execute_command(node, env_wrapper));
}
