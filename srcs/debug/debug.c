/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 14:00:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include <stdlib.h>

void	debug_input(char *line)
{
	// ANSI escape codes for changing text and background colors
	ft_printf("\n\x1B[45m\x1B[37m"); // Set purple background and white text
	ft_printf("---- input debug ----\n");
	ft_printf("line %p [%s]\n", line, line);// for debug
	ft_printf("\x1B[0m\n\n"); // Reset colors to default
}

void	debug_tokenize(t_token *tokens)
{
	int	i;

	ft_printf("\n\x1B[45m\x1B[37m"); // Set purple background and white text
	ft_printf("---- debug tokens ----\n");
	i = 0;
	while (tokens[i].var != NULL)
	{
		ft_printf("tokens[%d].var %p [%s]\ttokens[%d].type %d\n"
				, i, tokens[i].var, tokens[i].var
				, i, tokens[i].type);
		i++;
	}
	ft_printf("\x1B[0m\n\n"); // Reset colors to default
}
