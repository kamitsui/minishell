/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:31:11 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/10 13:33:31 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"
#include "environ.h"
#include "ft_printf.h"

static void	update_pwd_oldpwd(t_envwrap *env_wrap, char *oldpath, char *newpath)
{
	char	*newpwd;
	char	*oldpwd;

	newpwd = ft_strjoin("PWD=", newpath);
	oldpwd = ft_strjoin("OLDPWD=", oldpath);
	ft_export(env_wrap, newpwd);
	ft_export(env_wrap, oldpwd);
	free(oldpath);
	free(newpath);
	free(newpwd);
	free(oldpwd);
}

static int	ft_chdir(char *path, t_envwrap *env_wrap)
{
	int		sys_rtn;
	char	*oldpath;
	char	*newpath;

	sys_rtn = chdir(path);
	if (sys_rtn == SYSCALL_FAILED)
	{
		perror("cd");
		return (SYSCALL_FAILED);
	}
	oldpath = env_wrap->cwd;
	newpath = ft_getcwd(env_wrap);
	env_wrap->cwd = ft_strdup(newpath);
	update_pwd_oldpwd(env_wrap, oldpath, newpath);
	return (SYSCALL_SUCCESS);
}

int	ft_cd(char *path, t_envwrap *env_wrap)
{
	char	*new_path;
	int		sys_rtn;

	if (path == NULL)
	{
		new_path = env_get_value_by_key(env_wrap->env, "HOME");
		if (!new_path)
		{
			ft_dprintf(STDERR_FILENO, "minishell: cd: HOME not set\n");
			return (EXIT_FAILURE);
		}
		sys_rtn = ft_chdir(new_path, env_wrap);
		free(new_path);
	}
	else
	{
		sys_rtn = ft_chdir(path, env_wrap);
	}
	if (sys_rtn == SYSCALL_FAILED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
