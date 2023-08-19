/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:23:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 19:25:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <string.h>// for strcmp()

t_ast	*parse_argument(char ***tokens)
{
	// 要改良！ is_argument
	if (**tokens && strcmp(**tokens, "&&") != 0)
	{
		(*tokens)++;
		return (create_node(NODE_ARGUMENT, *(*tokens - 1)));
	}
	return (NULL);
}
