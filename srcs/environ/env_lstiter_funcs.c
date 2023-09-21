/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstiter_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:10 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 17:35:32 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "ft_printf.h"

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

void	_print_env_lst(void *content)
{
	t_env	*node;

	node = content;
	ft_printf("%s=%s\n", node->key, node->val);
}

void	_print_env_with_export(void *content)
{
	t_env	*node;

	node = content;
	ft_printf("declare -x %s=\"%s\"\n", node->key, node->val);
}
