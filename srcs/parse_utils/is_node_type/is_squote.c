/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_squote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:29:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 02:35:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "parse.h"
#include <stdlib.h>

bool	is_squote(const char *token)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] == META_SQUOT_CHR)
			count++;
		i++;
	}
	if (count == 0)
		return (false);
	return (count % 2 == 0);
}
