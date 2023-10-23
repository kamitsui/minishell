/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:33 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/24 08:40:02 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
// #include "libft.h"

void	ft_unset(t_envwrap *env_wrap, char *tgt_key)
{
	t_list	*crnt;
	t_list	*next;
	t_list	*prev;
	t_env	*env_node;

	crnt = env_wrap->env->next;
	while (crnt)
	{
		next = crnt->next;
		prev = crnt->prev;
		env_node = crnt->content;
		if (ft_strcmp(env_node->key, tgt_key) == 0)
		{
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			// crnt->prev->next = crnt->next;
			// crnt->next->prev = crnt->prev;
			ft_lstdelone(crnt, _env_del_content);
		}
		crnt = next;
	}
}
