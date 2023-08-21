/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:26:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 16:11:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file tokenize.c
 * @brief <command-line>をトークン訳する関数
 */
#include "minishell.h"
#include "tokenize.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief 入力文字列を条件に応じてトークン分けする。
 *
 * @param line プロンプトに入力された文字列（readlineで読み取った文字列）
 *
 * @return tokens 複数の文字列要素もつ二次元配列（最後の要素はNULL）
 * @note 未完成（ステートマシンの考え方を使って精度を上げていきたい）
 */
char	**tokenize(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	return (tokens);
}
