/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:22:26 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 01:51:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "meta_minishell.h"
#include "libft.h"
#include <stdbool.h>

bool	is_in_red(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_IN) == 0);
}

bool	is_here_doc(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_HERE) == 0);
}

bool	is_out_red(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_OUT) == 0);
}

bool	is_out_append(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_APPEND) == 0);
}

bool	is_redirection(const char *token)
{
	bool	result;
	size_t	i;
	t_is_type_node	f_is_redirection[NUM_REDIRECTION] = {
						is_in_red, is_here_doc, is_out_red, is_out_append};

	if (token == NULL)
		return (false);
	result = false;
	i = 0;
	while (i < NUM_REDIRECTION && result == false)
	{
		result = f_is_redirection[i](token);
		i++;
	}
	return (result);
}
