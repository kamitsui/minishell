/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_handle_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 20:50:38 by kamitsui         ###   ########.fr       */
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

int main() {
    // Example usage
	t_ASTNode* pipe_node = create_node(NODE_OPERATOR, "|");
	pipe_node->num_children = 3;
	pipe_node->children = (t_ASTNode**)malloc(3 * sizeof(t_ASTNode*));
	pipe_node->children[0] = create_node(NODE_COMMAND, "ls -a -l");
		pipe_node->children[0]->num_children = 2;
		pipe_node->children[0]->children = (t_ASTNode**)malloc(2 * sizeof(t_ASTNode*));
		pipe_node->children[0]->children[0] = create_node(NODE_ARGUMENT, "-a");
		pipe_node->children[0]->children[1] = create_node(NODE_ARGUMENT, "-l");
	pipe_node->children[1] = create_node(NODE_COMMAND, "cat -e");
		pipe_node->children[1]->num_children = 1;
		pipe_node->children[1]->children = (t_ASTNode**)malloc(1 * sizeof(t_ASTNode*));
		pipe_node->children[1]->children[0] = create_node(NODE_ARGUMENT, "-e");
	pipe_node->children[2] = create_node(NODE_COMMAND, "grep Make");
		pipe_node->children[2]->num_children = 1;
		pipe_node->children[2]->children = (t_ASTNode**)malloc(1 * sizeof(t_ASTNode*));
		pipe_node->children[2]->children[0] = create_node(NODE_ARGUMENT, "Make");

	debug_ast(pipe_node);
    handle_operator(pipe_node);

    // Clean up allocated memory
    free_ast(pipe_node);

    return 0;
}
