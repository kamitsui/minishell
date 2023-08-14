/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_connect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:27:09 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 12:28:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief lineの中に <connector> があるか調べる
 *
 * @param line readlineで読み込んだ <command-line> １行分
 *
 * @return true or false (bool型)
 */
bool	inc_connect(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	return (ft_strnstr(line, CONNECT_AND, len) != NULL ||
			ft_strnstr(line, CONNECT_OR, len) != NULL);
}
