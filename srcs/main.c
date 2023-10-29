/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:41:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 12:50:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief minishellの入口　環境変数のデータをinput関数へ渡して、
 * minishell終了時は最後のコマンドを終了ステータスに返す
 */
#include "minishell.h"
#include "execute.h"
#include "free_minishell.h"

/**
 * @brief minishellの入口　環境変数のデータをinput関数へ渡して、
 * minishell終了時は最後のコマンドを終了ステータスに返す
 *
 * @param argc コマンドライン引数の個数。
 * @param argv[] コマンドライン引数の文字列。
 * @param env[] 環境変数。
 *
 * @return minishellで実行された最後のコマンドの終了ステータスを返す
 * @note 終了ステータスの返す処理は未実装
 */
int	main(int argc, char *argv[], char *env[])
{
	int			status;
	t_envwrap	*env_wrapper;

	env_wrapper = create_env_list(env);
	if (argc == 1)
		status = input(env_wrapper);
	else
		status = execute_script_file(argv[1], env_wrapper);
	free_envwrap(env_wrapper);
	return (status);
}
// debug code
//
//#include "debug.h"
//#include "ft_printf.h"
//int	g_fd_log;
//int	g_flag_debug;
//
//	enable_debug(DEBUG_OFF);// debug on:DEBUG_ON  off:DEBUG_OFF
//	debug_leaks("main", NULL);// debug
