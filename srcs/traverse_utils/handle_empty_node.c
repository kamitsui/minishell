/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_empty_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 17:03:25 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"
#include "meta_minishell.h"

static void	remove_one_node(t_ast *node)
{
	free(node->value);
	free(node);
}

static t_ast	*extract_executable_node(t_ast *node, size_t *i)
{
	t_ast	*executable_node;

	executable_node = NULL;
	while (*i < node->num_children)
	{
		if (node->children[*i]->flag & BIT_EMPTY)
		{
			remove_one_node(node->children[*i]);
			(*i)++;
		}
		else
		{
			executable_node
				= create_node(NODE_EXECUTABLE, node->children[*i]->value);
			executable_node->num_children = 0;
			remove_one_node(node->children[*i]);
			(*i)++;
			break ;
		}
	}
	return (executable_node);
}

static void	extract_argument_node(t_ast *node,
				t_ast *executable_node, size_t *i)
{
	while (*i < node->num_children)
	{
		if (node->children[*i]->flag & BIT_EMPTY)
		{
			free(node->children[*i]->value);
			free(node->children[*i]);
		}
		else
		{
			executable_node->num_children++;
			executable_node->children
				= (t_ast **)ft_realloc_tentative(executable_node->children,
					executable_node->num_children * sizeof(t_ast *),
					(executable_node->num_children - 1) * sizeof(t_ast *));
			executable_node->children[executable_node->num_children - 1]
				= node->children[*i];
		}
		(*i)++;
	}
}

static void	adjust_executable_node(t_ast **node)
{
	size_t	i;
	t_ast	*tmp;

	if ((*node)->num_children == 0)
		return ;
	i = 0;
	tmp = extract_executable_node(*node, &i);
	if (tmp != NULL)
		extract_argument_node(*node, tmp, &i);
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
			adjust_executable_node(node);
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
