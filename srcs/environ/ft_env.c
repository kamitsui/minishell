/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 17:35:43 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

//todo no error handling and no exit (EXIT_SUCCESS)
void	ft_env(t_list *lst_head)
{
	ft_lstiter(lst_head, _print_env_lst);
	// exit (EXIT_SUCCESS);
}
