/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_children.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:06:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 14:06:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error_minishell.h"
#include <stdlib.h>

void	add_node_children(
			t_ast *node, enum e_NodeType new_node_type, char *value)
{
	t_ast	*new_node;

	new_node = create_node(new_node_type, value);
	node->num_children++;
	node->children = (t_ast **)ft_realloc_tentative(node->children,
			node->num_children * sizeof(t_ast *),
			(node->num_children - 1) * sizeof(t_ast *));
	node->children[node->num_children - 1] = new_node;
}
