/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:27:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/28 22:05:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include	"libft.h"
//#include	"ft_printf.h"
//#include	"parse.h"
//#include	"debug.h"
//
//static char	*get_flag_value(int i)
//{
//	static char	*src[25] = {
//		"BIT_OPERATOR", "BIT_COMMAND", "BIT_CONNECTOR", "BIT_PIPE_COM",
//		"BIT_SIMPLE_COM", "BIT_EXECUTABLE", "BIT_ARGUMENT",
//		"BIT_IO_REDIRECTIONS",
//		"BIT_REDIRECTION", "BIT_FILE", NULL, NULL,
//		"BIT_AND_LIST", "BIT_OR_LIST", NULL, NULL,
//		"BIT_IN_RED", "BIT_HERE_DOC", "BIT_OUT_RED", "BIT_APPEND",
//		"BIT_EXPANSION", "BIT_DQUOTE", "BIT_SQUOTE", "BIT_VAR",
//		"BIT_PARENTHESIS"};
//	char		*value;
//
//	value = NULL;
//	if (src[i] != NULL)
//		value = ft_strdup(src[i]);
//	return (value);
//}
//
//void	debug_flag(t_ast *node)
//{
//	char	*value;
//	char	*ref_bit;
//	int		i;
//
//	i = 0;
//	while ((0x1 << i) <= BIT_PARENTHESIS)
//	{
//		value = get_flag_value(i);
//		ref_bit = ft_itoa_binary(0x01 << i);
//		if (node->flag & 1 << i)
//			ft_dprintf(g_fd_log, "\tflag[%s]\t%s\n", ref_bit, value);
//		if (value != NULL)
//			free(value);
//		free(ref_bit);
//		i++;
//	}
//}
