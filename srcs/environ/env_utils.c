/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:33:31 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 22:09:37 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

char	*env_get_value(t_list *env_head, char *key)
{
	t_list	*crnt;
	t_env	*env;

	crnt = env_head;
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
