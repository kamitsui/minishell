/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:39:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 20:56:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_pipeline.c
 * @brief <pipe-command>のノードを実行する関数
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_printf.h"
#include "error_minishell.h"
#include "execute.h"
#include "parse.h"

/**
 * @brief コマンドを実行する関数
 *
 * @param command 実行させるコマンドの構造体
 * @param pipefd[2] プロセス間通信用のパイプfd
 * @param i 現在のコマンドの位置
 * @param num_commands <pipe-command>のコマンド数
 */
static void	child_process(t_command command, int pipefd[2], int i,
		int num_commands)
{
	char	*file;

	file = command.args[0];
	close(pipefd[READ_END]);
	if (i < num_commands - 1)
	{
		if (dup2(pipefd[WRITE_END], STDOUT_FILENO) == -1)
		{
			close(pipefd[WRITE_END]);
			ft_errno_exit("dup2");
		}
	}
	close(pipefd[WRITE_END]);
	exec_file(file, command.args, command.env);
	ft_fprintf(STDERR_FILENO, "%s: %s: command not found\n", NAME, file);
	exit (127);
}

/**
 * @brief ヘルパー関数：次のコマンド用プロセスのために、パイプ入力を標準入力に複製する。
 *
 * @param pipefd[2] プロセス通信用のパイプfd
 */
static void	parent_process(int pipefd[2])
{
	close(pipefd[WRITE_END]);
	if (dup2(pipefd[READ_END], STDIN_FILENO) == -1)
	{
		close(pipefd[READ_END]);
		ft_errno_exit("dup2");
	}
	return ;
}

/**
 * @brief コマンド実行用のプロセスを作る関数
 *
 * @param cmdstack コマンド実行プロセスに渡す構造体
 * @param pipefd プロセス間通信用のパイプfd
 * @param i 現在のコマンドの位置
 * @param num_commands <pipe-command>のコマンド数
 *
 * @return pid コマンド実行用のプロセスID
 */
pid_t	create_process(t_cmdstack *cmdstack, int *pipefd,
		int i, int num_commands)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
	else if (pid == 0)
		child_process(cmdstack->commands[i], pipefd, i, num_commands);
	else
		parent_process(pipefd);
	return (pid);
}

/**
 * @brief <pipe-command>を実行する関数
 *
 * @param commands <pipe-command>のノード
 * @param num_commands パイプでつなげるコマンドの数
 * @param env 環境変数
 * @note デバッグコードあり\n
 * \#include "debug.h"//for debug\n
 * debug_token(cmd_args);\n
 *
 * @return 最後のコマンドの終了ステータス
 */
int	execute_pipeline(t_ast **commands, size_t num_commands, char **env)
{
	int			pipefd[2];
	int			i;
	pid_t		pid;
	t_cmdstack	cmdstack;

	set_cmd_stack(&cmdstack, commands, num_commands);
	set_environ(&cmdstack, env);
	i = 0;
	while (i < cmdstack.num_commands)
	{
		if (cmdstack.commands[i].args == NULL)
			ft_perror_exit("ft_split");
		if (pipe(pipefd) == -1)
			ft_perror_exit("pipe");
		pid = create_process(&cmdstack, pipefd, i, cmdstack.num_commands);
		free(cmdstack.commands[i].args);
		i++;
	}
	exit (wait_process(pid, cmdstack.num_commands));
}
// how to test this function
// |
// cd minishell/test/unit_function
// make 1
// make run1
