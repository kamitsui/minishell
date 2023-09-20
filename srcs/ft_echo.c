/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:10:56 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/20 13:02:22 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"
#include "libft.h"

static bool	has_n_option(char *arg)
{
	if (ft_strcmp(arg, "-n") == 0)
		return (true);
	else
		return (false);
}

//! no error handling implimented. no error exit implimented.
void	ft_echo(char **argv)
{
	const bool	has_n = has_n_option(argv[OPTION_LOC]);//! OPTION_LOC == 1 or 0? コマンド名渡す？
	size_t		i;

	i = OPTION_LOC;//!OPTION_LOC
	if (has_n)
		i = OPTION_LOC + 1;//!OPTION_LOC
	while (argv[i])
	{
		if (has_n == true)
			ft_putstr_fd(argv[i], STDOUT_FILENO);
		else
			ft_putendl_fd(argv[i], STDOUT_FILENO);
		i++;
	}
	exit (EXIT_SUCCESS);
}

// int	main(void)
// {
// 	char	**cmd;

// 	cmd = ft_split("-n hello world", ' ');
// 	ft_echo(cmd);
// }