/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_handle_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 19:17:35 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"
#include "debug.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int	main(int argc, char *argv[], char *env[])
{
	t_ast* pipe_node = create_node(NODE_OPERATOR, "|");
	pipe_node->num_children = 3;
	pipe_node->children = (t_ast**)malloc(3 * sizeof(t_ast*));
	pipe_node->children[0] = create_node(NODE_COMMAND, "ls");
		pipe_node->children[0]->num_children = 2;
		pipe_node->children[0]->children = (t_ast**)malloc(2 * sizeof(t_ast*));
		pipe_node->children[0]->children[0] = create_node(NODE_ARGUMENT, "-a");
		pipe_node->children[0]->children[1] = create_node(NODE_ARGUMENT, "-l");
	pipe_node->children[1] = create_node(NODE_COMMAND, "cat");
		pipe_node->children[1]->num_children = 1;
		pipe_node->children[1]->children = (t_ast**)malloc(1 * sizeof(t_ast*));
		pipe_node->children[1]->children[0] = create_node(NODE_ARGUMENT, "-e");
	pipe_node->children[2] = create_node(NODE_COMMAND, "grep");
		pipe_node->children[2]->num_children = 1;
		pipe_node->children[2]->children = (t_ast**)malloc(1 * sizeof(t_ast*));
		pipe_node->children[2]->children[0] = create_node(NODE_ARGUMENT, "Make");

	debug_ast(pipe_node);
	int	status;
	status = 0;
	status = handle_operator(pipe_node, env, status);
	ft_printf("(%d) ... exit status from handle_operator(pipe_node, env)\n", status);
	free_ast(pipe_node);
	(void)argv[argc];
	return (status);
}
// tokens = { "ls", "-a", "-l", "|", "cat", "-e", "|", "grep", "Make", NULL }
	//pipe_node->children[2] = create_node(NODE_COMMAND, "grepee");// exit status 127 (command not found)
