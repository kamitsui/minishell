/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalloc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:55:20 by mogawa            #+#    #+#             */
/*   Updated: 2023/07/26 14:55:20 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lalloc_init(void)
{
	t_list	*head;

	head = ft_lstnew(NULL);
	if (head == NULL)
		return (NULL);
	return (head);
}

void	ft_lalloc_destroy(t_list *head)
{
	ft_lfree(&head, ALL);
	free(head);
	head = NULL;
}
