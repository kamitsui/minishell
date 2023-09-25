/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:33:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 12:28:59 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

char	*env_get_value(t_list *env_head, char *key)
{
	t_list	*crnt;
	t_env	*env;

	crnt = env_head->next;
	while (crnt)
	{
		env = crnt->content;
		if (ft_strcmp(env->key, key) == 0)
		{
			return (env->val);
		}
		crnt = crnt->next;
	}
	return (NULL);
}

t_env	*env_create_node_from_char(char *key_or_full, char *val_or_null)
{
	char	*key;
	char	*value;
	char	*loc_of_eq;
	t_env	*node;
	size_t	i;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (NULL);
	if (val_or_null == NULL)
	{
		loc_of_eq = ft_strchr(key_or_full, '=');
		if (!loc_of_eq)
			return (NULL);
		node->key = ft_strndup(key_or_full, loc_of_eq - key_or_full);
		node->val = ft_strdup(loc_of_eq + 1);
	}
	else
	{
		node->key = ft_strdup(key_or_full);
		node->val = ft_strdup(val_or_null);
		if (!node->key || !node->val)
			return (NULL);
	}
	return (node);
}
