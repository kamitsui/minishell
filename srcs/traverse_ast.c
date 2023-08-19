/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:12:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 18:41:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"
#include "execute.h"

int	process_command(t_ast *node, char **env, int status)
{
	execute_command(node, env, status);
	return (status);
}

int	process_argument(t_ast *node, char **env, int status)
{
	(void)env;
	(void)node;
	return (status);
}

int	traverse_ast(t_ast *node, char **env, int status)
{
	int						i;
	enum e_NodeType			state;
	static t_handle_node	handle_node[3] = {
		process_command, process_argument, handle_operator};
	size_t					j;

	if (node == NULL)
		return (1);
	// Depth-First search (DFS) approach
	i = 0;
	state = NODE_COMMAND;
	while (state != NODE_END)
	{
		if (node->type == state)
			status = handle_node[i](node, env, status);
		state++;
	}
	// Traverse the children of the current node
	j = 0;
	while (j < node->num_children)
	{
		status = traverse_ast(node->children[j], env, status);
		j++;
	}
	return (status);
}
