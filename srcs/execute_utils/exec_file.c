/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/27 23:39:35 by kamitsui         ###   ########.fr       */
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
		else
			ft_errno_exit(file);
	}
	else
		search_exec_file(file, arguments, env);
}
//	要修正！！ ↓これができない。
//	else if ("./")
//	else if ("../")
