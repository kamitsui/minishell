/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:47:36 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 10:53:59 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
// #include "ft_pwd.h"
#include "libft.h"

char	*ft_get_char_pwd(t_envwrap *env_wrap)
{
	char	*abs_path;
	char	*buf;

	buf = NULL;
	abs_path = getcwd(buf, UNDEFINED);
	if (abs_path == NULL)
	{
		abs_path = env_get_value(env_wrap->env, "PWD");
		if (abs_path == NULL)
		{
			abs_path = ft_strdup(env_wrap->pwd);
			if (abs_path == NULL)
			{
				perror("pwd:");
				return (NULL);
			}
		}
	}
	return (abs_path);
}

//! 環境変数からｇ取る必要かも？folderが削除されたあとのPWDの挙動。
void	ft_pwd(t_envwrap *env_wrap)
{
	char	*abs_path;

	abs_path = ft_get_char_pwd(env_wrap);
	if (!abs_path)
	{
		env_wrap->exit_code = EXIT_FAILURE;
		return ;
	}
	ft_putendl_fd(abs_path, STDOUT_FILENO);
	free(abs_path);
}

int	main(void)
{
	ft_pwd();
	system("leaks -q pwd");
}
