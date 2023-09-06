/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/06 18:02:19 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <readline/history.h>
#include <readline/readline.h>
#include "libft.h"

typedef enum e_div
{
	unclassified,
	quote,
	metachar,
	redirect,
	control,
}	t_div;

typedef enum e_subdiv
{
	nonclassified,
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
}	t_subdiv;

typedef struct s_token
{
	char		*word;
	t_div		div;
	t_subdiv	subdiv;
	bool		to_concat;
}	t_token;


//* lstiter関数の関数ポインタ引数として渡される関数類
void	_print_list(void *content);
void	_delete_list(void *content);
void	_assign_divs_list(void *content);

//* tokenizeユーティリティ関数類
static bool tkn_is_quote(char const c);
static bool	tkn_is_metachar(char const c);
static bool	tkn_is_ctrl_operator(char const c);
static bool	tkn_is_redirect_operator(char const c);

#endif