/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:19:42 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/02 15:57:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "libft.h"
#include <stdbool.h>

bool	is_tilde(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strcmp(token, META_TILDE) == 0
		|| ft_strncmp(token, "~/", 2) == 0);
}
