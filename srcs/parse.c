/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:25:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 04:52:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse.c
 * @brief \<command-line>から各トークンを抽出して、
 * 抽象構文木ASTのデータ構造に置き換える関数
 */

#include	"libft.h"
#include	"minishell.h"
#include	"parse.h"
#include	<stdlib.h>
#include	<string.h>

#include	"ft_printf.h"// debug
#include	"debug.h"// debug

/**
 * @brief \<command-line>から各トークンを抽出して、
 * 抽象構文木ASTのデータ構造に置き換える関数
 *
 * @param tokens 複数の文字列要素もつ二次元配列（最後の要素はNULL）
 *
 * @return ast 生成された抽象構文木のデータ
 */
t_ast	*parse(char **tokens)
{
	t_ast	*ast;
	t_ast	*operator_node;

	ast = create_node(NODE_OPERATOR, PROGRAM_NAME);
	while (*tokens)
	{
		if (is_operator(*tokens) == true)
		{
			operator_node = parse_operator(&tokens);
//			debug_parse("parse", operator_node);// debug
			if (operator_node)
			{
				ast->num_children++;
				ast->children = (t_ast **)realloc(ast->children,// use ft_realloc
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
