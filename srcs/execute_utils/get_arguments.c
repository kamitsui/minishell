/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:13:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 13:27:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_arguments.c
 * @brief <simple-command>のノードからコマンド引数を取り出す関数
 */
#include "parse.h"
#include "execute.h"

/**
 * @brief <simple-command>のノードからコマンド引数を取り出す関数
 *
 * @param commands コマンド引数の格納先（コマンドの構造体）
 * @param node <simple-command>のノード
 */
void	get_arguments(t_command *commands, t_ast *node)
{
	size_t	i;

	i = 0;
	commands->args = (char **)malloc(sizeof(char *) * (node->num_children + 2));
	commands->args[i] = node->value;
	while (i < node->num_children)
	{
		commands->args[i + 1] = node->children[i]->value;
		i++;
	}
	commands->args[i + 1] = NULL;
	commands->num_args = i + 1;
}
