/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_squote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/02 14:45:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "traverse.h"
#include "meta_minishell.h"
#include "error_minishell.h"

size_t	exp_squote(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_squote;
	size_t	len;

	value++;
	len = ft_strchr(value, META_SQUOT_CHR) - value;
	if (len == 0)
	{
		machine->state = EXP_LETTER;
		return (2);
	}
	str_squote = ft_strndup(value, len);
	if (str_squote == NULL)
		ft_perror_exit("ft_strndup");
	add_token(&machine->str, str_squote);
	free(str_squote);
	(void)env_wrapper;
	machine->state = EXP_LETTER;
	return (len + 2);
}
