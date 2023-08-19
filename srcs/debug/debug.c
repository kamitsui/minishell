/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 18:43:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execute.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	debug_input(char *line)
{
	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- input debug ----\n");
	ft_printf("line %p [%s]\n", line, line);
	ft_printf("\x1B[0m\n\n");
}

void	debug_token(char **tokens)
{
	int		i;

	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- char *tokens[] ----\n");
	i = 0;
	while (tokens[i] != NULL)
	{
		ft_printf("tokens[%d] %p [%s]\n", i, tokens[i], tokens[i]);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}

void	debug_command(t_command *command)
{
	int		i;

	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- command ----\n");
	ft_printf("\tcmd_name [%s]\n", command->cmd_name);
	ft_printf("\t");
	i = 0;
	ft_printf("args");
	while (command->args[i] != NULL)
	{
		ft_printf(" [%s]", command->args[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\tnum_args [%d]\n", command->num_args);
	ft_printf("\n");
	i = 0;
	ft_printf("\tenv [%s]\n", command->env[i]);
	while (command->env[i] != NULL)
	{
		ft_printf("\t    [%s]\n", command->env[i]);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}
