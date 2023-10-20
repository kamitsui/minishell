/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:45:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/20 20:23:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "error_minishell.h"
#include "ft_echo.h"
//void	ft_echo(char **argv);
#include "ft_cd.h"
//void	ft_cd(char *path, t_envwrap *env_wrap);

#include "environ.h"
//void	ft_pwd(t_envwrap *env);
//void	ft_env(t_envwrap *env_wrapper);
//void	ft_unset(t_envwrap *env_wrap, char *tgt_key);
//void	ft_export(t_envwrap *env_wrap, char *key_or_full, char *val_or_null);
//void	ft_exit(int status, t_envwrap *env_wrap);

#include "builtins.h"
#include "debug.h"
#include "libft.h"

#include "ft_printf.h"

int	call_echo(t_ast *node, t_envwrap *env_wrapper)
{
	char	**argv;
	size_t	i;

	(void)env_wrapper;
	argv = (char **)malloc(sizeof(char *) * (node->num_children + 1));
	i = 0;
	while (i < node->num_children)
	{
		argv[i] = node->children[i]->value;
		i++;
	}
	argv[i] = NULL;
	ft_echo(argv);
	free(argv);
	// ここではargv[i]をfreeせず、
	// 大元のlets_go_shell関数でnode->children[i]->valueをまとめてフリーする
	return (EXIT_SUCCESS);
}

int	call_cd(t_ast *node, t_envwrap *env_wrapper)
{
	char	*path;
	int		status;

	path = NULL;
	if (node->num_children > 0)
		path = node->children[0]->value;
	status = ft_cd(path, env_wrapper);
	return (status);
}

int	call_pwd(t_ast *node, t_envwrap *env_wrapper)
{
// pwd の失敗ケースは存在しないのでは？？？
	(void)node;
	ft_pwd(env_wrapper);
	return (EXIT_SUCCESS);
}

int	call_env(t_ast *node, t_envwrap *env_wrapper)
{
//	static const char	*cause = "env";
//	static const char	*error_msg = "No such file or directory";
// env: 123: No such file or directory

//	if (is_error_env(...) == true)
//	{
//		handl_error_not_exit(...);
//		return (EXIT_FAILURE);
//	}
	(void)node;// remove
	ft_env(env_wrapper);
	return (EXIT_SUCCESS);
}

int	call_unset(t_ast *node, t_envwrap *env_wrapper)
{
	char	*tgt_key;
//	static const char	*cause = "unset";
//	static const char	*error_msg = "not a valid identifier";
// bash: unset: `1': not a valid identifier

//	if (is_error_unset(...) == true)
//		handl_error_not_exit(...);
//		return (EXIT_FAILURE);
	tgt_key = node->children[0]->value;
	ft_unset(env_wrapper, tgt_key);
	return (EXIT_SUCCESS);
}

int	call_export(t_ast *node, t_envwrap *env_wrapper)
{
	char	*key_or_full;
	char	*val_or_null;
	size_t	i;
//	static const char	*cause = "exit";
//	static const char	*error_msg = "not a valid identifier";
// bash: export: `#JOI': not a valid identifier

	key_or_full = NULL;
	val_or_null = NULL;
//	if (is_error_export(...) == true)
//		handl_error_not_exit(...);
//		return (EXIT_FAILURE);
	if (node->num_children == 0)
		ft_export(env_wrapper, key_or_full, val_or_null);
	else
	{
		i = 0;
		while (i < node->num_children)
		{
			key_or_full = node->children[0]->value;
			ft_export(env_wrapper, key_or_full, val_or_null);
			i++;
		}
	}
	return (EXIT_SUCCESS);// 失敗のケースはどんな時？？？
}

bool	is_long(const char *str)
{
	char	*end_ptr;
	int		base;

	if (str == NULL)
		return (false);
	base = 10;
	ft_strtol(str, &end_ptr, base);
	if (*end_ptr == '\0')
		return (true);
	else
		return (false);
}

#define ERR_MSG_TOO_MANY_ARGS		"too many arguments"
#define ERR_MSG_NUMERRIC_ARG_REQUIRED	"numeric argument required"

int	call_exit(t_ast *node, t_envwrap *env_wrapper)
{
	int		status;
	char	*value;

	status = EXIT_SUCCESS;
	value = NULL;
	if (node->num_children > 0)
		value = node->children[0]->value;
	if (node->num_children == 0
		|| (is_long(value) == true && node->num_children > 0))
	{
				ft_dprintf(g_fd_log, ">> here2?\n");// debug
		if (node->num_children > 1)
		{
			ft_dprintf(STDERR_FILENO, "%s\n", STR_EXIT);
			ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
							NAME, STR_EXIT, ERR_MSG_TOO_MANY_ARGS);
			//exit
			//bash: exit: too many arguments
		}
		else
		{
			if (node->num_children == 1)
			{
				value = node->children[0]->value;
				status = (int)ft_strtol(value, NULL, 10);
			}
			ft_exit(status, env_wrapper);
		}
		return (EXIT_FAILURE);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "%s\n", STR_EXIT);
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n",
						NAME, value, ERR_MSG_NUMERRIC_ARG_REQUIRED);
		//exit
		//bash: exit: numeric argument required
		exit (255);// ??? ハードコーディングでいいのか？？
	}
}


int	execute_builtins_command(t_ast *node, t_envwrap *env_wrapper)
{
	static t_call_builtins	f_call_builtins[NUM_BUILTINS] = {
		call_echo, call_cd, call_pwd, call_env, call_unset, call_export, call_exit};
	static char				*str_builtins[NUM_BUILTINS] = {
		STR_ECHO, STR_CD, STR_PWD, STR_ENV, STR_UNSET, STR_EXPORT, STR_EXIT};
	size_t					i;
	int						status;

	status = EXIT_SUCCESS;
	i = 0;
	while (i < NUM_BUILTINS)
	{
		if (ft_strcmp(str_builtins[i], node->value) == 0)
		{
			ft_dprintf(g_fd_log, ">> call ft_%s\n", str_builtins[i]);//debug
			status = f_call_builtins[i](node, env_wrapper);
			break ;
		}
		i++;
	}
	debug_status("builtins_command", status);// debug
	debug_leaks("builtins_command", "minishell");// debug
	return (status);
}
