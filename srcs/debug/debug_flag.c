/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:27:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/14 17:39:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"
#include	"parse.h"
#include	"debug.h"

static char	*get_value(int i)
{
	static char	*src[BIT_VAR / 4] = {
			"BIT_COMMAND", "BIT_ARGUMENT", "BIT_OPERATOR", "BIT_IO_RED",
			"BIT_FILE", NULL, NULL, NULL,
			"BIT_AND_LIST", "BIT_OR_LIST", "BIT_PIPE", NULL,
			"BIT_IN_RED", "BIT_HERE_DOC", "BIT_OUT_RED", "BIT_APPEND",
			"BIT_EXPANSION", "BIT_DQUOTE", "BIT_SQUOTE", "BIT_VAR"};
	char		*value;

	value = NULL;
	if (src[i] != NULL)
		value = ft_strdup(src[i]);
	return (value);
}

void	debug_flag(t_ast *node)
{
	char	*value;
	char	*ref_bit;
	int		i;

	i = 0;
	while ((0x1 << i) <= BIT_VAR)
	{
		value = get_value(i);// handle_error
		ref_bit = ft_itoa_binary(0x01 << i);// handle_error
		if (node->flag & 1 << i)
			ft_dprintf(g_fd_log, "\tflag[%s]\t%s\n", ref_bit, value);
		if (value != NULL)
			free(value);
		free(ref_bit);
		i++;
	}
}
