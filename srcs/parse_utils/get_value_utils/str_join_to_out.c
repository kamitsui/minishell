/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join_to_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:07:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 13:31:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include "libft.h"
#include <stdlib.h>

char	*str_join_to_out(const char *s1, const char *s2, size_t len2)
{
	char	*str;
	size_t	len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	str = ft_strnew(len1 + len2);
	if (str == NULL)
		ft_errno_exit("ft_strnew");
	ft_strlcpy(str, s1, len1 + 1);
	ft_memcpy(&str[len1], s2, len2 + 1);
	free((void *)s1);
	return (str);
}
