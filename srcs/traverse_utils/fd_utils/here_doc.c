/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:40:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/06 22:30:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "traverse.h"
#include "environ.h"
#include "error_minishell.h"
#include "get_next_line.h"
#include "ft_signal.h"
#include "execute.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	here_doc(char *end_of_block)
{
	int			pipefd[2];
	pid_t		pid;

	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		close(pipefd[READ_END]);
		write(pipefd[WRITE_END], end_of_block, ft_strlen(end_of_block) + 1);
		close(pipefd[WRITE_END]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[WRITE_END]);
		dup2(pipefd[READ_END], STDIN_FILENO);
		close(pipefd[READ_END]);
	}
	return (wait_process(pid, 1));
}
