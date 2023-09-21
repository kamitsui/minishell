/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 14:58:28 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

void	_env_del_content(void *content)
{
	t_env	*node;

	node = content;
	free(node->key);
	node->key = NULL;
	free(node->val);
	node->val = NULL;
	free (node);
	node = NULL;
}
