/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:47:36 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 15:41:14 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pwd.h"
#include "libft.h"

void	ft_pwd(void)
{
	char	*abs_path;
	char	*buf;

	buf = NULL;
	abs_path = getcwd(buf, UNDEFINED);
	if (abs_path == NULL)
	{
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
