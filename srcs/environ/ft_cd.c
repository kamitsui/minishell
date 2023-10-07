/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:31:11 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/07 13:59:05 by kamitsui         ###   ########.fr       */
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
		perror("cd");
		return (SYSCALL_FAILED);
	}
	tmp = env_wrap->cwd;
	env_wrap->cwd = ft_getcwd(env_wrap);
	ft_export(env_wrap, "PWD", env_wrap->cwd);
	ft_export(env_wrap, "OLDPWD", tmp);
	// printf("PWD[%s]\nOLDPWD[%s]\n", env_get_value_by_key(env_wrap->env,"PWD"), env_get_value_by_key(env_wrap->env, "OLDPWD"));//! delete
	free(tmp);
	return (SYSCALL_SUCCESS);
}

//todo error handling not implimented
void	ft_cd(char *path, t_envwrap *env_wrap)
{
	char	*new_path;
	int		sys_rtn;

	if (path == NULL)
	{
		new_path = env_get_value_by_key(env_wrap->env, "HOME");
		sys_rtn = ft_chdir(new_path, env_wrap);
	}
	else
	{
		sys_rtn = ft_chdir(path, env_wrap);
	}
	// if (sys_rtn	== SYSCALL_FAILED)
		//todo error handle
	(void)sys_rtn;// Add by kamitsui (compile error : use of undeclared identifier 'sys_rtn')
//	return (sys_rtn);// 返すべき？？　未確認　by kamitsui
}
