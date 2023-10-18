/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:40:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 19:17:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traverse.h"
#include "environ.h"
#include "error_minishell.h"
#include "get_next_line.h"
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
		//if (ft_strnequ(line, end_of_block, ft_strlen(end_of_block)) == true)
		if (ft_strcmp(line, end_of_block) == true)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
		write(STDIN_FILENO, PROMPT_HERE_DOC, ft_strlen(PROMPT_HERE_DOC));
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd);
	exit(EXIT_SUCCESS);// exit(6);// ?????
}

int	here_doc(char *end_of_block, t_envwrap *env_wrapper)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	//file_name = handle_expansion(file_name, env_wrapper);
	(void)env_wrapper;// case of no expansion
	status = EXIT_SUCCESS;
	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		close(pipefd[READ_END]);
		write_to_pipefd(pipefd[WRITE_END], end_of_block);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pipefd[WRITE_END]);
		dup2(pipefd[READ_END], STDIN_FILENO);
		close(pipefd[READ_END]);
	}
	//  here_doc は常に EXIT_SUCCESS を返すのでいいのか？？？
	return (status);
}
