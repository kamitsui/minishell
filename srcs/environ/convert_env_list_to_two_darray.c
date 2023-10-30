/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_list_to_two_darray.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:23:19 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 18:36:16 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "minishell.h"
#include "error_minishell.h"

char	*dup_env_element(t_env *env_node)
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

void	copy_env_element(char buff[BUFF_SIZE], t_env *env_node)
{
	size_t	buff_size;

	buff_size = sizeof(char [BUFF_SIZE]);
	ft_strlcpy(buff, env_node->key, buff_size);
	ft_strlcat(buff, "=", buff_size);
	ft_strlcat(buff, env_node->val, buff_size);
}

char	*get_env_element(char buff[BUFF_SIZE], t_env *env_node)
{
	size_t	len;

	len = ft_strlen(env_node->key) + ft_strlen(env_node->val);
	if (len + 1 > BUFF_SIZE)
		return (dup_env_element(env_node));
	else
	{
		copy_env_element(buff, env_node);
		return (buff);
	}
}

char	**convert_env_list_to_two_darray(t_list *env_list)
{
	char		**env;
	char		*env_element;
	char		buff[BUFF_SIZE];
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
		env_element = get_env_element((char *)buff, crnt->content);
		env[i] = ft_strdup(env_element);
		if (sizeof(env_element) > BUFF_SIZE)
			free(env_element);
		crnt = crnt->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}
