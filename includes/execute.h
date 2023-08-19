/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:59:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 10:39:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parse.h"

# define MAX_SIZE 32
# define READ_END	0
# define WRITE_END	1


typedef struct s_command
{
	char	*cmd_name;
	char	**args;
	int		num_args;
	char	**env;
} t_command;

typedef struct s_cmdstack
{
	t_command	commands[MAX_SIZE];
	int			num_commands;
}	t_cmdstack;

void	exec_file(char *file, char *arguments[], char *env[]);
int		execute_command(t_ASTNode *command_node, char **env, int status);
//int	exec_pipe_cmd(t_cmdstack *cmdstack);
int		execute_pipeline(t_ASTNode **commands, size_t num_commands, char **env);
int		wait_process(pid_t pid, int num_commands);
void	set_cmd_stack(t_cmdstack *cmdstack,
		t_ASTNode **commands, size_t num_commands);
void	set_environ(t_cmdstack *cmdstack, char **env);
void	get_arguments(t_command *commands, t_ASTNode *node);

#endif
