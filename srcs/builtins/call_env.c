/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:18:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 21:56:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "ft_printf.h"
#include "builtins.h"

static void	handle_error_env(char *value)
{
	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
		STR_ENV, value, "No such file or directory");
}

int	call_env(t_ast *node, t_envwrap *env_wrapper)
{
	if (node->num_children > 0)
	{
		handle_error_env(node->children[0]->value);
		return (127);
	}
	ft_env(env_wrapper);
	return (EXIT_SUCCESS);
}
