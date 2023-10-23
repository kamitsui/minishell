/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_or_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 01:50:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "libft.h"
#include <stdbool.h>

bool	is_or_list(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_OR_LIST) == 0);
}
