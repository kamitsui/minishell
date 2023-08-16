/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_traverse_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 18:17:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include <stdlib.h>

t_ASTNode	*set_test_ast(void)
{
	t_ASTNode	*ast = create_node(NODE_OPERATOR, "minishell");
	t_ASTNode	*node = ast;

	// parent		"minishell"
	// childerenls	"ls" "operator" "cat"
	node->num_children = 3;
	node->children = (t_ASTNode **)realloc(node->children, node->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_COMMAND, "ls");
	node->children[1] = create_node(NODE_OPERATOR, "|");
	node->children[2] = create_node(NODE_COMMAND, "cat");

	// parent		"ls"
	// childerenls	"-a" "file.txt"
	node = ast->children[0];
	node->num_children = 2;
	node->children = (t_ASTNode **)realloc(node->children, node->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_ARGUMENT, "-a");
	node->children[1] = create_node(NODE_ARGUMENT, "file.txt");

	// parent		"operator"
	// childerenls	non

	// parent		"cat"
	// childerenls	"file.txt"
	node = ast->children[2];
	node->num_children = 1;
	node->children = (t_ASTNode **)realloc(node->children, node->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_ARGUMENT, "file.txt");

	return (ast);
}

int main() {
//	assumption
//	char* tokens[] = { "ls", "-l", "file.txt", "|", "cat", "file.txt", NULL };
//	debug_token(tokens);
    t_ASTNode* ast = set_test_ast();
	debug_ast(ast);

    // Traverse the AST and execute the commands (implementation not shown here)
	traverse_ast(ast);

    // Free the allocated memory for the AST
    free_ast(ast);

    return 0;
}
