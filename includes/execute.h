/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:59:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 22:21:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parse.h"

# define MAX_SIZE 32
# define READ_END	0
# define WRITE_END	1

void	exec_file(char *file, char *arguments[], char *env[]);

typedef struct s_command {
    char *cmd_name;
    char **args;
    int num_args;
	char	**env;
} t_command;

typedef struct s_cmdstack
{
	t_command	commands[MAX_SIZE];
	int			num_commands;
}	t_cmdstack;

int	exec_pipe_cmd(t_cmdstack *cmdstack);
int	execute_pipeline(t_ASTNode **commands, size_t num_commands);
void	set_cmd_stack(t_cmdstack *cmdstack,
		t_ASTNode **commands, size_t num_commands);

#endif
