/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 13:47:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ft_printf.h"//for debug

int	execute_command(t_ASTNode *node, char **env)
{
	if (node->type != NODE_COMMAND)
		return (-1);
	ft_printf("node [%p]", node);
	ft_printf("\tCOMMAND\t\t[%s]\n", node->value);
	(void)env;
	return (0);
}

int	process_argument(t_ASTNode *node, char **env)
{
	if (node->type != NODE_ARGUMENT)
		return (-1);
	ft_printf("node [%p]", node);
	ft_printf("\tARGUMENT\t[%s]\n", node->value);
	(void)env;
	return (0);
}

int	handle_operator(t_ASTNode *node, char **env)
{
	if (node->type != NODE_OPERATOR)
		return (-1);
	ft_printf("node [%p]", node);
	ft_printf("\tOPERATOR\t[%s]\n", node->value);
	(void)env;
	return (0);
}

void	traverse_ast(t_ASTNode* node, char **env)
{
	int						i;
	int						ret;
	static t_handle_node	handle_node[NODE_END] = {
		execute_command, process_argument, handle_operator};

	if (node == NULL)
		return ;

	// Depth-First search (DFS) approach
	i = 0;
	ret = -1;
	while (i < NODE_END && ret < 0)
	{
		ret = handle_node[i](node, env);
		i ++;
	}

	// Traverse the children of the current node
	size_t	j;
	j = 0;
	while (j < node->num_children)
	{
		traverse_ast(node->children[j], env);
		j++;
	}
}
