/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:21:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:14:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Here Docがシグナルで終了する際は、
 * EXIT_FAILUREを使って終了する。
 */
static void	_sigint_heredoc(void)
{
	exit(EXIT_FAILURE);
}

/**
 * @brief Here Docの入力時（子プロセス）に、
 * SIGINTが送られた時のシグナルハンドラー
 *
 * @param sig SIGINT
 * @param siginfo 不使用
 * @param ucontext 不使用
 */
void	sig_handler_heredoc_children(
			int sig, siginfo_t *siginfo, void *ucontext)
{
	(void)sig;
	(void)siginfo;
	(void)ucontext;
	_sigint_heredoc();
}

/**
 * @brief Here Docが複数ある場合は、親プロセス側でまとめて終了する。
 *
 * @param sig SIGINT
 * @param siginfo 不使用
 * @param ucontext 不使用
 */
void	sig_handler_heredoc_parent(int sig, siginfo_t *siginfo, void *ucontext)
{
	g_flag = sig;
	(void)siginfo;
	(void)ucontext;
	write(STDOUT_FILENO, "\n", 1);
}
