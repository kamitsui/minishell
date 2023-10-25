/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_is_flg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:27:47 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/25 14:02:42 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

//todo check which flg_func is in use to remove unused.

bool	flg_is_metachar(t_flg flg)
{
	if (flg == space || \
		flg == newline || \
		flg == ampersand || \
		flg == single_pipe || \
		flg == allow_read || \
		flg == allow_write || \
		flg == astarisk)
	{
		return (true);
	}
	else
		return (false);
}

// bool	flg_is_control(t_flg flg)
// {
// 	if (flg == ampersand || flg == single_pipe)//!double ampersand?
// 		return (true);
// 	else
// 		return (false);
// }

bool	flg_is_redirect(t_flg flg)
{
	if (flg == allow_read || flg == allow_write)
		return (true);
	else if (flg == allow_append || flg == allow_heredoc)
		return (true);
	else
		return (false);
}

bool	flg_is_cmd_divider(t_flg flg)
{
	if (flg == double_ampersand || flg == double_pipe || flg == single_pipe)
		return (true);
	else
		return (false);
}

bool	flg_is_join_operator(t_flg flg)
{
	if (flg == ampersand || flg == single_pipe)
		return (true);
	else if (flg == allow_read || flg == allow_write)
		return (true);
	else
		return (false);
}

bool	flg_is_operator(t_flg flg)//todo should change name to describe the func.
{
	if (flg == ampersand || flg == single_pipe)
		return (true);
	else if (flg == allow_read || flg == allow_write)
		return (true);
	else
		return (false);
}

bool	flg_is_quote(t_flg flg)
{
	if (flg == doube_quote || \
		flg == single_quote || \
		flg == parenthesis_open || \
		flg == parenthesis_close)
	{
		return (true);
	}
	else
		return (false);
}

// static bool tkn_is_quote(char const c)
// {
// 	if (c == '"' || c == '\'' || c == '(' || c == ')')
// 		return (true);
// 	else
// 		return (false);
// }

// static bool	tkn_is_metachar(char const c)
// {
// 	if (c == ' ' || c == '\t' || c == '|' || c == '&' || c == '<' || c == '>' || c == '\n' || c == '*')
// 		return (true);
// 	else
// 		return (false);
// }

// static bool	tkn_is_ctrl_operator(char const c)
// {
// 	if (c == '|' || c == '&' || c == '\n')
// 		return (true);
// 	else
// 		return (false);
// }

// static bool	tkn_is_redirect_operator(char const c)
// {
// 	if (c == '<' || c == '>')
// 		return (true);
// 	else
// 		return (false);
// }