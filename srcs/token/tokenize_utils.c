/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:24:03 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/22 13:59:53 by mogawa           ###   ########.fr       */
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

char	**tkn_create_dptrchar_from_list(t_list *cmdlst)
{
	char		**cmdlines;
	t_list		*crnt;
	t_token		*tkn;
	const int	lstsize = ft_lstsize(cmdlst);
	int			i;

	if (cmdlst == NULL)
		return (NULL);
	cmdlines = ft_calloc(lstsize + 1, sizeof(char *));
	if (cmdlines == NULL)
		return (NULL);//todo error handle
	i = 0;
	crnt = cmdlst;
	while (i < lstsize)
	{
		tkn = crnt->content;
		cmdlines[i] = ft_strdup(tkn->word);
		crnt = crnt->next;
		i++;
	}
	cmdlines[i] = NULL;
	//todo need to free cmdlst;
	return (cmdlines);
}

void	tkn_del_one_on_flg(t_list **cmdlst, t_flg del_flg)
{
	t_list	*dummy;
	t_list	*crnt;
	t_list	*next;

	dummy = ft_lstnew(NULL);
	ft_lstadd_front(cmdlst, dummy);
	crnt = dummy->next;
	while (crnt)
	{
		next = crnt->next;
		if (((t_token *)(crnt->content))->flg == del_flg)
		{
			crnt->prev->next = crnt->next;
			if (crnt->next != NULL)
				crnt->next->prev = crnt->prev;
			ft_lstdelone(crnt, _tkn_delete_list);
			crnt = NULL;
		}
		crnt = next;
	}
	*cmdlst = dummy->next;
	if (dummy->next != NULL)
		dummy->next->prev = *cmdlst;
	ft_lstdelone(dummy, _tkn_delete_list);
}
