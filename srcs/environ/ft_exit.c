/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:58:19 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/20 14:42:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_exit.h"// remove by kamitsui ( compile error : file not found )
#include "environ.h"

void	ft_exit(int status, t_envwrap *env_wrap)
{
	env_delete_t_envwrap(env_wrap);
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(status);
}
