/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:10:38 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/28 22:05:32 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include	"libft.h"
//#include	"ft_printf.h"
//#include	"parse.h"
//#include	"debug.h"
//
//void	debug_parse(const char *call_by, t_ast *node)
//{
//	char	*flag;
//
//	if (g_flag_debug == DEBUG_OFF)
//		return ;
//	ft_dprintf(g_fd_log, "%s---- ONE NODE debug  ----\n", DEBUG_COLOR);
//	ft_dprintf(g_fd_log, ">> call by [%s] function\t", call_by);
//	ft_dprintf(g_fd_log, "\n\nnode info\n");
//	flag = ft_itoa_binary(node->flag);
//	ft_dprintf(g_fd_log, "\tnode[%s]\ttype[%d]\n\tflag[%s]\n",
//		node->value, (int)node->type, flag);
//	free(flag);
//	debug_flag(node);
//	ft_dprintf(g_fd_log, "\n\n");
//}
