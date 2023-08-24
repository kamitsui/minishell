/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 17:00:44 by kamitsui         ###   ########.fr       */
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
	t_ast	*node;
	size_t	num_pipe;

	num_pipe = is_pipe_command(*tokens);//! count_pipes?
	if (num_pipe > 0)
		node = parse_pipe_command(tokens, num_pipe);
	else
		node = parse_simple_command(tokens);
	if (node)
	{
		ast->num_children++;
		ast->children = (t_ast **)realloc(ast->children,
				ast->num_children * sizeof(t_ast *));
		ast->children[ast->num_children - 1] = node;
	}
	return (ast);
}
