/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:54:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 15:35:22 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create_node.c
 * @brief 新規ノードを作る関数
 */
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

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
	node->type = type;
	node->flag = 1 << type;
	node->value = ft_strdup(value);
	node->children = NULL;
	node->num_children = 0;
	return (node);
}
