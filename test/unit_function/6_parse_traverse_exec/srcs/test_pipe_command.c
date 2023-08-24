/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:10:07 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 15:22:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "traverse.h"
#include "execute.h"
#include "ft_printf.h"
#include "libft.h"

// test 2 patern
#define LINE1 "ls -l -a | cat -e | grep Make"
#define LINE2 "hoge1 hoge2 hoge3"

int main(int argc, char *argv[], char *env[])
{
	int		status;
	char	*line1 = LINE1;// exit status 0
	char	*line2 = LINE2;// exit status 127
	char	**tokens1 = ft_split(line1, ' ');
	char	**tokens2 = ft_split(line2, ' ');
	t_ast* ast1 = parse(tokens1);
	t_ast* ast2 = parse(tokens2);

	// Traverse the AST and execute the commands (implementation not shown here)
	ft_printf("> minishell %s\n", LINE1);
	debug_token(tokens1);
	debug_ast(ast1);
	status = -1;
	status = traverse_ast(ast1, env, status);
	ft_printf("return(%d) ... from traverse(ast, env)\n\n", status);
	exit(status);
	ft_printf("> minishell %s\n", LINE2);
	debug_token(tokens2);
	debug_ast(ast2);
	status = -1;
	status = traverse_ast(ast2, env, status);
	ft_printf("return(%d) ... from traverse(ast, env)\n", status);

	// Free the allocated memory for the AST
	free_ast(ast1);
	free_ast(ast2);

	int	i;
	i = 0;
	while (tokens1[i] != NULL)
	{
		free(tokens1[i]);
		i++;
	}
	free(tokens1);
	i = 0;
	while (tokens2[i] != NULL)
	{
		free(tokens2[i]);
		i++;
	}
	free(tokens2);
	(void)argv[argc];
	return (status);
}
