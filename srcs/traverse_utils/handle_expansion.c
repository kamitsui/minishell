/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/04 13:26:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"
#include "meta_minishell.h"
#include "traverse.h"

static void	init_exp_sm(t_exp_sm *machine)
{
	machine->state = EXP_LETTER;
	init_t_string(&machine->str);
}

static void	expansion(char **value, t_envwrap *env_wrapper)
{
	t_exp_sm		machine;
	char			*current_value;
	size_t			ret;
	static t_f_exp	f_expansion[EXP_END]
		= {exp_letter, exp_dquote, exp_squote, exp_var, exp_tilde};

	init_exp_sm(&machine);
	current_value = *value;
	while (*current_value != '\0')
	{
		ret = f_expansion[machine.state](current_value, &machine, env_wrapper);
		current_value += ret;
	}
	free(*value);
	*value = str_join_to_out(
			machine.str.out, machine.str.buffer, machine.str.len);
}

void	handle_expansion(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;

	if (node->flag & BIT_EXPANSION
		&& node->flag & (BIT_EXECUTABLE | BIT_ARGUMENT | BIT_FILE))
	{
		expansion(&node->value, env_wrapper);
		if (*node->value == '\0')
			node->flag |= BIT_EMPTY;
	}
	i = 0;
	while (i < node->num_children)
	{
		handle_expansion(node->children[i], env_wrapper);
		i++;
	}
}
