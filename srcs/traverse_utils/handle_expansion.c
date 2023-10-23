/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/23 20:06:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"

#include "debug.h"
#include "ft_printf.h"

static char	*expansion_exit_status(char *old_value, t_envwrap *env_wrapper)
{
	char	*new_value;
	t_string	str;

	init_t_string(&str);
	new_value = ft_itoa(env_wrapper->exit_code);
	if (new_value == NULL)
		ft_perror_exit("ft_itoa");
	add_token(&str, new_value);
	if (ft_strlen(old_value) > 2)
		add_token(&str, old_value + 2);
	free(old_value);
	free(new_value);
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}

void	handle_expansion(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;

	if (node->flag & BIT_EXPANSION)
	{
		ft_dprintf(g_fd_log, "[%s] before expansion\n", node->value);//debug
		if (node->flag & BIT_VAR && node->value[1] == '?')
			node->value = expansion_exit_status(node->value, env_wrapper);
		else
			expand_dollar_sign_on_char(&node->value, env_wrapper);
		ft_dprintf(g_fd_log, "[%s] after expansion\n", node->value);//debug
	}
	i = 0;
	while (i < node->num_children)
	{
		handle_expansion(node->children[i], env_wrapper);
		i++;
	}
}
