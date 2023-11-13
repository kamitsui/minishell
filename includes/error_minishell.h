/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minishell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 07:47:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error_minishell.h
 * @brief minishellのエラー処理で使う関数、マクロの定義
 */
#ifndef ERROR_MINISHELL_H
# define ERROR_MINISHELL_H

# include "minishell.h"

# define MSG_SIGQUIT	"Quit: 3\n"

void	handle_syntax_error(char *unexpected_token);

# define MSG_SYNTAX_ERR	"syntax error near unexpected token"
# define MSG_NEW_LINE	"newline"
# define MSG_NOT_VALID	"not a valid identifier"

/**
 * @brief システムコール失敗時のエラーメッセージ出力とexitを行う関数。
 */
void	ft_errno_exit(char *cause);
void	put_error_message_from_errno(char *cause);

/**
 * @brief エラーメッセージ出力とexit(1)を行う関数
 */
void	ft_perror_exit(char *message);

#endif
