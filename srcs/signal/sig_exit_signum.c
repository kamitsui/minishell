/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_exit_signum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:19 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 18:29:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

// type == HANDLE_EXIT_SIGNUM
void	sig_exit_signum(int sig, siginfo_t *siginfo, void *ucontext)
{
	(void)siginfo;
	(void)ucontext;
	exit(sig);
}
