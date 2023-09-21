/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:16:21 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 22:15:16 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*str1 = (const unsigned char *) s1;
	const unsigned char	*str2 = (const unsigned char *) s2;

	i = 0;
	while (true)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			return ((int)(str1[i] - str2[i]));
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	s1len;
// 	int	s2len;
// 	int	len;

// 	s1len = ft_strlen(s1);
// 	s2len = ft_strlen(s2);
// 	if (s1len <= s2len)
// 		len = s1len;
// 	else
// 		len = s2len;
// 	return (ft_strncmp(s1, s2, len));
// }