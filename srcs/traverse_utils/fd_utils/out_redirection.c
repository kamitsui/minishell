/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:25:44 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 12:57:00 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	out_redirection_trunc(char *file_name, t_envwrap *env_wrapper)
{
	int	fdout;
	int	status;

	(void)env_wrapper;// case of no expansion
	status = EXIT_FAILURE;
	if (access(file_name, F_OK) == 0
		&& access(file_name, W_OK) == -1)
		put_error_message_from_errno(file_name);
	else
	{
		fdout = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fdout == -1)
			put_error_message_from_errno(file_name);
		else
		{
			if (dup2(fdout, STDOUT_FILENO) == -1)
				put_error_message_from_errno("dup2");
			else
			{
				close(fdout);
				status = EXIT_SUCCESS;
			}
		}
	}
	return (status);
}

int	out_redirection_append(char *file_name, t_envwrap *env_wrapper)
{
	int	fdout;
	int	status;

	(void)env_wrapper;// case of no expansion
	status = EXIT_FAILURE;
	if (access(file_name, F_OK) == 0
		&& access(file_name, W_OK) == -1)
		put_error_message_from_errno(file_name);
	else
	{
		fdout = open(file_name, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fdout == -1)
			put_error_message_from_errno(file_name);
		else
		{
			if (dup2(fdout, STDOUT_FILENO) == -1)
				put_error_message_from_errno("dup2");
			else
			{
				close(fdout);
				status = EXIT_SUCCESS;
			}
		}
	}
	return (status);
}
