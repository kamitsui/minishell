/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:12:38 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/15 16:12:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include <unistd.h>

void	recover_fd(int prev_fd, int recover_fd)
{
	dup2(prev_fd, recover_fd);
	if (dup2(prev_fd, recover_fd) == -1)
		ft_errno_exit("dup2");
	close(prev_fd);
}
