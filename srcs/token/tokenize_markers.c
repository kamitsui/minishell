/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_markers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:13:43 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/26 10:26:10 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"

void	tkn_mark_quote_to_concatinate(t_list *cmdlst, size_t *concat_id)
{
	t_token	*token;
	bool	to_join;
	t_flg	closing_flg;

	to_join = false;
	while (cmdlst)
	{
		token = cmdlst->content;
		if (to_join == false)
			closing_flg = tkn_get_closing_flg(token->flg);
		if (flg_is_quote(token->flg) || to_join == true)
		{
			token->concat_idx = *concat_id;
			if (to_join == false)
				to_join = true;
			else if (to_join == true && token->flg == closing_flg)
				to_join = false;
		}
		cmdlst = cmdlst->next;
	}
	*concat_id = *concat_id + 1;
}

size_t	tkn_mark_normal_words_to_concatinate(t_list *cmdlist, size_t concat_id)
{
	t_token	*token;

	while (cmdlist)
	{
		token = cmdlist->content;
		if (token->flg == unclassified || flg_is_quote(token->flg) \
										|| token->flg == ampersand)
			token->concat_idx = concat_id;
		else
			concat_id++;
		cmdlist = cmdlist->next;
	}
	return (concat_id);
}

size_t	tkn_mark_operators_to_concatinate(t_list *crnt, size_t concat_id)
{
	t_token	*crnt_tkn;
	t_token	*prev_tkn;

	while (crnt)
	{
		if (crnt->prev == NULL)
		{
			crnt = crnt->next;
			continue ;
		}
		prev_tkn = crnt->prev->content;
		crnt_tkn = crnt->content;
		if (flg_is_operator(crnt_tkn->flg) && crnt_tkn->flg == prev_tkn->flg)
		{
			crnt_tkn->concat_idx = concat_id;
			prev_tkn->concat_idx = concat_id;
			concat_id++;
			if (crnt->next == NULL || crnt->next->next == NULL)
				break ;
			crnt = crnt->next->next;
			continue ;
		}
		crnt = crnt->next;
	}
	return (concat_id);
}
