/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_flg_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:00:38 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 14:17:42 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	tkn_del_one_by_flg(t_list **cmdlst, t_flg del_flg)
{
	t_list	*crnt;
	t_list	*prev;
	t_list	*next;
	t_token	*token;

	crnt = (*cmdlst)->next;
	while (crnt)
	{
		next = crnt->next;
		prev = crnt->prev;
		token = crnt->content;
		if (token->flg == del_flg)
		{
			prev->next = next;
			if (next != NULL)
			next->prev = prev;
			ft_lstdelone(crnt, _tkn_delete_list);
			crnt = NULL;
		}
		crnt = next;
	}
}

t_flg	tkn_get_closing_flg(t_flg opening_flg)
{
	if (opening_flg == parenthesis_open)
		return (parenthesis_close);
	else
		return (opening_flg);
}

static t_flg	tkn_assign_flg_to_word1(char *s)
{
	if (ft_strcmp(s, "\"") == 0)
		return (doube_quote);
	else if (ft_strcmp(s, "\'") == 0)
		return (single_quote);
	else if (ft_strcmp(s, "(") == 0)
		return (parenthesis_open);
	else if (ft_strcmp(s, ")") == 0)
		return (parenthesis_close);
	else if (ft_strcmp(s, " ") == 0 || ft_strcmp(s, "\t") == 0)
		return (space);
	else if (ft_strcmp(s, "\n") == 0)
		return (newline);
	else if (ft_strcmp(s, "&") == 0)
		return (ampersand);
	else if (ft_strcmp(s, "&&") == 0)
		return (double_ampersand);
	else
		return (unclassified);
}

static t_flg	tkn_assign_flg_to_word2(char *s)
{
	if (ft_strcmp(s, "|") == 0)
		return (single_pipe);
	else if (ft_strcmp(s, "||") == 0)
		return (double_pipe);
	else if (ft_strcmp(s, "<") == 0)
		return (allow_read);
	else if (ft_strcmp(s, "<<") == 0)
		return (allow_heredoc);
	else if (ft_strcmp(s, ">") == 0)
		return (allow_write);
	else if (ft_strcmp(s, ">>") == 0)
		return (allow_append);
	else if (ft_strcmp(s, "*") == 0)
		return (astarisk);
	else
		return (unclassified);
}

t_flg	tkn_assign_flg_to_word(char *s)
{
	t_flg const	res_flg1 = tkn_assign_flg_to_word1(s);
	t_flg const	res_flg2 = tkn_assign_flg_to_word2(s);

	if (res_flg1 != unclassified)
	{
		return (res_flg1);
	}
	else if (res_flg2 != unclassified)
	{
		return (res_flg2);
	}	
	else
	{
		return (unclassified);
	}
}
