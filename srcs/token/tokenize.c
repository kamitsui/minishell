/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/07 13:42:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"

t_list	*tkn_create_list_with_flags(const char *cmdline, size_t *concat_id)
{
	t_list	*head;
	t_token	*token;
	size_t	i;

	head = NULL;
	i = 0;
	while (cmdline[i])
	{
		token = ft_calloc(1, sizeof(t_token));
		if (!token)
			return (NULL);
		token->word = ft_strndup(&cmdline[i], 1);
		if (!token->word)
			return (NULL);
		token->concat_idx = *concat_id;
		ft_lstadd_back(&head, ft_lstnew(token));
		i++;
		*concat_id = *concat_id + 1;
	}
	ft_lstiter(head, _tkn_assign_flg_to_list);
	return (head);
}

static t_list	**tkn_concat_same_idx(t_list *oldlst, t_list **newlst)
{
	t_token	*new_tkn;
	char	*tmp;

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
				return (NULL);
		}
		ft_lstadd_back(newlst, ft_lstnew(new_tkn));
		if (oldlst != NULL)
			oldlst = oldlst->next;
	}
	return (newlst);
}

static t_list	*tkn_concater(t_list *oldlst)
{
	t_list	*newlst;
	t_list	**error_check;

	newlst = NULL;
	error_check = tkn_concat_same_idx(oldlst, &newlst);
	if (error_check == NULL)
	{
		return (NULL);
	}
	ft_lstclear(&oldlst, _tkn_delete_list);
	return (newlst);
}

char	**tkn_controller(char const *raw_cmds)//! has to add to tokenize.h to use on other files.
{
	t_list	*head;
	size_t	idx;
	char	**token_cmds;

	idx = 0;
	head = tkn_create_list_with_flags(raw_cmds, &idx);
	if (!head)
	{
		//todo error
	}
	tkn_mark_quote_to_concatinate(head, &idx);
	head = tkn_concater(head);
	ft_lstiter(head, _tkn_print_list);
	if (!head)
	{
		//todo error
	}
	idx = tkn_mark_operators_to_concatinate(head, idx);
	head = tkn_concater(head);
	ft_lstiter(head, _tkn_reassign_flg_to_operator);
	t_flg	flags[] = {unclassified, end};
	idx = tkn_mark_to_concat_for_flg(head, idx, flags);
	t_flg	flags2[] = {unclassified, single_pipe, ampersand, end};
	idx = tkn_mark_to_concat_for_flg(head, idx, flags2);
	head = tkn_concater(head);

	//! expansion start here
	// tkn_expansion_handler(head, NULL);

	//! concat normal word, double quote and single quote	
	t_flg	flag1[] = {unclassified, doube_quote, single_quote, end};
	idx = tkn_mark_to_concat_for_flg(head, idx, flag1);
	head = tkn_concater(head);
	if (!head)
	{
		//todo error
	}
	tkn_del_one_on_flg(&head, space);
	ft_lstiter(head, _tkn_print_list);
	token_cmds = tkn_create_dptrchar_from_list(head);
	if (token_cmds == NULL)
	{
		printf("error in token_cmds\n");
		ft_lstclear(&head, _tkn_delete_list);
		system("leaks -q token");
		return (NULL);
	}
	ft_lstclear(&head, _tkn_delete_list);
	// //* print char ** to be deleted
	// int j = 0;
	// while (token_cmds[j])
	// {
	// 	printf("char**[%s]\n", token_cmds[j]);
	// 	free (token_cmds[j]);
	// 	j++;
	// }
	// free (token_cmds);
	// system("leaks -q token");
	return (token_cmds);
}

// disable by kamitsui ( for use srcs/main.c )
//int main()
//{
//    char *line = NULL;
//
//    while (1)
//    {
//        line = readline("> ");
//        if (line == NULL || ft_strlen(line) == 0)
//        {
//            free(line);
//            break;
//        }
//		// create_token_list(line);
//		tkn_controller(line);
//        // printf("line is '%s'\n", line);
//        add_history(line);
//        free(line);
//    }
//    printf("exit\n");
//    return 0;
//}
