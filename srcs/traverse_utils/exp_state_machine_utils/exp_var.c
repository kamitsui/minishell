/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:16:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/02 15:02:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "expansion.h"
#include "traverse.h"
#include "error_minishell.h"
#include "meta_minishell.h"

static size_t	add_tilde_char(char *value, t_exp_sm *machine)
{
	size_t	len;

	len = 0;
	while (*value != '\0')
	{
		value++;
		if (*value == META_TILDE_CHR)
		{
			str_add_to_buff(&machine->str, *value);
			len++;
		}
		else
			break ;
	}
	return (len);
}

size_t	exp_var(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_var;
	size_t	len;

	len = count_variable_char(value);
	if (len == 1)
	{
		str_add_to_buff(&machine->str, *value);
		len += add_tilde_char(value, machine);
		machine->state = EXP_LETTER;
	}
	else
	{
		str_var = ft_strndup(value, len);
		if (str_var == NULL)
			ft_perror_exit("ft_strndup");
		expand_dollar_sign_on_char(&str_var, env_wrapper);
		add_token(&machine->str, str_var);
		free(str_var);
		machine->state = EXP_LETTER;
	}
	return (len);
}
