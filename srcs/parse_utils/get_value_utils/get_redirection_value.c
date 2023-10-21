/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:58:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 21:03:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include "libft.h"
#include <stdlib.h>

char	*get_redirection_value(char **tokens)
{
	t_string	str;

	init_t_string(&str);
	while (is_connector(*tokens) == false && is_end(*tokens) == false)
	{
		if (is_pipe(*tokens) == true)
		{
			while (is_connector(*tokens) == false && is_end(*tokens) == false
				&& is_include_pipe_command(tokens) == true)
				tokens++;
		}
		if (is_redirection(*tokens) == true)
		{
			add_redirection_token(&str, tokens);
			add_file_token(&str, tokens);
		}
		else
			tokens++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}

char	*get_redirection_value_in_simple_command(char **tokens)
{
	t_string	str;

	init_t_string(&str);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
		{
			add_redirection_token(&str, tokens);
			add_file_token(&str, tokens);
		}
		else
			tokens++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}

char	*get_one_redirection_value(char **tokens)
{
	t_string	str;

	init_t_string(&str);
	add_token(&str, tokens);
	str_add_to_buff(&str, ' ');
	tokens++;
	add_token(&str, tokens);
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}
