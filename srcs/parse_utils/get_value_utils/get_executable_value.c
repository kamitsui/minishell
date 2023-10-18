/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:11:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 13:28:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include <stdlib.h>

char	*get_executable_value(char **tokens)
{
	t_string	str;
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = ft_strnew(1);
	if (str.out == NULL)
		ft_errno_exit("ft_strnew");
	str.out_len = 0;
	while (is_connector(*tokens) == false && is_end(*tokens) == false
			&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
		{
			tokens += 2;//　エラーケースは未想定　例えば”>>"のみ
			continue ;
		}
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
