/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 22:26:54 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

static void	env_add_new_at_last(t_list *env_head, char *new_key, char *new_val)
{
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	new_env->key = new_key;
	new_env->val = new_val;
	ft_lstadd_back(&env_head, ft_lstnew(new_env));
}

static void	env_add_new_env(t_list *env_head, char *new_key, char *new_val)
{
	t_list	*crnt;
	t_env	*new_env;
	t_env	*old_env;
	char	*tmp;

	crnt = env_head;
	while (crnt)
	{
		old_env = crnt->content;
		if (ft_strcmp(old_env->key, new_key) == 0)
		{
			free (old_env->val);
			old_env->val = new_val;
			return ;
		}
		crnt = crnt->next;
	}
	env_add_new_at_last(env_head, new_key, new_val);
}

static void	env_export_without_arg(t_list *env_head)
{
	char	*tmp;
	char 	*tmp2;

	tmp = ft_strdup(env_get_value(env_head, "_"));
	ft_unset(env_head, "_");
	ft_lstiter(env_head, _print_env_with_export);
	ft_export(env_head, ft_strjoin("_=", tmp));
	free(tmp);
}

//! no validation check included
void	ft_export(t_list *env_head, char *new_env)
{
	char	*new_key;
	char	*new_value;
	char	**splited;

	if (new_env == NULL)
	{
		env_export_without_arg(env_head);
	}
	else
	{
		splited = ft_split(new_env, '=');
		new_key = splited[KEY];
		new_value = splited[VALUE];
		free(splited);
		env_add_new_env(env_head, new_key, new_value);
	}
}
