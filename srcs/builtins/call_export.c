/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:17:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 13:04:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "meta_minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"

static bool	is_valid_export_variable(char *str)
{
	if (*str == '=' || ft_isdigit(*str) == true)
		return (false);
	while (*str != '\0')
	{
		if (ft_isalnum(*str) == false && *str != META_UNDER_CHR)
		{
			if (*str != '=')
				return (false);
			else
				return (true);
		}
		str++;
	}
	return (true);
}

static int	handle_error_export(char *unexpected_token)
{
	const char	*message = MSG_NOT_VALID;

	ft_dprintf(STDERR_FILENO,
		"%s: %s: `%s': %s\n", NAME, "export", unexpected_token, message);
	return (EXIT_FAILURE);
}

int	call_export(t_ast *node, t_envwrap *env_wrapper)
{
	char	*key_or_full;
	char	*val_or_null;
	size_t	i;
	int		status;

	status = EXIT_SUCCESS;
	key_or_full = NULL;
	val_or_null = NULL;
	if (node->num_children == 0)
		ft_export(env_wrapper, key_or_full, val_or_null);
	else
	{
		i = 0;
		while (i < node->num_children)
		{
			key_or_full = node->children[i]->value;
			if (is_valid_export_variable(key_or_full) == true)
				ft_export(env_wrapper, key_or_full, val_or_null);
			else
				status = handle_error_export(key_or_full);
			i++;
		}
	}
	return (status);
}
