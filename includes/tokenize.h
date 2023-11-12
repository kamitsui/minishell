/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/10 14:05:03 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "libft.h"

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
	allow_read,
	allow_write,
	allow_heredoc,
	allow_append,
	astarisk,
	end,
}	t_flg;

typedef struct s_token
{
	char	*word;
	t_flg	flg;
	int		concat_idx;
}	t_token;

void	_tkn_print_list(void *content);
void	_tkn_delete_list(void *content);
void	_tkn_reassign_flg_to_operator(void *content);
void	_tkn_assign_flg_to_str(void *content);
bool	flg_is_operator(t_flg flg);
bool	flg_is_quote(t_flg div);
t_flg	tkn_assign_flg_to_word(char *s);
t_flg	tkn_get_closing_flg(t_flg opening_flg);
char	**tkn_create_dptrchar_from_list(t_list *cmdlst);
void	tkn_del_one_by_flg(t_list **cmdlst, t_flg del_flg);
t_token	*tkn_create_new_token_by_copy_old(t_token *old);
void	tkn_mark_quote_to_concatinate(t_list *cmdlst);
void	tkn_mark_operators_to_concatinate(t_list *dummyhead);
void	tkn_mark_to_concat_on_flg(t_list *cmdlst, t_flg const to_concat[]);
char	**token_controller(char *cmdline);

#endif
