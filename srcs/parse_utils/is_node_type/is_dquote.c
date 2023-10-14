/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dquote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:51:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 02:42:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "parse.h"
#include <stdlib.h>

bool	is_dquote(const char *token)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] == META_DQUOT_CHR)
			count++;
		i++;
	}
	if (count == 0)
		return (false);
	return (count % 2 == 0);
}
