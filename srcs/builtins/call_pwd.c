/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:18:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 17:59:04 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"

int	call_pwd(t_ast *node, t_envwrap *env_wrapper)
{
	(void)node;
	ft_pwd(env_wrapper);
	return (EXIT_SUCCESS);
}
// pwd の失敗ケースは存在しないのでは？？？
