/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:19:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/04 21:55:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"
#include "parse.h"
#include "environ.h"
#include "error_minishell.h"
#include "builtins.h"
#include "free_minishell.h"

static bool	is_multi_option(char *value, char *options)
{
	size_t	i;

	if (ft_strncmp(value, "-", 1) == 0)
	{
		i = 1;
		if (value[i] == '\0')
			return (false);
		else
		{
			while (value[i] != '\0')
			{
				if (ft_strchr(options, value[i]) != NULL)
				{
					i++;
					continue ;
				}
				else
					return (false);
			}
			return (true);
		}
	}
	else
		return (false);
}

static size_t	get_argument_number(t_ast *node)
{
	size_t	count_argument;
	char	*value;
	size_t	i;

	count_argument = 1;
	if (node->num_children == 0)
		return (count_argument);
	i = 0;
	if (*(node->children[i]->value) == '-')
	{
		while (i < node->num_children)
		{
			value = node->children[i]->value;
			if (is_multi_option(value, OPTION_ECHO) == true)
				count_argument += ft_strlen(value + 1);
			else
				count_argument++;
			i++;
		}
	}
	else
		count_argument = node->num_children;
	return (count_argument);
}

static void	set_echo_arguments(t_ast *node, char **argv)
{
	size_t	i;
	char	*value;
	bool	is_option;
	bool	is_find_string;

	is_find_string = false;
	i = 0;
	while (i < node->num_children)
	{
		value = node->children[i]->value;
		is_option = (*value == '-' && is_find_string == false);
		if (is_option == false)
			is_find_string = true;
		if (is_multi_option(value, OPTION_ECHO) == true && is_option == true)
			argv[i] = ft_strdup("-n");
		else
			argv[i] = ft_strdup(value);
		i++;
	}
	argv[i] = NULL;
}

int	call_echo(t_ast *node, t_envwrap *env_wrapper)
{
	char	**argv;
	size_t	size;

	(void)env_wrapper;
	size = get_argument_number(node);
	argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (argv == NULL)
		ft_errno_exit("malloc");
	if (node->num_children == 0)
	{
		argv[0] = ft_strdup("");
		argv[1] = NULL;
		ft_echo(argv);
	}
	else
	{
		set_echo_arguments(node, argv);
		ft_echo(argv);
	}
	free_two_darray(argv);
	return (EXIT_SUCCESS);
}
