/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:22:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 17:49:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file count_tokens.c
 * @brief line１行あたりのトークン数（<connector> "&&" も含めてカウントする）
 */
#include "libft.h"
#include "tokenize.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>// ft_strncspn を実装したら消そう。

/**
 * @brief line１行あたりのトークン数（<connector> "&&" も含めてカウントする）
 *
 * @param line readlineで読み込んだ <command-line> １行分
 *
 * @return トークンの数
 * @note 8/21時点はこの関数を未使用（最終的に削除か。。。？）
 * 別の方法で再実装を検討中(kamitsui)
 */
size_t	count_tokens(char *line)
{
	size_t	size;
	size_t	connect_len;

	connect_len = ft_strlen(CONNECT_AND);
	size = 0;
	if (*line == '\0')
		return (size);
	if (ft_substr_exist(line, CONNECT_AND))
	{
		size++;
		while (ft_substr_exist(line, CONNECT_AND))
		{
			if (ft_strnequ(line, CONNECT_AND, connect_len) == false)
				size++;
			line += strcspn(line, CONNECT_AND) + connect_len;
//			line += ft_strcspn(line, CONNECT_AND) + connect_len;
			if (*line != '\0')
				size++;
		}
	}
	else
		size++;
	return (size);
}
