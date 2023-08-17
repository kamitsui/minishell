/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:41:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 12:12:27 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"parse.h"

void	display_head(t_ASTNode *node)
{
	ft_printf("\n\nnode address [%p]\n", node);
	ft_printf("\ttype\t[%d]\n", (int)node->type);
	ft_printf("\tvalue\t[%s]\n", node->value);
	ft_printf("\tchildren\t[%p]\n", node->children);
	ft_printf("\tnum_children\t[%d]\n", node->num_children);
}

void	display_children(t_ASTNode *node)
{
	size_t	i;

	if (node->num_children == 0)
		return ;
	ft_printf("\n\n");
	ft_printf("\tparent[%s]\ttype[%d]\n", node->value, (int)node->type);
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

void	debug_ast(t_ASTNode *ast)
{
	size_t	i;
	t_ASTNode	*node;

	ft_printf("\n\x1B[45m\x1B[37m");
	ft_printf("---- AST debug  ----\n");
	display_children(ast);
	node = ast;
	i = 1;
	while (i < ast->num_children)
	{
		display_children(node->children[i]);
		i++;
	}
	ft_printf("\x1B[0m\n\n");
}
