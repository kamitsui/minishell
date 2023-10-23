/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:11:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/23 19:51:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include <stdlib.h>

char	*get_executable_value(char **tokens)
{
	t_string	str;

	init_t_string(&str);
	while (is_connector(*tokens) == false && is_end(*tokens) == false
		&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
		{
			tokens += 2;//　エラーケースは未想定　例えば”>>"のみ
			continue ;
		}
		add_token(&str, *tokens);
		tokens++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}
