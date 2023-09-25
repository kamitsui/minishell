/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 09:30:24 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

static void	add_new_env_node_to_list(t_list **env_head, t_list *to_add)
{
	t_env const	*new_env = to_add->content;
	t_list		*crnt;
	t_list		*next;
	t_list		*prev;
	t_env		*old_env;

	crnt = (*env_head)->next;
	while (crnt)
	{
		old_env = crnt->content;
		if (ft_strcmp(old_env->key, new_env->key) == 0)
		{
			next = crnt->next;
			prev = crnt->prev;
			to_add->prev = prev;
			to_add->next = next;
			next->prev = to_add;
			prev->next = to_add;
			ft_lstdelone(crnt, _env_del_content);
			return ;
		}
		crnt = crnt->next;
	}
	ft_lstadd_back(env_head, to_add);
}

//! no validation check included
void	ft_export(t_list **env_head, char *new_env)
{
	t_list	*new_list_node;
	t_env	*env_to_add;

	if (new_env == NULL)
	{
		ft_lstiter((*env_head)->next, _env_print_with_export);
	}
	else
	{
		env_to_add = env_create_node_from_char(new_env);
		if (!env_to_add)
		{
			return ;
		}
		new_list_node = ft_lstnew(env_to_add);
		add_new_env_node_to_list(env_head, new_list_node);
	}
}
