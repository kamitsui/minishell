/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tokenize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/06 15:42:11 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool tkn_is_quote(char const c);

typedef enum e_flag
{
	unclassified,
	quote,
	redirect,
	control,
}	t_flag;

typedef struct s_token
{
	char	*word;
	t_flag	flag;
	bool	is_metachar;
	bool	is_ctrl_char;
	bool	is_redirect_char;
	bool	is_quote;
	bool	is_splittable;
	char	target_char;
}	t_token;

void	_print_list(void *content)
{
	t_token	*token;

	token = content;
	printf("list:[%s]|quote?:[%d]\n", token->word, token->is_quote);
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

void	_mark_isquote(void *content)
{
	t_token	*token;
	char	*word;

	token= content;
	word = token->word;
	if (tkn_is_quote(word[0]))
	{
		token->is_quote = true;
	}
	else
		token->is_quote = false;
}

static bool tkn_is_quote(char const c)
{
	if (c == '"' || c == '\'' || c == '(' || c == ')')
		return (true);
	else
		return (false);
}

static bool	tkn_is_metachar(char const c)
{
	if (c == ' ' || c == '\t' || c == '|' || c == '&' || c == '<' || c == '>')//todo add newline
		return (true);
	else
		return (false);
}

static bool	tkn_is_ctrl_operator(char const c)
{
	if (c == '|' || c == '&')//todo add newline
		return (true);
	else
		return (false);
}

static bool	tkn_is_redirect_operator(char const c)
{
	if (c == '<' || c == '>')
		return (true);
	else
		return (false);
}

void	tkn_list_check_isquoted(t_list *cmdlist)
{
	ft_lstiter(cmdlist, _mark_isquote);
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
	token->is_quote = false;
	token->is_splittable = true;
	token->is_ctrl_char = false;
	token->is_metachar = false;
	token->is_redirect_char = false;
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

void	_mark_metachar(void *content)
{
	t_token	*token;
	char	*word;

	token = content;
	word = token->word;
	if (tkn_is_metachar(word[0]))
	{
		token->is_metachar = true;
	}
}

void	_mark_control_char(void *content)
{
	t_token	*token;
	char	*word;

	token = content;
	word = token->word;
	if (tkn_is_ctrl_operator(word[0]))
	{
		token->is_ctrl_char = true;
	}
}

void	_mark_redirect_char(void *content)
{
	t_token	*token;
	char	*word;

	token = content;
	word = token->word;
	if (tkn_is_redirect_operator(word[0]))
	{
		token->is_redirect_char = true;
	}
}

static void	tkn_mark_char_type(t_list *cmdlist)
{
	ft_lstiter(cmdlist, _mark_metachar);
	ft_lstiter(cmdlist, _mark_control_char);
	ft_lstiter(cmdlist, _mark_redirect_char);
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
		if (old_word[0] == joint || (joint == '(' && old_word[0] == ')'))
		{
			if (to_join == true)
			{
				to_join = false;
				new_token = ft_calloc(1, sizeof(t_token));
				new_token->word = new_word;
				new_token->is_splittable = false;
				new_token->is_quote = true;
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
			new_token->is_splittable = false;
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
		is_quote = ((t_token *)cmdlist->content)->is_quote;
		if (is_splittable == false || is_quote == true)
		{
			new_token = ft_calloc(1, sizeof(t_token));
			new_token->word = ft_strdup(raw_word);
			new_token->is_splittable = false;
			new_token->is_quote = true;
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
	printf("--start--\n");
	printf("*test case*\n");
	ft_lstiter((t_list *)head, _print_list);
	tmp = tkn_list_split(head, '"');
	tmp = tkn_list_split(tmp, '\'');
	tmp = tkn_list_split(tmp, '(');
	tmp = tkn_list_split(tmp, ')');
	tkn_list_check_isquoted(tmp);
	printf("*quote split*\n");
	ft_lstiter(tmp, _print_list);
	// tmp = tkn_list_concat(tmp, '"');
	// tmp = tkn_list_concat(tmp, '\'');
	// printf("*after''*\n");
	// ft_lstiter(tmp, _print_list);
	// tmp = tkn_list_concat(tmp, '(');
	// tkn_flag_no_split(tmp, '\'');
	// tkn_flag_no_split(tmp, '"');
	// printf("*after quote isolated*\n");
	// ft_lstiter(tmp, _print_list);
	// tmp = tkn_list_split(tmp, ' ');
	// tkn_flag_no_split(tmp, ' ');
	// tmp = tkn_list_split(tmp, '>');
	// tkn_flag_no_split(tmp, '>');
	// tmp = tkn_list_split(tmp, '<');
	// tkn_flag_no_split(tmp, '<');
	// tmp = tkn_list_split(tmp, '|');
	// tkn_flag_no_split(tmp, '|');
	// tmp = tkn_list_split(tmp, '&');
	// tkn_flag_no_split(tmp, '&');
	printf("*final result*\n");
	ft_lstiter(tmp, _print_list);
	printf("--end--\n");
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