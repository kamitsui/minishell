/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:35:18 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 17:16:29 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	input_redirection(char *file_name)
{
	int	fdin;
	int	status;

	status = EXIT_FAILURE;
	if (access(file_name, F_OK | R_OK) == 0)
	{
		fdin = open(file_name, O_RDONLY);
		if (fdin == -1)
			put_error_message_from_errno(file_name);
		else
		{
			if (dup2(fdin, STDIN_FILENO) == -1)
				put_error_message_from_errno("dup2");
			else
			{
				close(fdin);
				status = EXIT_SUCCESS;
			}
		}
	}
	else
		put_error_message_from_errno(file_name);
	return (status);
}
