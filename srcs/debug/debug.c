/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/20 20:53:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file debug.c
 * @brief 各データ構造のデバッグ出力　抽象構文木(ast)以外
 */
#include "minishell.h"
#include "execute.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief 文字列をデバッグ出力
 *
 * @param line readline関数で読み込まれた文字列
 */
void	debug_input(char *line)
{
	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- input debug ----\n");
	ft_printf("line %p [%s]\n", line, line);
	ft_printf("\x1B[0m\n\n");
}

/**
 * @brief tokenize関数で生成されたトークンをデバッグ出力
 *
 * @param tokens 複数の文字列要素もつ二次元配列（最後の要素はNULL）
 */
void	debug_token(char **tokens)
{
	int		i;

	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- char *tokens[] ----\n");
	i = 0;
	while (tokens[i] != NULL)
	{
		ft_printf("tokens[%d] %p [%s]\n", i, tokens[i], tokens[i]);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}

/**
 * @brief execute関数内で実行するコマンドの要素をデバッグ出力します。
 *
 * @param command デバッグ対象の
 */
void	debug_command(t_command *command)
{
	int		i;

	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- command ----\n");
	ft_printf("\tcmd_name [%s]\n", command->cmd_name);
	ft_printf("\t");
	i = 0;
	ft_printf("args");
	while (command->args[i] != NULL)
	{
		ft_printf(" [%s]", command->args[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\tnum_args [%d]\n", command->num_args);
	ft_printf("\n");
	i = 0;
	ft_printf("\tenv [%s]\n", command->env[i]);
	while (command->env[i] != NULL)
	{
		ft_printf("\t    [%s]\n", command->env[i]);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}
