/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 14:59:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE	100

# include "tokenize.h"

# define PROMPT			"minishell> "
# define PROGRAM_NAME	"minishell"

/**
 * @brief 環境変数のハッシュテーブル（未実装）
 */
//typedef struct s_hash
//{
//	char			*key;
//	char			*value;
//	struct s_hash	*next;
//}	t_hash;

/**
 * @brief 実行や展開の時に必要なデータ構造 (未実装)
 */
//typedef struct s_data
//{
//	t_hash	*env;
//	char	*current_dir;
//// ...追加していくかも。。。
//}	t_data;

/**
 * @brief mainからで使う関数
 */
void	input(char **line, char **env);
void	free_line(char **line);

#endif
