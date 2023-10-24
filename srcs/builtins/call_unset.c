/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:17:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"

int	call_unset(t_ast *node, t_envwrap *env_wrapper)
{
	char	*tgt_key;
//	static const char	*cause = "unset";
//	static const char	*error_msg = "not a valid identifier";
// bash: unset: `1': not a valid identifier

//	if (is_error_unset(...) == true)
//		handl_error_not_exit(...);
//		return (EXIT_FAILURE);
	if (node->num_children == 0)
		return (EXIT_SUCCESS);
	tgt_key = node->children[0]->value;
	ft_unset(env_wrapper, tgt_key);
	return (EXIT_SUCCESS);
}
