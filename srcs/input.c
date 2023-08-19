/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 18:38:58 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "traverse.h"
#include "error_minishell.h"
#include "libft.h"
#include "debug.h"
#include <readline/readline.h>

int	lets_go_shell(char *line, char **env)
{
	int		status;
	char	**tokens;
	t_ast	*ast;

	debug_input(line);// debug
	tokens = tokenize(line);
	debug_token(tokens);// debug
	ast = parse(tokens);
	debug_ast(ast);// debug
	status = -1;
	status = traverse_ast(ast, env, status);
	free(line);
	free_tokens(tokens);
	free_ast(ast);
	return (status);
}

/**
 * @brief read_lineを使って終端文字 '\0' まで文字列を返す。
 *
 * @return 型：int 値：コマンドラインの終了ステータス
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
		{
			free_line(line);
			error_code(ERR_READLINE);
		}
		if (ft_strcmp(line[i], "exit") == 0)
		{
			free(line[i]);
			break ;
		}
		// if (^Dがきたら)  .....
		// if (lineの最後の文字がエスケープ文字'\'だったら）.....
		status = lets_go_shell(line[i], env);
		i++;
	}
	line[i] = NULL;
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
