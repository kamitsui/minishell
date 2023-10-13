/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 14:45:56 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "traverse.h"
#include "execute.h"
#include "environ.h"
#include "minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"
#include "libft.h"

// test 2 patern
#define LINE1 "ls -l -a"
#define LINE2 "hoge1 hoge2 hoge3"

int main(int argc, char *argv[], char *env[])
{
	t_envwrap	*env_wrapper;
	int		status;
	char	*line1 = LINE1;// exit status 0
	char	*line2 = LINE2;// exit status 127
	char	**tokens1 = ft_split(line1, ' ');
	char	**tokens2 = ft_split(line2, ' ');

	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		handle_error(ERR_CREATE_ENV);
	t_ast* ast1 = parse(tokens1);
	t_ast* ast2 = parse(tokens2);

	// Traverse the AST and execute the commands (implementation not shown here)
	ft_printf("> minishell %s\n", LINE1);
	debug_token(tokens1);
	debug_ast(ast1);
	status = traverse_ast(ast1, env_wrapper);
	ft_printf("return(%d) ... from traverse(ast, env)\n\n", status);
	ft_printf("> minishell %s\n", LINE2);
	debug_token(tokens2);
	debug_ast(ast2);
	status = traverse_ast(ast2, env_wrapper);
	ft_printf("return(%d) ... from traverse(ast, env)\n", status);

	// Free the allocated memory for the AST
	free_ast(ast1);
	free_ast(ast2);

	free_two_darray(tokens1);
	free_envwrap(env_wrapper);
	(void)argv[argc];
	return (status);
}
