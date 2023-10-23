/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:55:37 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/23 17:11:05 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "libft.h"
#include "execute.h"
#include "error_minishell.h"
#include "meta_minishell.h"
#include "traverse.h"
#include <sys/wait.h>

#include "debug.h"
#include "ft_printf.h"

//static void	child_process_in_parenthesis(
//			int pipefd[2], char *token, t_envwrap *env_wrapper)
//{
//	close(pipefd[READ_END]);
//	if (dup2(pipefd[WRITE_END], STDOUT_FILENO) == -1)
//	{
//		close(pipefd[WRITE_END]);
//		ft_errno_exit("dup2");
//	}
//	close(pipefd[WRITE_END]);
//	exit (lets_go_shell(token, env_wrapper));
//}
//
//static void	parent_process_in_parenthesis(int pipefd[2])
//{
//	close(pipefd[WRITE_END]);
//	if (dup2(pipefd[READ_END], STDIN_FILENO) == -1)
//	{
//		close(pipefd[READ_END]);
//		perror("dup2");
//	}
//	return ;
//}

char	*get_token_in_parenthesis(char *value)
{
	t_string	str;
	size_t	i;
	char	*end;

	init_t_string(&str);
	end = ft_strrchr(value, META_ROUND_BRACKET_RIGHT);
	i = 1;
	while (value + i != end)
	{
		str_add_to_buff(&str, value[i]);
		i++;
	}
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}

int	sub_minishell(char *value, t_envwrap *env_wrapper)
{
	char	*token;
	int		pipefd[2];
	pid_t	pid;

	token = get_token_in_parenthesis(value);
	if (is_parenthesis(token) == true)
		return (EXIT_FAILURE);
	if (pipe(pipefd) == -1)
		ft_perror_exit("pipe");
	pid = fork();
	if (pid == -1)
		ft_perror_exit("fork");
//	else if (pid == 0)
	if (pid == 0)
		exit (lets_go_shell(token, env_wrapper));
//		child_process_in_parenthesis(pipefd, token, env_wrapper);
//	else
//		parent_process_in_parenthesis(pipefd);
	free(token);
	return (wait_process(pid, 1));
}

int	handle_parenthesis(t_ast *node, t_envwrap *env_wrapper)
{
	int	status;
	int	original_stdout_fd;
	int	original_stdin_fd;

	ft_dprintf(g_fd_log, ">> call in handle_parenthesis([%s], env_wrapper)\n", node->value);//debug
	original_stdin_fd = buck_up_fd(STDIN_FILENO);
	if (original_stdin_fd == -1)
		ft_errno_exit("dup");
	original_stdout_fd = buck_up_fd(STDOUT_FILENO);
	if (original_stdout_fd == -1)
		ft_errno_exit("dup");
	status = sub_minishell(node->value, env_wrapper);
	recover_fd(original_stdin_fd, STDIN_FILENO);
	recover_fd(original_stdout_fd, STDOUT_FILENO);
	ft_dprintf(g_fd_log, ">> end in handle_parenthesis ... status [%d]\n", status);//debug
	return (status);
}
