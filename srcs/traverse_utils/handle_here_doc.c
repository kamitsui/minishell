/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:44:55 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/09 03:57:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traverse.h"
#include "error_minishell.h"
#include "ft_signal.h"
#include "execute.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	input_from_stdin(int fd, char *end_of_block)
{
	char	*line;

	write(STDIN_FILENO, PROMPT_HERE_DOC, ft_strlen(PROMPT_HERE_DOC));
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, end_of_block, ft_strlen(line) - 1) == 0)
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

static char	*get_string(int fd)
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

static void	child_process_heredoc(int pipefd[], char *end_of_block)
{
	t_sigaction	act_sigint_child;

	signal_initializer(&act_sigint_child, SIGINT, HANDLE_HEREDOC_CHILD);
	close(pipefd[READ_END]);
	input_from_stdin(pipefd[WRITE_END], end_of_block);
}

void	input_and_update(char **end_of_block)
{
	int			pipefd[2];
	pid_t		pid;
	t_sigaction	act_sigint_parent;

	signal_initializer(&act_sigint_parent, SIGINT, HANDLE_HEREDOC_PARENT);
	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		signal_initializer(&act_sigint_parent, SIGINT, HANDLE_IGN);
		child_process_heredoc(pipefd, *end_of_block);
	}
	else
	{
		g_flag = wait_process(pid, 1);
		close(pipefd[WRITE_END]);
		free(*end_of_block);
		*end_of_block = get_string(pipefd[READ_END]);
		close(pipefd[READ_END]);
	}
	signal_initializer(&act_sigint_parent, SIGINT, HANDLE_IGN);
}

void	handle_here_doc(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;

	if (node->type == NODE_COMMAND && node->num_children > 1)
		if (node->children[0]->flag & BIT_HERE_DOC)
			input_and_update(&node->children[1]->value);
	if (g_flag != 0)
		return ;
	i = 0;
	while (i < node->num_children && node->type <= NODE_REDIRECTION)
	{
		handle_here_doc(node->children[i], env_wrapper);
		if (g_flag != 0)
			break ;
		i++;
	}
}
