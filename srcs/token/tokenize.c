/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/19 15:50:37 by mogawa           ###   ########.fr       */
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
	ft_lstiter(head, _tkn_assign_division_to_list);
	return (head);
}

static t_list	**tkn_concat_same_concat_idx(t_list *oldlst, t_list **newlst)
{
	t_token	*new_tkn;
	char	*tmp;

	while (oldlst != NULL)
	{
		new_tkn = ft_calloc(1, sizeof(t_token));
		if (new_tkn == NULL)
			return (NULL);
		new_tkn = (t_token *)oldlst->content;
		while (oldlst->next != NULL && ((t_token *)oldlst->content)->concat_idx \
							== ((t_token *)oldlst->next->content)->concat_idx)
		{
			oldlst = oldlst->next;
			tmp = new_tkn->word;
			new_tkn->word = ft_strjoin(tmp, ((t_token *)oldlst->content)->word);//!leaks???
			free(tmp);
			if (new_tkn->word == NULL)
				return (NULL);
		}
		ft_lstadd_back(newlst, ft_lstnew(new_tkn));
		if (oldlst != NULL)
			oldlst = oldlst->next;
	}
	// system("leaks -q token");//!
	return (newlst);
}

static t_list	*tkn_concater(t_list *oldlst)
{
	t_list	*newlst;
	t_list	**error_check;

	newlst = NULL;
	error_check = tkn_concat_same_concat_idx(oldlst, &newlst);
	if (error_check == NULL)
	{
		return (NULL);
	}
	// printf("newlst\n");
	// ft_lstiter(newlst, _tkn_print_list);
	// ft_lstiter(oldlst, _tkn_delete_list);
	// free(oldlst);
	// oldlst = NULL;
	return (newlst);
}

int	tkn_controller(char const *cmdline)
{
	t_list	*head;
	size_t	idx;

	idx = 0;
	head = tkn_create_list_with_flags(cmdline, &idx);
	if (!head)
	{
		//todo error
	}
	tkn_mark_quote_to_concatinate(head, &idx);
	head = tkn_concater(head);
	if (!head)
	{
		//todo error
	}
	idx = tkn_mark_operators_to_concatinate(head, idx);
	idx = tkn_mark_normal_words_to_concatinate(head, idx);
	head = tkn_concater(head);
	if (!head)
	{
		//todo error
	}
	ft_lstiter(head, _tkn_print_list);//todo delete
	ft_lstclear(&head, _tkn_delete_list);//todo delete
	// system("leaks -q token");
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