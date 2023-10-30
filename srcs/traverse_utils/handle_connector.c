/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_connector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 15:34:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_operator.c
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 */
#include "parse.h"
#include "traverse.h"
#include "libft.h"

/**
 * @brief ノードのタイプがコネクターノードの時の処理  "&&" or "||"
 *
 * @param node 走査対象のノード
 * @param env_wrapper 環境変数を含めたラッパー構造体
 *
 * @return 走査結果を終了ステータスとして次のノードに渡す
 */
int	handle_connector(t_ast *node, t_envwrap *env_wrapper)
{
	if (node->flag & BIT_AND_LIST)
	{
		if (env_wrapper->exit_code != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	else
	{
		if (env_wrapper->exit_code == EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
