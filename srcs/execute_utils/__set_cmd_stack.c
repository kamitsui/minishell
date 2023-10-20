/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:17:11 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 20:21:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file set_cmd_stack.c
 * @brief <pipe-command>のノードからスタック構造体へデータを取り出す関数
 */
#include "parse.h"
#include "execute.h"

/**
 * @brief <pipe-command>の全ての子ノードからデータを取り出す関数。
 * コマンドの数分だけスタック構造体に格納場所を確保し、
 * 各コマンドのデータ（コマンド構造体）を取り出す。
 *
 * @param cmdstack スタック構造体（複数コマンドのデータが入る）
 * @param commands <pipe-command>の子ノード
 * @param num_commands <pipe-command>でつなげるコマンドの数
 */
void	set_cmd_stack(t_cmdstack *cmdstack, t_ast **commands,
		size_t num_commands, t_envwrap *env_wrapper)
{
	size_t	i;

	cmdstack->num_commands = num_commands;
	i = 0;
	while (i < num_commands)
	{
		//cmdstack->commands[i].cmd_name = expansion(commands[i]->value);// 仮
		// word split のexpansionについては要検討！
		cmdstack->commands[i].cmd_name = commands[i]->value;
		get_arguments(&(cmdstack->commands[i]), commands[i]);
		i++;
	}
	(void)env_wrapper;// expansion実装すればこの行は不要になる
}

/**
 * @brief <pipe-command>の全てのコマンド構造体へ環境変数をセットする関数
 *
 * @param cmdstack スタック構造体
 * @param env 環境変数
 */
void	set_environ(t_cmdstack *cmdstack, t_envwrap *env_wrapper)
{
	int		i;
	char	**env;

	env = convert_env_list_to_two_darray(env_wrapper->env->next);
	i = 0;
	while (i < cmdstack->num_commands)
	{
		cmdstack->commands[i].env = env;
		i++;
	}
}
