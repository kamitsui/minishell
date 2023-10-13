/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:54:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 01:48:59 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create_node.c
 * @brief 新規ノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include "error_minishell.h"
#include <stdlib.h>

static int	get_node_flag(enum e_NodeType type, char *value)
{
	int	flag;
	int	i;
	static t_is_type_node	f_is_type_node[NUM_OPERATOR + NUM_REDIRECTION] = {
			is_and_list, is_or_list,
			is_in_red, is_here_doc, is_out_red, is_out_append};
	static int		match_flag[NUM_OPERATOR + NUM_REDIRECTION] = {
			BIT_AND_LIST, BIT_OR_LIST,
			BIT_IN_RED, BIT_HERE_DOC, BIT_OUT_RED, BIT_APPEND};

	flag = 0x1 << type;
	i = 0;
	while (i < NUM_OPERATOR + NUM_REDIRECTION)
	{
		if (f_is_type_node[i](value) == true)
			flag |= match_flag[i];
		i++;
	}
	return (flag);
}

/**
 * @brief 新規ノードを作る関数
 * ノードのタイプと値を引数で受け取り、ノードの構造体にセットする
 *
 * @param type ノードのタイプ
 * @param value ノードの値
 *
 * @return 
 */
t_ast	*create_node(enum e_NodeType type, char *value)
{
	t_ast	*node;

	node = (t_ast *)malloc(sizeof(t_ast));
	if (node == NULL)
		ft_errno_exit("malloc");
	node->type = type;
	node->flag = get_node_flag(type, value);
	node->value = ft_strdup(value);
	if (node == NULL)
		ft_errno_exit("ft_strdup");
	node->children = NULL;
	node->num_children = 0;
	return (node);
}
