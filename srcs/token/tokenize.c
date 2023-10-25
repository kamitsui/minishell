/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/25 14:01:40 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "ft_signal.h"
#include "libft.h"
// #include "readline/readline.h"//! delete
// #include "readline/history.h"//! delete

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
			return (NULL);
		token->word = ft_substr(cmdline, i, 1);
		if (!token->word)
			return (NULL);
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
				return (NULL);
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
	if (newlst == NULL)
	{
		return (NULL);
	}
	ft_lstclear(&oldlst, _tkn_delete_list);
	return (newlst);
}

void	tkn_concat_id_initializer(t_list *dummyhead)
{
	t_list	*crnt;
	t_token	*token;
	size_t	i;

	crnt = dummyhead->next;
	i = 0;
	while (crnt)
	{
		token = crnt->content;
		token->concat_idx = i;
		if (i > SIZE_MAX - 1)
		{
			//todo overflow error handle
			exit(1);
		}
		i++;
		crnt = crnt->next;
	}
}

t_list	*make_tokenlist_from_char(char const *raw_cmds)
{
	t_list	*dummy_head;
	t_flg const	flags[] = {unclassified, ampersand, end};

	dummy_head = tkn_make_list_from_line(raw_cmds);
	//todo error handle
	ft_lstiter(dummy_head, _tkn_assign_flg_to_str);//!
	tkn_concat_id_initializer(dummy_head);
	tkn_mark_quote_to_concatinate(dummy_head);
	dummy_head = tkn_concater(dummy_head);
	//todo error handle
	tkn_concat_id_initializer(dummy_head);
	tkn_mark_operators_to_concatinate(dummy_head);
	dummy_head = tkn_concater(dummy_head);
	//todo error handle
	ft_lstiter(dummy_head, _tkn_assign_flg_to_str);//!
	tkn_concat_id_initializer(dummy_head);
	tkn_mark_to_concat_on_flg(dummy_head, flags);
	dummy_head = tkn_concater(dummy_head);
	//todo error handle
	tkn_del_one_by_flg(&dummy_head, space);
	return (dummy_head);
}

char	**token_controller(char *cmdline)
{
	t_list	*tokenized_head;
	// t_list	*cmdslst_head;
	char	**dptr_cmds;

	//todo cmdline validator
	tokenized_head = make_tokenlist_from_char(cmdline);
	dptr_cmds = tkn_create_dptrchar_from_list(tokenized_head);//for dptrline, need to free
	ft_lstclear(&tokenized_head, _tkn_delete_list);
	return (dptr_cmds);
	// cmdslst_head = create_cmdslst_from_tknlst(tokenized_head->next);//free tokenized list
	//todo error handle
	//! below leak check
	// int i = 0;
	// while (dptr_cmds[i])
	// {
	// 	free(dptr_cmds[i]);
	// 	i++;
	// }
	// free(dptr_cmds);
	// system("leaks -q token");
	// return (NULL);
}

// int main()
// {
//     char *line = NULL;
// 	// t_sigaction	act_sigint;
// 	// t_sigaction	act_sigquit;

// 	// sig_signal_initializer(&act_sigint, SIGINT, false);
// 	// sig_signal_initializer(&act_sigquit, SIGQUIT, false);
// 	// sigaction(SIGINT, &act_sigint, NULL);
// 	// sigaction(SIGQUIT,&act_sigquit, NULL);
//     while (1)
//     {
//         line = readline("> ");
//         if (line == NULL || ft_strlen(line) == 0)
//         {
//             free(line);
//             break;
//         }
// 		// create_token_list(line);
// 		token_controller(line);
//         // printf("line is '%s'\n", line);
//         add_history(line);
//         free(line);
//     }
//     printf("exit\n");
//     return 0;
// }