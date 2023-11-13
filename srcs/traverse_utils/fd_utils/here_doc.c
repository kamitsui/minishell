/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:40:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:50:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include "execute.h"
#include <fcntl.h>
#include <unistd.h>

int	here_doc(char *end_of_block)
{
	int			pipefd[2];
	pid_t		pid;

	if (pipe(pipefd) == -1)
		ft_errno_exit("pipe");
	pid = fork();
	if (pid == -1)
		ft_errno_exit("fork");
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
