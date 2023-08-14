/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:22:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 15:13:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenize.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>// ft_strncspn を実装したら消そう。

/**
 * @brief line１行あたりのトークン数（<connector> "&&" も含めてカウントする）
 *        "||"の対応は未実装
 *
 * @param line readlineで読み込んだ <command-line> １行分
 *
 * @return 
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
