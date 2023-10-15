/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:10:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/15 14:37:17 by kamitsui         ###   ########.fr       */
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

// test patern
#define LINE1 "ls -l -a | cat -e | grep Make"// return(0)
#define LINE2 "hoge1 -a | hoge2 -b | hoge3"// return(127)
#define LINE3 "hoge1 | ls -l | echo 42"// return(0)
#define NUM 3

int main(int argc, char *argv[], char *env[])
{
	t_envwrap	*env_wrapper;
	int		status;
	char	**tokens;
	t_ast	*ast;
	static char	*line[3] = {LINE1, LINE2, LINE3};
	size_t	i;

	env_wrapper = create_env_list(env);
	if (env_wrapper == NULL)
		handle_error(ERR_CREATE_ENV);

	i = 0;
	while (i < NUM)
	{
		tokens = ft_split(line[i], ' ');
		ast = parse(tokens);
		ft_printf("> minishell %s\n", line[i]);
		debug_token(tokens);
		debug_ast(ast);
		// Traverse the AST and execute the commands (implementation not shown here)
		status = traverse_ast(ast, env_wrapper);
		ft_printf("return(%d) ... from traverse(ast, env_wrapper)\n\n", status);
		// Free the allocated memory for the AST
		free_ast(ast);
		free_two_darray(tokens);
		i++;
	}

	free_envwrap(env_wrapper);
	(void)argv[argc];
	return (status);
}
