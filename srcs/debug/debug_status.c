/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:22:01 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/10 21:24:53 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "ft_printf.h"

void	debug_status(const char *call_by, int status)
{
	if (g_flag_debug == DEBUG_ON)
		ft_dprintf(g_fd_log,
			"%sstatus [%d] ... call by [%s] function\n",
			DEBUG_COLOR, status, call_by);
}
