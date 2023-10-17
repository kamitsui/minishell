/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:50:26 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 04:00:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

bool	is_string(const char *token)
{
	t_is_type_node	f_is_not_string[NUM_NOT_STRING] = {
						is_and_list, is_or_list, is_pipe, is_redirection};
	size_t			i;
	bool			is_string;

	if (token == NULL)
		return (false);
	i = 0;
	is_string = true;
	while (i < NUM_NOT_STRING && is_string == true)
	{
		is_string = is_string && f_is_not_string[i](token) == false;
		i++;
	}
	return (is_string);
}
