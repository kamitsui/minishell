/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 22:47:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE	100

#include "tokenize.h"

# define PROMPT			"minishell> "
# define PROGRAM_NAME	"minishell"

/**
 * @brief 環境変数のハッシュテーブル
 */
typedef struct s_hash
{
	char			*key;
	char			*value;
	struct s_hash	*next;
}	t_hash;

/**
 * @brief 実行や展開の時に必要なデータ構造
 */
typedef struct s_data
{
	t_hash	*env;
	char	*current_dir;
	// ...追加していくかも。。。
}	t_data;


/**
 * @brief minishellで使う関数
 */
void	input(char **line);
t_token	*tokenize(char *line);
void	free_line(char **line);
void	free_tokens(t_token *tokens);

#endif
