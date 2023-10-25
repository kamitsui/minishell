/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_markers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:13:43 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/25 14:02:09 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"

//todo need to separate the func to meet norm.
void	tkn_mark_quote_to_concatinate(t_list *cmdlst)
{
	t_token	*token;
	bool	to_join;
	t_flg	opening_flg;
	t_flg	closing_flg;
	size_t	i;

	i = 0;
	to_join = false;
	cmdlst = cmdlst->next;
	while (cmdlst)
	{
		token = cmdlst->content;
		if (to_join == false && flg_is_quote(token->flg))
		{
			closing_flg = tkn_get_closing_flg(token->flg);
			opening_flg = token->flg;
		}
		if (token->flg == opening_flg || to_join == true)
		{
			token->concat_idx = i;
			if (to_join == false)
				to_join = true;
			else if (to_join == true && token->flg == closing_flg)
			{
				to_join = false;
				i++;
			}
		}
		cmdlst = cmdlst->next;
	}
	i++;
}

void	tkn_mark_operators_to_concatinate(t_list *dummyhead)
{
	t_list	*crnt;
	t_token	*crnt_tkn;
	t_token	*prev_tkn;
	size_t	i;

	i = 0;
	crnt = dummyhead->next->next;
	while (crnt)
	{
		prev_tkn = crnt->prev->content;
		crnt_tkn = crnt->content;
		if (flg_is_operator(crnt_tkn->flg) && crnt_tkn->flg == prev_tkn->flg)
		{
			crnt_tkn->concat_idx = i;
			prev_tkn->concat_idx = i;
			i++;
			if (crnt->next == NULL || crnt->next->next == NULL)
				break ;
			crnt = crnt->next->next;
			continue ;
		}
		crnt = crnt->next;
	}
}

void	tkn_mark_to_concat_on_flg(t_list *cmdlst, t_flg const to_concat[])
{
	t_token	*token;
	t_list	*crnt;
	size_t	i;
	size_t	idx;

	idx = 0;
	crnt = cmdlst->next;
	while (crnt)
	{
		token = crnt->content;
		i = 0;
		while (to_concat[i] != end)
		{
			if (token->flg == to_concat[i])
			{
				token->concat_idx = idx;
			}
			i++;
		}
		crnt = crnt->next;
	}
	idx++;
}
