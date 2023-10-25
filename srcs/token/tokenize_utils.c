/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:24:03 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/25 14:25:21 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

// t_flg	tkn_assign_flg_to_c(char c)
// {
// 	if (c == '"')
// 		return (doube_quote);
// 	else if (c == '\'')
// 		return (single_quote);
// 	else if (c == '(')
// 		return (parenthesis_open);
// 	else if (c == ')')
// 		return (parenthesis_close);
// 	else if (c == ' ' || c == '\t')
// 		return (space);
// 	else if (c == '\n')
// 		return (newline);
// 	else if (c == '&')
// 		return (ampersand);
// 	else if (c == '|')
// 		return (single_pipe);
// 	else if (c == '<')
// 		return (allow_read);
// 	else if (c == '>')
// 		return (allow_write);
// 	else if (c == '*')
// 		return (astarisk);
// 	else
// 		return (unclassified);
// }

const t_flg	tkn_assign_flg_to_word1(char *s)
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

const t_flg	tkn_assign_flg_to_word2(char *s)
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

t_flg	tkn_get_closing_flg(t_flg opening_flg)
{
	if (opening_flg == parenthesis_open)
		return (parenthesis_close);
	else
		return (opening_flg);
}

t_token	*tkn_create_new_token_by_copy_old(t_token *old_tkn)
{
	t_token	*new_tkn;

	if (old_tkn == NULL)
		return (NULL);
	new_tkn = ft_calloc(1, sizeof(t_token));
	if (new_tkn == NULL)
	{
		return (NULL);
	}
	new_tkn->word = ft_strdup(old_tkn->word);
	if (new_tkn->word == NULL)
	{
		free (new_tkn);
		new_tkn = NULL;
		return (NULL);
	}
	new_tkn->concat_idx = old_tkn->concat_idx;
	new_tkn->flg = old_tkn->flg;
	return (new_tkn);
}

char	**tkn_create_dptrchar_from_list(t_list *cmdlst)
{
	char		**cmdlines;
	t_list		*crnt;
	t_token		*tkn;
	int const	lstsize = ft_lstsize(cmdlst);
	int			i;

	if (cmdlst == NULL)
		return (NULL);
	cmdlines = ft_calloc(lstsize + 1, sizeof(char *));
	if (cmdlines == NULL)
		return (NULL);//todo error handle
	crnt = cmdlst;
	i = 0;
	while (i < lstsize)
	{
		tkn = crnt->content;
		cmdlines[i] = ft_strdup(tkn->word);
		crnt = crnt->next;
		i++;
	}
	cmdlines[i] = NULL;
	return (cmdlines);
}

// void	tkn_del_one_on_flg(t_list **cmdlst, t_flg del_flg)
// {
// 	t_list	*dummy;
// 	t_list	*crnt;
// 	t_list	*next;

// 	dummy = ft_lstnew(NULL);
// 	ft_lstadd_front(cmdlst, dummy);
// 	crnt = dummy->next;
// 	while (crnt)
// 	{
// 		next = crnt->next;
// 		if (((t_token *)(crnt->content))->flg == del_flg)
// 		{
// 			crnt->prev->next = next;
// 			if (crnt->next != NULL)
// 				next->prev = crnt->prev;
// 			ft_lstdelone(crnt, _tkn_delete_list);
// 			crnt = NULL;
// 		}
// 		crnt = next;
// 	}
// 	*cmdlst = dummy->next;
// 	if (dummy->next != NULL)
// 		dummy->next->prev = *cmdlst;
// 	ft_lstdelone(dummy, _tkn_delete_list);
// }

void   tkn_del_one_by_flg(t_list **cmdlst, t_flg del_flg)
{
	t_list  *crnt;
	t_list  *prev;
	t_list	*next;
	t_token *token;

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
