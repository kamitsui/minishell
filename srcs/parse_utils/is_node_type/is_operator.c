/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:04:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 03:51:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdbool.h>

// for debug
#include "debug.h"// debug
#include "ft_printf.h"// debug

bool	is_operator(const char *token)
{
	t_is_type_node	f_type_operator[NUM_OPERATOR] = {is_and_list, is_or_list};
	bool			result;
	size_t			i;

	if (token == NULL)
		return (false);
	result = false;
	i = 0;
	while (i < NUM_OPERATOR && result == false)
	{
		result = f_type_operator[i](token);
		i++;
	}
	return (result);
}
