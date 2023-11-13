/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_exit_signum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:19 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:06:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

/**
 * @brief signalの値を使ってプロセスを終了するシグナルハンドラー
 * コマンドの実行時（子プロセス）にシグナルハンドラーを使用。
 *
 * @param sig 設定しているシグナル（SIGINT）
 * @param siginfo 不使用
 * @param ucontext 不使用
 */
void	sig_exit_signum(int sig, siginfo_t *siginfo, void *ucontext)
{
	(void)siginfo;
	(void)ucontext;
	exit(sig);
}
