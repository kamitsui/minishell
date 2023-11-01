/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:16:27 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/01 17:10:56 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "builtins.h"
#include "ft_printf.h"
#include "libft.h"
#include "error_minishell.h"
#include "meta_minishell.h"

static bool	is_long(const char *str)
{
	char	*end_ptr;
	int		base;

	if (str == NULL)
		return (false);
	base = 10;
	ft_strtol(str, &end_ptr, base);
	if (*end_ptr == '\0')
		return (true);
	else
		return (false);
}

static void	handle_error_too_many_args(char *value)
{
	ft_dprintf(STDERR_FILENO, "%s\n", STR_EXIT);
	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
		NAME, value, "too many arguments");
}

static void	handle_error_nurmeric_args(char *value)
{
	ft_dprintf(STDERR_FILENO, "%s\n", STR_EXIT);
	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
		NAME, value, "numeric argument required");
	exit (255);
}

int	call_exit(t_ast *node, t_envwrap *env_wrapper)
{
	int		status;
	char	*value;

	(void) env_wrapper;
	status = EXIT_SUCCESS;
	value = NULL;
	if (node->num_children > 0)
		value = node->children[0]->value;
	if (node->num_children == 0
		|| (is_long(value) == true && node->num_children > 0))
	{
		if (node->num_children > 1)
			handle_error_too_many_args(STR_EXIT);
		else
		{
			if (node->num_children == 1)
			{
				value = node->children[0]->value;
				status = (int)ft_strtol(value, NULL, 10);
			}
			ft_exit(status);
		}
	}
	else
		handle_error_nurmeric_args(value);
	return (EXIT_FAILURE);
}
