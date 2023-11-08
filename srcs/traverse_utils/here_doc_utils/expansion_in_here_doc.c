/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_in_here_doc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:29:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/09 06:52:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"
#include "meta_minishell.h"
#include "traverse.h"

static size_t	exp_letter_here_doc(char *value, t_exp_sm *machine)
{
	size_t	len;

	len = 0;
	if (*value == META_DQUOT_CHR || *value == META_SQUOT_CHR)
		len = 1;
	else
	{
		str_add_to_buff(&machine->str, *value);
		len++;
	}
	return (len);
}

void	expansion_in_here_doc(char **value)
{
	t_exp_sm		machine;
	char			*current_value;
	size_t			ret;

	init_exp_sm(&machine);
	current_value = *value;
	while (*current_value != '\0')
	{
		ret = exp_letter_here_doc(current_value, &machine);
		current_value += ret;
	}
	free(*value);
	*value = str_join_to_out(
			machine.str.out, machine.str.buffer, machine.str.len);
}
