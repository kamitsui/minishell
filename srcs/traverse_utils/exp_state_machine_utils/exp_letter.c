/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_letter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:38:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/02 14:46:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "meta_minishell.h"
#include "traverse.h"

static size_t	check_valid_quote_value(char *value, t_exp_sm *machine)
{
	size_t	len;

	len = 0;
	if (*value == META_DQUOT_CHR && is_dquote(value) == true)
		machine->state = EXP_DQUOTE;
	else if (*value == META_SQUOT_CHR && is_squote(value) == true)
		machine->state = EXP_SQUOTE;
	else
	{
		str_add_to_buff(&machine->str, *value);
		len++;
	}
	return (len);
}

size_t	exp_letter(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	size_t	len;

	len = 0;
	if (*value == META_DQUOT_CHR || *value == META_SQUOT_CHR)
		len = check_valid_quote_value(value, machine);
	else if (*value == META_VAR_CHR)
		machine->state = EXP_VAR;
	else if (is_tilde(value) == true)
		machine->state = EXP_TILDE;
	else
	{
		str_add_to_buff(&machine->str, *value);
		len++;
	}
	(void)env_wrapper;
	return (len);
}
