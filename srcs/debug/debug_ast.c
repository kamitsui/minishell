/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:41:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/20 22:45:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file debug_ast.c
 * @brief 抽象構文木のデータをデバッグ出力する関数
 */
#include	"ft_printf.h"
#include	"parse.h"

/**
 * @brief ヘルパー関数：ASTの一番上のノードのみ出力
 *
 * @param node ASTの先頭ノード（minishellノード）
 */
static void	display_head(t_ast *node)
{
	ft_printf("\tTop Node [%s]\n", node->value);
}

/**
 * @brief ヘルパー関数：ノード自身と子ノードを出力\n
 * （コマンド引数は出力しない）
 *
 * @param node 出力させたいノード
 */
static void	display_children(t_ast *node)
{
	size_t	i;

	if (node->type == NODE_ARGUMENT)
		return ;
	ft_printf("\n\n");
	ft_printf("\tparent[%s]\ttype[%d]\n",
		node->value, (int)node->type);
	i = 0;
	while (i < node->num_children)
	{
		ft_printf("\t\tchildren[%d]\t[%s]",
			i, node->children[i]->value);
		ft_printf("\ttype\t[%d]\n", (int)node->children[i]->type);
		i++;
	}
	i = 0;
	while (i < node->num_children)
	{
		display_children(node->children[i]);
		i++;
	}
}

/**
 * @brief parse関数で生成されたASTをデバッグ出力\n
 * 全てのノードと子ノードをデバッグ出力
 *
 * @param ast parseで生成された抽象構文木ASTのデータ
 */
void	debug_ast(t_ast *ast)
{
	t_ast	*node;

	ft_printf("\n\x1B[100m\x1B[37m");
	ft_printf("---- AST debug  ----\n");
	display_head(ast);
	node = ast;
	display_children(node);
	ft_printf("\x1B[0m\n\n");
}
