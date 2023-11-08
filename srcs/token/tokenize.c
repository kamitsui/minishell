/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/09 06:47:19 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "ft_signal.h"
#include "libft.h"
#include "error_minishell.h"

t_list	*tkn_make_list_from_line(const char *cmdline)
{
	t_list	*head;
	t_token	*token;
	size_t	i;

	head = ft_lstnew(NULL);
	i = 0;
	while (cmdline[i])
	{
		token = ft_calloc(1, sizeof(t_token));
		if (!token)
			ft_errno_exit("ft_calloc");
		token->word = ft_substr(cmdline, i, 1);
		if (!token->word)
			ft_errno_exit("ft_substr");
		ft_lstadd_back(&head, ft_lstnew(token));
		i++;
	}
	return (head);
}

static t_list	*tkn_concat_same_idx(t_list *oldlst)
{
	t_token	*new_tkn;
	char	*tmp;
	t_list	*newlst;

	newlst = ft_lstnew(NULL);
	oldlst = oldlst->next;
	while (oldlst != NULL)
	{
		new_tkn = tkn_create_new_token_by_copy_old(oldlst->content);
		while (oldlst->next != NULL && ((t_token *)oldlst->content)->concat_idx \
							== ((t_token *)oldlst->next->content)->concat_idx)
		{
			oldlst = oldlst->next;
			tmp = new_tkn->word;
			new_tkn->word = ft_strjoin(tmp, ((t_token *)oldlst->content)->word);
			free(tmp);
			if (new_tkn->word == NULL)
				ft_errno_exit("ft_strjoin");
		}
		ft_lstadd_back(&newlst, ft_lstnew(new_tkn));
		if (oldlst != NULL)
			oldlst = oldlst->next;
	}
	return (newlst);
}

static t_list	*tkn_concater(t_list *oldlst)
{
	t_list	*newlst;

	newlst = tkn_concat_same_idx(oldlst);
	ft_lstclear(&oldlst, _tkn_delete_list);
	return (newlst);
}

void	tkn_concat_id_initializer(t_list *dummyhead)
{
	t_list	*crnt;
	t_token	*token;
	int		i;

	crnt = dummyhead->next;
	i = 0;
	while (crnt)
	{
		token = crnt->content;
		token->concat_idx = i;
		if (i > INT_MAX - 1)
		{
			ft_perror_exit("number of chars in input passed \
									the max allowed amount");
		}
		i++;
		crnt = crnt->next;
	}
}

char	**token_controller(char *cmdline)
{
	t_list		*tokenized_lst_head;
	char		**dptr_cmds;
	t_flg const	flags[] = {unclassified, ampersand, end};

	tokenized_lst_head = tkn_make_list_from_line(cmdline);
	ft_lstiter(tokenized_lst_head, _tkn_assign_flg_to_str);
	tkn_concat_id_initializer(tokenized_lst_head);
	tkn_mark_quote_to_concatinate(tokenized_lst_head);
	tokenized_lst_head = tkn_concater(tokenized_lst_head);
	tkn_concat_id_initializer(tokenized_lst_head);
	tkn_mark_operators_to_concatinate(tokenized_lst_head);
	tokenized_lst_head = tkn_concater(tokenized_lst_head);
	ft_lstiter(tokenized_lst_head, _tkn_assign_flg_to_str);
	tkn_concat_id_initializer(tokenized_lst_head);
	tkn_mark_to_concat_on_flg(tokenized_lst_head, flags);
	tokenized_lst_head = tkn_concater(tokenized_lst_head);
	tkn_del_one_by_flg(&tokenized_lst_head, space);
	dptr_cmds = tkn_create_dptrchar_from_list(tokenized_lst_head->next);
	ft_lstclear(&tokenized_lst_head, _tkn_delete_list);
	return (dptr_cmds);
}
