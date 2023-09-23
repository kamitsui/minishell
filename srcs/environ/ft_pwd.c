/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:47:36 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/23 14:10:46 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pwd.h"
#include "libft.h"

//! 環境変数からｇ取る必要かも？folderが削除されたあとのPWDの挙動。
void	ft_pwd(t_env *env_head)
// void	ft_pwd(void)
{
	char	*abs_path;
	char	*buf;

	buf = NULL;
	abs_path = getcwd(buf, UNDEFINED);
	if (abs_path == NULL)
	{
		abs_path = env_get_value(env_head, "PWD");
		if (abs_path == NULL)
			perror("pwd:");
	}
	ft_putendl_fd(abs_path, STDOUT_FILENO);
	free(abs_path);
	exit (EXIT_SUCCESS);
}

int	main(void)
{
	ft_pwd();
	system("leaks -q pwd");
}
