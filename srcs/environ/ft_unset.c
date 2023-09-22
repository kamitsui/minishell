/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:33 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/22 16:50:15 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
// #include "libft.h"

void	ft_unset(t_list **env_head, char *tgt_key)//todo double pointer
{
	t_list	*crnt;
	t_list	*next;
	t_env	*env_node;

	crnt = (*env_head)->next;
	while (crnt)
	{
		next = crnt->next;
		env_node = crnt->content;
		if (ft_strcmp(env_node->key, tgt_key) == 0)
		{
			crnt->prev->next = crnt->next;
			crnt->next->prev = crnt->prev;
			ft_lstdelone(crnt, _env_del_content);
		}
		crnt = next;
	}
}
