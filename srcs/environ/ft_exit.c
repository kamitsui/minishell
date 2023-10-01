/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:58:19 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/01 16:22:49 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

void	ft_exit(int status, t_envwrap *env)
{
	env_delete_t_envwrap(env);
	//? statusによってEXITｈ出力先をｈするあ必要性はあるだろうか？
	if (status == EXIT_SUCCESS)
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	else
		ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(status);
}
