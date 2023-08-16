/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 12:20:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	debug_input(char *line)
{
	ft_printf("\n\x1B[45m\x1B[37m");
	ft_printf("---- input debug ----\n");
	ft_printf("line %p [%s]\n", line, line);
	ft_printf("\x1B[0m\n\n");
}

void	debug_tokenize(t_token *tokens)
{
	int		i;
	char	*type;

	ft_printf("\n\x1B[45m\x1B[37m");
	ft_printf("---- debug tokens ----\n");
	i = 0;
	while (tokens[i].var != NULL)
	{
		type = ft_itoa_binary(tokens[i].type);
		ft_printf("tokens[%d].var %p [%s]\ttokens[%d].type 0x%s\n",
			i, tokens[i].var, tokens[i].var, i, type);
		free(type);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}


void	debug_token(char **tokens)
{
	int		i;

	ft_printf("\n\x1B[45m\x1B[37m");
	ft_printf("---- char *tokens[] ----\n");
	i = 0;
	while (tokens[i] != NULL)
	{
		ft_printf("tokens[%d] %p [%s]\n", i, tokens[i], tokens[i]);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}
