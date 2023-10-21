/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:19:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 17:20:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"
#include "parse.h"
#include "environ.h"

int	call_echo(t_ast *node, t_envwrap *env_wrapper)
{
	char	**argv;
	size_t	i;

	(void)env_wrapper;
	argv = (char **)malloc(sizeof(char *) * (node->num_children + 1));
	i = 0;
	while (i < node->num_children)
	{
		argv[i] = node->children[i]->value;
		i++;
	}
	argv[i] = NULL;
	ft_echo(argv);
	free(argv);
	// ここではargv[i]をfreeせず、
	// 大元のlets_go_shell関数でnode->children[i]->valueをまとめてフリーする
	return (EXIT_SUCCESS);
}
