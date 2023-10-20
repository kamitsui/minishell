/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:41:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/20 22:17:54 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief minishellの入口　環境変数のデータをinput関数へ渡して、
 * minishell終了時は最後のコマンドを終了ステータスに返す
 */
#include "minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"
#include "ft_signal.h"

//デバッグ用
#include "debug.h"
#include <fcntl.h>
int	g_fd_log;
int	g_flag_debug;

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
	t_sigaction	act_sigint;
	t_sigaction	act_sigquit;

	g_flag = 0;
	sig_signal_initializer(&act_sigint, SIGINT);
	sig_signal_initializer(&act_sigquit, SIGQUIT);
	sigaction(SIGINT, &act_sigint, NULL);
	sigaction(SIGQUIT,&act_sigquit, NULL);
	enable_debug(DEBUG_ON);// debug on:DEBUG_ON  off:DEBUG_OFF
	env_wrapper = create_env_list(env);
	if (argc == 1)
		status = input(env_wrapper);
	else
		status = execute_script_file(argv[1], env);// 未着手
	(void)argc;
	free_envwrap(env_wrapper);
	debug_leaks("main", NULL);// debug  リークあり10/6 kamitsui
	return (status);
}
// デバッグログの保存ファイルを開く & デバッグON
//
////----- debug code ----------
//	g_flag_debug = DEBUG_ON;// debug
////	g_flag_debug = DEBUG_OFF;// debug
//	if (g_flag_debug == DEBUG_ON)// debug
//		g_fd_log = open_log("debug.log", O_TRUNC);// debug
////---------------------------

// スタックの状態出力
////----- debug code ----------
//	if (g_flag_debug == DEBUG_ON)
//		debug_data(g_fd_log, &stack_a, &stack_b);
////---------------------------

// fd_logのリソースを解放
////----- debug code ----------
//	if (g_flag_debug == DEBUG_ON)
//		close (g_fd_log);
////---------------------------
