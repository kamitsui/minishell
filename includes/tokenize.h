/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/19 13:32:34 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include <readline/history.h>
# include <readline/readline.h>
// # include <stdbool.h>
// # include <stdlib.h>
# include "libft.h"

typedef enum e_flg
{
	unclassified,
	doube_quote,
	singl_equote,
	parenthesis_open,
	parenthesis_close,
	space,
	newline,
	ampersand,
	pipe_sign,
	allow_open,
	allow_close,
	astarisk,
}	t_flg;

typedef struct s_token
{
	char	*word;
	t_flg	flg;
	size_t	concat_idx;
}	t_token;

//* lstiter関数の関数ポインタ引数として渡される関数類
void	_tkn_print_list(void *content);//! debug purpose so to be deleted
void	_tkn_delete_list(void *content);
void	_tkn_assign_division_to_list(void *content);

//* tokenizeユーティリティ関数類
bool	flg_is_metachar(t_flg div);
bool	flg_is_control(t_flg div);
bool	flg_is_redirect(t_flg div);
bool	flg_is_operator(t_flg flg);
bool	flg_is_quote(t_flg div);
t_flg	tkn_assign_flg_to_c(char c);
t_flg	tkn_get_closing_flg(t_flg opening_flg);

//* tokenizeマーカー
void	tkn_mark_quote_to_concatinate(t_list *cmdlst, size_t *concat_id);
size_t	tkn_mark_normal_words_to_concatinate(t_list *cmdlist, size_t concat_id);
size_t	tkn_mark_operators_to_concatinate(t_list *crnt, size_t concat_id);

#endif