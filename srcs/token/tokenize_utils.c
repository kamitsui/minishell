/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:27:47 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/16 20:39:58 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static t_division tkn_return_subdiv(char const c)
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

bool	tkn_div_is_metachar(t_division div)
{
	if (div == space || div == newline || div == ampersand || div == pipe_sign || div == allow_open || div == allow_close || div == astarisk)
		return (true);
	else
		return (false);
}

bool	tkn_div_is_control_operator(t_division div)
{
	if (div == ampersand || div == pipe_sign)
		return (true);
	else
		return (false);
}

bool	tkn_div_is_redirect_operator(t_division div)
{
	if (div == allow_open || div == allow_close)
		return (true);
	else
		return (false);
}

bool	tkn_div_is_quote(t_division div)
{
	if (div == doube_quote || div == singl_equote || div == parenthesis_open || div == parenthesis_close)
		return (true);
	else
		return (false);
}

void	_print_list(void *content)
{
	t_token	*token;

	token = content;
	printf("list:[%s](div:%d/catidx:%zu)\n", token->word, token->division, token->concat_idx);
}

void	_delete_list(void *content)
{
	t_token	*token;

	token = content;
	free(token->word);
	token->word = NULL;
	free(token);
	token = NULL;
}

void	_assign_div_and_subdiv(void *content)
{
	t_token	*token;
	char	c;

	token = content;
	c = token->word[0];
	token->division = tkn_return_subdiv(c);
}
