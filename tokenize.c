/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/02 17:13:53 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include "./libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_token
{
	char	*word;
	int		flag;
}	t_token;

void	_print_list(void *content)
{
	t_token	*token;

	token = content;
	printf("list:[%s]\n", token->word);
}

void	_delete_list_elem(void *content)
{
	t_token	*token;

	token = content;
	free(token->word);
	token->word = NULL;
	free(token);
	token = NULL;
}

static t_list	*tkn_initialize(char const *cmdline)
{
	t_list	*head;
	t_list	*elem;
	t_token	*token;

	head = NULL;
	token = ft_calloc(1, sizeof(t_token));
	token->word = ft_strdup(cmdline);
	token->flag = 0;
	ft_lstadd_back(&head, ft_lstnew(token));
	return (head);
}

static t_list	*tkn_list_splitter(t_list const *cmdlist, char const delim)
{
	t_list	*new_list;
	t_token	*new_token;
	char	*raw_word;
	size_t	search_idx;
	size_t	follow_idx;
	bool	had_delim;

	new_list = NULL;
	while (cmdlist != NULL)
	{
		had_delim = false;
		search_idx = 0;
		follow_idx = 0;
		raw_word = ((t_token *)cmdlist->content)->word;
		while (raw_word[search_idx])
		{
			if (raw_word[search_idx] == delim)
			{
				//todo error
				if (search_idx - follow_idx != 0)
				{
					new_token = ft_calloc(1, sizeof(t_token));
					new_token->word = ft_strndup(&raw_word[follow_idx], search_idx - follow_idx);
					ft_lstadd_back(&new_list, ft_lstnew(new_token));
				}
				new_token = ft_calloc(1, sizeof(t_token));
				new_token->word = ft_strndup(&raw_word[search_idx], 1);
				ft_lstadd_back(&new_list, ft_lstnew(new_token));
				search_idx++;
				follow_idx = search_idx;
				had_delim = true;
			}
			else
			{
				search_idx++;
			}
		}
		if (had_delim && search_idx != follow_idx)
		{
				new_token = ft_calloc(1, sizeof(t_token));
				new_token->word = ft_strndup(&raw_word[follow_idx], search_idx - follow_idx);
				ft_lstadd_back(&new_list, ft_lstnew(new_token));
		}
		else if (!had_delim)
		{
			new_token = ft_calloc(1, sizeof(t_token));
			new_token->word = ft_strdup(raw_word);
			ft_lstadd_back(&new_list, ft_lstnew(new_token));
		}
		cmdlist = cmdlist->next;
	}
	return (new_list);
}

static int	tkn_controller(char const *cmdline)
{
	t_list const	*head;
	t_list			*tmp;
	t_list			*newtmp;
	t_list			*new_list;

	head = tkn_initialize(cmdline);
	tmp = tkn_list_splitter(head, ' ');
	//todo free head
	ft_lstiter(tmp, _print_list);
	printf("new list\n");
	//todo free tmp
	tmp = tkn_list_splitter(tmp, '"');
	ft_lstiter(tmp, _print_list);

	return (0);
}

int main()
{
    char *line = NULL;

    while (1)
    {
        line = readline("> ");
        if (line == NULL || strlen(line) == 0)
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