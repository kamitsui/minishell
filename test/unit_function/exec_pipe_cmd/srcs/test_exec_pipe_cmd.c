/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec_pipe_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 11:44:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <stdlib.h>

int main(int ac, char **av, char **env) {
    t_command pipe_commands[2];

    char *ls_args[] = {"/bin/ls", "-a", NULL};
    char *grep_args[] = {"/usr/bin/grep", "Make", NULL};

    pipe_commands[0].cmd_name = "/bin/ls";
    pipe_commands[0].args = ls_args;
    pipe_commands[0].num_args = 2;
	pipe_commands[0].env = env;

    pipe_commands[1].cmd_name = "/usr/bin/grep";
    pipe_commands[1].args = grep_args;
    pipe_commands[1].num_args = 2;
	pipe_commands[1].env = env;

	t_cmdstack	cmdstack;
	cmdstack.commands[0] = pipe_commands[0];
	cmdstack.commands[1] = pipe_commands[1];
	cmdstack.num_commands = 2;


//	printf("0[%s] 1[%s]\n", commands[0].cmd_name, commands[1].cmd_name);
    exec_pipe_cmd(&cmdstack);
    
	(void)av[ac];
    return 0;
}
