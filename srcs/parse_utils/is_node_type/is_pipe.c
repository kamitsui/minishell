/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:20:25 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 06:33:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_char.h"
#include "libft.h"
#include <stdbool.h>

bool	is_pipe(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_PIPE) == 0);
}
