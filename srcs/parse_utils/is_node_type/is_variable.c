/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:53:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 15:53:21 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_minishell.h"
#include "libft.h"
#include <stdlib.h>

bool	is_variable(const char *token)
{
	return (ft_strchr(token, META_VAR_CHR) != NULL);
}
