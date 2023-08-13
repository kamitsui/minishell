/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:26:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/13 19:42:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

# define CONNECT_AND "&&"

bool	inc_connect(char *line)
{
	return (strstr(line, "&&") != NULL ||
			strstr(line, "||") != NULL);
}

char	*get_next_token(char *str, char const *sep)
{
	static char	*next_token;
	char		*start;
	size_t		sep_len;

//	printf("next_token |%s| %p\n", next_token, next_token);
	sep_len = ft_strlen(sep);
	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	start = next_token;
	if (ft_strnequ(start, sep, sep_len))
	{
		next_token += sep_len;
		return (ft_strndup(start, sep_len));
	}
	next_token += strcspn(start, sep);
	return (ft_strndup(start, next_token - start));
}

/**
 * @brief line１行あたりのトークン数（<connector> "&&" も含めてカウントする）
 *        "||"の対応は未実装
 *
 * @param line
 *
 * @return 
 */
size_t	count_tokens(char *line)
{
	size_t	size;
	size_t	connect_len;

	connect_len = ft_strlen(CONNECT_AND);
	size = 0;
	if (*line == '\0')
		return (size);
	if (inc_connect(line))
	{
		size++;
		while (inc_connect(line))
		{
			if (ft_strnequ(line, CONNECT_AND, connect_len) == false)
				size++;
			line += strcspn(line, CONNECT_AND) + connect_len;
			if (*line != '\0')
				size++;
		}
	}
	return (size);
}
//	char *line = "ls \"-a\" | grep $VAR&&echo 42 > file"
//		--> 3
//	char *line = "ls \"-a\" | grep $VAR&&echo 42 > file && ls"
//		--> 5
//	char *line = "ls \"-a\" | grep $VAR&&echo 42 > file && ls&&");
//		--> 6
//	char *line = "&&ls \"-a\" | grep $VAR&&echo 42 > file && ls&&&&");
//		--> 7
//	char *line = "ls \"-a\" | grep $VAR"
//		--> 1


/**
 * @brief 文字列1行を受け取って、トークン単位に分けていく。
 *
 * @param line : type (char *)
 *
 * @return type (t_token *)
 */
//void	tokenize_var(char *line, size_t size, t_token *tokens)
//char **tokenize_line(char *line)
//{
//	// line_trim = ft_strtrim(line, " \t");// don't check
//	// error handle if (*line == '\0')??
//	size_t	size;
//	char	**tokens;
//	int		i;
//
//	size = count_tokens(line);
//	tokens = (char **)malloc(sizeof(char *) * (size + 1));
//	i = 0;
//	tokens[i] = get_next_token(line, CONNECT_AND);
//	while (tokens[i] != NULL)
//	{
//		i++;
//		tokens[i] = get_next_token(NULL, CONNECT_AND);
//		//if (tokens[i] == NULL)
//		//	error_....
//	}
//	free(line);
//	return (tokens);
//}

//t_token	*tokenize(char *line, t_token *tokens)
t_token	**tokenize(char *line)
{
//	t_token	tokens[100];
	t_token	**tokens;
	t_token	**tokens_head;
	size_t	size;
	int		i;

	size = count_tokens(line);
	printf("size + 1  %zu\n", size + 1);
	tokens = (t_token **)malloc(sizeof(t_token **) * (size + 1));
	tokens_head = tokens;
	i = 0;
	printf("%p tokens[%d]\n", tokens, i);
	tokens[i]->var = get_next_token(line, CONNECT_AND);
	printf("%p %s %d\n", tokens[i]->var, tokens[i]->var, i);
	while (tokens[i]->var != NULL)
	{
		i++;
		printf("%p tokens[%d]\n", tokens[i], i);
		char *tmp = get_next_token(NULL, CONNECT_AND);
		printf("%p %s %d\n", tmp, tmp, i);
		tokens[i]->var = tmp;
//		printf("%p %s %d\n", tokens->var, tokens->var, i);
//		printf("%p [%s] %d\n", tokens[i].var, tokens[i].var, i);
//		printf("%s\n", tokens[i]->var
	}
	free(line);
	return (tokens_head);
}

/**
 * @brief tokenize()の動作確認用
 *
 * @return 
 */
int main() {

//	char *line = strdup("ls \"-a\" | grep $VAR&&echo 42 > file");
//	char *line = strdup("ls \"-a\" | grep $VAR&&echo 42 > file && ls");
	char *line = strdup("ls \"-a\" | grep $VAR&&echo 42 > file && ls&&");
//	char *line = strdup("&&ls \"-a\" | grep $VAR&&echo 42 > file && ls&&&&");
//	char *line = strdup("ls \"-a\" | grep $VAR");
//	char **tokens = tokenize_line(line);
	t_token **tokens = NULL;
//	tokens = tokenize(line, tokens);
//	t_token	tokens[100];
	tokens = tokenize(line);

	int	i;
// Print tokens
	i = 0;
	while (tokens[i]->var != NULL)
	{
		printf("tokens[%d] %p\n", i, tokens[i]->var);
		//printf("tokens[%d] %s\n", i, tokens[i].var);
		i++;
	}

// Free memory
	i = 0;
	while (tokens[i]->var != NULL)
	{
		free(tokens[i]->var);
		i++;
	}
//	system("leaks a.out");
	return (0);
}

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
