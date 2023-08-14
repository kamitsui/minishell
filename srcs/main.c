/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:41:05 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 10:48:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_minishell.h"
#include "ft_printf.h"
//#include <stdlib.h>// for leak check

int	main(int argc, char *argv[], char *env[])
{
	char	*line[100];

	if (argc != 1)
		error_code(ERR_ARG);
	input(line);
	(void)argv[argc];
	(void)env[0];
	system("leaks minishell");
	return (0);
}
