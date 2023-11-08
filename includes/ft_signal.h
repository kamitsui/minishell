/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:48 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/09 04:01:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct sigaction	t_sigaction;
volatile sig_atomic_t		g_flag;

typedef enum e_Handler_Type
{
	HANDLE_NORMAL,
	HANDLE_HEREDOC_CHILD,
	HANDLE_HEREDOC_PARENT,
	HANDLE_EXIT_SIGNUM,
	HANDLE_IGN
}	t_Handler_Type;

void	signal_initializer(
			t_sigaction *act, int sig_type, t_Handler_Type type);

typedef void				(*t_sig_handler)(int, siginfo_t *, void *);
void	sig_handler_normal(int sig, siginfo_t *siginfo, void *ucontext);
void	sig_handler_heredoc_children(
			int sig, siginfo_t *siginfo, void *ucontext);
void	sig_handler_heredoc_parent(int sig, siginfo_t *siginfo, void *ucontext);
void	sig_exit_signum(int sig, siginfo_t *siginfo, void *ucontext);

#endif
