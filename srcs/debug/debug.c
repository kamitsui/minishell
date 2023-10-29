/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/28 22:04:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file debug.c
 * @brief 各データ構造のデバッグ出力　抽象構文木(ast)以外
 */
//#include "minishell.h"
//#include "execute.h"
//#include "ft_printf.h"
//#include "libft.h"
//#include <stdlib.h>
//
////デバッグ用
//#include "debug.h"
//
//void	enable_debug(int flag)
//{
//	g_flag_debug = flag;
//	if (g_flag_debug == DEBUG_ON)
//		g_fd_log = open_log("debug.log", O_TRUNC);
//}
//
///**
// * @brief 文字列をデバッグ出力
// *
// * @param line readline関数で読み込まれた文字列
// */
//void	debug_input(char *line)
//{
//	if (g_flag_debug == DEBUG_OFF)
//		return ;
//	ft_dprintf(g_fd_log, "%s---- input debug ----\n", DEBUG_COLOR);
//	ft_dprintf(g_fd_log, "line %p [%s]\n", line, line);
//}
//
///**
// * @brief tokenize関数で生成されたトークンをデバッグ出力
// *
// * @param tokens 複数の文字列要素もつ二次元配列（最後の要素はNULL）
// */
//void	debug_token(char **tokens)
//{
//	int	i;
//
//	if (g_flag_debug == DEBUG_OFF)
//		return ;
//	ft_dprintf(g_fd_log, "%s---- char *tokens[] ----\n", DEBUG_COLOR);
//	i = 0;
//	while (tokens[i] != NULL)
//	{
//		ft_dprintf(g_fd_log, "tokens[%d] %p [%s]\n", i, tokens[i], tokens[i]);
//		i++;
//	}
//	ft_dprintf(g_fd_log, "\n\n");
//}
//
//void	debug_env_two_darray(char **tokens)
//{
//	int		i;
//
//	ft_dprintf(g_fd_log, "%s---- char *env[] ----\n", DEBUG_COLOR);
//	i = 0;
//	while (tokens[i] != NULL)
//	{
//		ft_dprintf(g_fd_log, "env[%d] %p [%s]\n", i, tokens[i], tokens[i]);
//		i++;
//	}
//	ft_dprintf(g_fd_log, "\n\n");
//}
//
///**
// * @brief execute関数内で実行するコマンドの要素をデバッグ出力します。
// *
// * @param command デバッグ対象の
// */
//void	debug_command(t_command *command)
//{
//	int		i;
//
//	ft_dprintf(g_fd_log, "%s---- command ----\n", DEBUG_COLOR);
//	ft_dprintf(g_fd_log, "\tcmd_name [%s]\n", command->cmd_name);
//	ft_dprintf(g_fd_log, "\t");
//	i = 0;
//	ft_dprintf(g_fd_log, "args");
//	while (command->args[i] != NULL)
//	{
//		ft_dprintf(g_fd_log, " [%s]", command->args[i]);
//		i++;
//	}
//	ft_dprintf(g_fd_log, "\n");
//	ft_dprintf(g_fd_log, "\tnum_args [%d]\n", command->num_args);
//	ft_dprintf(g_fd_log, "\n");
//	i = 0;
//	ft_dprintf(g_fd_log, "\tenv [%s]\n", command->env[i]);
//	while (command->env[i] != NULL)
//	{
//		ft_dprintf(g_fd_log, "\t    [%s]\n", command->env[i]);
//		i++;
//	}
//	ft_dprintf(g_fd_log, "\n\n");
//}
