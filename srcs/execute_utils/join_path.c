/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:30:18 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 18:31:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief PATHと実行ファイル名を繋げる関数（free必要）
 *
 * @param dir 実行ファイルが存在するディレクトリパス名
 * @param file 実行ファイル
 *
 * @return パス付き実行ファイル 例 "/bin/ls"
 */
char	*join_path(char const *dir, char const *file)
{
	size_t	len_dir;
	size_t	len_file;
	char	*path;

	if (dir == NULL || file == NULL)
		return (NULL);
	len_dir = ft_strlen(dir);
	len_file = ft_strlen(file);
	path = malloc(sizeof(char) * (len_dir + len_file + 2));
	if (path == NULL)
		return (NULL);
	ft_memcpy(path, dir, len_dir);
	ft_memcpy(path + len_dir, "/", 1);
	ft_memcpy(path + len_dir + 1, file, len_file + 1);
	return (path);
}
