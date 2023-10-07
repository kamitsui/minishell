/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:25:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/28 18:44:36 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse.c
 * @brief \<command-line>から各トークンを抽出して、
 * 抽象構文木ASTのデータ構造に置き換える関数
 */

#include "libft.h"
#include "minishell.h"
#include "parse.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief オペレーターのノードを作ってトークンを一つ進める関数。
 * （tokensのアドレスを引数で持たせているため、ポインタの移動が可能）
 *
 * @param tokens トークンのアドレス
 *
 * @return 生成されたオペレーターのノードを返す。
 */
t_ast	*parse_operator(char ***tokens)
{
	if (**tokens && ft_strcmp(**tokens, "&&") == 0)
	{
		(*tokens)++;
		return (create_node(NODE_OPERATOR, *(*tokens - 1)));
	}
	return (NULL);
}

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
		if (ft_strcmp(*tokens, "&&") == 0)
		{
			operator_node = parse_operator(&tokens);
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
