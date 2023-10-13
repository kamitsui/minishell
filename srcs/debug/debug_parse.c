/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:10:38 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/13 02:08:55 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"
#include	"parse.h"
#include	"debug.h"

char	*get_value(int i)
{
	static char	*src[BIT_APPEND / 4] = {
			"BIT_COMMAND", "BIT_ARGUMENT", "BIT_OPERATOR", "BIT_REDIRECTION",
			"BIT_FILE", NULL, NULL, NULL,
			"BIT_AND_LIST", "BIT_OR_LIST", NULL, NULL,
			"BIT_IN_RED", "BIT_HERE_DOC", "BIT_OUT_RED", "BIT_APPEND"};
	char		*value;

	value = NULL;
	if (src[i] != NULL)
		value = ft_strdup(src[i]);
	return (value);
}

void	put_reference(t_ast *node)
{
	char	*value;
	char	*ref_bit;
	int		i;

	ft_dprintf(g_fd_log, "\nreference\n");
	i = 0;
	while ((0x1 << i) <= BIT_APPEND)
	{
		value = get_value(i);
		ref_bit = ft_itoa_binary(0x01 << i);
		if (node->flag & 1 << i)
			ft_dprintf(g_fd_log, "\tflag[%s]\t%s\n", ref_bit, value);
		if (value != NULL)
			free(value);
		free(ref_bit);
		i++;
	}
	ft_dprintf(g_fd_log,
		"\ttype[%d] COMMAND[%d] ARGUMENT[%d] OPERATOR[%d] REDIRECTION[%d] FILE[%d]\n",
		node->type, NODE_COMMAND, NODE_ARGUMENT, NODE_OPERATOR, NODE_REDIRECTION, NODE_FILE);
}

void	debug_parse(const char *call_by, t_ast *node)
{
	char	*flag;

	if (g_flag_debug == DEBUG_OFF)
		return ;
	ft_dprintf(g_fd_log, "%s---- NODE debug  ----\n", DEBUG_COLOR);
	ft_dprintf(g_fd_log, ">> call by [%s] function\t", call_by);
	ft_dprintf(g_fd_log, "\n\nnode info\n");
	flag = ft_itoa_binary(node->flag);
	ft_dprintf(g_fd_log, "\tnode[%s]\ttype[%d]\n\tflag[%s]\n",
		node->value, (int)node->type, flag);
	free(flag);
	put_reference(node);
	ft_dprintf(g_fd_log, "\n\n");
}
