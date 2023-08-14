/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:27:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 15:08:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief 文字列(haystack)の内に文字列(needle)の存在を調べる関数
 *
 * @param haystack　検索する場所
 * @param needle　　調べる部分文字列
 *
 * @return true:存在する  false:存在しない
 */
bool	ft_substr_exist(char *haystack, char *needle)
{
	size_t	len;

	len = ft_strlen(haystack);
	return (ft_strnstr(haystack, needle, len) != NULL ||
			ft_strnstr(haystack, needle, len) != NULL);
}
