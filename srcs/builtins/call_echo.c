/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:19:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 21:27:19 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"
#include "parse.h"
#include "environ.h"

static size_t	get_argument_number(size_t num_children)
{
	if (num_children == 0)
		return (1);
	else
		return (num_children);
}

static void	set_echo_arguments(t_ast *node, char **argv)
{
	size_t	i;

	i = 0;
	while (i < node->num_children)
	{
		argv[i] = node->children[i]->value;
		i++;
	}
	argv[i] = NULL;
}

int	call_echo(t_ast *node, t_envwrap *env_wrapper)
{
	char	**argv;
	size_t	size;

	(void)env_wrapper;
	size = get_argument_number(node->num_children);
	argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (node->num_children == 0)
	{
		argv[0] = "";
		argv[1] = NULL;
		ft_echo(argv);
	}
	else
	{
		set_echo_arguments(node, argv);
		ft_echo(argv);
	}
	free(argv);
	return (EXIT_SUCCESS);
}
