/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lstiter_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:52:43 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/26 10:49:54 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

//! for debug purpose - delete when submit
void	_tkn_print_list(void *content)
{
	t_token	*token;

	token = content;
	printf("list:[%s](flg:%d/catidx:%zu)\n", \
			token->word, token->flg, token->concat_idx);
}

void	_tkn_delete_list(void *content)
{
	t_token	*token;

	if (!content)
		return ;
	token = content;
	free(token->word);
	token->word = NULL;
	free(token);
	token = NULL;
}

void	_tkn_assign_flg_to_list(void *content)
{
	t_token	*token;
	char	c;

	token = content;
	c = token->word[0];
	token->flg = tkn_assign_flg_to_c(c);
}

// classify single and double ampersand and pipe
void	_tkn_reassign_flg_to_operator(void *content)
{
	t_token	*token;
	char	*word;

	token = content;
	word = token->word;
	if (ft_strcmp(word, "&&") == 0)
		token->flg = double_ampersand;
	else if (ft_strcmp(word, "&") == 0)
		token->flg = ampersand;
	else if (ft_strcmp(word, "|") == 0)
		token->flg = single_pipe;
	else if (ft_strcmp(word, "||") == 0)
		token->flg = double_pipe;
	else
		return ;
}
