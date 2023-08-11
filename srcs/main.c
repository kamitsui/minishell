/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:41:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/11 22:49:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include <stdlib.h>// for leak check

void	line_free(char **line)
{
	int	i = 0;

//	ft_printf("\n\n--- line_free -----\n", i);
	while (line[i] != NULL)
	{
//		ft_printf("--- free(line[%d] -----\n", i);
//		ft_printf("%s\t%p\n", line[i], line[i]);
		free(line[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char *env[])
{
	char	*line[100];

	if (argc != 1)
	{
		ft_printf("Error : argument number -> Usage \"./minishell\"\n");
		exit(1);
	}
	input(line);
	line_free(line);
	(void)argv[argc];
	(void)env[0];
	system("leaks minishell");
	return (0);
}
