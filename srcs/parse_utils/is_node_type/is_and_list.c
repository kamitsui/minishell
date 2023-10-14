/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_and_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:29:30 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 01:50:23 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "libft.h"
#include <stdbool.h>

bool	is_and_list(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_AND_LIST) == 0);
}
