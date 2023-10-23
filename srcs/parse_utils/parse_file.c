/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:40:13 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 03:49:14 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

t_ast	*parse_file(char ***tokens)
{
	if (is_string(**tokens) == true)
	{
		(*tokens)++;
		return (create_node(NODE_FILE, *(*tokens - 1)));
	}
	return (NULL);
}
