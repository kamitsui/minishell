/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:41:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 20:02:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdlib.h>

bool	is_expansion(const char *token)
{
	static t_is_type_node	f_type_expansion[NUM_EXPANSION]
		= {is_squote, is_dquote, is_variable};
	bool					result;
	size_t					i;

	if (token == NULL)
		return (false);
	result = false;
	i = 0;
	while (i < NUM_EXPANSION && result == false)
	{
		result = f_type_expansion[i](token);
		i++;
	}
	return (result);
}
