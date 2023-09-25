/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 10:33:07 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "ft_pwd.h"

t_envwrap	*env_make_env_list_to_wrap(char **environ)
{
	t_list		*env_head;
	t_envwrap	*wrap_head;
	t_env		*env_node;
	char		**one_env_line;
	size_t		i;

	env_head = ft_lstnew(NULL);
	wrap_head = ft_lstnew(NULL);
	if (!env_head || !wrap_head)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		env_node = env_create_node_from_char(environ[i]);
		if (env_node == NULL)
			return (NULL);
		ft_lstadd_back(&env_head, ft_lstnew(env_node));
		i++;
	}
	wrap_head->env = env_head;
	wrap_head->exit_code = EXIT_SUCCESS;
	wrap_head->pwd = ft_pwd(env_head);
	return (wrap_head);
}

//! *env_headはdummy node
int	env_controller(void)
{
	extern char	**environ;
	t_list		*env_head;
	t_envwrap	*env_wrapper;

	env_wrapper = env_make_env_list_to_wrap(environ);
	if (wrap_head == NULL)
		return (EXIT_FAILURE);
	printf("\n***initial env lst***\n");
	ft_env(wrap_head);
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