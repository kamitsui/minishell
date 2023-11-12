/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:17:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 07:43:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "builtins.h"
#include "error_minishell.h"
#include "ft_printf.h"

static int	handle_error_unset(char *value)
{
	ft_dprintf(STDERR_FILENO, "%s: %s: `%s': %s\n",
		PROGRAM_NAME, STR_UNSET, value, "not a valid identifier");
	return (EXIT_FAILURE);
}

int	call_unset(t_ast *node, t_envwrap *env_wrapper)
{
	char	*tgt_key;
	size_t	i;
	int		status;

	status = EXIT_SUCCESS;
	if (node->num_children == 0)
		return (EXIT_SUCCESS);
	else
	{
		i = 0;
		while (i < node->num_children)
		{
			tgt_key = node->children[i]->value;
			if (is_valid_export_variable(tgt_key) == true)
				ft_unset(env_wrapper, tgt_key);
			else
				status = handle_error_unset(tgt_key);
			i++;
		}
	}
	return (status);
}
