/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:19:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 17:21:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"
#include "parse.h"
#include "environ.h"

int	call_cd(t_ast *node, t_envwrap *env_wrapper)
{
	char	*path;
	int		status;

	path = NULL;
	if (node->num_children > 0)
		path = node->children[0]->value;
	status = ft_cd(path, env_wrapper);
	return (status);
}
