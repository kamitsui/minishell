/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:58:19 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/04 14:24:22 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

void	ft_exit(int status, t_envwrap *env_wrap)
{
	env_delete_t_envwrap(env_wrap);
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(status);
}
