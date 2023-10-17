/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 07:05:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "error_minishell.h"
#include "parse.h"
#include "traverse.h"
#include "minishell.h"
#include "ft_printf.h"

#include "debug.h"
int	g_flag_debug;
int	g_fd_log;

// test 2 patern
#define LINE1 "> in"
#define LINE2 ">> here_doc"
#define LINE3 "< out"
#define LINE4 "<< append"
#define LINE5 "ls -l && < non_exist ls_zzz || ls -l | cat -e | grep Make"
#define LINE6 "$(VAR) \"42tokyo\" && \"ec\"\"ho\" \'hello_world\'"
#define LINE7 "ls | < file_in cat > file_out << eof1 << eof2 | cat"
#define LINE8 "< file_in ls | < file_in cat > file_out << eof1 << eof2 | cat > file_out"
#define NUM		7

//int main(int argc, char *argv[], char *env[])
int main(int argc, char *argv[])
{
	t_ast	*ast;
	char	**tokens;
//	static char	*lines[NUM] = {LINE1, LINE2, LINE3, LINE4, LINE5, LINE6};
	char	*line;
	int	i;
	char	*file_log;

	if (argc == 1)
		ft_perror_exit("error of num argment\n");
	file_log = argv[1];
	g_flag_debug = DEBUG_ON;
	g_fd_log = open_log(file_log, O_TRUNC);

	i = 2;
	line = ft_strdup(argv[i]);
	i++;
	while (argv[i] != NULL)
	{
		line = ft_strjoin_free(line, " ");
		line = ft_strjoin_free(line, argv[i]);
		i++;
	}
	//tokens = tkn_controller(line);// why does not derimiter? in test5,6
	tokens = ft_split(line, ' ');
	debug_token(tokens);
	ast = parse(tokens);
	debug_ast(ast);
	free_two_darray(tokens);

	debug_leaks("main", "a.out");
	return (0);
}
