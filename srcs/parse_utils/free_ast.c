/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:28:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 18:29:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

void	free_ast(t_ASTNode *node)
{
	size_t	i;

	if (!node)
		return ;
	i = 0;
	while (i <node->num_children)
	{
		free_ast(node->children[i]);
		i++;
	}
	free(node->children);
	free(node->value);
	free(node);
}
