/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:16:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 07:45:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute_command.c
 * @brief <simple-command>のノードを実行する関数
 */
#include "error_minishell.h"
#include "parse.h"
#include "execute.h"
#include "tokenize.h"
#include "ft_printf.h"
#include "ft_signal.h"
#include "free_minishell.h"
#include <unistd.h>
#include <signal.h>

/**
 * @brief ヘルパー関数：ファイルの実行　存在しなければエラー出力とexit(127)
 *
 * @param command 実行ファイルの構造体
 */
static void	child_process(t_command command)
{
	char		*file;
	t_sigaction	sa_int;
	t_sigaction	sa_quit;

	signal_initializer(&sa_int, SIGINT, HANDLE_EXIT_SIGNUM);
	signal_initializer(&sa_quit, SIGQUIT, HANDLE_NORMAL);
	file = command.args[0];
	exec_file(file, command.args, command.env);
	ft_dprintf(STDERR_FILENO,
		"%s: %s: command not found\n", PROGRAM_NAME, file);
	exit (127);
}

/**
 * @brief <simple-command>のノードを実行する関数
 *
 * @param command_node 実行させるノード
 * @param env 環境変数
 * @param status １つ前のノードの終了ステータス
 *
 * @return 自身のノードで実行したコマンドの終了ステータスを返す
 */
int	execute_command(t_ast *command_node, t_envwrap *env_wrapper)
{
	t_command	command;
	pid_t		pid;

	if (command_node->type != NODE_EXECUTABLE)
		return (-1);
	command.cmd_name = command_node->value;
	get_arguments(&command, command_node);
	command.env = convert_env_list_to_two_darray(env_wrapper->env->next);
	if (command.env == NULL)
	{
		ft_dprintf(STDERR_FILENO, "environ variable is empty\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
	if (pid == 0)
		child_process(command);
	free(command.args);
	free_two_darray(command.env);
	return (wait_process(pid, 1));
}
