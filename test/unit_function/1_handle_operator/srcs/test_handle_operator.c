/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_handle_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 19:28:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "debug.h"

int main(int argc, char *argv[], char *env[]) {
    // tokens = { "ls", "-a", "-l", "|", "cat", "-e", "|", "grep", "Make", NULL }
	t_ASTNode* pipe_node = create_node(NODE_OPERATOR, "|");
	pipe_node->num_children = 3;
	pipe_node->children = (t_ASTNode**)malloc(3 * sizeof(t_ASTNode*));
	pipe_node->children[0] = create_node(NODE_COMMAND, "ls");
		pipe_node->children[0]->num_children = 2;
		pipe_node->children[0]->children = (t_ASTNode**)malloc(2 * sizeof(t_ASTNode*));
		pipe_node->children[0]->children[0] = create_node(NODE_ARGUMENT, "-a");
		pipe_node->children[0]->children[1] = create_node(NODE_ARGUMENT, "-l");
	pipe_node->children[1] = create_node(NODE_COMMAND, "cat");
		pipe_node->children[1]->num_children = 1;
		pipe_node->children[1]->children = (t_ASTNode**)malloc(1 * sizeof(t_ASTNode*));
		pipe_node->children[1]->children[0] = create_node(NODE_ARGUMENT, "-e");
	pipe_node->children[2] = create_node(NODE_COMMAND, "grep");
	//pipe_node->children[2] = create_node(NODE_COMMAND, "grepee");// exit status 127 (command not found)
		pipe_node->children[2]->num_children = 1;
		pipe_node->children[2]->children = (t_ASTNode**)malloc(1 * sizeof(t_ASTNode*));
		pipe_node->children[2]->children[0] = create_node(NODE_ARGUMENT, "Make");

	debug_ast(pipe_node);
    int status = handle_operator(pipe_node, env);
	printf("(%d) ... exit status from handle_operator(pipe_node, env)\n", status);

    // Clean up allocated memory
    free_ast(pipe_node);

	(void)argv[argc];
    return status;
}
