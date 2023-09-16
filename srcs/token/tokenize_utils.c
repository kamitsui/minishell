/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:27:47 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/16 12:40:08 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static t_subdiv	tkn_return_subdiv(char const c)
{
	if (c == '"')
		return (doube_quote);
	else if (c == '\'')
		return (singl_equote);
	else if (c == '(')
		return (parenthesis_open);
	else if (c == ')')
		return (parenthesis_close);
	else if (c == ' ')
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
		return (nonclassified);
}

static bool tkn_is_quote(char const c)
{
	if (c == '"' || c == '\'' || c == '(' || c == ')')
		return (true);
	else
		return (false);
}

static bool	tkn_is_metachar(char const c)
{
	if (c == ' ' || c == '\t' || c == '|' || c == '&' || c == '<' || c == '>' || c == '\n' || c == '*')
		return (true);
	else
		return (false);
}

static bool	tkn_is_ctrl_operator(char const c)
{
	if (c == '|' || c == '&' || c == '\n')
		return (true);
	else
		return (false);
}

static bool	tkn_is_redirect_operator(char const c)
{
	if (c == '<' || c == '>')
		return (true);
	else
		return (false);
}

bool	tkn_subdiv_is_metachar(t_subdiv subdiv)
{
	// if (c == ' ' || c == '\t' || c == '|' || c == '&' || c == '<' || c == '>' || c == '\n' || c == '*')
	if (subdiv == space || subdiv == newline || subdiv == ampersand || subdiv == pipe_sign || subdiv == allow_open || subdiv == allow_close || subdiv == astarisk)
		return (true);
	else
		return (false);
}

bool	tkn_subdiv_is_control_operator(t_subdiv subdiv)
{
	// if (c == ' ' || c == '\t' || c == '|' || c == '&' || c == '<' || c == '>' || c == '\n' || c == '*')
	if (subdiv == ampersand || subdiv == pipe_sign)
		return (true);
	else
		return (false);
}

bool	tkn_subdiv_is_redirect_operator(t_subdiv subdiv)
{
	// if (c == ' ' || c == '\t' || c == '|' || c == '&' || c == '<' || c == '>' || c == '\n' || c == '*')
	if (subdiv == allow_open || subdiv == allow_close)
		return (true);
	else
		return (false);
}

//todo void	_undo_to_concat(void *content)

void	_print_list(void *content)
{
	t_token	*token;

	token = content;
	printf("list:[%s](div:%d/sdiv:%d/catidx:%zu)\n", token->word, token->div, token->subdiv, token->concat_idx);
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
	if (tkn_is_quote(c))
		token->div = quote;
	else if (tkn_is_redirect_operator(c))
		token->div = redirect;
	else if (tkn_is_ctrl_operator(c))
		token->div = control;
	else if (tkn_is_metachar(c))
		token->div = metachar;
	else
		token->div = unclassified;
	token->subdiv = tkn_return_subdiv(c);
}
