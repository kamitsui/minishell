/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_script_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:51:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 18:40:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "environ.h"
#include "error_minishell.h"
#include "execute.h"
#include "ft_printf.h"

/**
 * @brief minishell起動時に引数で渡されたスクリプトファイルを実行する関数
 *
 * @param file インタプリンタ言語で書かれたスクリプトファイル\n
 * (#!/bin/bash)で始まるスクリプトなら実行できる。
 * @param env_wrap
 *
 * @return 実行結果の終了ステータス
 */
int	execute_script_file(char *file, t_envwrap *env_wrapper)
{
	char	*arguments[2];
	char	*path;
	char	**env;

	path = join_path(env_wrapper->cwd, file);
	arguments[0] = file;
	arguments[1] = NULL;
	env = convert_env_list_to_two_darray(env_wrapper->env->next);
	exec_file(path, arguments, env);
	ft_dprintf(STDERR_FILENO, "%s: %s: No such file or directory\n", NAME, file);
	return (127);
}
