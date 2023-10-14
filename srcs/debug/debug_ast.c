/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:41:58 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 19:31:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file debug_ast.c
 * @brief 抽象構文木のデータをデバッグ出力する関数
 */
#include	"ft_printf.h"
#include	"parse.h"
#include	"debug.h"

/**
 * @brief ヘルパー関数：ASTの一番上のノードのみ出力
 *
 * @param node ASTの先頭ノード（minishellノード）
 */
static void	display_head(t_ast *node)
{
	ft_dprintf(g_fd_log, "\tTop Node [%s]\t", node->value);
	ft_dprintf(g_fd_log, "Type COMMAND[%d] ARGUMENT[%d] OPERATOR[%d] ",
		NODE_COMMAND, NODE_ARGUMENT, NODE_OPERATOR);
	ft_dprintf(g_fd_log, "REDIRECTION[%d] FILE[%d]",
		NODE_REDIRECTION, NODE_FILE);
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
	char	*bit_str;
	t_ast	*children;

	if (node->type == NODE_ARGUMENT)
		return ;
	ft_dprintf(g_fd_log, "\n\n");
	ft_dprintf(g_fd_log, "\tparent[%s]\ttype[%d]\n",
		node->value, (int)node->type);
	bit_str = ft_itoa_binary(node->flag);// handle_error
	ft_dprintf(g_fd_log, "\tflag[%s]\n", bit_str);
	free(bit_str);
	debug_flag(node);
	i = 0;
	while (i < node->num_children)
	{
		children = node->children[i];
		ft_dprintf(g_fd_log, "\t\tchildren[%d]\t[%s]",
					i, children->value);
		ft_dprintf(g_fd_log, "\ttype\t[%d]\n", (int)children->type);
		if (children->flag & BIT_ARGUMENT
			|| children->flag & BIT_FILE)
		{
			ft_dprintf(g_fd_log, "\n\tchildren[%d]\t[%s]",
						i, children->value);
			bit_str = ft_itoa_binary(children->flag);// handle_error
			ft_dprintf(g_fd_log, "\n\tflag[%s]\n", bit_str);
			free(bit_str);
			debug_flag(children);
		}
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

	ft_dprintf(g_fd_log, "%s---- AST debug  ----\n", DEBUG_COLOR);
	display_head(ast);
	node = ast;
	display_children(node);
	ft_dprintf(g_fd_log, "\n\n");
}
