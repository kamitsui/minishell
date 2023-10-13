/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 15:06:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"
#include "parse.h"
#include "traverse.h"
#include "minishell.h"
#include "ft_printf.h"

#include "debug.h"
int	g_flag_debug;
int	g_fd_log;

// test 2 patern
#define LINE1 ">in"
#define LINE2 ">>here_doc"
#define LINE3 "<out"
#define LINE4 "<<append"
#define LINE5 "ls -l && non_exist || echo 42"
#define NUM		5

int main(int argc, char *argv[], char *env[])
{
	t_envwrap	*env_wrapper;
	t_ast	*ast;
	char	**tokens;
	static char	*lines[NUM] = {LINE1, LINE2, LINE3, LINE4, LINE5};
	int	i;

	g_flag_debug = DEBUG_ON;
	g_fd_log = open_log("debug.log", O_TRUNC);
	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		handle_error(ERR_CREATE_ENV);

	i = 0;
	while (i < NUM)
	{
		tokens = tkn_controller(lines[i]);
		debug_token(tokens);
		ast = parse(tokens);
		debug_ast(ast);
		free_two_darray(tokens);
		i++;
	}
//	env_wrapper->exit_code = execute_command(ast->children[0], env_wrapper);

	free_envwrap(env_wrapper);

	system("leaks a.out");
	(void)argv[argc];
	return (0);
}
