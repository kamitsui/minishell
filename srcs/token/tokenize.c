/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:58:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/06 18:41:33 by mogawa           ###   ########.fr       */
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
	ft_lstiter(head, _assign_divs_list);
	return (head);
}

//todo tkn_concater(t_list const *cmdlst)

void	tkn_mark_quote_concat(t_list *cmdlst)
{
	t_token		*token;
	bool		in_quote;
	t_subdiv	closing_subdiv;

	in_quote = false;
	while (cmdlst)
	{
		token = cmdlst->content;
		if (in_quote == false)
			closing_subdiv = token->subdiv;
		if (token->div == quote || in_quote == true)
		{
			token->to_concat = true;
			if (in_quote == false)
			{
				in_quote = true;
			}
			else if (in_quote == true && token->subdiv == closing_subdiv)
			{
				in_quote = false;
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
	tkn_mark_quote_concat(head);
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