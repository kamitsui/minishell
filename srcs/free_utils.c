/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:29:22 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 13:57:30 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include <stdlib.h>

void	free_line(char **line)
{
	int	i = 0;

	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
}

void	free_tokens(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

//void	free_tokens(t_token *tokens)
//{
//	int	i;
//
//	i = 0;
//	while (tokens[i].var != NULL)
//	{
//		free(tokens[i].var);
//		i++;
//	}
//	free(tokens);
//}

void	free_ast(t_ASTNode *node)
{
	size_t	i;

	if (!node)
		return ;
	i = 0;
	while (i <node->num_children)
	{
		free_ast(node->children[i]);
		i++;
	}
	free(node->children);
	free(node->value);
	free(node);
}
