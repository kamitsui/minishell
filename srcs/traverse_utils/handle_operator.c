/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 16:57:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_operator.c
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 */
#include "parse.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "execute.h"
#include "debug.h"

/**
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 *
 * @param operator_node 走査対象のノード
 * @param env 環境変数
 * @param status １つ前のノードの終了ステータス
 *
 * @return 走査結果を終了ステータスとして次のノードに渡す
 */
int	handle_operator(t_ast *operator_node, char **env, int status)
{
	t_ast	**commands;

	if (operator_node->type != NODE_OPERATOR)
	{
//		status = -1;
		return (status);
	}
//	status = 0;
	if (ft_strcmp(operator_node->value, "|") == 0)
	{
		commands = operator_node->children;
		// Execute the pipeline
		status = execute_pipeline(commands, operator_node->num_children, env);
	}
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
//int	handle_operator(t_ast *operator_node, char **env, int status)
//{
//	t_ast	**commands;
//
////	debug_ast(operator_node);
//		ft_printf("handle_operator\n");
//	if (operator_node->type != NODE_OPERATOR)
//	{
////		status = -1;
//		return (status);
//	}
////	status = 0;
//	if (strcmp(operator_node->value, "|") == 0)
//	{
//		ft_printf("pipe\n");
//		commands = operator_node->children;
//		// Execute the pipeline
//		status = execute_pipeline(commands, operator_node->num_children, env);
//	}
//	else if (strcmp(operator_node->value, "&") == 0)
//	{
//		// Implement background execution logic
//		// ...
//	}
//	else
//	{
//		// Handle other operators if needed
//		// ...
//	}
//	return (status);
//}
