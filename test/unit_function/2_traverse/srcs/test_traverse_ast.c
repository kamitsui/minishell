/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_traverse_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 20:45:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "traverse.h"
#include "ft_printf.h"
#include <stdlib.h>

void	set_test_ast(t_ast *ast)
{
	t_ast *node;

	// parent		"minishell"
	// childerenls	"|"
	node = ast;
	ast->num_children = 1;
	ast->children = (t_ast **)realloc(ast->children, ast->num_children * sizeof(t_ast*));
	node->children[0] = create_node(NODE_OPERATOR, "|");

	// parent		"|"
	// childerenls	"ls" "cat"
	node = ast->children[0];
	node->num_children = 2;
	node->children = (t_ast **)realloc(node->children, node->num_children * sizeof(t_ast*));
	node->children[0] = create_node(NODE_COMMAND, "ls");
	node->children[1] = create_node(NODE_COMMAND, "cat");

	// parent		"ls"
	// childerenls	"-a" "-l"
	node = ast->children[0]->children[0];
	node->num_children = 2;
	node->children = (t_ast **)realloc(node->children, node->num_children * sizeof(t_ast*));
	node->children[0] = create_node(NODE_ARGUMENT, "-a");
	node->children[1] = create_node(NODE_ARGUMENT, "-l");

	// parent		"cat"
	// childerenls	"file.txt"
	node = ast->children[0]->children[1];
	node->num_children = 1;
	node->children = (t_ast **)realloc(node->children, node->num_children * sizeof(t_ast*));
	node->children[0] = create_node(NODE_ARGUMENT, "file.txt");

}

int main(int argc, char *argv[], char *env[])
{
//	assumption
//	char* tokens[] = { "ls", "-a", "-l", "|", "cat", "file.txt", NULL };
//	debug_token(tokens);

	t_ast *ast;
	// ast head "minishell"
	ast = create_node(NODE_OPERATOR, "minishell");
	set_test_ast(ast);
	debug_ast(ast);

	t_envwrap	*env_wrapper;
	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		return (EXIT_FAILURE);

	// Traverse the AST and execute the commands (implementation not shown here)
	ft_printf("env_wrapper exit_code [%d]\n", env_wrapper->exit_code);
	env_wrapper->exit_code = traverse_ast(ast, env_wrapper);
	ft_printf("return(%d)\n", env_wrapper->exit_code);

	// Free the allocated memory for the AST
	//free_ast(ast);

	free_envwrap(env_wrapper);

	(void)argv[argc];
	return 0;
}
