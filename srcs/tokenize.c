/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:26:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 15:26:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenize.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief １行の文字列を受け取って、
 *        <connector> "&&" や "||" で区切り構造体tokenに格納する。
 *
 * @param line readlineで読み込んだ <command-line> １行分
 *
 * @return 構造体tokens (呼び出し側でfree)
 */
t_token	*tokenize(char *line)
{
	t_token	*tokens;
	size_t	size;
	int		i;

	size = count_tokens(line);
	tokens = (t_token *)malloc(sizeof(t_token) * (size + 1));
	i = 0;
	tokens[i].var = get_next_token(line, CONNECT_AND);
	tokens[i].type = get_token_type(tokens[i].var);
	while (tokens[i].var != NULL)
	{
		i++;
		tokens[i].var = get_next_token(NULL, CONNECT_AND);
		tokens[i].type = get_token_type(tokens[i].var);
	}
	return (tokens);
}

//#define STR1 "ls \"-a\" | grep $VAR&&echo 42 > file"				// 3
//#define STR2 "ls \"-a\" | grep $VAR&&echo 42 > file && ls"		// 5
//#define STR3 "ls \"-a\" | grep $VAR&&echo 42 > file && ls&&"		// 6
//#define STR4 "&&ls \"-a\" | grep $VAR&&echo 42 > file && ls&&&&"	// 8
//#define STR5 "ls \"-a\" | grep $VAR"								// 1
//#define STR6 "12345"												// 1
//#define STR7 "ls \"-a\" | grep $VAR&&echo 42 > file && ls&&&"		// segfault
//#include <stdio.h>
//#include <string.h>
///**
// * @brief tokenize()の動作確認用
// *
// * @return 
// */
//int main()
//{
//	char *line = strdup(STR6);
//	t_token *tokens = NULL;
//	printf("line %s\n", line);
//	tokens = tokenize(line);
//	free(line);
//
//	int	i;
//	i = 0;
//	while (tokens[i].var != NULL)
//	{
//		printf("tokens[%d].var %p %s\n", i, tokens[i].var, tokens[i].var);
//		i++;
//	}
//
//// Free memory
//	i = 0;
//	while (tokens[i].var != NULL)
//	{
//		free(tokens[i].var);
//		i++;
//	}
////	system("leaks a.out");
//	return (0);
//}

// 例　line[0]  "ls -a | grep "$VAR" && echo 42 > file"
//
// tokens[0]
//     **var   [ls] [-a] [|] [grep] ["$VAR"]
//     type               ^          ^    ^ <quoted-string>
//                   <pipe_command>
// tokens[1]
//     **var  [&&]
//     type    ^ <connector>
// tokens[2]
//     **var  [echo] [42] [>] [file]
//     type    ^           ^ <output-redirection>
//             <simple-command>
//
