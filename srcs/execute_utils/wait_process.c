/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:07:43 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 20:57:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wait_process.c
 * @brief コマンドの数分だけコマンド実行プロセスの終了を待ち、
 * 最後の終了ステータスを返す関数
 */
#include <sys/wait.h>

/**
 * @brief コマンドの数分だけコマンド実行プロセスの終了を待ち、
 * 最後の終了ステータスを返す関数
 *
 * @param pid 最後のコマンド実行プロセスID
 * @param num_commands <pipe-command>でつなげるコマンドの数
 *
 * @return 最後のコマンドの終了ステータス
 */
int	wait_process(pid_t pid, int num_commands)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_commands - 1)
	{
		waitpid(-1, &status, 0);
		i++;
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status);
	return (status);
}
