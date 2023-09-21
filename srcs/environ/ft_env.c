/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 15:15:38 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "ft_printf.h"

static void	_print_env_lst(void *content)
{
	t_env	*node;

	node = content;
	ft_printf("%s=%s\n", node->key, node->val);
}

//todo no error handling and no exit (EXIT_SUCCESS)
void	ft_env(t_list *lst_head)
{
	ft_lstiter(lst_head, _print_env_lst);
	// exit (EXIT_SUCCESS);
}

// int	main(void)
// {
// 	ft_env();
// }