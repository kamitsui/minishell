/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:01:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 13:54:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"

int	handle_operator(t_ast *node, t_envwrap *env_wrapper)
{
	if (node->flag & BIT_PARENTHESIS)
	{
		// fork して、lets_go_minishell をよぶ
		return (env_wrapper->exit_code);
	}
	else
		return (env_wrapper->exit_code);
}
