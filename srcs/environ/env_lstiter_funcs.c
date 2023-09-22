/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/22 16:37:10 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "ft_printf.h"

void	_env_del_content(void *content)
{
	t_env	*node;	

	if (!content)
		return ;
	node = content;
	free(node->key);
	node->key = NULL;
	free(node->val);
	node->val = NULL;
	free (node);
	node = NULL;
}

void	_print_env_lst(void *content)
{
	t_env	*node;

	if (!content)
		return ;
	node = content;
	ft_printf("%s=%s\n", node->key, node->val);
}

void	_print_env_with_export(void *content)
{
	t_env	*node;

	if (!content)
		return ;
	node = content;
	if (ft_strcmp(node->key, "-") == 0)
		return ;
	ft_printf("declare -x %s=\"%s\"\n", node->key, node->val);
}
