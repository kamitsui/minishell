/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/16 21:48:02 by kamitsui         ###   ########.fr       */
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
 * ::= <simple-command> or <pipe-command>
 *
 * @param ast 親のノード
 * @param tokens トークンのアドレス
 *
 * @return 生成された<command>のノードを返す
 */
t_ast	*parse_command(t_ast *ast, char ***tokens)
{
	t_ast	*command_node;
	char	*value;

	value = get_command_value(*tokens);
	if (ft_strchr(value, '|') != NULL)// 要改良　'abc|efg' がNG
		command_node = parse_pipe_command(tokens, value);
	else
		command_node = parse_simple_command(tokens, value);
	if (command_node)
	{
		ast->num_children++;
		ast->children = (t_ast **)realloc(ast->children,// use ft_realloc
				ast->num_children * sizeof(t_ast *));
		ast->children[ast->num_children - 1] = command_node;
	}
	free(value);
	return (ast);
}
// debug code
//	debug_parse("parse_command", node);// debug
