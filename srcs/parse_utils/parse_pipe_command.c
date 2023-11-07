/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:44:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/07 15:14:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_pipe_command.c
 * @brief \<pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include "error_minishell.h"
#include "ft_signal.h"
#include <stdlib.h>

static void	add_simple_command_node(char ***tokens, t_ast *node)
{
	char	*value;
	t_ast	*command_node;

	value = get_simple_command_value(*tokens);
	command_node = parse_simple_command(tokens, value);
	node->num_children++;
	node->children = (t_ast **)ft_realloc_tentative(node->children,
			node->num_children * sizeof(t_ast *),
			(node->num_children - 1) * sizeof(t_ast *));
	node->children[node->num_children - 1] = command_node;
	free(value);
}

/**
 * @brief \<pipe-command> のノードを作る関数
 *
 * @param tokens トークンのアドレス
 * @param num_pipe パイプでつなげるコマンドの数
 *
 * @return 生成された<pipe-command>のノードを返す
 * @note 未完成
 * あと一部未実装。is_connector()関数　引数num_pipeは不要か。。。
 */
t_ast	*parse_pipe_command(char ***tokens, char *head_value)
{
	t_ast	*node;

	node = create_node(NODE_PIPE_COM, head_value);
	while (is_end(**tokens) == false && is_connector(**tokens) == false)
	{
		if (is_pipe(**tokens) == true
			&& node->num_children > 0 && !is_end(**tokens))
			(*tokens)++;
		if (**tokens == NULL)
		{
			handle_syntax_error(NULL);
			break ;
		}
		add_simple_command_node(tokens, node);
		if (g_flag == SIGINT)
			break ;
	}
	return (node);
}
