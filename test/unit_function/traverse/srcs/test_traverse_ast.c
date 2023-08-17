/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_traverse_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 13:13:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include <stdlib.h>

void	set_test_ast(t_ASTNode *ast)
{
	t_ASTNode *node;

	// parent		"minishell"
	// childerenls	"|"
	node = ast;
	ast->num_children = 1;
	ast->children = (t_ASTNode **)realloc(ast->children, ast->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_OPERATOR, "|");

	// parent		"|"
	// childerenls	"ls" "cat"
	node = ast->children[0];
	node->num_children = 2;
	node->children = (t_ASTNode **)realloc(node->children, node->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_COMMAND, "ls");
	node->children[1] = create_node(NODE_COMMAND, "cat");

	// parent		"ls"
	// childerenls	"-a" "-l"
	node = ast->children[0]->children[0];
	node->num_children = 2;
	node->children = (t_ASTNode **)realloc(node->children, node->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_ARGUMENT, "-a");
	node->children[1] = create_node(NODE_ARGUMENT, "-l");

	// parent		"cat"
	// childerenls	"file.txt"
	node = ast->children[0]->children[1];
	node->num_children = 1;
	node->children = (t_ASTNode **)realloc(node->children, node->num_children * sizeof(t_ASTNode*));
	node->children[0] = create_node(NODE_ARGUMENT, "file.txt");

}

int main(int argc, char *argv[], char *env[])
{
//	assumption
//	char* tokens[] = { "ls", "-l", "file.txt", "|", "cat", "file.txt", NULL };
//	debug_token(tokens);

	t_ASTNode *ast;
	// ast head "minishell"
	ast = create_node(NODE_OPERATOR, "minishell");
	set_test_ast(ast);
	debug_ast(ast);

	// Traverse the AST and execute the commands (implementation not shown here)
	traverse_ast(ast, env);

	// Free the allocated memory for the AST
	//free_ast(ast);

	(void)argv[argc];
	return 0;
}
