/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:49 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/13 09:25:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "libft.h"
#include "error_minishell.h"

/**
 * @brief シグナルの初期化関数
 *
 * @param act セットするシグアクションの構造体
 * @param sig_type 初期化の対象となるシグナル
 * @param type セットしたいシグナルハンドラーの種類
 */
void	signal_initializer(
			t_sigaction *act, int sig_type, t_Handler_Type type)
{
	static t_sig_handler	f_sig_handler[HANDLE_IGN]
		= {sig_handler_normal, sig_handler_heredoc_children,
		sig_handler_heredoc_parent, sig_exit_signum};

	if (type < HANDLE_IGN)
	{
		if (sigemptyset(&act->sa_mask) == -1)
			ft_errno_exit("sigemptyeset");
		if (sigaddset(&act->sa_mask, sig_type) == -1)
			ft_errno_exit("sigaddset");
		act->sa_sigaction = f_sig_handler[type];
		act->sa_flags = SA_SIGINFO | SA_RESTART;
	}
	else
	{
		act->sa_handler = SIG_IGN;
		if (sigemptyset(&act->sa_mask) == -1)
			ft_errno_exit("sigemptyeset");
		act->sa_flags = 0;
	}
	if (sigaction(sig_type, act, NULL) == -1)
		ft_errno_exit("sigaction");
}
