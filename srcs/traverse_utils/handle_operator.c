/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:01:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 15:34:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"

int	handle_operator(t_ast *node, t_envwrap *env_wrapper)
{
	if (node->flag & BIT_PARENTHESIS)
		return (env_wrapper->exit_code);
	else
		return (env_wrapper->exit_code);
}
