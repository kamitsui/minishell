/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:13:28 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/23 19:49:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"

void	add_token(t_string *str, char *tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i] != '\0')
	{
		str_add_to_buff(str, tokens[i]);
		i++;
	}
}

void	add_redirection_token(t_string *str, char ***tokens)
{
	if (str->out_len > 0)
		str_add_to_buff(str, ' ');
	add_token(str, **tokens);
	(*tokens)++;
}

void	add_file_token(t_string *str, char ***tokens)
{
	if (is_end(**tokens) == false)
	{
		str_add_to_buff(str, ' ');
		add_token(str, **tokens);
		(*tokens)++;
	}
}
