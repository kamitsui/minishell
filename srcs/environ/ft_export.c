/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:49:27 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/20 18:18:08 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

void	_is_key_in_env_list(void *content)
{
	t_env	*node;

	node = content;
	if (node->key == )
}

//! no validation check included
void	ft_export(t_list *head, char *new_env)
{
	char	*key;
	char	*value;
	char	**splited;

	splited = ft_split(new_env, '=');
	key = splited[KEY];
	value = splited[VALUE];
	
}