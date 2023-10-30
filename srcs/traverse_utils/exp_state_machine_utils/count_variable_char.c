/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_variable_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:13:00 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 15:16:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "libft.h"

static bool	is_allowed_variable_char(char c)
{
	return (ft_isalnum(c) == true
		|| c == META_UNDER_CHR || c == META_QUESTION_CHR);
}

size_t	count_variable_char(char *value)
{
	size_t	len;

	len = 0;
	if (ft_strncmp(value, "$?", 2) == 0)
		len = 2;
	else
	{
		len++;
		while (is_allowed_variable_char(value[len]) == true)
		{
			len++;
			if (value[len] == META_QUESTION_CHR)
				break ;
		}
	}
	return (len);
}
