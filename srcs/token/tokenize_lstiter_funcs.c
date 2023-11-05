/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lstiter_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:52:43 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/05 05:18:53 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "error_minishell.h"

//! for debug purpose - delete when submit
void	_tkn_print_list(void *content)//!
{
	t_token	*token;

	if (!content)
		return ;
	token = content;
	printf("list:[%s](flg:%d/catidx:%d)\n", \
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

void	_tkn_assign_flg_to_str(void *content)
{
	t_token	*token;
	char	*word;

	if (!content)
		return ;
	token = content;
	word = token->word;
	token->flg = tkn_assign_flg_to_word(word);
}

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

void	*_tkn_dup_content(void *content)
{
	t_token	*oldnode;
	t_token	*newnode;

	if (!content)
		return (NULL);
	oldnode = content;
	newnode = ft_calloc(1, sizeof(t_token));
	if (!newnode)
		ft_errno_exit("ft_calloc");
	newnode->concat_idx = oldnode->concat_idx;
	newnode->flg = oldnode->flg;
	newnode->word = ft_strdup(oldnode->word);
	if (!newnode->word)
		ft_errno_exit("ft_strdup");
	return ((void *)newnode);
}
