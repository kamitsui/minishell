/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minishell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/11 23:21:08 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MINISHELL_H
# define ERROR_MINISHELL_H

#define	MSG_READLINE	"readline"
#define	ERR_READLINE	0
#define	ERR_NUM			1

#define	NAME			"minishell"

void	error_code(int error_code);
void	ft_errno_exit(char *cause);
void	ft_perror_exit(char *message);

#endif
