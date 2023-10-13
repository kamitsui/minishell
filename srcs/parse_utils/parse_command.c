/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 04:57:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_command.c
 * @brief <simple-command> or <pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

// for debug
#include "ft_printf.h"// debug
#include "debug.h"// debug

/**
 * @brief \<command>のノードを作る関数
 * ::= <simple-command> or <pipe-command> or <io-redirection>
 *
 * @param ast 親のノード
 * @param tokens トークンのアドレス
 *
 * @return 生成された<command>のノードを返す
 */
t_ast	*parse_command(t_ast *ast, char ***tokens)
{
	t_ast	*node;
	size_t	num_pipe;

	num_pipe = count_pipe_command(*tokens);
	if (num_pipe > 0)
		node = parse_pipe_command(tokens, num_pipe);
	else if (is_redirection(**tokens) == true)
		node = parse_io_redirection(tokens);
	else
		node = parse_simple_command(tokens);
	if (node)
	{
		ast->num_children++;
		ast->children = (t_ast **)realloc(ast->children,// use ft_realloc
				ast->num_children * sizeof(t_ast *));
		ast->children[ast->num_children - 1] = node;
	}
	return (ast);
}
// debug code
//	debug_parse("parse_command", node);// debug
