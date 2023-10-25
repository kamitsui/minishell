/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_command_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:16:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/23 19:52:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include "libft.h"
#include <stdlib.h>

char	*get_pipe_command_value(char **tokens)
{
	t_string	str;

	init_t_string(&str);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_include_pipe_command(tokens) == true)
	{
		if (str.out_len > 0)
			str_add_to_buff(&str, ' ');
		add_token(&str, *tokens);
		tokens++;
	}
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_redirection(*tokens) == false)
	{
		str_add_to_buff(&str, ' ');
		add_token(&str, *tokens);
		tokens++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}
