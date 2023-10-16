/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:45:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/15 16:14:09 by kamitsui         ###   ########.fr       */
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

/**
 *
 * @param pipe_node パイプのノード
 * @param env 環境変数
 * @param status １つ前のノードの終了ステータス
 *
 * @return パイプコマンドの終了ステータス
 */
int	handle_pipe_command(t_ast *pipe_node, t_envwrap *env_wrapper)
{
	int	original_stdout_fd;
	int	original_stdin_fd;
	int	status;

	original_stdin_fd = buck_up_fd(STDIN_FILENO);
	original_stdout_fd = buck_up_fd(STDOUT_FILENO);
	if (original_stdout_fd == -1)
		ft_errno_exit("dup");
	status = execute_pipeline(
			pipe_node->children, pipe_node->num_children, env_wrapper);
	recover_fd(original_stdin_fd, STDIN_FILENO);
	recover_fd(original_stdout_fd, STDOUT_FILENO);
	return (status);
}
//{
//	pid_t	pid;
//
//	pid = fork();
//	if (pid == 0)
//		execute_pipeline(pipe_node->children,
//					pipe_node->num_children, env_wrapper);
//	waitpid(pid, &status, 0);
//	if (WIFEXITED(status))
//		env_wrapper->exit_code = WEXITSTATUS(status);
//	else if (WIFSIGNALED(status))
//		env_wrapper->exit_code = WTERMSIG(status);
//	return (env_wrapper->exit_code);
//}
