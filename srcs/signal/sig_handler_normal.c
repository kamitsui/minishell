/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:17 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:18:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_signal.h"
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	_sigint_normal(void)
{
	g_flag = EXIT_FAILURE;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/**
 * @brief minishellのプロンプト入力時の、SIGINTに対するシグナルハンドラー
 *
 * @param sig SIGINT
 * @param siginfo 不使用
 * @param ucontext 不使用
 */
void	sig_handler_normal(int sig, siginfo_t *siginfo, void *ucontext)
{
	_sigint_normal();
	(void)sig;
	(void)siginfo;
	(void)ucontext;
}
