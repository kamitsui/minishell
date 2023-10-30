/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:40:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 17:16:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traverse.h"
#include "environ.h"
#include "error_minishell.h"
#include "get_next_line.h"
#include "ft_signal.h"
#include "execute.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void	write_to_pipefd(int fd, char *end_of_block)
{
	char	*line;

	write(STDIN_FILENO, PROMPT_HERE_DOC, ft_strlen(PROMPT_HERE_DOC));
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, end_of_block, ft_strlen(end_of_block)) == 0)
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

int	here_doc(char *end_of_block)
{
	int			pipefd[2];
	pid_t		pid;
	t_sigaction	act_sigint;

	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		sig_signal_initializer(&act_sigint, SIGINT, HANDLE_HEREDOC);
		close(pipefd[READ_END]);
		write_to_pipefd(pipefd[WRITE_END], end_of_block);
	}
	else
	{
		close(pipefd[WRITE_END]);
		dup2(pipefd[READ_END], STDIN_FILENO);
		close(pipefd[READ_END]);
	}
	return (wait_process(pid, 1));
}
