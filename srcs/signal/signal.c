/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:49 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/23 16:44:16 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"

#include <unistd.h>
#include <stdio.h>
#include "readline/readline.h"
#include "readline/history.h"
#include <string.h>

static void	handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	write(STDOUT_FILENO, "HERE", 5);
}

void	sig_signal_initializer(t_sigaction *act)
{
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGINT);
	sigaddset(&act->sa_mask, SIGQUIT);
	act->sa_sigaction = handler;
	act->sa_flags = SA_SIGINFO;
}

int main()
{
    char *line = NULL;
	t_sigaction	act;

    sig_signal_initializer(&act);
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGQUIT, &act, NULL);
    while (1)
    {
        line = readline("> ");
        if (line == NULL || strlen(line) == 0)
        {
            free(line);
            break;
        }
        add_history(line);
        free(line);
    }
    printf("exit\n");
    return 0;
}