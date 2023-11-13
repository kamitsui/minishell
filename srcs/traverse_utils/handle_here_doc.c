/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:44:55 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:48:58 by kamitsui         ###   ########.fr       */
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

static void	child_process_heredoc(int pipefd[], char *end_of_block)
{
	t_sigaction	act_sigint_child;

	signal_initializer(&act_sigint_child, SIGINT, HANDLE_HEREDOC_CHILD);
	close(pipefd[READ_END]);
	input_from_stdin(pipefd[WRITE_END], end_of_block);
}

static void	parent_process_heredoc(int pipefd[], pid_t pid, char **end_of_block)
{
	g_flag = wait_process(pid, 1);
	close(pipefd[WRITE_END]);
	free(*end_of_block);
	*end_of_block = get_string(pipefd[READ_END]);
	close(pipefd[READ_END]);
}

static void	input_and_update(char **end_of_block)
{
	int			pipefd[2];
	pid_t		pid;
	t_sigaction	act_sigint_parent;
	t_sigaction	act_sigquit;

	signal_initializer(&act_sigint_parent, SIGINT, HANDLE_HEREDOC_PARENT);
	signal_initializer(&act_sigquit, SIGQUIT, HANDLE_IGN);
	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		ft_errno_exit("fork");
	else if (pid == 0)
	{
		signal_initializer(&act_sigint_parent, SIGINT, HANDLE_IGN);
		child_process_heredoc(pipefd, *end_of_block);
	}
	else
		parent_process_heredoc(pipefd, pid, end_of_block);
	signal_initializer(&act_sigint_parent, SIGINT, HANDLE_IGN);
}

void	handle_here_doc(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;

	g_flag = 0;
	if (node->type == NODE_COMMAND && node->num_children > 1)
	{
		if (node->children[0]->flag & BIT_HERE_DOC)
		{
			if (node->children[1]->flag & BIT_EXPANSION)
				expansion_in_here_doc(&node->children[1]->value);
			input_and_update(&node->children[1]->value);
		}
	}
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
