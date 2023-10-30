/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:17 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 18:25:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_signal.h"
#include "libft.h"
//#include "error_minishell.h"

#include <unistd.h>
//#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include <string.h>

static void	_sigint_normal(void)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

// type == HANDLE_NORMAL
void	sig_handler_normal(int sig, siginfo_t *siginfo, void *ucontext)
{
	if (siginfo->si_signo == SIGINT)
		_sigint_normal();
	else if (siginfo->si_signo == SIGQUIT)
	{
		write(STDOUT_FILENO, "QUIT\n", 6);
		return ;
	}
	else
		write(STDOUT_FILENO, "ELSE\n", 6);
	(void)sig;
	(void)ucontext;
}
