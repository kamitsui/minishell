/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 15:20:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"
#include "execute.h"
#include "ft_printf.h"//for debug

//int	process_command(t_ast *node, char **env, int status)
//{
//	execute_command(node, env, status);
//	return (status);
//}

int	process_argument(t_ast *node, char **env, int status)
{
//	if (node->type != NODE_ARGUMENT)
//		return (-1);
//	ft_printf("node [%p]", node);
//	ft_printf("\tARGUMENT\t[%s]\n", node->value);
    // Handle variable expansion $VAR
    // Handle tilde expansion  ~/Document
	(void)env;
	(void)node;
	ft_printf("process arg status[%d]\n", status);
	return (status);
}

int	traverse_ast(t_ast* node, char **env, int status)
{
	int						i;
	enum e_NodeType			state;
	static t_handle_node	handle_node[3] = {
		execute_command, process_argument, handle_operator};
		//process_command, process_argument, handle_operator};

	if (node == NULL)
		return (1);

	// Depth-First search (DFS) approach
	i = 0;
	state = NODE_COMMAND;
	while (state != NODE_END)
	{
//		ft_printf("node value[%s] type[%d]\n", node->value, node->type);
		if (node->type == state)
			status = handle_node[i](node, env, status);
//		ft_printf("status[%d] ... value[%s] type[%d] num while[%d]\n",
//				status, node->value, node->type, state);
		state++;
	}

	// Traverse the children of the current node
	size_t	j;
	j = 0;
	while (j < node->num_children)
	{
		status = traverse_ast(node->children[j], env, status);
		j++;
	}
	return (status);
}
