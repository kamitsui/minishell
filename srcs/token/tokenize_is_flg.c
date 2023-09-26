/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_is_flg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:27:47 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/26 13:23:43 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

bool	flg_is_metachar(t_flg flg)
{
	if (flg == space || \
		flg == newline || \
		flg == ampersand || \
		flg == single_pipe || \
		flg == allow_open || \
		flg == allow_close || \
		flg == astarisk)
	{
		return (true);
	}
	else
		return (false);
}

bool	flg_is_control(t_flg flg)
{
	if (flg == ampersand || flg == single_pipe)
		return (true);
	else
		return (false);
}

bool	flg_is_redirect(t_flg flg)
{
	if (flg == allow_open || flg == allow_close)
		return (true);
	else
		return (false);
}

bool	flg_is_operator(t_flg flg)
{
	if (flg_is_control(flg) || flg_is_redirect(flg))
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