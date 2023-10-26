/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io_redirections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:03:50 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/26 00:04:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "traverse.h"
#include "execute.h"
#include "error_minishell.h"

#include "debug.h"
#include "ft_printf.h"

static int	set_redirection(t_ast *node, t_envwrap *env_wrapper)
{
	int	status;
	int	current_flag;
	size_t	i;
	static t_select_redirection	f_select_redirection[4] = {
			input_redirection, here_doc,
			out_redirection_trunc, out_redirection_append};

	if (node->num_children == 1)
		return (handle_syntax_error(NULL, 0));
	if (is_redirection(node->children[1]->value) == true)
		return (handle_syntax_error(node->children[1]->value, 0));
	status = EXIT_SUCCESS;
	current_flag = BIT_IN_RED;
	i = 0;
	while (current_flag <= BIT_APPEND && status == EXIT_SUCCESS)
	{
		if (node->children[0]->flag & current_flag)
			status = f_select_redirection[i](node->children[1]->value, env_wrapper);
		current_flag = current_flag << 1;
		i++;
	}
	return (status);
}
// BIT_IN_RED		0x00010000
// BIT_HERE_DOC		0x00020000
// BIT_OUT_RED		0x00040000
// BIT_APPEND		0x00080000

/**
 * @brief <io-redirection>のノードに対しての処理
 *
 * @param node 処理対象のノード
 * @param env_wrapper構造体  (env、exit_code, pwd)
 *
 * @return ノードの処理結果を終了ステータスとして返す
 */
int	handle_io_redirections(t_ast *node, t_envwrap *env_wrapper)
{
//	if (node->flag & BIT_EXPANSION)
//		node = handle_expansion(node);
	// 未実装
	int		status;
	size_t	i;

	status = EXIT_SUCCESS;
	i = 0;
	while (i < node->num_children && status == EXIT_SUCCESS)
	{
		status = set_redirection(node->children[i], env_wrapper);
		i++;
	}
	return (status);
}
