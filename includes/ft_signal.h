/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:48 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/20 22:28:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>
# include <stdlib.h>

typedef struct sigaction	t_sigaction;
//volatile sig_atomic_t		g_flag = 0;// fix by kamitsui
							// (compile error : duplicate symbol '_g_flag' in:)
volatile sig_atomic_t		g_flag;

int	g_signal_num;// move from signal.h by kamitsui (compile error)

void	sig_signal_initializer(t_sigaction *act, int sig_type);

#endif
