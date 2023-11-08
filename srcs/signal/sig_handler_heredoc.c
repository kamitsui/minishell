/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:21:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/09 03:58:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//todo heredocを抜けるだけに変更必要（exitではなく）
// todo have to set signal back to normal after heredoc
static void	_sigint_heredoc(void)
{
	exit(EXIT_FAILURE);
}

// type == HANDLE_HEREDOC
void	sig_handler_heredoc_children(
			int sig, siginfo_t *siginfo, void *ucontext)
{
	(void)sig;
	(void)siginfo;
	(void)ucontext;
	_sigint_heredoc();
}

void	sig_handler_heredoc_parent(int sig, siginfo_t *siginfo, void *ucontext)
{
	g_flag = sig;
	(void)siginfo;
	(void)ucontext;
	write(STDOUT_FILENO, "\n", 1);
}
