/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:06:24 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/20 22:28:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file debug.h
 * @brief 各種デバッグ関数を使用するための関数宣言
 */
#ifndef DEBUG_H
# define DEBUG_H

# include "tokenize.h"
# include "parse.h"
# include "execute.h"

/**
 * @brief 文字列をデバッグ出力
 */
void	debug_input(char *line);

/**
 * @brief tokenize関数で生成されたトークンをデバッグ出力
 */
void	debug_token(char **tokens);

/**
 * @brief parse関数で生成されたASTをデバッグ出力\n
 * 全てのノードと子ノードをデバッグ出力する
 */
void	debug_ast(t_ast *ast);

/**
 * @brief execute関数内で実行するコマンドの要素をデバッグ出力
 */
void	debug_command(t_command *command);

#endif
