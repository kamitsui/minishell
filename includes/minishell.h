/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 18:32:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file minishell.h
 * @brief minishellのmain関数で使う関数、マクロを定義
 */
#ifndef MINISHELL_H
# define MINISHELL_H

# include "environ.h"

/**
 * @brief 文字列操作用のバッファサイズ
 * @detail
 * 使用関数：convert_env_wrap, get_value.c
 */
# define BUFF_SIZE	1024

typedef struct s_string
{
	char			buffer[BUFF_SIZE];
	size_t			len;
	char			*out;
	size_t			out_len;
}	t_string;

/**
 * @brief プロンプトに出力する文字列
 */
# define PROMPT			"minishell> "

/**
 * @brief AST構造体の先頭ノード作成時に使う文字列
 */
# define PROGRAM_NAME	"minishell"

/**
 * @brief mainからで使う関数
 */
int			input(t_envwrap *env_wrapper);

/**
 * @brief readlineで得た文字列をトークン分けする関数
 */
char		**tkn_controller(char const *raw_cmds);

t_envwrap	*create_env_list(char **environ);

#endif
