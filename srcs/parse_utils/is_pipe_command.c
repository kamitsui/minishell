/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:37:54 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 11:26:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"//debug

size_t	is_pipe_command(char **tokens)
{
	size_t	num_pipe;

	num_pipe = 0;
	ft_printf("token[%d] [%s]\n", num_pipe, *tokens);
	while (*tokens && ft_strcmp(*tokens, "&&"))
	{
		if (ft_strcmp(*tokens, "|") == 0)
			num_pipe++ ;
		tokens++;
		ft_printf("num_pipe[%d] token[%s]\n", (int)num_pipe, *tokens);
	}
	return (num_pipe);
}
