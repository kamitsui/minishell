/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/03 14:58:40 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

//# include <readline/history.h>// compile error by kamitsui
//# include <readline/readline.h>// compile error by kamitsui
// # include <stdbool.h>
// # include <stdlib.h>
# include "libft.h"
# include "environ.h"

typedef enum e_flg
{
	unclassified,
	doube_quote,
	single_quote,
	parenthesis_open,
	parenthesis_close,
	space,
	newline,
	ampersand,
	double_ampersand,
	single_pipe,
	double_pipe,
	allow_open,
	allow_close,
	astarisk,
	end, 
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
void	_tkn_assign_flg_to_list(void *content);
void	_tkn_reassign_flg_to_operator(void *content);

//* tokenizeユーティリティ関数類
bool	flg_is_metachar(t_flg div);
bool	flg_is_control(t_flg div);
bool	flg_is_redirect(t_flg div);
bool	flg_is_operator(t_flg flg);
bool	flg_is_quote(t_flg div);
t_flg	tkn_assign_flg_to_c(char c);
t_flg	tkn_get_closing_flg(t_flg opening_flg);
char	**tkn_create_dptrchar_from_list(t_list *cmdlst);
void	tkn_del_one_on_flg(t_list **cmdlst, t_flg del_flg);
t_token	*tkn_create_new_token_by_copy_old(t_token *old);

//* tokenizeマーカー
void	tkn_mark_quote_to_concatinate(t_list *cmdlst, size_t *concat_id);
// size_t	tkn_mark_normal_words_to_concatinate(t_list *cmdlist, size_t concat_id);
size_t	tkn_mark_operators_to_concatinate(t_list *crnt, size_t concat_id);
size_t	tkn_mark_to_concat_for_flg(t_list *cmdlst, size_t idx, t_flg *to_concat);

//* expansion
int		tkn_expansion_handler(t_list *cmdlst, t_envwrap *env_wrap);

#endif
