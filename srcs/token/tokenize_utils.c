/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:24:03 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/22 10:58:25 by mogawa           ###   ########.fr       */
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

char	**tkn_create_char_from_list(t_list *cmdlst)
{
	char		**cmdlines;
	t_list		*crnt;
	t_token		*tkn;
	const int	lstsize = ft_lstsize(cmdlst);
	int			i;

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
