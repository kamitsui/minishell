/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:45:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 17:04:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_pipe_command.c
 * @brief ノードタイプが　”｜”　パイプに対しての処理
 */
#include "parse.h"
#include "libft.h"
#include "execute.h"
#include "error_minishell.h"
#include "traverse.h"
#include <sys/wait.h>

static void	child_process_in_pipe_com(
				int pipefd[2], size_t i, t_ast *node, t_envwrap *env_wrapper)
{
	close(pipefd[READ_END]);
	if (i < node->num_children - 1)
	{
		if (dup2(pipefd[WRITE_END], STDOUT_FILENO) == -1)
		{
			close(pipefd[WRITE_END]);
			ft_errno_exit("dup2");
		}
	}
	close(pipefd[WRITE_END]);
	exit (handle_simple_command(node->children[i], env_wrapper));
}

static void	parent_process_in_pipe_com(int pipefd[2])
{
	close(pipefd[WRITE_END]);
	if (dup2(pipefd[READ_END], STDIN_FILENO) == -1)
	{
		close(pipefd[READ_END]);
		perror("dup2");
	}
	return ;
}

static pid_t	create_process_in_pipe_com(
				int pipefd[2], size_t i, t_ast *node, t_envwrap *env_wrapper)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
	else if (pid == 0)
		child_process_in_pipe_com(pipefd, i, node, env_wrapper);
	else
		parent_process_in_pipe_com(pipefd);
	return (pid);
}

int	handle_one_pipe_command(t_ast *node, t_envwrap *env_wrapper)
{
	int		pipefd[2];
	size_t	i;
	pid_t	pid;

	i = 0;
	while (i < node->num_children)
	{
		if (pipe(pipefd) == -1)
			ft_perror_exit("pipe");
		pid = create_process_in_pipe_com(pipefd, i, node, env_wrapper);
		i++;
	}
	return (wait_process(pid, node->num_children));
}

/**
 *
 * @param pipe_node パイプのノード
 * @param env 環境変数
 * @param status １つ前のノードの終了ステータス
 *
 * @return パイプコマンドの終了ステータス
 */
int	handle_pipe_command(t_ast *node, t_envwrap *env_wrapper)
{
	int	original_stdout_fd;
	int	original_stdin_fd;
	int	status;

	original_stdin_fd = buck_up_fd(STDIN_FILENO);
	original_stdout_fd = buck_up_fd(STDOUT_FILENO);
	if (original_stdout_fd == -1)
		ft_errno_exit("dup");
	status = handle_one_pipe_command(node, env_wrapper);
	recover_fd(original_stdin_fd, STDIN_FILENO);
	recover_fd(original_stdout_fd, STDOUT_FILENO);
	return (status);
}
