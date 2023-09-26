/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:49 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/26 09:57:00 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h>
#include "readline/readline.h"
#include "readline/history.h"
#include <string.h>

// void	sig_handle_ctrl_d

void	sig_handle_ctrl_c(void)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	//todo kill all process and back to getline
}

void	sig_handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	if (siginfo->si_signo == SIGINT)
	{
		// write(STDOUT_FILENO, "INT\n", 5);
		g_flag = SIGINT;
		sig_handle_ctrl_c();
		//! kill other process and back to readline prompt
	}
	else if (siginfo->si_signo == SIGQUIT)
	{
		// wont hit here as SIGQUIT uses SIG_IGN
		write(STDOUT_FILENO, "QUIT\n", 6);
		return ;
	}
	else
	{
		write(STDOUT_FILENO, "ELSE\n", 6);

	}
}

void	sig_signal_initializer(t_sigaction *act, int sig_type)
{
	if (sig_type == SIGINT)
	{
		sigemptyset(&act->sa_mask);
		sigaddset(&act->sa_mask, sig_type);
		act->sa_sigaction = sig_handler;
		act->sa_flags = SA_SIGINFO | SA_RESTART;
	}
	else if (sig_type == SIGQUIT)
		act->sa_handler = SIG_IGN;
}

int main()
{
	char *line = NULL;
	t_sigaction	act_sigint;
	t_sigaction	act_sigquit;

	sig_signal_initializer(&act_sigint, SIGINT);
	sig_signal_initializer(&act_sigquit, SIGQUIT);
	sigaction(SIGINT, &act_sigint, NULL);
	sigaction(SIGQUIT,&act_sigquit, NULL);
	while (1)
	{
		// printf("gflag=[%d]\n", g_flag);
		line = readline("> ");
		if (line == NULL || strlen(line) == 0)
		{
			free(line);
			break ;
		}
		printf("%s\n", line);
		add_history(line);
		free(line);
	}
	printf("exit\n");
	return 0;
}
