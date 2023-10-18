/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:50:28 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/18 19:15:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char const *s)
{
	size_t	n;

	n = 0;
	while (s[n])
	{
		n++;
	}
	return (n);
}

void	ft_free_null_gnl(char *s)
{
	free(s);
	s = NULL;
}

char	*ft_strndup_gnl(char *s, size_t len)
{
	char	*res;
	size_t	n;

	res = malloc(sizeof(char) * (len + SIZE_NULLCHAR));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (n < len)
	{
		res[n] = s[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}

/*
* param 	ファイルデスクリプタ
* return	改行までの文字列
* free		必要
*/
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + (size_t)1];
	static char	*saved[FOPEN_MAX];
	size_t		lf_loc;
	ssize_t		n_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd > FOPEN_MAX)
		return (NULL);
	if (saved[fd] == NULL)
		saved[fd] = ft_strndup_gnl("", 0);
	while (1)
	{
		if (saved[fd] == NULL)
			return (NULL);
		lf_loc = ft_lf_loc(saved[fd]);
		if (lf_loc)
			return (ft_output(&saved[fd], lf_loc));
		else if (!lf_loc)
		{
			n_read = read(fd, buf, BUFFER_SIZE);
			if (n_read >= READ_SUCCESS)
				ft_read_success(&saved[fd], buf, n_read);
			else
				return (ft_read_finish(&saved[fd], n_read));
		}
	}
}

/*
* param1	fd(ファイルデスクリプタ)
* param2	char **line
* return	成功：文字数、失敗：−１、終わり：０
* free		必要
*/
ssize_t	gnl_wrapper(int fd, char **line)
{
	errno = 0;
	*line = get_next_line(fd);
	if (errno)
		return (-1);
	else if (*line == NULL)
		return (0);
	else
		return (ft_strlen_gnl(*line));
}
