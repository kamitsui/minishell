/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/10 22:24:07 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1024

#include "minishell.h"
#include "libft.h"
#include <readline/readline.h>

/**
 * @brief read_lineを使って終端文字 '\0' まで文字列を返す。
 *
 * @return 型：char *
 */
char	*input(void)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		//*lines[i] = *readline("minishell> ");
		line = readline("minishell> ");
		if (line == NULL)
		{
			printf("line == NULL\n");
			exit (1);
		}
//		if (lines[i] == NULL)
//		{
//			printf("lines[i] == NULL\n");
//			exit (1);
//		}
		//lines[i] = readline("minishell> ");
//		printf("%s\n", lines[i]);
		printf("%s\n", line);
		if (ft_strcmp(line, "exit") == 0) {
			free(line);
			break;
		}
//		if (ft_strcmp(lines[i], "exit") == 0) {
//			free(lines[i]);
//			break;
//		}
//		system(*input); // execute command
		i++;
//		printf("%s\n", lines[i]);
		printf("%s\n", line);
	}
	return (line);
//	return (lines);
}

	// char	**lines;
	// 例　下記をリードラインする。　\0までの文字列を返す。
	//
	// lines[0]  echo "aaa"\n
	// lines[1]  ls -l\n
	// lines[2]  | cat -e\n
	// lines[3]  '\0'<-ここまで
	// lines[4]  NULL
	//
	// return(lines);
