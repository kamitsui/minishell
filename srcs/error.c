/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:05:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/11 23:20:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_minishell.h"
#include "ft_printf.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

static void	error_message(int error_code)
{
	static char	*msg[ERR_NUM] = {MSG_READLINE};

	ft_fprintf(STDERR_FILENO, msg[error_code]);
}

void	error_code(int error_code)
{
	error_message(error_code);
	exit(error_code);
}

void	ft_errno_exit(char *cause)
{
	int		error_number;
	char	*error_message;

	error_number = errno;
	error_message = strerror(error_number);
	ft_fprintf(STDERR_FILENO, "%s: %s: %s\n", NAME, cause, error_message);
	exit (1);
}

void	ft_perror_exit(char *message)
{
	perror(message);
	exit (1);
}
