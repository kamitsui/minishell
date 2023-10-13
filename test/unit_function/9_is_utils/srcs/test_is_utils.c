/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 17:48:00 by kamitsui         ###   ########.fr       */
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
#define LINE1 ">in"
#define LINE2 ">>here_doc"
#define LINE3 "<out"
#define LINE4 "<<append"
#define LINE5 "ls -l && < non_exist || echo 42"
#define NUM				1
#define NUM_IS_UTILS	6

void	test_is_node_type(char **token)
{
	int	i;
	static t_is_type_node	f_is_utils[NUM_IS_UTILS] = {
			is_string, is_operator, is_and_list, is_or_list, is_pipe,
			is_redirection};
	static char *str_type[NUM_IS_UTILS] = {
			"is_string", "is_operator", "is_and_list", "is_or_list", "is_pipe",
			"is_redirection"};

	ft_dprintf(g_fd_log, ">> test_is_node_type\n");
	while (*token != NULL)
	{
		i = 0;
		while (i < NUM_IS_UTILS)
		{
			if (f_is_utils[i](*token))
				ft_dprintf(g_fd_log, "\ttoken[%s] type[%s]\n", *token, str_type[i]);
			i++;
		}
		token++;
	}
}

int main(void)
{
	t_ast	*ast;
	char	**tokens;
	static char	*lines[NUM] = {LINE5};
//	static char	*lines[NUM] = {LINE1, LINE2, LINE3, LINE4, LINE5};
	int	i;

	g_flag_debug = DEBUG_ON;
	g_fd_log = open_log("debug.log", O_TRUNC);

	i = 0;
	while (i < NUM)
	{
		//tokens = tkn_controller(lines[i]);// why does not derimiter?
		tokens = ft_split(lines[i], ' ');
		debug_token(tokens);
		test_is_node_type(tokens);
		ast = parse(tokens);
		debug_ast(ast);
		free_two_darray(tokens);
		i++;
	}

	system("leaks a.out");
	return (0);
}
