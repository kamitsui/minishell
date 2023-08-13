/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/13 17:44:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// token->type に
# define TOK_CONNECT	0x00000001
# define TOK_CON_AND	0x00000002
# define TOK_CON_OR		0x00000004
//# define TOK_			0x00000008
# define TOK_COMMAND	0x00000010
# define TOK_SIMPLE_COM	0x00000020
# define TOK_PIPE_COM	0x00000040
//# define TOK_			0x00000080
# define TOK_IO_REDIR	0x00000100
# define TOK_IN_REDIR	0x00000200
# define TOK_OUT_REDIR	0x00000400
# define TOK_FILE		0x00000800
# define TOK_DQUOTED	0x00001000
# define TOK_SQUOTED	0x00002000
# define TOK_VAR		0x00004000

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
char	**input(char **line);
void	line_free(char **line);
//char	*input(void);
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

