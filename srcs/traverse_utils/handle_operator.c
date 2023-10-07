/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 17:35:43 by kamitsui         ###   ########.fr       */
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
int	handle_operator(t_ast *operator_node, t_envwrap *env_wrapper)
{
	if (operator_node->type != NODE_OPERATOR)
		return (env_wrapper->exit_code);
	if (ft_strcmp(operator_node->value, "|") == 0)
		env_wrapper->exit_code = handle_pipe_command(operator_node, env_wrapper);
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
	return (env_wrapper->exit_code);
}
