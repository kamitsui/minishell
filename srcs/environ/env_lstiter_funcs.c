/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/11/08 17:15:08 by mogawa           ###   ########.fr       */
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

void	_env_print_lst(void *content)
{
	t_env	*node;

	if (!content)
		return ;
	node = content;
	if (ft_strcmp(node->val, "") == 0)
		return ;
	ft_printf("%s=%s\n", node->key, node->val);
}

void	_env_print_with_export(void *content)
{
	t_env	*node;

	if (!content)
		return ;
	node = content;
	if (ft_strcmp(node->key, "_") == 0)
		return ;
	if (ft_strcmp(node->val, "") == 0)
		ft_printf("declare -x %s\n", node->key);
	else
		ft_printf("declare -x %s=\"%s\"\n", node->key, node->val);
}
