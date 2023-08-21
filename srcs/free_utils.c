/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:29:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 16:07:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_utils.c
 * @brief minishellで確保したヒープ領域のメモリを開放する関数群
 */
#include "minishell.h"
#include "parse.h"
#include <stdlib.h>

/**
 * @brief readlineで読み取った関数をフリーする\n
 * lineのfreeは不要（スタック領域を使っているため）
 *
 * @param line 複数の文字列要素もつ二次元配列（最後の要素はNULL）
 */
void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
}

/**
 * @brief char**型の二次元配列をフリーする関数\n
 * tokensのfreeは必要（ヒープ領域にメモリ確保しているため）
 *
 * @param tokens 複数の文字列要素もつ二次元配列（最後の要素はNULL）
 */
void	free_tokens(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
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
