/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:17:23 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 17:23:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"

int	call_export(t_ast *node, t_envwrap *env_wrapper)
{
	char	*key_or_full;
	char	*val_or_null;
	size_t	i;
//	static const char	*cause = "exit";
//	static const char	*error_msg = "not a valid identifier";
// bash: export: `#JOI': not a valid identifier

	key_or_full = NULL;
	val_or_null = NULL;
//	if (is_error_export(...) == true)
//		handl_error_not_exit(...);
//		return (EXIT_FAILURE);
	if (node->num_children == 0)
		ft_export(env_wrapper, key_or_full, val_or_null);
	else
	{
		i = 0;
		while (i < node->num_children)
		{
			key_or_full = node->children[0]->value;
			ft_export(env_wrapper, key_or_full, val_or_null);
			i++;
		}
	}
	return (EXIT_SUCCESS);// 失敗のケースはどんな時？？？
}
