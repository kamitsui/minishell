/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/12 15:08:44 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "libft.h"
#include <readline/readline.h>

/**
 * @brief read_lineを使って終端文字 '\0' まで文字列を返す。
 *
 * @return 型：char *
 */
char	**input(char **line)
{
	int		i;

	i = 0;
	while (1)
	{
		line[i] = readline("minishell> ");
		if (line[i] == NULL)
		{
			line_free(line);
			error_code(ERR_READLINE);
		}
		if (ft_strcmp(line[i], "exit") == 0) {
			free(line[i]);
			break;
		}
		printf("%s\t%p\n", line[i], line[i]);// for debug
		// if (i == BUFF_SIZE)  .....
		i++;
	}
	line[i] = NULL;
	return (line);
}

	// char	**lines;
	// 例　下記をリードラインする。　\0までの文字列を返す。
	//
	// lines[0]  "echo aaa\"
	// lines[1]  "ls -l\"
	// lines[2]  "| cat -e\"
	// lines[3]  "exit" or '\n' or ^D <-ここまで
	// lines[3]  NULL
	//
	// return(lines);
