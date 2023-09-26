/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:06:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/26 22:14:13 by mogawa           ###   ########.fr       */
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
	char			*new_word;
	char			*tmp;
	char			*dollar_string;
	char			*res;

	word = *cmdline;
	new_word = ft_strdup("");
	start = 0;
	while (word[start])
	{
		if (word[start] == '$')
		{
			end = start + 1;
			while (word[end] && ft_isalnum(word[end]))
				end++;
			dollar_string = ft_substr(word, start, (size_t)end - start);
			res = env_get_value(env_wrap->env, &dollar_string[1]);
			printf("%s\n", res);
			if (res == NULL)
			{
				free(dollar_string);
			}
			else
			{
				tmp = new_word;
				new_word = ft_strjoin(new_word, res);
				printf("substr[%s]\n", dollar_string);
				// free(res);
				free(tmp);
			}
		}
		else
		{
			end = start + 1;
			while (word[end] && word[end] != '$')
				end++;
			dollar_string = ft_substr(word, start, (size_t)end - start);
			tmp = new_word;
			new_word = ft_strjoin(new_word, dollar_string);
			printf("substr[%s]\n", dollar_string);
			free(dollar_string);
			free(tmp);
		}
		start = end;
	}
	printf("final[%s]\n", new_word);
	*cmdline = new_word;
	free(word);
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
