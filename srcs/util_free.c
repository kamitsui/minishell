/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:29:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 10:53:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_line(char **line)
{
	int	i = 0;

	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
}

void	free_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].var != NULL)
	{
		free(tokens[i].var);
		i++;
	}
	free(tokens);
}
