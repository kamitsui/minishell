/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:35:18 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/18 18:46:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	input_redirection(char *file_name, t_envwrap *env_wrapper)
{
	int	fdin;

	//file_name = handle_expansion(file_name, env_wrapper);
	(void)env_wrapper;// case of no expansion
	if (access(file_name, F_OK | R_OK) == 0)
	{
		fdin = open(file_name, O_RDONLY);
		if (fdin == -1)
			perror("open");
		if (dup2(fdin, STDIN_FILENO) == -1)
			perror("dup2");
		close(fdin);
		return (EXIT_SUCCESS);
	}
	else
	{
//		fdin = open("/dev/null", O_RDONLY);
//		if (fdin == -1)
//			perror("open");
//		if (dup2(fdin, STDIN_FILENO) == -1)
//			perror("dup2");
//		close(fdin);
//		status = ft_errno_set_status(pipex->in_file) != 0;
		put_error_message_from_errno(file_name);
		return (EXIT_FAILURE);
	}
}
