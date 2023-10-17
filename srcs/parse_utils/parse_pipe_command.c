/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:44:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 14:21:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_pipe_command.c
 * @brief \<pipe-command> のノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

// for debug
#include "debug.h"
#include "ft_printf.h"

//t_ast	*parse_one_pipe_command(char ***tokens, char *head_value)
//{
//	t_ast	*node;
//	t_ast	*redirection_node;
//	t_ast	*command_node;
//	char	*value;
//
//	node = create_node(NODE_COMMAND, head_value);
//	while (is_end(**tokens) == false && is_connector(**tokens) == false
//			&& is_pipe(**tokens) == false)
//	{
//		if (is_include_redirection(*tokens) == true)
//		{
//			value = get_redirection_value(*tokens);
//			redirection_node = parse_io_redirections(*tokens, value);
//			node->num_children++;
//			node->children = (t_ast **)realloc(node->children,// use ft_realloc
//					node->num_children * sizeof(t_ast *));
//			node->children[node->num_children - 1] = redirection_node;
//			free(value);
//		}
//		value = get_one_pipe_command_value(*tokens);
//		ft_dprintf(g_fd_log, ">> in parse_pipe_command ... one_pipe_com_value[%s]\n", value);
//		command_node = parse_one_pipe_command(tokens, value);
//		node->num_children++;
//		node->children = (t_ast **)realloc(node->children,// use ft_realloc
//				node->num_children * sizeof(t_ast *));
//		node->children[node->num_children - 1] = command_node;
//	}
//	return (node);
//}
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
//	t_ast	*redirection_node;
	t_ast	*command_node;
	char	*value;

	node = create_node(NODE_PIPE_COM, head_value);
		ft_dprintf(g_fd_log, ">> in parse_pipe_command ... head_value[%s]\n", head_value);
	while (is_end(**tokens) == false && is_connector(**tokens) == false)
	{
		if (is_pipe(**tokens) == true)
		{
			(*tokens)++;
			continue ;
		}
//		if (is_include_redirection(*tokens) == true)
//		{
//			value = get_redirection_value(*tokens);
//			redirection_node = parse_io_redirections(*tokens, value);
//			node->num_children++;
//			node->children = (t_ast **)realloc(node->children,// use ft_realloc
//					node->num_children * sizeof(t_ast *));
//			node->children[node->num_children - 1] = redirection_node;
//			free(value);
//		}
		//value = get_one_pipe_command_value(*tokens);
		value = get_simple_command_value(*tokens);
		ft_dprintf(g_fd_log, ">> in parse_pipe_command ... one_pipe_com_value[%s]\n", value);
		command_node = parse_simple_command(tokens, value);
		node->num_children++;
		node->children = (t_ast **)realloc(node->children,// use ft_realloc
				node->num_children * sizeof(t_ast *));
		node->children[node->num_children - 1] = command_node;
	}
	return (node);
}
