/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/05 14:37:47 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum e_flag
{
	word,
	operand,
	redirect,
}	t_flag;

typedef struct s_token
{
	char	*word;
	t_flag	flag;
	// int		flag;
	bool	is_quoted;
	bool	is_splittable;
	char	target_char;
}	t_token;

void	_print_list(void *content)
{
	t_token	*token;

	token = content;
	printf("list:[%s]|splitable?:[%d]\n", token->word, token->is_splittable);
}

void	_delete_list(void *content)
{
	t_token	*token;

	token = content;
	free(token->word);
	token->word = NULL;
	free(token);
	token = NULL;
}

void	_mark_isquoted(void *content)
{
	t_token	*token;
	char	*word;

	token= content;
	word = token->word;
	if (word[0] == '"' || word[0] == '\'')
	{
		token->is_quoted = true;
	}
	else
		token->is_quoted = false;
}

void	tkn_list_check_isquoted(t_list *cmdlist)
{
	ft_lstiter(cmdlist, _mark_isquoted);
}

void	tkn_flag_no_split(t_list *cmdlist, const char target)
{
	t_token	*token;
	char	*word;

	while (cmdlist != NULL)
	{
		token = cmdlist->content;
		word = token->word;
		if (word[0] == target)
			token->is_splittable = false;
		cmdlist = cmdlist->next;
	}
}

void	tkn_list_add_target_char(t_list *cmdlist, char const target)
{
	t_list	*crnt;
	t_token	*token;

	crnt = cmdlist;
	while (crnt != NULL)
	{
		token = crnt->content;
		token->target_char = target;
		crnt = crnt->next;
	}
}

static t_list	*tkn_initialize(char const *cmdline)
{
	t_list	*head;
	t_token	*token;

	head = NULL;
	token = ft_calloc(1, sizeof(t_token));
	token->word = ft_strdup(cmdline);
	token->flag = 0;
	token->is_quoted = false;
	token->is_splittable = true;
	ft_lstadd_back(&head, ft_lstnew(token));
	return (head);
}

void	tkn_list_del_target_char(t_list **cmdlist, char const target)
{
	t_list	*crnt;
	t_list	*prev;
	t_list	*tmp_next;
	t_token	*token;
	char	*word;

	prev = NULL;
	crnt = *cmdlist;
	while (crnt != NULL)
	{
		tmp_next = crnt->next;
		token = crnt->content;
		word = token->word;
		if (word[0] == target && word[1] == '\0')
		{
			prev->next = tmp_next;
			ft_lstdelone(crnt, _delete_list);
		}
		else
		{
			prev = crnt;
		}
		crnt = tmp_next;
	}
}

static t_list	*tkn_list_concat(t_list const *cmdlist, char const joint)
{
	t_list	*new_list;
	t_token	*old_token;
	t_token	*new_token;
	char	*old_word;
	char 	*new_word;
	char	*tmp_word;
	bool	to_join;

	new_list = NULL;
	new_word = NULL;
	to_join = false;
	while (cmdlist != NULL)
	{
		old_token = cmdlist->content;
		old_word = old_token->word;
		if (to_join == false)
		{
			new_word = ft_strdup(old_word);
		}
		else if (to_join == true)
		{
			tmp_word = new_word;
			new_word = ft_strjoin(new_word, old_word);
			free(tmp_word);
		}
		if (old_word[0] == joint)
		{
			if (to_join == true)
			{
				to_join = false;
				new_token = ft_calloc(1, sizeof(t_token));
				new_token->word = new_word;
				new_token->is_splittable = false;
				ft_lstadd_back(&new_list, ft_lstnew(new_token));
			}
			else if (to_join == false)
			{
				to_join = true;
			}
		}
		else if (old_word[0] != joint && to_join == false)
		{
			new_token = ft_calloc(1, sizeof(t_token));
			new_token->word = new_word;
			new_token->is_splittable = true;
			ft_lstadd_back(&new_list, ft_lstnew(new_token));
		}
		cmdlist = cmdlist->next;
	}
	return (new_list);
}

static t_list	*tkn_list_split(t_list const *cmdlist, char const delim)
{
	t_list	*new_list;
	t_token	*new_token;
	char	*raw_word;
	size_t	search_idx;
	size_t	follow_idx;
	bool	is_splittable;
	bool	is_quote;
	bool	had_delim;

	new_list = NULL;
	while (cmdlist != NULL)
	{
		had_delim = false;
		search_idx = 0;
		follow_idx = 0;
		raw_word = ((t_token *)cmdlist->content)->word;
		is_splittable = ((t_token *)cmdlist->content)->is_splittable;
		is_quote = ((t_token *)cmdlist->content)->is_quoted;
		if (is_splittable == false || is_quote == true)
		{
			new_token = ft_calloc(1, sizeof(t_token));
			new_token->word = ft_strdup(raw_word);
			new_token->is_splittable = false;
			ft_lstadd_back(&new_list, ft_lstnew(new_token));
			cmdlist = cmdlist->next;
			continue ;
		}
		while (raw_word[search_idx])
		{
			if (raw_word[search_idx] == delim)
			{
				//todo error
				if (search_idx - follow_idx != 0)
				{
					new_token = ft_calloc(1, sizeof(t_token));
					new_token->word = ft_strndup(&raw_word[follow_idx], search_idx - follow_idx);
					new_token->is_splittable = true;
					ft_lstadd_back(&new_list, ft_lstnew(new_token));
				}
				new_token = ft_calloc(1, sizeof(t_token));
				new_token->word = ft_strndup(&raw_word[search_idx], 1);
				new_token->is_splittable = true;
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
				new_token->is_splittable = true;
				ft_lstadd_back(&new_list, ft_lstnew(new_token));
		}
		else if (!had_delim)
		{
			new_token = ft_calloc(1, sizeof(t_token));
			new_token->word = ft_strdup(raw_word);
			new_token->is_splittable = true;
			ft_lstadd_back(&new_list, ft_lstnew(new_token));
		}
		cmdlist = cmdlist->next;
	}
	// tkn_list_delete(cmdlist);
	return (new_list);
}

static int	tkn_controller(char const *cmdline)
{
	t_list const	*head;
	t_list			*tmp;

	head = tkn_initialize(cmdline);
	//todo free head
	//todo free tmp
	tmp = tkn_list_split(head, '"');
	tmp = tkn_list_concat(tmp, '"');
	tkn_flag_no_split(tmp, '"');
	// tkn_list_check_isquoted(tmp);
	ft_lstiter(tmp, _print_list);
	tmp = tkn_list_split(tmp, ' ');
	tkn_flag_no_split(tmp, ' ');
	tmp = tkn_list_split(tmp, '>');
	tkn_flag_no_split(tmp, '>');
	tmp = tkn_list_split(tmp, '<');
	tkn_flag_no_split(tmp, '<');
	tmp = tkn_list_split(tmp, '|');
	tkn_flag_no_split(tmp, '|');
	tmp = tkn_list_split(tmp, '&');
	tkn_flag_no_split(tmp, '&');
	printf("new list\n");
	ft_lstiter(tmp, _print_list);
	// tmp = tkn_list_concat(tmp, '"');
	// tmp = tkn_list_split(tmp, ' ');
	// tkn_list_del_target_char(&tmp, ' ');
	// printf("new list\n");
	// ft_lstiter(tmp, _print_list);
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