/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 22:25:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "libft.h"
#include "error_minishell.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static char	*join_path(char const *dir, char const *file)
{
	size_t	len_dir;
	size_t	len_file;
	char	*path;

	if (dir == NULL || file == NULL)
		return (NULL);
	len_dir = ft_strlen(dir);
	len_file = ft_strlen(file);
	path = malloc(sizeof(char) * (len_dir + len_file + 2));
	if (path == NULL)
		return (NULL);
	ft_memcpy(path, dir, len_dir);
	ft_memcpy(path + len_dir, "/", 1);
	ft_memcpy(path + len_dir + 1, file, len_file + 1);
	return (path);
}

static void	search_exec_file(char *file, char *arguments[], char *env[])
{
	char	*path;
	char	*dir;
	char	*token;

	dir = substr_env("PATH", env);
	if (dir == NULL)
		return ;
	token = ft_strtok(dir, ":");
	while (token != NULL)
	{
		path = join_path(token, file);
		if (path == NULL)
			return ;
		if (access(path, F_OK | X_OK) == 0)
			execve(path, arguments, env);
		free(path);
		token = ft_strtok(NULL, ":");
	}
	free(dir);
}

void	exec_file(char *file, char *arguments[], char *env[])
{
	if (file == NULL || arguments == NULL || env == NULL)
		return ;
	if (ft_strnequ(file, "/", 1) == true)
	{
		if (access(file, F_OK | X_OK) == 0)
			execve(file, arguments, env);
		else
			ft_errno_exit(file);
	}
	else
		search_exec_file(file, arguments, env);
}
//	要修正！！ ↓これができない。
//	else if ("./")
//	else if ("../")
