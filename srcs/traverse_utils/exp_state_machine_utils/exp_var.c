/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:16:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 15:18:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "expansion.h"
#include "traverse.h"

size_t	exp_var(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_var;
	size_t	len;

	len = count_variable_char(value);
	if (len == 1)
	{
		str_add_to_buff(&machine->str, *value);
		machine->state = EXP_LETTER;
	}
	else
	{
		str_var = ft_strndup(value, len);
		expand_dollar_sign_on_char(&str_var, env_wrapper);
		add_token(&machine->str, str_var);
		free(str_var);
		machine->state = EXP_LETTER;
	}
	return (len);
}
