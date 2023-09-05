/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:04:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 21:15:36 by kamitsui         ###   ########.fr       */
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
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status ノードの処理結果を終了ステータスとして返す
 */
int	handle_command(t_ast *node, char **env, int status)
{
	if (node->flag & BIT_OPERATOR)
		return (status);
	status = execute_command(node, env, status);
	return (status);
}
