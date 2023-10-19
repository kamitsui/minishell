/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/19 16:29:46 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"

#include "debug.h"
#include "ft_printf.h"


int	handle_expansion(t_ast *node, t_envwrap *env_wrapper)
{
	int		status;
	size_t	i;

	if (node->flag & BIT_EXPANSION)
		status = expand_dollar_sign_on_char(&node->value, env_wrapper);
	// Traverse the children of the current node
	i = 0;
	while (i < node->num_children)
	{
		status = handle_expansion(node->children[i], env_wrapper);
		i++;
	}
	return (status);
}
