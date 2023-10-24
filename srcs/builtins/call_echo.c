/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:19:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/24 16:26:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"
#include "parse.h"
#include "environ.h"

int	call_echo(t_ast *node, t_envwrap *env_wrapper)
{
	char	**argv;
	size_t	i;
	size_t	size;

	(void)env_wrapper;
	if (node->num_children == 0)
		size = 1;
	else
		size = node->num_children;
	argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (node->num_children == 0)
	{
		argv[0] = "";
		argv[1] = NULL;
		ft_echo(argv);
	}
	else
	{
		i = 0;
		while (i < node->num_children)
		{
			argv[i] = node->children[i]->value;
			i++;
		}
		argv[i] = NULL;
		ft_echo(argv);
	}
	free(argv);
	// ここではargv[i]をfreeせず、
	// 大元のlets_go_shell関数でnode->children[i]->valueをまとめてフリーする
	return (EXIT_SUCCESS);
}
