/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:04:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 20:05:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdbool.h>

// for debug
#include "debug.h"// debug
#include "ft_printf.h"// debug

bool	is_connector(const char *token)
{
	static t_is_type_node	f_is_connector[NUM_CONNECTOR]
		= {is_and_list, is_or_list};
	bool					result;
	size_t					i;

	if (token == NULL)
		return (false);
	result = false;
	i = 0;
	while (i < NUM_CONNECTOR && result == false)
	{
		result = f_is_connector[i](token);
		i++;
	}
	return (result);
}
