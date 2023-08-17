/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 10:13:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "libft.h"
#include <readline/readline.h>
#include "debug.h"

/**
 * @brief read_lineを使って終端文字 '\0' まで文字列を返す。
 *
 * @return 型：char *
 */
void	input(char **line)
{
	int		i;
	t_token	*tokens;

	i = 0;
	while (1)
	{
		line[i] = readline(PROMPT);
		if (line[i] == NULL)
		{
			free_line(line);
			error_code(ERR_READLINE);
		}
		if (ft_strcmp(line[i], "exit") == 0) {
			free(line[i]);
			break;
		}
		// if (^Dがきたら)  .....
		// if (lineの最後の文字がエスケープ文字'\'だったら）.....
		tokens = tokenize(line[i]);
		debug_input(line[i]);// debug
		debug_tokenize(tokens);// debug
//		parse(tokens);
		free(line[i]);
		free_tokens(tokens);
		i++;
	}
	line[i] = NULL;
	//	erro handle (^D が２回続いて入力された場合)
}
// エスケープ文字'\'がきたときの挙動(将来対応)
// 例　下記をリードラインする。　\0までの文字列を返す。
//
// lines[0]  "echo aaa\"
// lines[1]  "ls -l\"
// lines[2]  "| cat -e\"
// lines[3]  "exit" or '\n' or ^D <-ここまで
// lines[3]  NULL
//
// return(lines);
