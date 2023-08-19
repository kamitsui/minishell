/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 15:39:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "traverse.h"
#include "error_minishell.h"
#include "libft.h"
#include "debug.h"
#include <readline/readline.h>

/**
 * @brief read_lineを使って終端文字 '\0' まで文字列を返す。
 *
 * @return 型：char *
 */
void	input(char **line, char **env)
{
	int		i;
	int		status;
	char	**tokens;
	t_ast	*ast;

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
			break;
		}
		// if (^Dがきたら)  .....
		// if (lineの最後の文字がエスケープ文字'\'だったら）.....
		debug_input(line[i]);// debug
		tokens = tokenize(line[i]);
		debug_token(tokens);
		ast = parse(tokens);
		debug_ast(ast);
		status = -1;
		traverse_ast(ast, env, status);
		free(line[i]);
		free_tokens(tokens);
		free_ast(ast);
		i++;
	}
	line[i] = NULL;
	//	erro handle (^D が２回続いて入力された場合)
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
