/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minishell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 10:13:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MINISHELL_H
# define ERROR_MINISHELL_H

# define MSG_ARG		"Error: not enough arguments -> Usage \"./minishell\"\n"
# define MSG_READLINE	"Error: readline function\n"
# define ERR_ARG		1
# define ERR_READLINE	2
# define ERR_NUM		3

# define NAME			"minishell"

void	error_code(int error_code);
void	ft_errno_exit(char *cause);
void	ft_perror_exit(char *message);

#endif
