/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:24:03 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 14:02:57 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "error_minishell.h"

t_token	*tkn_create_new_token_by_copy_old(t_token *old_tkn)
{
	t_token	*new_tkn;

	if (old_tkn == NULL)
		return (NULL);
	new_tkn = ft_calloc(1, sizeof(t_token));
	if (new_tkn == NULL)
	{
		ft_errno_exit("ft_calloc");
	}
	new_tkn->word = ft_strdup(old_tkn->word);
	if (new_tkn->word == NULL)
	{
		free (new_tkn);
		new_tkn = NULL;
		ft_errno_exit("ft_strdup");
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
		ft_errno_exit("ft_calloc");
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
