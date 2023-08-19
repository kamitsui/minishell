/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:54:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 15:19:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

t_ast	*create_node(enum e_NodeType type, char *value)
{
	t_ast	*node;

	node = (t_ast *)malloc(sizeof(t_ast));
	node->type = type;
	node->flag = 1 << type;
	node->value = ft_strdup(value);
	node->children = NULL;
	node->num_children = 0;
	return (node);
}
