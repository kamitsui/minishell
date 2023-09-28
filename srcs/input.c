/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/28 22:54:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file input.c
 * @brief プロンプト表示、<command-line>入力、<command-line>処理を行う関数\n
 */
#include "minishell.h"
#include "parse.h"
#include "traverse.h"
#include "error_minishell.h"
#include "libft.h"
#include "debug.h"
#include <readline/readline.h>

/**
 * @brief lets_go_shell関数では、<command-line>の文字列に対して、
 * tokenize関数ー＞parse関数ー＞traverse_ast関数の順番で処理する。
 *
 * @param line readline関数から読みとった文字列。
 * @param env 環境変数。
 *
 * @return status 終了ステータス
 */
static int	lets_go_shell(char *line, char **env)
{
	int		status;
	char	**tokens;
	t_ast	*ast;

	debug_input(line);// debug
	tokens = tkn_controller(line);// 本番のトークナイズ
//	tokens = ft_split(line, ' ');// 仮のトークナイズ
	debug_token(tokens);// debug
	ast = parse(tokens);
	debug_ast(ast);// debug
	status = -1;
	status = traverse_ast(ast, env, status);
	free(line);
	free_tokens(tokens);
	free_ast(ast);
	system("leaks minishell");
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
int	input(char **line, char **env)
{
	int	i;
	int	status;

	i = 0;
	while (1)
	{
		line[i] = readline(PROMPT);
		if (line[i] == NULL)
			error_code(ERR_READLINE);
		if (ft_strcmp(line[i], "exit") == 0)
		{
			free(line[i]);
			break ;
		}
		// if (^Dがきたら)  .....
		// if (lineの最後の文字がエスケープ文字'\'だったら）.....
		status = lets_go_shell(line[i], env);
		//add_history(line[i]);//???上下キーでhistory参照できていない
		i++;
	}
	//	erro handle (^D が２回続いて入力された場合)
	return (status);
}
// debug code
// エスケープ文字'\'がきたときの挙動(将来対応)
// 例　下記をリードラインする。　\0までの文字列を返す。
//
// lines[0]  "echo aaa\"
// lines[1]  "ls -l\"
// lines[2]  "| cat -e\"
// lines[3]  "exit" or '\n' or ^D <-ここまで
// lines[3]  NULL
