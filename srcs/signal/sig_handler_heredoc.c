/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:21:04 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 18:27:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//todo heredocを抜けるだけに変更必要（exitではなく）
// todo have to set signal back to normal after heredoc
static void	_sigint_heredoc(void)
{
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

// type == HANDLE_HEREDOC
void	sig_handler_heredoc(int sig, siginfo_t *siginfo, void *ucontext)
{
	(void)sig;
	(void)siginfo;
	(void)ucontext;
	_sigint_heredoc();
}
