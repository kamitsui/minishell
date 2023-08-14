/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:17:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 12:21:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>// ft_strncspn を実装したら消そう。

/**
 * @brief 一連の文字列strをsepで分離する strtok()の改良版
 *
 * @param str '\0'で終わる文字列
 * @param sep 分離させる文字列
 *
 * @return ヒープ領域に確保された文字列
 */
char	*get_next_token(char *str, char const *sep)
{
	static char	*next_token;
	char		*start;
	size_t		sep_len;

	sep_len = ft_strlen(sep);
	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	start = next_token;
	if (ft_strnequ(start, sep, sep_len))
	{
		next_token += sep_len;
		return (ft_strndup(start, sep_len));
	}
	next_token += strcspn(start, sep);
//	next_token += ft_strcspn(start, sep);
	return (ft_strndup(start, next_token - start));
}
