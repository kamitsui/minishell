/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:31:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/02 14:45:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "expansion.h"
#include "traverse.h"
#include "error_minishell.h"

size_t	exp_tilde(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_var;

	(void)value;
	str_var = ft_strdup("$HOME");
	if (str_var == NULL)
		ft_perror_exit("ft_strdup");
	expand_dollar_sign_on_char(&str_var, env_wrapper);
	add_token(&machine->str, str_var);
	free(str_var);
	machine->state = EXP_LETTER;
	return (1);
}
