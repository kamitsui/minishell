/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:16:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/26 00:02:13 by kamitsui         ###   ########.fr       */
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
#include <unistd.h>
#include <signal.h>

// for debug
#include "debug.h"

/**
 * @brief ヘルパー関数：ファイルの実行　存在しなければエラー出力とexit(127)
 *
 * @param command 実行ファイルの構造体
 */
static void	child_process(t_command command)
{
	char	*file;

	file = command.args[0];
	if (is_pipe(file) == true)
		handle_syntax_error(file, SIGINT);
	else
	{
		exec_file(file, command.args, command.env);
		ft_dprintf(STDERR_FILENO, "%s: %s: command not found\n", NAME, file);
		exit (127);
	}
}

static void	sigint_handler_execute(int signum)
{
	(void)signum;
	exit (SIGINT);
}

/**
 * @brief <simple-command>のノードを実行する関数
 *
 * @param command_node 実行させるノード
 * @param env 環境変数
 * @param status １つ前のノードの終了ステータス
 *
 * @return 自身のノードで実行したコマンドの終了ステータスを返す
 * @note 関数単体のテストあり\n
 * cd minishell/test/unit_function\n
 * make 4\n
 * make run4\n\n
 * デバッグコードあり\n
 * \#include "debug.h"\n
 * debug_command(&command);
 */
int	execute_command(t_ast *command_node, t_envwrap *env_wrapper)
{
	t_command	command;
	pid_t		pid;
	struct sigaction	sa_int;

	sa_int.sa_handler = sigint_handler_execute;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);

	if (command_node->type != NODE_EXECUTABLE)
		return (-1);
	command.cmd_name = command_node->value;
	get_arguments(&command, command_node);
	command.env = convert_env_list_to_two_darray(env_wrapper->env->next);
	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
	if (pid == 0)
		child_process(command);
	free(command.args);
	free_two_darray(command.env);
	debug_leaks("execute_command", "minishell");// debug
	return (wait_process(pid, 1));
}
//	debug_env_two_darray(command.env);// debug
//	debug_command(&command);// debug
//	debug_leaks("execute_command", "minishell");// debug
