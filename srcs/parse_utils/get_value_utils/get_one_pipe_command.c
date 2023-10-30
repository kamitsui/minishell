/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_pipe_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:17:33 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 14:21:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include <stdlib.h>

char	*get_one_pipe_command_value(char **tokens)
{
	t_string	str;
	size_t		i;

	init_t_string(&str);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_pipe(*tokens) == false)
	{
		if (str.out_len > 0)
			str_add_to_buff(&str, ' ');
		i = 0;
		while ((*tokens)[i] != '\0')
		{
			str_add_to_buff(&str, (*tokens)[i]);
			i++;
		}
		tokens++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}
