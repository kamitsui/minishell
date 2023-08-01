/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:16:21 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/20 15:17:09 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	s1len;
	int	s2len;
	int	len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len <= s2len)
		len = s1len;
	else
		len = s2len;
	return (ft_strncmp(s1, s2, len));
}
