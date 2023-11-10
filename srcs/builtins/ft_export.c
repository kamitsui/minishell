/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/10 13:36:00 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

static void	add_new_env_node_to_list(t_envwrap *env_wrap, t_list *to_add)
{
	t_env const	*new_env = to_add->content;
	t_list		*crnt;
	t_list		*next;
	t_list		*prev;
	t_env		*old_env;

	crnt = env_wrap->env->next;
	while (crnt)
	{
		old_env = crnt->content;
		if (ft_strcmp(old_env->key, new_env->key) == 0)
		{
			next = crnt->next;
			prev = crnt->prev;
			to_add->prev = prev;
			to_add->next = next;
			if (next != NULL)
				next->prev = to_add;
			prev->next = to_add;
			ft_lstdelone(crnt, _env_del_content);
			return ;
		}
		crnt = crnt->next;
	}
	ft_lstadd_back(&env_wrap->env, to_add);
}

void	ft_export(t_envwrap *env_wrap, char *envline)
{
	t_list	*new_list_node;
	t_env	*env_to_add;

	if (envline == NULL)
	{
		ft_lstiter(env_wrap->env->next, _env_print_with_export);
	}
	else
	{
		env_to_add = env_create_node_from_char(envline);
		new_list_node = ft_lstnew(env_to_add);
		add_new_env_node_to_list(env_wrap, new_list_node);
	}
}
