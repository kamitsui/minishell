/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:37:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/20 21:56:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

char	*substr_env(char *name, char *env[])
{
	char	*dir;
	size_t	name_len;
	int		i;

	name_len = ft_strlen(name);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnequ(env[i], name, name_len) == true)
			break ;
		i++;
	}
	dir = (char *)ft_strdup(env[i] + name_len + 1);
	if (dir == NULL)
		return (NULL);
	return (dir);
}
