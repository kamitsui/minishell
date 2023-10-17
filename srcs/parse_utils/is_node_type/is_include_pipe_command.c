/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_include_pipe_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:11:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 08:12:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

bool	is_include_pipe_command(char **tokens)
{
	while (is_end(*tokens) == false && is_connector(*tokens) == false)
	{
		if (is_pipe(*tokens) == true)
			return (true);
		tokens++;
	}
	return (false);
}
