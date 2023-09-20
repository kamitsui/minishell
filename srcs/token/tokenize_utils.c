/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:24:03 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/19 15:52:56 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_flg	tkn_assign_flg_to_c(char c)
{
	if (c == '"')
		return (doube_quote);
	else if (c == '\'')
		return (singl_equote);
	else if (c == '(')
		return (parenthesis_open);
	else if (c == ')')
		return (parenthesis_close);
	else if (c == ' ' || c == '\t')
		return (space);
	else if (c == '\n')
		return (newline);
	else if (c == '&')
		return (ampersand);
	else if (c == '|')
		return (pipe_sign);
	else if (c == '<')
		return (allow_open);
	else if (c == '>')
		return (allow_close);
	else if (c == '*')
		return (astarisk);
	else
		return (unclassified);
}

t_flg	tkn_get_closing_flg(t_flg opening_flg)
{
	if (opening_flg == parenthesis_open)
		return (parenthesis_close);
	else
		return (opening_flg);
}
