/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:17:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 07:42:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "meta_minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"

bool	is_valid_export_variable(char *str)
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
		"%s: %s: `%s': %s\n", PROGRAM_NAME, "export", unexpected_token, message);
	return (EXIT_FAILURE);
}

int	call_export(t_ast *node, t_envwrap *env_wrapper)
{
	char	*envline;
	size_t	i;
	int		status;

	status = EXIT_SUCCESS;
	envline = NULL;
	if (node->num_children == 0)
		ft_export(env_wrapper, envline);
	else
	{
		i = 0;
		while (i < node->num_children)
		{
			envline = node->children[i]->value;
			if (is_valid_export_variable(envline) == true)
				ft_export(env_wrapper, envline);
			else
				status = handle_error_export(envline);
			i++;
		}
	}
	return (status);
}
