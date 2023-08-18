/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 20:28:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "execute.h"
#include "ft_printf.h"

int main(int argc, char *argv[], char *env[])
{
	int	status;
	char* tokens[] = {
		"ls", "-l", "-a", NULL };
	debug_token(tokens);
	t_ASTNode* ast = parse(tokens);
	debug_ast(ast);

	// Traverse the AST and execute the commands (implementation not shown here)
	ft_printf("execute_command() start\n");
	status = execute_command(ast, env);
	ft_printf("execute_command() end\n");
	ft_printf("(%d) ... exit status from handle_operator(pipe_node, env)\n", status);

	// Free the allocated memory for the AST
	free_ast(ast);

	(void)argv[argc];
	return (status);
}
		//"ls", "-l", "-a", "&&", "echo", "\n", "42", "tokyo", NULL };
