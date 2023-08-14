/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:49:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 15:14:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"
#include "ft_printf.h"

int	get_token_type(char *var)
{
	if (var == NULL)
		return (TOK_END);
	if (ft_substr_exist(var, CONNECT_AND))
		return (TOK_CON_AND);
	if (ft_strnstr(var, "|", ft_strlen(var)))
		return (TOK_PIPE_COM);
	return (TOK_COMMAND);
}
