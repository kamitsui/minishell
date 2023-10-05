/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_envwrap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:10:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 21:30:21 by kamitsui         ###   ########.fr       */
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
#define LINE1 "ls -l -a"
#define LINE2 "hoge1 hoge2 hoge3"

static int	change_stdout_fd(void)
{
	int	prev_fd;

	prev_fd = dup(STDOUT_FILENO);
	dup2(g_fd_log, STDOUT_FILENO);
	return (prev_fd);
}

static void	recover_stdout_fd(int prev_fd)
{
	dup2(prev_fd, STDOUT_FILENO);
}

static void	debug_env_lst(t_list *env_list)
{
	size_t	i;
	t_env	*env;
	char	*key;
	char	*val;

	i = 0;
	if (g_flag_debug == DEBUG_ON)
	{
		env = (t_env *)env_list->content;
		key = env->key;
		val = env->val;
		ft_dprintf(g_fd_log, "%s---- env list debug ----\n", DEBUG_COLOR);
		ft_dprintf(g_fd_log,
			"env list No.%d  key[%s]  val[%s]\n", i, key, val);
	}
}

int main(int argc, char *argv[], char *env[])
{
	t_envwrap	*env_wrapper;
	t_ast	*ast;
	char	**tokens;
	int	prev_fd;

	g_flag_debug = DEBUG_ON;
	g_fd_log = open_log("debug.log", O_TRUNC);
	ft_dprintf(g_fd_log, "\n>> call create_env_list\n");
	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		handle_error(ERR_CREATE_ENV);

	prev_fd = change_stdout_fd();
	ft_lstiter(env_wrapper->env->next, _env_print_lst);
	debug_env_lst(env_wrapper->env->next);
	recover_stdout_fd(prev_fd);

	ft_dprintf(g_fd_log, "\n>> call ft_env\n");
	prev_fd = change_stdout_fd();
	ft_env(env_wrapper);
	recover_stdout_fd(prev_fd);
//	tokens = tkn_controller(LINE1);// why ??
	tokens = ft_split(LINE1, ' ');
	debug_token(tokens);
	ast = parse(tokens);
	debug_ast(ast);
	env_wrapper->exit_code = execute_command(ast->children[0], env_wrapper);

	free_envwrap(env_wrapper);

//	system("leaks a.out");
	(void)argv[argc];
	return (0);
}
