/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:04:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 17:42:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_command.c
 * @brief <simple-command>のノードに対しての処理
 */
#include "parse.h"
#include "traverse.h"
#include "execute.h"

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
	if (node->flag & BIT_OPERATOR)
		return (env_wrapper->exit_code);
	return (execute_command(node, env_wrapper));
}
