/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:09:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 21:41:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_argument.c
 * @brief \<argument>のノードに対しての処理
 */
#include "parse.h"
#include "traverse.h"

/**
 * @brief \<argument>のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env 環境変数
 * @param status 再帰前のノードから渡される終了ステータス
 *
 * @return status コマンドのノードから受け取った終了ステータスをそのまま返す
 */
int	handle_argument(t_ast *node, char **env, int status)
{
	(void)node;
	(void)env;
	return (status);
}
