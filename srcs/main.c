/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:41:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 17:27:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief minishellの入口　環境変数のデータをinput関数へ渡して、
 * minishell終了時は最後のコマンドを終了ステータスに返す
 */
#include "minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"

/**
 * @brief minishellの入口　環境変数のデータをinput関数へ渡して、
 * minishell終了時は最後のコマンドを終了ステータスに返す
 *
 * @param argc コマンドライン引数の個数。
 * @param argv[] コマンドライン引数の文字列。
 * @param env[] 環境変数。
 *
 * @return minishellで実行された最後のコマンドの終了ステータスを返す
 * @note 終了ステータスの返す処理は未実装
 */
int	main(int argc, char *argv[], char *env[])
{
	char	*line[100];

	if (argc != 1)
		error_code(ERR_ARG);
	input(line, env);
	(void)argv[argc];
	(void)env[0];
	system("leaks minishell");
	return (0);
}
