/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:22:48 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/21 14:54:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>
# include <stdlib.h>

typedef struct sigaction	t_sigaction;
volatile sig_atomic_t		g_flag;

void	sig_signal_initializer(t_sigaction *act, int sig_type);

#endif
