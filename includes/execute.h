/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:59:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/20 23:08:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute.h
 * @brief コマンドのノードを実行する時に必要な構造体や関数を定義
 */
#ifndef EXECUTE_H
# define EXECUTE_H

# include "parse.h"

/**
 * @struct s_command
 * @brief コマンド１つ毎に持つ構造体
 * @details
 * cmd_name:実行対象のコマンド(PATHを通す前)\n
 * args:コマンドとコマンド引数を要素にもつ二次元配列（最後の要素はNULL）\n
 * num_args:コマンド引数の要素数\n
 * env:環境変数
 */
typedef struct s_command
{
	char	*cmd_name;
	char	**args;
	int		num_args;
	char	**env;
}	t_command;

/**
 * @struct s_cmdstack
 * @brief スタック構造体：パイプコマンドで実行させる複数のコマンド構造体
 * @details
 * commands[]:構造体の配列。順番に実行するコマンドを格納する\n
 * num_commands:パイプで繋げるコマンドの数\n\n
 * 例\n
 * ls -a | cat -e | grep "Makefile"
 *
 */
typedef struct s_cmdstack
{
	t_command	commands[MAX_SIZE];
	int			num_commands;
}	t_cmdstack;

/**
 * @brief コマンドのスタック構造のバッファサイズ
 */
# define MAX_SIZE 32

/**
 * @brief pipefd[0]の時に使用
 */
# define READ_END	0

/**
 * @brief pipefd[0]の時に使用
 */
# define WRITE_END	1

/**
 * @brief コマンドにPATHを通して実行する関数
 */
void	exec_file(char *file, char *arguments[], char *env[]);

/**
 * @brief <simple-command>のノードを実行する関数
 */
int		execute_command(t_ast *command_node, char **env, int status);
void	get_arguments(t_command *commands, t_ast *node);
int		wait_process(pid_t pid, int num_commands);

int		execute_pipeline(t_ast **commands, size_t num_commands, char **env);
void	set_cmd_stack(t_cmdstack *cmdstack,
			t_ast **commands, size_t num_commands);
void	set_environ(t_cmdstack *cmdstack, char **env);

#endif
