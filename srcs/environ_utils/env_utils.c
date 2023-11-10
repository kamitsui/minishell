/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:33:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/10 13:30:53 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"

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
			if (env->val == NULL)
				return (NULL);
			else
				return (ft_strdup(env->val));
		}
		crnt = crnt->next;
	}
	return (NULL);
}

t_env	*env_create_node_from_char(char *envline)
{
	char	*loc_of_equal;
	int		idx_of_equal;
	t_env	*node;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		ft_errno_exit("ft_calloc");
	loc_of_equal = ft_strchr(envline, '=');
	if (loc_of_equal == NULL)
	{
		node->key = ft_strdup(envline);
		node->val = NULL;
		if (!node->key)
			ft_errno_exit("ft_strdup");
	}
	else
	{
		idx_of_equal = loc_of_equal - envline;
		node->key = ft_substr(envline, 0, idx_of_equal);
		node->val = ft_strdup(&envline[idx_of_equal + 1]);
		if (!node->key || !node->val)
			ft_errno_exit("ft_substr or ft_strdup");
	}
	return (node);
}
