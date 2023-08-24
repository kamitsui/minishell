/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 21:49:54 by kamitsui         ###   ########.fr       */
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
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 * "|" / "&&" / "||"
 *
 * @param operator_node 走査対象のノード
 * @param env 環境変数
 * @param status １つ前のノードの終了ステータス
 *
 * @return 走査結果を終了ステータスとして次のノードに渡す
 */
int	handle_operator(t_ast *operator_node, char **env, int status)
{
	if (operator_node->type != NODE_OPERATOR)
		return (status);
	if (ft_strcmp(operator_node->value, "|") == 0)
		status = handle_pipe_command(operator_node, env, status);
	else if (ft_strcmp(operator_node->value, "&") == 0)
	{
		// Implement background execution logic
		// ...
	}
	else
	{
		// Handle other operators if needed
		// ...
	}
	return (status);
}
