/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:48:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/28 21:21:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "error_minishell.h"
#include <fcntl.h>

int	open_log(const char *file_name, int oflag)
{
	int	fd;

	if (oflag & O_TRUNC)
	{
		fd = open(file_name,
				O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	else if (oflag & O_APPEND)
	{
		fd = open(file_name,
				O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	else
		fd = -1;
	if (fd == -1)
		ft_perror_exit("open");
	return (fd);
}
