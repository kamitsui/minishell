/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:20:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/02 14:45:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "expansion.h"
#include "traverse.h"
#include "meta_minishell.h"
#include "error_minishell.h"

static size_t	add_dquote_token(
				char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	size_t	i;
	size_t	len_var;
	char	*str_dquote;

	i = 0;
	while (value[i] != '"')
	{
		len_var = count_variable_char(value + i);
		if (value[i] == '$' && len_var > 1)
		{
			str_dquote = ft_strndup(value + i, len_var);
			if (str_dquote == NULL)
				ft_perror_exit("ft_strndup");
			expand_dollar_sign_on_char(&str_dquote, env_wrapper);
			add_token(&machine->str, str_dquote);
			free(str_dquote);
			i += len_var;
		}
		else
		{
			str_add_to_buff(&machine->str, value[i]);
			i++;
		}
	}
	return (i);
}

size_t	exp_dquote(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	size_t	len;

	value++;
	len = ft_strchr(value, META_DQUOT_CHR) - value;
	if (len == 0)
		machine->state = EXP_LETTER;
	len = add_dquote_token(value, machine, env_wrapper);
	machine->state = EXP_LETTER;
	return (len + 2);
}
