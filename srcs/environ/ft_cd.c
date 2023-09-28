/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:31:11 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/28 08:47:43 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"
#include "environ.h"
#include "libft.h"

static int	ft_chdir(char *path, t_envwrap *env_wrap)
{
	int		sys_rtn;
	char	*tmp;

	sys_rtn = chdir(path);
	if (sys_rtn == SYSCALL_FAILED)
	{
		printf("syscall failed\n");//!
		return (SYSCALL_FAILED);
	}
	ft_export(env_wrap, "OLDPWD", env_wrap->pwd);
	ft_export(env_wrap, "PWD", path);
	free(env_wrap->pwd);
	env_wrap->pwd = ft_strdup(path);
	return (SYSCALL_SUCCESS);
}

//todo error handling not implimented
void	ft_cd(char *path, t_envwrap *env_wrap)
{
	int	sys_rtn;

	sys_rtn = access(path, R_OK | W_OK | X_OK);
	// if (res_val == ACCESS_FAILED);
	if (sys_rtn == SYSCALL_FAILED)
	{
		//todo error handling
		env_wrap->exit_code = SYSCALL_FAILED;
		return ;
	}
	sys_rtn = ft_chdir(path, env_wrap);
	if (sys_rtn == SYSCALL_FAILED)
	{
		//todo error handling
		env_wrap->exit_code = SYSCALL_FAILED;
		return ;
	}
	env_wrap->exit_code = SYSCALL_SUCCESS;
}