/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:20:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 01:50:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "libft.h"
#include <stdbool.h>

bool	is_pipe(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_PIPE) == 0);
}
