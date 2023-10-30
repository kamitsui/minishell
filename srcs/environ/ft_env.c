/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 18:27:17 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

void	ft_env(t_envwrap *env_wrapper)
{
	t_list	*env_start;

	env_start = env_wrapper->env->next;
	ft_lstiter(env_start, _env_print_lst);
}
