/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:59:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 07:34:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file execute.h
 * @brief コマンドのノードを実行する時に必要な構造体や関数を定義
 */
#ifndef EXECUTE_H
# define EXECUTE_H

# include "parse.h"
# include "environ.h"

/**
 * @brief pipefd[0]の時に使用
 */
# define READ_END	0

/**
 * @brief pipefd[1]の時に使用
 */
# define WRITE_END	1

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
 * @brief コマンドにPATHを通して実行する関数
 */
void	exec_file(char *file, char *arguments[], char *env[]);
char	*get_substr_env(char *name, char *env[]);
char	*join_path(char const *dir, char const *file);
int		execute_script_file(char *file, t_envwrap *env_wrapper);

/**
 * @brief <simple-command>のノードを実行する関数
 */
int		execute_command(t_ast *command_node, t_envwrap *env_wrapper);
int		execute_builtins_command(t_ast *node, t_envwrap *env_wrapper);

/**
 * @brief <simple-command>のノードからコマンド引数を取り出す関数
 */
void	get_arguments(t_command *commands, t_ast *node);

/**
 * @brief コマンドの数分だけコマンド実行プロセスの終了を待ち、
 */
int		wait_process(pid_t pid, int num_commands);

#endif
