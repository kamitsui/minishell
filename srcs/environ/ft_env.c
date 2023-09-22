/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/22 15:58:39 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

//todo no error handling and no exit (EXIT_SUCCESS)
void	ft_env(t_list *lst_head)
{
	t_list	*env_start;

	env_start = lst_head->next;
	ft_lstiter(env_start, _print_env_lst);
	// exit (EXIT_SUCCESS);
}
