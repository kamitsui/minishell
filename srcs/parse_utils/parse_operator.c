/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:33:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 03:50:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

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
	if (is_operator(**tokens) == true)
	{
		(*tokens)++;
		return (create_node(NODE_OPERATOR, *(*tokens - 1)));
	}
	return (NULL);
}
