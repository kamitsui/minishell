/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:33:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 11:44:28 by mogawa           ###   ########.fr       */
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

t_env	*env_create_node_from_char(char *env_line)
{
	char	*key;
	char	*value;
	char	*loc_of_eq;
	t_env	*node;
	size_t	i;

	loc_of_eq = ft_strchr(env_line, '=');
	node = ft_calloc(1, sizeof(t_env));
	if (!loc_of_eq || !node)
		return (NULL);
	node->key = ft_strndup(env_line, loc_of_eq - env_line);
	node->val = ft_strdup(loc_of_eq + 1);
	// printf("split[%s]|[%s]\n", node->key, node->val);
	return (node);
}
