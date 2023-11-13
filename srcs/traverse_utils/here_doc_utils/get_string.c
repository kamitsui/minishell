/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:09:33 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:55:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_minishell.h"
#include "minishell.h"
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
