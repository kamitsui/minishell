/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/16 14:12:30 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"

t_list	*tkn_split_and_assign_flag(const char *cmdline, size_t *concat_id)
{
	t_list	*head;
	t_token	*token;
	size_t	i;

	head = NULL;
	i = 0;
	while (cmdline[i])
	{
		token = ft_calloc(1, sizeof(t_token));
		//todo malloc error
		token->word = ft_strndup(&cmdline[i], 1);
		//todo malloc error
		token->subdiv = nonclassified;
		// token->to_concat = false;
		token->concat_idx = *concat_id;
		ft_lstadd_back(&head, ft_lstnew(token));
		i++;
		*concat_id = *concat_id + 1;
	}
	ft_lstiter(head, _assign_div_and_subdiv);
	return (head);
}

t_list	*tkn_concater(t_list *oldlst)
{
	t_list	*head;
	t_token	*old_token;
	t_token	*new_token;
	char	*new_word;
	char	*tmp;

	head = NULL;
	while (true)
	{
		old_token = oldlst->content;
		new_token = ft_calloc(1, sizeof(t_token));
		new_token->div = old_token->div;
		new_token->subdiv = old_token->subdiv;
		new_token->concat_idx = old_token->concat_idx;
		// new_token->to_concat = false;
		//todo malloc error
		new_word = ft_strdup(old_token->word);
		while (oldlst->next != NULL && ((t_token *)oldlst->content)->concat_idx == ((t_token *)oldlst->next->content)->concat_idx)
		{
			oldlst = oldlst->next;
			old_token = oldlst->content;
			tmp = new_word;
			new_word = ft_strjoin(tmp, old_token->word);//! old token list will be freed by lstiter
			free(tmp);
		}
		new_token->word = new_word;
		ft_lstadd_back(&head, ft_lstnew(new_token));
		if (oldlst->next == NULL)
			break ;
		else
			oldlst = oldlst->next;
	}
	return (head);
}

void	tkn_mark_quote_to_concatinate(t_list *cmdlst, size_t *concat_id)
{
	t_token		*token;
	bool		to_join;
	t_subdiv	closing_subdiv;

	to_join = false;
	while (cmdlst)
	{
		token = cmdlst->content;
		if (to_join == false)
		{
			if (token->subdiv == parenthesis_open)
				closing_subdiv = parenthesis_close;
			else
				closing_subdiv = token->subdiv;
		}
		if (token->div == quote || to_join == true)//! only place using t_div?
		{
			// token->to_concat = true;
			token->concat_idx = *concat_id;
			if (to_join == false)
			{
				to_join = true;
			}
			else if (to_join == true && token->subdiv == closing_subdiv)
			{
				to_join = false;
			}
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
		if (token->subdiv == nonclassified)
			token->concat_idx = concat_id;
		else
			concat_id++;
		cmdlist = cmdlist->next;
	}
	return (concat_id);
}

size_t	tkn_mark_operators_to_concatinate(t_list *cmdlist, size_t concat_id)
{
	t_token	*crnt_token;
	t_token	*prev_token;
	t_list	*crnt;

	prev_token = NULL;
	crnt = cmdlist;
	while (crnt)
	{
		if (crnt->prev == NULL)
		{
			crnt = crnt->next;
			continue ;
		}
		prev_token = crnt->prev->content;
		crnt_token = crnt->content;
		if (tkn_subdiv_is_control_operator(crnt_token->subdiv) || tkn_subdiv_is_redirect_operator(crnt_token->subdiv))
		{
			// if (prev_token != NULL && crnt_token->subdiv == prev_token->subdiv)
			if (crnt_token->subdiv == prev_token->subdiv)
			{
				crnt_token->concat_idx = concat_id;
				prev_token->concat_idx = concat_id;
				concat_id++;
				if (crnt->next == NULL || crnt->next->next == NULL)
					break ;
				crnt = crnt->next->next;
				continue ;
			}
		}
		crnt = crnt->next;
	}
	return (concat_id);
}

// size_t	tkn_mark_

int	tkn_controller(char const *cmdline)
{
	t_list	*head;
	t_list	*temp;
	size_t	concat_group_id;

	concat_group_id = 0;
	head = tkn_split_and_assign_flag(cmdline, &concat_group_id);
	printf("splited into a char\n");
	ft_lstiter(head, _print_list);
	tkn_mark_quote_to_concatinate(head, &concat_group_id);
	head = tkn_concater(head);
	printf("after quote concat\n");
	concat_group_id = tkn_mark_normal_words_to_concatinate(head, concat_group_id);
	printf("---\n");
	concat_group_id = tkn_mark_operators_to_concatinate(head, concat_group_id);
	ft_lstiter(head, _print_list);
	temp = head;
	head = tkn_concater(head);
	ft_lstclear(&temp, _delete_list);
	printf("---\n");
	ft_lstiter(head, _print_list);
	ft_lstclear(&head, _delete_list);
	return (EXIT_SUCCESS);
}

int main()
{
    char *line = NULL;

    while (1)
    {
        line = readline("> ");
        if (line == NULL || ft_strlen(line) == 0)
        {
            free(line);
            break;
        }
		// create_token_list(line);
		tkn_controller(line);
        // printf("line is '%s'\n", line);
        add_history(line);
        free(line);
    }
    printf("exit\n");
    return 0;
}