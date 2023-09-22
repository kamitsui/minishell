/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/22 17:22:32 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

t_list	*env_make_env_list(char **environ)
{
	t_list	*env_head;
	t_env	*env_node;
	char	**one_env_line;
	size_t	i;

	env_head = ft_lstnew(NULL);
	i = 0;
	while (environ[i])
	{
		env_node = env_create_node_from_char(environ[i]);
		if (env_node == NULL)
			return (NULL);
		ft_lstadd_back(&env_head, ft_lstnew(env_node));
		i++;
	}
	return (env_head);
}

//! *env_headはdummy node
int	env_controller(void)
{
	extern char	**environ;
	t_list		*env_head;

	env_head = env_make_env_list(environ);
	if (env_head == NULL)
		return (EXIT_FAILURE);
	printf("\n***initial env lst***\n");
	ft_env(env_head);
	ft_unset(&env_head, "LANG");
	ft_export(&env_head, "SHELL=TAKOHACHIRO");
	ft_export(&env_head, "PWD=42tokyo");
	ft_export(&env_head, "NOTHING=hogehoge");
	printf("\n***after exports ****\n");
	ft_env(env_head);
	printf("\n***export with no arg ****\n");
	ft_export(&env_head, NULL);
	printf("\n***after export with no arg ****\n");
	ft_env(env_head);
	ft_lstclear(&env_head, _env_del_content);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	env_controller();
	system("leaks -q env");
}