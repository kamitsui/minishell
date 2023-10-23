/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipe_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:37:54 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 15:09:03 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file count_pipe_command.c
 * @brief <pipe-command>のパイプの数を数える関数
 */
#include <stdlib.h>
#include "parse.h"
#include "libft.h"

/**
 * @brief <pipe-command>のパイプの数を数える関数
 *
 * @param tokens トークンの変数（大元のポインタ移動はできない）
 *
 * @return パイプの数
 */
size_t	count_pipe_command(char **tokens)
{
	size_t	num_pipe;

	num_pipe = 0;
	while (is_operator(*tokens) == false && is_redirection(*tokens) == false
			&& *tokens != NULL)
	{
		if (is_pipe(*tokens) == true)
			num_pipe++;
		tokens++;
	}
	return (num_pipe);
}
