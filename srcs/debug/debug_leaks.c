/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:54:20 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 22:28:13 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "ft_printf.h"
#include "minishell.h"

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

void	debug_leaks(char *call_by_func, char *target)
{
	int	prev_fd;
	int	prev_stderr_fd;
	char	*str_leak;

	if (g_flag_debug == DEBUG_ON)
	{
		if (target != NULL)
			str_leak = ft_strjoin("leaks -q ", target);
		else
			str_leak = ft_strjoin("leaks -q ", PROGRAM_NAME);
		ft_dprintf(g_fd_log, "%s---- leaks debug ----\n", DEBUG_COLOR);
		ft_dprintf(g_fd_log, ">> call by [%s]\n", call_by_func);
		prev_fd = buck_up_and_associate_fd(STDOUT_FILENO);
		prev_stderr_fd = buck_up_and_associate_fd(STDERR_FILENO);
		system(str_leak);
		recover_filedes(prev_fd, STDOUT_FILENO);
		recover_filedes(prev_stderr_fd, STDERR_FILENO);
		free(str_leak);
	}
}
