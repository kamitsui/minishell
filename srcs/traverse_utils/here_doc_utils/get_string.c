/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:09:33 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/09 05:14:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traverse.h"
#include "libft.h"
#include "get_next_line.h"
#include "error_minishell.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_string(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	ssize_t	bytes_read;
	char	*saved;

	saved = ft_strnew(1);
	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		saved = ft_strjoin_free(saved, buffer);
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read < 0)
			ft_errno_exit("read");
	}
	return (saved);
}
