/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_list_to_two_darray.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:23:19 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 19:12:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"

static char	*get_env_element(t_env *env_node)
{
	char	*env_element;

	env_element = ft_strdup(env_node->key);
	if (env_element == NULL)
		ft_errno_exit("ft_strdup");
	env_element = ft_strjoin_free(env_element, "=");
	if (env_element == NULL)
		ft_errno_exit("ft_strjoin_free");
	env_element = ft_strjoin_free(env_element, env_node->val);
	if (env_element == NULL)
		ft_errno_exit("ft_strjoin_free");
	return (env_element);
}

char	**convert_env_list_to_two_darray(t_list *env_list)
{
	char		**env;
	t_list		*crnt;
	const int	lstsize = ft_lstsize(env_list);
	int			i;

	if (env_list == NULL)
		return (NULL);
	env = (char **)malloc(sizeof(char *) * (lstsize + 1));
	if (env == NULL)
		ft_errno_exit("malloc");
	i = 0;
	crnt = env_list;
	while (i < lstsize)
	{
		env[i] = get_env_element(crnt->content);
		crnt = crnt->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}
