/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_include_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:09:48 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 20:04:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

bool	is_include_redirection(char **tokens)
{
	while (is_end(*tokens) == false && is_connector(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
			return (true);
		tokens++;
	}
	return (false);
}

bool	is_include_redirection_in_simple_com(char **tokens)
{
	while (is_end(*tokens) == false && is_connector(*tokens) == false
		&& is_pipe(*tokens) == false)
	{
		if (is_redirection(*tokens) == true)
			return (true);
		tokens++;
	}
	return (false);
}
