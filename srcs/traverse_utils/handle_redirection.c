/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:03:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 04:10:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"
#include "execute.h"

/**
 * @brief <io-redirection>のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env_wrapper構造体  (env、exit_code, pwd)
 *
 * @return ノードの処理結果を終了ステータスとして返す
 */
int	handle_redirection(t_ast *node, t_envwrap *env_wrapper)
{
	if (node->flag & BIT_IO_REDIRECTIONS)
		return (env_wrapper->exit_code);
	return (execute_command(node, env_wrapper));
}
