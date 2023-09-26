/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:06:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/26 17:02:27 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "environ.h"

// astarisk

// $ expansion
static void	tkn_expand_dollar_sign(char **cmdline, t_envwrap *env_wrap)
{
	t_list			dummy_head;
	unsigned int	start;
	unsigned int	end;
	char			*word;
	char			*dollar_string;

	word = *cmdline;
	start = 0;
	while (word[start])
	{
		if (word[start] == '$')
		{
			end = start + 1;
			while (word[end] && ft_isalnum(word[end]))
				end++;
			dollar_string = ft_substr(word, start, (size_t)end - start);
			printf("substr[%s]\n", dollar_string);
			free (dollar_string);
		}
		else
		{
			end = start + 1;
			while (word[end] && word[end] != '$')
				end++;
			dollar_string = ft_substr(word, start, (size_t)end - start);
			printf("substr[%s]\n", dollar_string);
			free (dollar_string);
		}
		start = end;
	}
}

int	tkn_expansion_handler(t_list *cmdlst, t_envwrap *env_wrap)
{
	extern char	**environ;
	t_token	*token;
	char	*word;

	env_wrap = create_env_list(environ);
	while (cmdlst)
	{
		token = cmdlst->content;
		if (token->flg == unclassified || token->flg == doube_quote)
		{
			if (ft_strchr(token->word, '$') != NULL)
				tkn_expand_dollar_sign(&token->word, env_wrap);
		}
		cmdlst = cmdlst->next;
	}
}
