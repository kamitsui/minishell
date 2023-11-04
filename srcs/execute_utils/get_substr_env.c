/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_substr_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:37:40 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/04 14:33:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file substr_env.c
 * @brief 環境変数から値を取り出す関数
 */
#include "libft.h"
#include <stdbool.h>

/**
 * @brief 環境変数からPATHを取り出す時に使う関数(free必要)
 *
 * @param name 取り出したい変数名を指定
 * @param env[] 環境変数
 *
 * @return dir 環境変数のから取り出した値（文字列）
 */
char	*get_substr_env(char *name, char *env[])
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
	if (env[i] == NULL)
		return (ft_strdup(""));
	dir = (char *)ft_strdup(env[i] + name_len + 1);
	if (dir == NULL)
		return (NULL);
	return (dir);
}
