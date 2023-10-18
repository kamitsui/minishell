/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:09:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/15 15:17:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_file.c
 * @brief \<file>のノードに対しての処理
 */
#include "parse.h"
#include "traverse.h"

/**
 * @brief \<file>のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status コマンドのノードから受け取った終了ステータスをそのまま返す
 */
int	handle_file(t_ast *node, t_envwrap *env_wrapper)
{
	(void)node;
	return (env_wrapper->exit_code);
}
