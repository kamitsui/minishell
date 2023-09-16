/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/16 21:00:28 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum e_division
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
}	t_division;

typedef struct s_token
{
	char		*word;
	// t_div		div;
	t_division	division;
	size_t		concat_idx;
}	t_token;


//* lstiter関数の関数ポインタ引数として渡される関数類
void	_print_list(void *content);
void	_delete_list(void *content);
void	_assign_div_and_subdiv(void *content);

//* tokenizeユーティリティ関数類
// static bool tkn_is_quote(char const c);
// static bool	tkn_is_metachar(char const c);
// static bool	tkn_is_ctrl_operator(char const c);
// static bool	tkn_is_redirect_operator(char const c);
bool	tkn_div_is_metachar(t_division div);
bool	tkn_div_is_control_operator(t_division div);
bool	tkn_div_is_redirect_operator(t_division div);
bool	tkn_div_is_quote(t_division div);

#endif