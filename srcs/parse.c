/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:25:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 19:31:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "parse.h"
#include <stdlib.h>
#include <string.h>

t_ast	*parse_operator(char ***tokens)
{
	if (**tokens && strcmp(**tokens, "&&") == 0)
	{
		(*tokens)++;
		return (create_node(NODE_OPERATOR, *(*tokens - 1)));
	}
	return (NULL);
}

t_ast	*parse(char **tokens)
{
	t_ast	*ast;
	t_ast	*operator_node;

	ast = create_node(NODE_OPERATOR, PROGRAM_NAME);
	while (*tokens)
	{
		if (strcmp(*tokens, "&&") == 0)
		{
			operator_node = parse_operator(&tokens);
			if (operator_node)
			{
				ast->num_children++;
				ast->children = (t_ast **)realloc(ast->children,
						ast->num_children * sizeof(t_ast *));
				ast->children[ast->num_children - 1] = operator_node;
			}
		}
		else
			ast = parse_command(ast, &tokens);
	}
	return (ast);
}
// The way of test parse function
// |
// cd minishell/test/unit_function
// |
// parse test
//     tokens = { "ls", "-l", "file.txt", "&&", "cat", "file.txt", NULL }
// make 3
// make run3
// |
// parse & execute
//     tokens = { "ls", "-l", "-a", "&&", "echo", "\n", "42", "tokyo", NULL }
// make 4
// make run4
