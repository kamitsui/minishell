/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_letter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:38:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 15:23:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "meta_minishell.h"
#include "traverse.h"

size_t	exp_letter(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	if (*value == META_DQUOT_CHR || *value == META_SQUOT_CHR)
	{
		if (*value == META_DQUOT_CHR && is_dquote(value) == true)
		{
			machine->state = EXP_DQUOTE;
			return (0);
		}
		else if (*value == META_SQUOT_CHR && is_squote(value) == true)
		{
			machine->state = EXP_SQUOTE;
			return (0);
		}
		else
			str_add_to_buff(&machine->str, *value);
	}
	else if (*value == META_VAR_CHR)
	{
		machine->state = EXP_VAR;
		return (0);
	}
	else
		str_add_to_buff(&machine->str, *value);
	(void)env_wrapper;
	return (1);
}
