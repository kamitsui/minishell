/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:58:10 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/16 21:43:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "parse.h"
#include "libft.h"
#include <stdlib.h>

char	*join_to_out(const char *s1, const char *s2, size_t len2)
{
	char	*str;
	size_t	len1;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL && s2 != NULL)
	{
		s1 = ft_strnew(1);
		len1 = 0;
	}
	else
		len1 = ft_strlen(s1);
	str = ft_strnew(len1 + len2);
	if (str == NULL)
		ft_errno_exit("ft_strnew");
	ft_strlcpy(str, s1, len1 + 1);
	ft_memcpy(&str[len1], s2, len2);
	free((void *)s1);
	return (str);
}

void	add_to_buff(t_string *str, const char c)
{
	if (str->len == BUFF_SIZE)
	{
		str->out = join_to_out(str->out, str->buffer, str->len);
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

char	*get_command_value(char **tokens)
{
	t_string	str;
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	while (is_connector(*tokens) == false && is_end(*tokens) == false)
	{
		i = 0;
		while (*tokens[i] != '\0')
		{
			add_to_buff(&str, *tokens[i]);
			i++;
		}
		tokens++;
	}
	return (str.out);
}

char	*get_simple_command_value(char **tokens)
{
	t_string	str;
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = NULL;
	str.out_len = 0;
	while (is_connector(*tokens) == false && is_end(*tokens) == false
			&& is_pipe(*tokens) == false)
	{
		i = 0;
		while (*tokens[i] != '\0')
		{
			add_to_buff(&str, *tokens[i]);
			i++;
		}
		tokens++;
	}
	return (str.out);
}

char	*get_redirection_value(char **tokens)
{
	t_string	str;
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = NULL;
	str.out_len = 0;
	while (is_connector(*tokens) == false && is_end(*tokens) == false
			&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
		{
			if (str.out_len > 0)
				add_to_buff(&str, ' ');
			// add_redirection_token(tokens);//以下をまとめる
			i = 0;
			while (*tokens[i] != '\0')
			{
				add_to_buff(&str, *tokens[i]);
				i++;
			}
			tokens++;
			// add_file_token(tokens);//以下をまとめる
			if (is_end(*tokens) == false)
			{
				i = 0;
				while (*tokens[i] != '\0')
				{
					add_to_buff(&str, *tokens[i]);
					i++;
				}
				tokens++;
			}
		}
		else
			tokens++;
	}
	return (str.out);
}

char	*get_executable_value(char **tokens)
{
	t_string	str;
	size_t		i;

	ft_bzero(&str.buffer, BUFF_SIZE);
	str.len = 0;
	str.out = NULL;
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
		while (*tokens[i] != '\0')
		{
			add_to_buff(&str, *tokens[i]);
			i++;
		}
		tokens++;
	}
	return (str.out);
}
