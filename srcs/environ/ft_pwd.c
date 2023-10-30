/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:47:36 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 18:26:11 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

char	*ft_getcwd(t_envwrap *env_wrap)
{
	char	*abs_path;
	char	*buf;

	buf = NULL;
	abs_path = getcwd(buf, UNDEFINED);
	if (abs_path == NULL)
	{
		abs_path = env_get_value_by_key(env_wrap->env, "PWD");
		if (abs_path == NULL)
		{
			abs_path = ft_strdup(env_wrap->cwd);
			if (abs_path == NULL)
			{
				perror("cwd:");
				return (NULL);
			}
		}
	}
	return (abs_path);
}

void	ft_pwd(t_envwrap *env_wrap)
{
	char	*abs_path;

	abs_path = ft_getcwd(env_wrap);
	if (!abs_path)
	{
		env_wrap->exit_code = EXIT_FAILURE;
		return ;
	}
	ft_putendl_fd(abs_path, STDOUT_FILENO);
	free(abs_path);
}
