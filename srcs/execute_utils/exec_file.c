/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/04 14:36:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_file.c
 * @brief コマンドにPATHを通して実行する関数
 * @bug 要修正："./file" や "../file" などの実行ができない
 */
#include "execute.h"
#include "libft.h"
#include "error_minishell.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/errno.h>
#include <limits.h>

static void	exec_in_current_dir(char *file, char *arguments[], char *env[])
{
	char	*dir;
	char	*buf;
	char	*path;

	buf = (char *)malloc((size_t)PATH_MAX);
	if (buf == NULL)
		ft_perror_exit("malloc");
	dir = getcwd(buf, PATH_MAX);
	path = join_path(dir, file);
	if (path == NULL)
		ft_perror_exit("join_path");
	free(dir);
	if (access(path, F_OK | X_OK) == 0)
		execve(path, arguments, env);
	free(path);
	ft_dprintf(STDERR_FILENO, "%s: %s: No such file or directory\n", NAME, file);
	exit (127);
}

/**
 * @brief 絶対パス、相対パスで渡された実行ファイルに対しての処理
 *
 * @param file 実行するファイル（コマンド名）
 * @param arguments[] コマンドとコマンド引数
 * @param env[] 環境変数
 */
static void	search_exec_file(char *file, char *arguments[], char *env[])
{
	char	*path;
	char	*dir;
	char	*token;

	dir = get_substr_env("PATH", env);
	if (dir == NULL)
		return ;
	if (*dir == '\0')
		exec_in_current_dir(file, arguments, env);
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

/**
 * @brief コマンドにPATHを通して実行する関数
 *
 * @param file 実行するファイル（コマンド名）
 * @param arguments[] コマンドとコマンド引数
 * @param env[] 環境変数
 */
void	exec_file(char *file, char *arguments[], char *env[])
{
	if (file == NULL || arguments == NULL || env == NULL)
		return ;
	if (ft_strchr(file, '/') != NULL)
	{
		if (access(file, F_OK | X_OK) == 0)
		{
			execve(file, arguments, env);
			ft_dprintf(STDERR_FILENO, "%s: %s: is a directory\n", NAME, file);
			exit (126);
		}
		put_error_message_from_errno(file);
		if (errno == EACCES)
			exit (126);
		else
			exit (127);
	}
	else
		search_exec_file(file, arguments, env);
}
