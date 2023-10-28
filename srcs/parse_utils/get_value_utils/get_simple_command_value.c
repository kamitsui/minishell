/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simple_command_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:14:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/27 18:40:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include "libft.h"
#include <stdlib.h>

char	*get_simple_command_value(char **tokens)
{
	t_string	str;

	init_t_string(&str);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_pipe(*tokens) == false)
	{
		if (str.out_len > 0)
			str_add_to_buff(&str, ' ');
		add_token(&str, *tokens);
		tokens++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}
