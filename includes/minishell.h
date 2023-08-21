/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 16:42:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file minishell.h
 * @brief minishellのmain関数で使う関数、マクロを定義
 */
#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * @brief readlineで読み取った文字列の格納先のバッファサイズ
 */
# define BUFFER_SIZE	100

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
int		input(char **line, char **env);

#endif
//
///**
// * @brief 環境変数のハッシュテーブル（未実装）
// */
//typedef struct s_hash
//{
//	char			*key;
//	char			*value;
//	struct s_hash	*next;
//}	t_hash;
//
///**
// * @brief 実行や展開の時に必要なデータ構造 (未実装)
// */
//typedef struct s_data
//{
//	t_hash	*env;
//	char	*current_dir;
//// ...追加していくかも。。。
//}	t_data;
