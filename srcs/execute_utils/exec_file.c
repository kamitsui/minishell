/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:47:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/20 22:52:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exec_file.c
 * @brief コマンドにPATHを通して実行する関数
 * @bug 要修正："./file" や "../file" などの実行ができない
 */
#include "environ.h"
#include "libft.h"
#include "error_minishell.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * @brief PATHと実行ファイル名を繋げる関数（free必要）
 *
 * @param dir 実行ファイルが存在するディレクトリパス名
 * @param file 実行ファイル
 *
 * @return パス付き実行ファイル 例 "/bin/ls"
 */
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
