/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_include_pipe_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:11:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/25 23:00:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

bool	is_include_pipe_command(char **tokens)
{
	size_t	count_pipe;

	count_pipe = 0;
	while (is_end(*tokens) == false && is_connector(*tokens) == false)
	{
		if (is_pipe(*tokens) == true)
		{
			if (count_pipe > 0)
				return (true);
			else
				count_pipe++;
		}
		tokens++;
	}
	return (false);
}
