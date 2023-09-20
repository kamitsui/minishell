/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/20 17:04:21 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "ft_printf.h"

void	_delete_env_list(void *content)
{
	t_env	*node;

	node = content;
	free(node->key);
	free(node->val);
	node->key = NULL;
	node->val = NULL;
	free(node);
	node = NULL;
}

t_list	*env_make_env_list(char **environ)
{
	t_list	*env_head;
	t_env	*env_node;
	char	**one_env;
	size_t	i;

	env_head = NULL;
	i = 0;
	while (environ[i])
	{
		one_env = ft_split(environ[i], '=');
		env_node = ft_calloc(1, sizeof(t_env));
		if (one_env == NULL || env_node == NULL)
			return (NULL);
		env_node->key = one_env[KEY];
		env_node->val = one_env[VALUE];
		free (one_env);
		ft_lstadd_back(&env_head, ft_lstnew(env_node));
		// printf("key:[%s]val:[%s]\n", one_env[0], one_env[1]);
		i++;
	}
	return (env_head);
}

void	env_controller(void)
{
	extern char	**environ;
	t_list		*env_head;

	env_head = NULL;
	env_head = env_make_env_list(environ);
	// if (env_head == NULL)
	//todo error handle
	ft_lstclear(env_head, _delete_env_list);
}

int	main(void)
{
	env_controller();
}