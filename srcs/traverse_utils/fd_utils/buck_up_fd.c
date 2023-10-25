/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buck_up_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:09:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/15 16:15:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include <unistd.h>

int	buck_up_fd(int fd)
{
	int	prev_fd;

	prev_fd = dup(fd);
	if (prev_fd == -1)
		ft_errno_exit("dup");
	return (prev_fd);
}
