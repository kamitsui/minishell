/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/10 13:31:40 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"

t_envwrap	*create_env_list(char **environ)
{
	t_list		*env_head;
	t_envwrap	*env_wrapper;
	t_env		*env_node;
	size_t		i;

	env_head = ft_lstnew(NULL);
	env_wrapper = ft_calloc(1, sizeof(t_envwrap));
	if (!env_head || !env_wrapper)
		ft_errno_exit("ft_callor or ft_lstnew");
	i = 0;
	while (environ[i])
	{
		env_node = env_create_node_from_char(environ[i]);
		ft_lstadd_back(&env_head, ft_lstnew(env_node));
		i++;
	}
	env_wrapper->env = env_head;
	env_wrapper->exit_code = EXIT_SUCCESS;
	env_wrapper->cwd = ft_getcwd(env_wrapper);
	return (env_wrapper);
}
