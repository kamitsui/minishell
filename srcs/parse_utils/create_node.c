/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:54:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 22:24:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

t_ASTNode	*create_node(t_NodeType type, char *value)
{
	t_ASTNode	*node;

	node = (t_ASTNode *)malloc(sizeof(t_ASTNode));
	node->type = type;
	node->flag = 1 << type;
	node->value = ft_strdup(value);
	node->children = NULL;
	node->num_children = 0;
	return (node);
}
