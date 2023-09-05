/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:59:43 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/05 18:09:44 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// add new node at the beg of lst
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old_head;

	if (!lst || !new)
		return ;
	old_head = *lst;
	new->next = old_head;
	if (old_head != NULL)
		old_head->prev = new;
	old_head = new;
}
