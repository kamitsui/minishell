/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:10:56 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/29 21:11:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"
#include "libft.h"

static size_t	get_last_idx(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	if (i == 0)
		return (i);
	else
		return (i - 1);
}

static size_t	get_arg_start_idx(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-n") != 0)
			return (i);
		else
			i++;
	}
	return (i);
}

//! no error handling implimented. no error exit implimented.
void	ft_echo(char **argv)
{
	const size_t	last_idx = get_last_idx(argv);
	const size_t	start_arg_idx = get_arg_start_idx(argv);
	size_t			i;
	bool			has_n_option;

	has_n_option = false;
	if (start_arg_idx != FIRST_IDX)
		has_n_option = true;
	i = start_arg_idx;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (i == last_idx && has_n_option == false)
			ft_putchar_fd('\n', STDOUT_FILENO);
		else if (i == last_idx && has_n_option == true)
			break ;
		else
			ft_putchar_fd(SPACE, STDOUT_FILENO);
		i++;
	}
}

// int	main(void)
// {
// 	char	**cmd;

// 	cmd = ft_split("     -n -n     -n hello   -n        world", ' ');
// 	// cmd = ft_split("", ' ');
// 	ft_echo(cmd);
// }
