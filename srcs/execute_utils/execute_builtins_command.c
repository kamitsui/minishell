/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:45:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 18:02:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "builtins.h"
#include "libft.h"

// for debug
#include "ft_printf.h"
#include "debug.h"

int	execute_builtins_command(t_ast *node, t_envwrap *env_wrapper)
{
	static t_call_builtins	f_call_builtins[NUM_BUILTINS]
		= {call_echo, call_cd, call_pwd, call_env,
		call_unset, call_export, call_exit};
	static char				*str_builtins[NUM_BUILTINS]
		= {STR_ECHO, STR_CD, STR_PWD, STR_ENV, STR_UNSET, STR_EXPORT, STR_EXIT};
	size_t					i;
	int						status;

	status = EXIT_SUCCESS;
	i = 0;
	while (i < NUM_BUILTINS)
	{
		if (ft_strcmp(str_builtins[i], node->value) == 0)
		{
			status = f_call_builtins[i](node, env_wrapper);
			break ;
		}
		i++;
	}
	return (status);
}
// debug code
//			ft_dprintf(g_fd_log, ">> call ft_%s\n", str_builtins[i]);//debug
//	debug_status("builtins_command", status);// debug
//	debug_leaks("builtins_command", "minishell");// debug
