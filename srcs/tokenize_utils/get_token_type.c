/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:49:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/20 16:48:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"
#include "ft_printf.h"

/**
 * @brief 文字列のタイプを調べて分類分けする。
 *
 * @param var 文字列<connecotor>か<command> のいずれか。
 *
 * @return type 該当するタイプのbitを立てる。
 */
int	get_token_type(char *var)
{
	int	type;

	type = 0;
	if (var == NULL)
		return (TOK_END);
	if (ft_substr_exist(var, CONNECT_AND) || ft_substr_exist(var, CONNECT_OR))
	{
		type |= TOK_CONNECT;
		if (ft_substr_exist(var, CONNECT_AND))
			type |= TOK_CON_AND;
		else
			type |= TOK_CON_OR;
	}
	else
		type |= TOK_COMMAND;
	return (type);
}
// (NGなケース)
// line [echo "&&"]
//  本来は var[0] [echo "&&"]  type = TOK_COMMAND
//  現状は var[0] [echo "]     type = TOK_COMMAND
//         var[1] [&&]         type = TOK_CON_AND
//         var[2] ["]          type = TOK_CON_AND
// 他にもNGなケースはあると思う。。。
