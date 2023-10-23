/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parenthesis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:55:51 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/23 14:38:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "parse.h"
#include <stdlib.h>

bool	is_parenthesis(const char *token)
{
	char	*point_left;
	char	*point_right;
	size_t	len;

	point_left = ft_strchr(token, META_ROUND_BRACKET_LEFT);
	point_right = ft_strrchr(token, META_ROUND_BRACKET_RIGHT);
	len = ft_strlen(token);
	if (point_left == token && point_right == (token + len - 1))
		return (true);
	else
		return (false);
}
