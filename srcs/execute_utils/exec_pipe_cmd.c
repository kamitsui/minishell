/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:39:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/15 14:01:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_printf.h"
#include "error_minishell.h"
#include "execute.h"

//void	child_process(t_pipex *pipex, int pipefd[2], char **cmd_args, int i)
void	child_process(t_command command, int pipefd[2], int i, int num_commands)
{
	char	*file;

//	file = cmd_args[0];
	file = command.args[0];
	close(pipefd[READ_END]);
	if (i < num_commands - 1)
	{
		if (dup2(pipefd[WRITE_END], STDOUT_FILENO) == -1)
		{
			close(pipefd[WRITE_END]);
			ft_errno_exit("dup2");
		}
	}
	close(pipefd[WRITE_END]);
	exec_file(file, command.args, command.env);
	ft_fprintf(STDERR_FILENO, "bash: %s: command not found\n", file);
	exit (127);
}

void	parent_process(int pipefd[2])
{
	close(pipefd[WRITE_END]);
	if (dup2(pipefd[READ_END], STDIN_FILENO) == -1)
	{
		close(pipefd[READ_END]);
		ft_errno_exit("dup2");
	}
	return ;
}

static void	free_args(char **cmd_args)
{
	int		j;

	j = 0;
	while (cmd_args[j] != NULL)
	{
		free(cmd_args[j]);
		j++;
	}
	free(cmd_args);
}

//static int	wait_process(pid_t pid, t_pipex *pipex)
static int	wait_process(pid_t pid, int num_commands)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_commands - 1)
	{
		waitpid(-1, &status, 0);
		i++;
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status);
	return (status);
}

int	exec_pipe_cmd(t_cmdstack *cmdstack)
{
	int		pipefd[2];
	int		i;
	char	**cmd_args;
	pid_t	pid;

	i = 0;
	while (i < cmdstack->num_commands)
	{
		cmd_args = cmdstack->commands[i].args;
		//if (cmd_args == NULL)
		if (cmdstack->commands[i].args == NULL)
			ft_perror_exit("ft_split");
		if (pipe(pipefd) == -1)
			ft_perror_exit("pipe");
		pid = fork();
		if (pid == -1)
			ft_perror_exit("fork");
		else if (pid == 0)
			//child_process(pipex, pipefd, cmd_args, i);
			child_process(cmdstack->commands[i], pipefd, i, cmdstack->num_commands);
		else
			parent_process(pipefd);
		free_args(cmdstack->commands[i].args);
		i++;
	}
	return (wait_process(pid, cmdstack->num_commands));
}

//int exec_pipe_cmd(t_Command *commands, int num_commands, char *env[]) {
//    int pipe_fd[2];
//    int in_fd = STDIN_FILENO;
//
//    for (int i = 0; i < num_commands; i++) {
//        if (i < num_commands - 1) {
//            pipe(pipe_fd);
//        }
//
//			ft_printf("%d[%s]\n", i, commands[i].cmd_name);
//        pid_t pid = fork();
//        if (pid == 0) {
//            // Child process
//            if (i > 0) {
//                dup2(in_fd, STDIN_FILENO);
//                close(in_fd);
//            }
//            
//            if (i < num_commands - 1) {
//                close(pipe_fd[0]);
//                dup2(pipe_fd[1], STDOUT_FILENO);
//                close(pipe_fd[1]);
//            }
//
//            execve(commands[i].cmd_name, commands[i].args, env);
//            perror("execve");
//            exit(EXIT_FAILURE);
//        } else if (pid > 0) {
//            // Parent process
//            if (i > 0) {
//                close(in_fd);
//            }
//            
//            if (i < num_commands - 1) {
//                close(pipe_fd[1]);
//                in_fd = pipe_fd[0];
//            }
//        } else {
//            perror("fork");
//            return -1;
//        }
//    }
//
//    for (int i = 0; i < num_commands; i++) {
//        wait(NULL);
//    }
//
//    return 0;
//}

//int main(int ac, char **av, char **env) {
//    t_command pipe_commands[2];
//
//    char *ls_args[] = {"/bin/ls", "-a", NULL};
//    char *grep_args[] = {"/usr/bin/grep", "42", NULL};
//
//    pipe_commands[0].cmd_name = "/bin/ls";
//    pipe_commands[0].args = ls_args;
//    pipe_commands[0].num_args = 2;
//	pipe_commands[0].env = env;
//
//    pipe_commands[1].cmd_name = "/usr/bin/grep";
//    pipe_commands[1].args = grep_args;
//    pipe_commands[1].num_args = 2;
//	pipe_commands[1].env = env;
//
////    t_Command *commands = {&pipe_commands[0], &pipe_commands[1]};
//    t_cmdstack	cmdstack;
//	cmdstack.commands[0] = pipe_commands[0];
//	cmdstack.commands[1] = pipe_commands[1];
//	cmdstack.num_commands = 2;
//
////    char *env[] = {NULL}; // You can set your environment variables here
//
////	printf("0[%s] 1[%s]\n", commands[0].cmd_name, commands[1].cmd_name);
//    exec_pipe_cmd(&cmdstack);
////    exec_pipe_cmd(&pipe_commands[0], 2, env);
//    
//	(void)av[ac];
//    return 0;
//}
//
