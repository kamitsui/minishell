/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 15:41:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_command.c
 * @brief <simple-command> or <pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

/**
 * @brief \<command> ::= <simple-command> or <pipe-command> のノードを作る関数
 *
 * @param ast 親のノード
 * @param tokens トークンのアドレス
 *
 * @return 生成された<command>のノードを返す
 */
t_ast	*parse_command(t_ast *ast, char ***tokens)
{
	t_ast	*command_node;
	size_t	num_pipe;

	num_pipe = is_pipe_command(*tokens);
	if (num_pipe > 0)
	{
		// 未実装
		//t_ast	*pipe_node = parse_pipe_command(tokens);
		return (ast);
	}
	command_node = parse_simple_command(tokens);
	if (command_node)
	{
		ast->num_children++;
		ast->children = (t_ast **)realloc(ast->children,
				ast->num_children * sizeof(t_ast *));
		ast->children[ast->num_children - 1] = command_node;
	}
	return (ast);
}
