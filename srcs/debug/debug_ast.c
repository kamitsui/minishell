/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:41:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 18:43:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"parse.h"

void	display_head(t_ast *node)
{
	ft_printf("\tTop Node [%s]\n", node->value);
}

void	display_children(t_ast *node)
{
	size_t	i;

	if (node->type == NODE_ARGUMENT)
		return ;
	ft_printf("\n\n");
	ft_printf("\tparent[%s]\ttype[%d]\n",
		node->value, (int)node->type);
	i = 0;
	while (i < node->num_children)
	{
		ft_printf("\t\tchildren[%d]\t[%s]",
			i, node->children[i]->value);
		ft_printf("\ttype\t[%d]\n", (int)node->children[i]->type);
		i++;
	}
	i = 0;
	while (i < node->num_children)
	{
		display_children(node->children[i]);
		i++;
	}
}

void	debug_ast(t_ast *ast)
{
	t_ast	*node;

	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- AST debug  ----\n");
	display_head(ast);
	node = ast;
	display_children(node);
	ft_printf("\x1B[0m\n\n");
}
