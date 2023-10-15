/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:10:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 21:21:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "traverse.h"
#include "execute.h"
#include "minishell.h"
#include "environ.h"
#include "error_minishell.h"
#include "ft_printf.h"
#include "libft.h"

#include "debug.h"
int	g_flag_debug;
int	g_fd_log;

// test 2 patern
#define LINE1 "ls -l -a | cat -e | grep Make"
#define LINE2 "hoge1 -a | hoge2 -b | hoge3"

int main(int argc, char *argv[], char *env[])
{
	t_envwrap	*env_wrapper;
	int		status;
	char	**tokens;
	t_ast	*ast;


	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		handle_error(ERR_CREATE_ENV);

// test1
	tokens = ft_split(LINE1, ' ');
	ast = parse(tokens);

	// Traverse the AST and execute the commands (implementation not shown here)
	ft_printf("> minishell %s\n", LINE1);
	debug_token(tokens);
	debug_ast(ast);
	status = traverse_ast(ast, env_wrapper);
	ft_printf("return(%d) ... from traverse(ast, env_wrapper)\n\n", status);
	// Free the allocated memory for the AST
	free_ast(ast);
	free_two_darray(tokens);

// test2
	tokens = ft_split(LINE2, ' ');
	ast = parse(tokens);

	// Traverse the AST and execute the commands (implementation not shown here)
	ft_printf("> minishell %s\n", LINE2);
	debug_token(tokens);
	debug_ast(ast);
	status = traverse_ast(ast, env_wrapper);
	ft_printf("return(%d) ... from traverse(ast, env_wrapper)\n\n", status);
	// Free the allocated memory for the AST
	free_ast(ast);
	free_two_darray(tokens);

	free_envwrap(env_wrapper);
	(void)argv[argc];
	return (status);
}
