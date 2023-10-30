/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:49 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 18:32:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "libft.h"
#include "error_minishell.h"

void	sig_signal_initializer(
			t_sigaction *act, int sig_type, t_Handler_Type type)
{
	static t_sig_handler	f_sig_handler[HANDLE_IGN]
		= {sig_handler_normal, sig_handler_heredoc, sig_exit_signum};

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
