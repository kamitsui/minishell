/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 16:14:26 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

static void	env_add_new_at_last(t_list *env_head, char *key, char *val)
{
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	new_env->key = key;
	new_env->val = val;
	ft_lstadd_back(&env_head, ft_lstnew(new_env));
}

static void	env_add_new_env(t_list *env_head, char *key, char *val)
{
	t_list	*crnt;
	t_env	*new_env;
	t_env	*old_env;
	char	*tmp;
	bool	has_same_key;

	has_same_key = false;
	crnt = env_head;
	while (crnt)
	{
		old_env = crnt->content;
		if (ft_strcmp(old_env->key, key) == 0)
		{
			free (old_env->val);
			old_env->val = val;
			has_same_key = true;
			break ;
		}
		crnt = crnt->next;
	}
	if (has_same_key == false)
		env_add_new_at_last(env_head, key, val);
}

//! no validation check included
void	ft_export(t_list *env_head, char *new_env)
{
	char	*new_key;
	char	*new_value;
	char	**splited;
	char	*tmp;

	// if (new_env == NULL)
	// {
	// 	printf("here\n");
	// 	tmp = env_get_value(env_head, "_=");
	// 	ft_unset(env_head, "_=");
	// 	ft_env(env_head);
	// 	ft_export(env_head, ft_strjoin("_=", tmp));
	// 	return ;
	// }
	splited = ft_split(new_env, '=');
	new_key = splited[KEY];
	new_value = splited[VALUE];
	free(splited);
	env_add_new_env(env_head, new_key, new_value);
}
