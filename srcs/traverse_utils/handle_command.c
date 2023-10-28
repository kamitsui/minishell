/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:04:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/28 19:31:24 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_command.c
 * @brief <simple-command>のノードに対しての処理
 */
#include "parse.h"
#include "traverse.h"
#include "execute.h"
#include "builtins.h"
#include "error_minishell.h"
#include <signal.h>

#include "debug.h"
#include "ft_printf.h"


int	handle_executable(t_ast *node, t_envwrap *env_wrapper)
{
	int	status;

	if (node->flag & BIT_EMPTY)
		return (EXIT_SUCCESS);
	if (is_builtins_command(node->value) == true)
		status = execute_builtins_command(node, env_wrapper);
	else
		status = execute_command(node, env_wrapper);
	if (status == (0x80 | SIGINT))
		ft_printf("\n");
	if (status == (0x80 | SIGQUIT))
		ft_printf(MSG_SIGQUIT);
	return (status);
}
// debug code
//	debug_status("handle_executable", status);// debug

int	handle_simple_command(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;
	int		status;
	int	original_stdout_fd;
	int	original_stdin_fd;

	if (node->flag & BIT_PARENTHESIS)
		return (handle_parenthesis(node, env_wrapper));
	i = 0;
	if (node->children[i]->type == NODE_EXECUTABLE)
	{
		status = handle_executable(node->children[i], env_wrapper);
		debug_status("handle_simple_command ... only executable", status);// debug
		ft_dprintf(g_fd_log, "\thead value[%s]\n", node->value);//debug
		return (status);
	}
	else
	{
		original_stdin_fd = buck_up_fd(STDIN_FILENO);
		original_stdout_fd = buck_up_fd(STDOUT_FILENO);
		status = handle_io_redirections(node->children[i], env_wrapper);
		if (status == EXIT_SUCCESS && node->num_children > 1)
			status = handle_executable(node->children[++i], env_wrapper);
		recover_fd(original_stdin_fd, STDIN_FILENO);
		recover_fd(original_stdout_fd, STDOUT_FILENO);
		debug_status("handle_simple_command ... exist redirection", status);// debug
		ft_dprintf(g_fd_log, "\thead value[%s]\n", node->value);//debug
		return (status);
	}
}

/**
 * @brief <simple-command>のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env_wrapper構造体  (env、exit_code, pwd)
 *
 * @return ノードの処理結果を終了ステータスとして返す
 */
int	handle_command(t_ast *node, t_envwrap *env_wrapper)
{
	int		status;

	debug_ast(node);
	handle_expansion(node, env_wrapper);
	handle_empty_node(&node, env_wrapper);
	if (node->children[0]->type == NODE_PIPE_COM)
		status = handle_pipe_command(node->children[0], env_wrapper);
	else
		status = handle_simple_command(node->children[0], env_wrapper);
	return (status);
}
