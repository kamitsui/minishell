/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add_to_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:01:18 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 13:30:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "minishell.h"
#include "error_minishell.h"

void	str_add_to_buff(t_string *str, char c)
{
	if (str->len == BUFF_SIZE)
	{
		str->out = str_join_to_out(str->out, str->buffer, str->len);
		if (str->out == NULL)
		{
			//handle_error(...); // 要実装
			return ;
		}
		ft_bzero(&str->buffer, BUFF_SIZE);
		str->len = 0;
	}
	str->buffer[str->len] = c;
	str->len++;
	str->out_len++;
}
