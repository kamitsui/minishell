/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/06 22:09:40 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"

t_list	*tkn_split_and_assign_flag(const char *cmdline)
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
		token->div = unclassified;
		token->subdiv = nonclassified;
		token->to_concat = false;
		ft_lstadd_back(&head, ft_lstnew(token));
		i++;
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
		new_token->to_concat = false;
		//todo malloc error
		new_word = ft_strdup(old_token->word);
		while (oldlst->next != NULL && ((t_token *)oldlst->content)->to_concat == true && ((t_token *)oldlst->next->content)->to_concat == true)
		{
			oldlst = oldlst->next;
			old_token = oldlst->content;
			tmp = new_word;
			new_word = ft_strjoin(new_word, old_token->word);
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

void	tkn_mark_to_concatinate(t_list *cmdlst, t_div division)
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
		if (token->div == division || to_join == true)
		{
			token->to_concat = true;
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
}

int	tkn_controller(char const *cmdline)
{
	t_list	*head;
	t_list	*temp;

	head = tkn_split_and_assign_flag(cmdline);
	tkn_mark_to_concatinate(head, quote);
	tkn_mark_to_concatinate(head, redirect);
	tkn_mark_to_concatinate(head, control);
	ft_lstiter(head, _print_list);
	printf("---\n");
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