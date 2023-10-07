/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:23:52 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/28 18:38:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_argument.c
 * @brief \<argument>のノードを作ってトークンを一つ進める関数。
 * （tokensのアドレスを引数で持たせているため、ポインタの移動が可能）
 */
#include "parse.h"
#include "libft.h"

/**
 * @brief \<argument>のノードを作ってトークンを一つ進める関数。
 * （tokensのアドレスを引数で持たせているため、ポインタの移動が可能）
 *
 * @param tokens トークンのアドレス
 *
 * @return 生成されたコマンド引数のノードを返す。
 */
t_ast	*parse_argument(char ***tokens)
{
	// 要改良！ is_argument
	if (**tokens && ft_strcmp(**tokens, "&&") != 0)
	{
		(*tokens)++;
		return (create_node(NODE_ARGUMENT, *(*tokens - 1)));
	}
	return (NULL);
}
