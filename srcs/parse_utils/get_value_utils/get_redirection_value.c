/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:58:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 13:26:18 by kamitsui         ###   ########.fr       */
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
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = ft_strnew(1);
	if (str.out == NULL)
		ft_errno_exit("ft_strnew");
	str.out_len = 0;
	while (is_connector(*tokens) == false && is_end(*tokens) == false)
	{
		if (is_pipe(*tokens) == true)
		{
			//skip_token(...);//要実装
			while (is_connector(*tokens) == false && is_end(*tokens) == false
					&& is_include_pipe_command(tokens) == true)
				tokens++;
		}
		if (is_redirection(*tokens) == true)
		{
			if (str.out_len > 0)
				str_add_to_buff(&str, ' ');// 見やすくするように区切り文字追加
			// add_redirection_token(tokens);//以下をまとめる
			i = 0;
			while ((*tokens)[i] != '\0')
			{
				str_add_to_buff(&str, (*tokens)[i]);
				i++;
			}
			tokens++;
			// add_file_token(tokens);//以下をまとめる
			if (is_end(*tokens) == false)
			{
				str_add_to_buff(&str, ' ');// 見やすくするように区切り文字追加
				i = 0;
				while ((*tokens)[i] != '\0')
				{
					str_add_to_buff(&str, (*tokens)[i]);
					i++;
				}
				tokens++;
			}
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
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = ft_strnew(1);
	str.out_len = 0;
	while (is_connector(*tokens) == false && is_end(*tokens) == false
			&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
		{
			if (str.out_len > 0)
				str_add_to_buff(&str, ' ');// 見やすくするように区切り文字追加
			// add_redirection_token(tokens);//以下をまとめる
			i = 0;
			while ((*tokens)[i] != '\0')
			{
				str_add_to_buff(&str, (*tokens)[i]);
				i++;
			}
			tokens++;
			// add_file_token(tokens);//以下をまとめる
			if (is_end(*tokens) == false)
			{
				str_add_to_buff(&str, ' ');// 見やすくするように区切り文字追加
				i = 0;
				while ((*tokens)[i] != '\0')
				{
					str_add_to_buff(&str, (*tokens)[i]);
					i++;
				}
				tokens++;
			}
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
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = ft_strnew(1);
	str.out_len = 0;
	i = 0;
	while ((*tokens)[i] != '\0')
	{
		str_add_to_buff(&str, (*tokens)[i]);
		i++;
	}
	str_add_to_buff(&str, ' ');// 見やすくするように区切り文字追加
	tokens++;
	i = 0;
	while ((*tokens)[i] != '\0')
	{
		str_add_to_buff(&str, (*tokens)[i]);
		i++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}
