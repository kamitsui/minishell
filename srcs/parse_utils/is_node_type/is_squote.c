/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_squote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:29:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/08 18:22:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "parse.h"
#include <stdlib.h>

bool	is_squote(const char *token)
{
	size_t	count_squote;
	size_t	count_dquote;
	size_t	i;

	count_squote = 0;
	count_dquote = 0;
	i = 0;
	while (token[i] != '\0')
	{
		if (count_squote == 0 && token[i] == META_DQUOT_CHR)
			count_dquote++;
		if ((count_dquote % 2) == 0 && token[i] == META_SQUOT_CHR)
			count_squote++;
		if (count_squote == 2)
			return (true);
		i++;
	}
	return (false);
}
