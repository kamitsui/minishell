/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:07:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/20 14:37:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <stdlib.h>

bool	is_builtins_command(const char *value)
{
	static const char				*str_builtins[NUM_BUILTINS] = {
		STR_ECHO, STR_CD, STR_PWD, STR_ENV, STR_UNSET, STR_EXPORT, STR_EXIT};
	bool			result;
	size_t			i;

	if (value == NULL)
		return (false);
	result = false;
	i = 0;
	while (i < NUM_BUILTINS && result == false)
	{
		result = ft_strcmp(str_builtins[i], value) == 0;
		i++;
	}
	return (result);
}
