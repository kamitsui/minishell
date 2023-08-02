/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:17:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/24 17:06:31 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*res;
	size_t	n;

	res = ft_calloc(len + 1, sizeof(char));
	n = 0;
	while (n < len)
	{
		res[n] = s[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}
