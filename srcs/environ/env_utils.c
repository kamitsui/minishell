/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:33:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/03 21:50:55 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

char	*env_get_value_by_key(t_list *env_head, char *key)
{
	t_list	*crnt;
	t_env	*env;

	crnt = env_head->next;
	while (crnt)
	{
		env = crnt->content;
		if (ft_strcmp(env->key, key) == 0)
		{
			// return (env->val);//! ft_strdupに変更
			return (ft_strdup(env->val));
		}
		crnt = crnt->next;
	}
	return (NULL);
}

t_env	*env_create_node_from_char(char *key_or_full, char *val_or_null)
{
	char	*key;
	char	*value;
	int		idx_of_equal;
	t_env	*node;
	size_t	i;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (NULL);
	if (val_or_null == NULL)
	{
		idx_of_equal = ft_strchr(key_or_full, '=') - key_or_full;
		//todo error handle
		node->key = ft_substr(key_or_full, 0, idx_of_equal);
		node->val = ft_strdup(&key_or_full[idx_of_equal + 1]);
	}
	else
	{
		node->key = ft_strdup(key_or_full);
		node->val = ft_strdup(val_or_null);
		// printf("[%s][%s]\n", node->key, node->val);
		if (!node->key || !node->val)
			return (NULL);
	}
	return (node);
}
