/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:33 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 11:14:31 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
// #include "libft.h"

void	ft_unset(t_envwrap *env_wrap, char *tgt_key)
{
	t_list	*crnt;
	t_list	*next;
	t_env	*env_node;

	crnt = env_wrap->env->next;
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
