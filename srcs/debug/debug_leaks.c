/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:54:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/07 11:03:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "ft_printf.h"

static int	buck_up_and_associate_fd(int associate_fd)
{
	int	prev_fd;

	prev_fd = dup(associate_fd);
	dup2(g_fd_log, associate_fd);
	// handle_error ... 未着手
	return (prev_fd);
}

static void	recover_filedes(int prev_fd, int recover_fd)
{
	dup2(prev_fd, recover_fd);
	// handle_error ... 未着手
	close(prev_fd);
}

void	debug_leaks(char *call_by_func)
{
	int	prev_fd;
	int	prev_stderr_fd;

	if (g_flag_debug == DEBUG_ON)
	{
		ft_dprintf(g_fd_log, "%s---- leaks debug ----\n", DEBUG_COLOR);
		ft_dprintf(g_fd_log, ">> call by [%s]\n", call_by_func);
		prev_fd = buck_up_and_associate_fd(STDOUT_FILENO);
		prev_stderr_fd = buck_up_and_associate_fd(STDERR_FILENO);
		system("leaks -q minishell");
		recover_filedes(prev_fd, STDOUT_FILENO);
		recover_filedes(prev_stderr_fd, STDERR_FILENO);
	}
}
