/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_handle_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 13:28:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"
#include "debug.h"
#include "ft_printf.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define LINE	"ls -a -l | cat -e | grep Make"

int	main(int argc, char *argv[], char *env[])
{
	enable_debug(DEBUG_ON);

	t_ast	*ast;
	t_ast	*pipe_node;
	char	**tokens;
	tokens = ft_split(LINE, ' ');
	ast = parse(tokens);
	debug_ast(ast);
	pipe_node = ast->children[0]->children[0];
	debug_ast(pipe_node);

	t_envwrap	*env_wrapper;
	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		return (EXIT_FAILURE);

	int	status;
	status = handle_pipe_command(pipe_node, env_wrapper);
	ft_printf("(%d) ... exit status from handle_operator(pipe_node, env)\n",
				status);
	free_two_darray(tokens);
	free_ast(pipe_node);
	free_envwrap(env_wrapper);
	(void)argv[argc];
	return (status);
}
