/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 00:49:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "execute.h"
#include "environ.h"
#include "minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"
#include "libft.h"

#include "debug.h"
int	g_flag_debug;
int	g_fd_log;

// test 2 patern
#define LINE1 "ls -l -a"
#define LINE2 "hoge1 hoge2 hoge3"

int main(int argc, char *argv[], char *env[])
{
	int		status = 0;
	char	*line1 = LINE1;// exit status 0
	char	*line2 = LINE2;// exit status 127
	char	**tokens1 = ft_split(line1, ' ');
	char	**tokens2 = ft_split(line2, ' ');
	t_ast	*ast1 = parse(tokens1);
	t_ast	*ast2 = parse(tokens2);
	t_ast	*command_node;
	t_envwrap	*env_wrapper;

	g_flag_debug = DEBUG_ON;
	g_fd_log = open_log("debug.log", O_TRUNC);
	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		handle_error(ERR_CREATE_ENV);

	// Parse the tokens and execute the commands (simple-command AST Node)
	ft_dprintf(g_fd_log, "> minishell %s\n", LINE1);
	debug_token(tokens1);
	command_node = ast1->children[0];
	debug_ast(command_node);
	//status = execute_command(command_node, env, status);
	status = execute_command(command_node, env_wrapper);
	ft_dprintf(g_fd_log,
		"return(%d) ... from execute_command(command_node, env_wrapper)\n\n", status);

	ft_dprintf(g_fd_log, "> minishell %s\n", LINE2);
	debug_token(tokens2);
	command_node = ast2->children[0];
	debug_ast(command_node);
	//status = execute_command(command_node, env, status);
	status = execute_command(command_node, env_wrapper);
	ft_dprintf(g_fd_log,
		"return(%d) ... from execute_command(command_node, env_wrapper)\n\n", status);

	// Free the allocated memory for the AST
	free_ast(ast1);
	free_ast(ast2);

	free_two_darray(tokens1);
	free_two_darray(tokens2);
	free_envwrap(env_wrapper);
	(void)argv[argc];
	return (status);
}
