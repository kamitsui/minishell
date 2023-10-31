/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:58:19 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/31 15:44:15 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"


void	ft_exit(int status, t_envwrap *env_wrap)
{
	//!delete　exitなのでフリー必要なし
	// env_delete_t_envwrap(env_wrap);
	(void) env_wrap;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(status);
}
