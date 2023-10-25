/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/25 14:21:08 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file input.c
 * @brief プロンプト表示、<command-line>入力、<command-line>処理を行う関数\n
 */
#include "minishell.h"
#include "tokenize.h"
#include "parse.h"
#include "traverse.h"
#include "error_minishell.h"
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>

// for debug
#include "debug.h"
#include "ft_printf.h"

/**
 * @brief lets_go_shell関数では、<command-line>の文字列に対して、
 * tokenize関数ー＞parse関数ー＞traverse_ast関数の順番で処理する。
 *
 * @param line readline関数から読みとった文字列。
 * @param env 環境変数。
 *
 * @return status 終了ステータス
 */
int	lets_go_shell(char *line, t_envwrap *env_wrapper)
{
	int		status;
	char	**tokens;
	t_ast	*ast;

	debug_input(line);// debug
	tokens = token_controller(line);
	debug_token(tokens);// debug
	ast = parse(tokens);
	debug_ast(ast);// debug
	status = traverse_ast(ast, env_wrapper);
	free_two_darray(tokens);
	free_ast(ast);
	return (status);
}

/**
 * @brief プロンプト表示、<command-line>入力、<command-line>処理を行う関数\n
 * "exit"が入力されるまで上記処理を繰り返します\n
 *
 * @param line readline関数によって読み取った文字列。
 * @param env 環境変数。
 *
 * @return status 終了ステータスを返す。
 * @note シグナルハンドル未実装
 */
int	input(t_envwrap *env_wrapper)
{
	int		status;
	char	*line;

	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL)
			handle_error(ERR_READLINE);
		ft_dprintf(g_fd_log, "line[%s] [%p] *line[%c]\n", line, line, *line);
		if (*line == '\0')
		{
			free (line);
			continue ;
		}
		add_history(line);
		// if (^Dがきたら)  .....
		// if (lineの最後の文字がエスケープ文字'\'だったら）.....
		status = lets_go_shell(line, env_wrapper);
		debug_status("lets_go_shell", status);// debug
		debug_leaks("lets_go_shell", "minishell");// debug
		free (line);
	}
	//	erro handle (^D が２回続いて入力された場合)
	return (status);
}
