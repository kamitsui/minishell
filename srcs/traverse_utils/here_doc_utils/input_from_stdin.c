/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_from_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:12:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/09 05:58:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traverse.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	input_from_stdin(int fd, char *end_of_block)
{
	char	*line;
	size_t	len;

	write(STDIN_FILENO, PROMPT_HERE_DOC, ft_strlen(PROMPT_HERE_DOC));
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		len = ft_strlen(end_of_block);
		if (ft_strncmp(line, end_of_block, len - 1) == 0
			&& line[len] == '\n')
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
		write(STDIN_FILENO, PROMPT_HERE_DOC, ft_strlen(PROMPT_HERE_DOC));
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd);
	exit(EXIT_SUCCESS);
}
