/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_connector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:33:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/16 08:53:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

/**
 * @brief コネクターのノードを作ってトークンを一つ進める関数。
 * （tokensのアドレスを引数で持たせているため、ポインタの移動が可能）
 *
 * @param tokens トークンのアドレス
 *
 * @return 生成されたコネクターのノードを返す。
 */
t_ast	*parse_connector(char ***tokens)
{
	if (is_connector(**tokens) == true)
	{
		(*tokens)++;
		return (create_node(NODE_CONNECTOR, *(*tokens - 1)));
	}
	return (NULL);
}
