/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 14:34:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE	100

/**
 * @brief tokenizeで使う構造体
 * <command> or <connector> ごとに１つのtokenとして構造体に格納する。
 */
typedef struct s_token
{
	char	*var;
	int		type;
}	t_token ;

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

// void
///**
// * @brief Double Queue の構造体。
// */
//typedef struct s_deque
//{
//	t_deq_node	*node;
//	int			size;
//}	t_deque;
//
///**
// * @brief １つのコンテンツを持ち、前後のノードアドレスを持つ。
// */
//typedef struct s_deq_node
//{
//	void		content;
//	t_deq_node	*next;
//	t_deq_node	*prev;
//}	t_deq_node;

