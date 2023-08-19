/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 16:29:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include "execute.h"
#include "ft_printf.h"
#include "libft.h"

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

	// Parse the tokens and execute the commands (simple-command AST Node)
	ft_printf("> minishell %s\n", LINE1);
	debug_token(tokens1);
	command_node = ast1->children[0];
	debug_ast(command_node);
	status = execute_command(command_node, env, status);
	ft_printf("return(%d) ... from execute_command(command_node, env)\n\n", status);
	ft_printf("> minishell %s\n", LINE2);
	debug_token(tokens2);
	command_node = ast2->children[0];
	debug_ast(command_node);
	status = execute_command(command_node, env, status);
	ft_printf("return(%d) ... from execute_command(command_node,enc)\n", status);

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
