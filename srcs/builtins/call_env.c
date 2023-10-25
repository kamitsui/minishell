/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:18:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 17:21:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"

int	call_env(t_ast *node, t_envwrap *env_wrapper)
{
//	static const char	*cause = "env";
//	static const char	*error_msg = "No such file or directory";
// env: 123: No such file or directory

//	if (is_error_env(...) == true)
//	{
//		handl_error_not_exit(...);
//		return (EXIT_FAILURE);
//	}
	(void)node;// remove
	ft_env(env_wrapper);
	return (EXIT_SUCCESS);
}
