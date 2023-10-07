/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:29:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/07 14:09:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_utils.c
 * @brief minishellで確保したヒープ領域のメモリを開放する関数群
 */
#include "minishell.h"
#include "parse.h"
#include "environ.h"
#include <stdlib.h>

/**
 * @brief char**型の二次元配列をフリーする関数\n
 *
 * @param *array[] 複数の文字列要素もつ二次元配列（最後の要素はNULL）
 */
void	free_two_darray(char *array[])
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * @brief 抽象構文木のノードとその子ノードを全てフリーする関数
 *
 * @param node フリーさせたい抽象構文木のノード
 */
void	free_ast(t_ast *node)
{
	size_t	i;

	if (!node)
		return ;
	i = 0;
	while (i < node->num_children)
	{
		free_ast(node->children[i]);
		i++;
	}
	free(node->children);
	free(node->value);
	free(node);
}

void	free_envwrap(t_envwrap *env_wrapper)
{
	ft_lstclear(&env_wrapper->env, _env_del_content);
	free(env_wrapper->cwd);
	free(env_wrapper);
}
