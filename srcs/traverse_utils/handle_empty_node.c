/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_empty_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/28 19:31:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"
#include "meta_minishell.h"

// for debug
#include "debug.h"
#include "ft_printf.h"

void	adjust_argument_node(t_ast **node)
{
	size_t	i;
	t_ast	*tmp;

	if ((*node)->num_children == 0)
		return ;
	i = 0;
	tmp = NULL;
	while (i < (*node)->num_children)
	{
		if ((*node)->children[i]->flag & BIT_EMPTY)
		{
			free((*node)->children[i]->value);
			free((*node)->children[i]);
			i++;
		}
		else
		{
			tmp = create_node(NODE_EXECUTABLE, (*node)->children[i]->value);
			tmp->num_children = 0;
			free((*node)->children[i]->value);
			free((*node)->children[i]);
			i++;
			break ;
		}
	}
	while (i < (*node)->num_children)
	{
		if ((*node)->children[i]->flag & BIT_EMPTY)
		{
			free((*node)->children[i]->value);
			free((*node)->children[i]);
		}
		else
		{
			tmp->num_children++;
			tmp->children = (t_ast **)realloc(tmp->children,
				tmp->num_children * sizeof(t_ast *));// ft_realloc
			tmp->children[tmp->num_children - 1] = (*node)->children[i];
		}
		i++;
	}
	free((*node)->value);
	free((*node)->children);
	*node = tmp;
}

void	handle_empty_node(t_ast **node, t_envwrap *env_wrapper)
{
	size_t	i;

	if ((*node)->flag & BIT_EMPTY)
	{
		if ((*node)->flag & BIT_EXECUTABLE)
			adjust_argument_node(node);
	}
	if ((*node)->flag & BIT_EXECUTABLE)
		return ;
	i = 0;
	while (i < (*node)->num_children)
	{
		handle_empty_node(&(*node)->children[i], env_wrapper);
		i++;
	}
}
