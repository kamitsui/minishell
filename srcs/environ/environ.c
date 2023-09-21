/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 15:51:41 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

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
	ft_env(env_head);
	printf("****\n");
	ft_unset(env_head, "LANG");
	ft_export(env_head, "SHELL=TAKOHACHIRO");
	ft_export(env_head, "PWD=42tokyo");
	ft_export(env_head, "NOTHING=hogehoge");
	ft_env(env_head);
	printf("****\n");
	ft_export(env_head, NULL);
	ft_env(env_head);
	ft_lstclear(&env_head, _env_del_content);
}

int	main(void)
{
	env_controller();
	system("leaks -q env");
}