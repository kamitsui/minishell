/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minishell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/25 23:57:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error_minishell.h
 * @brief minishellのエラー処理で使う関数、マクロの定義
 */
#ifndef ERROR_MINISHELL_H
# define ERROR_MINISHELL_H

/**
 * @brief minishell実行時に引数が渡された時のエラーメッセージ
 * @note 要検討（引数を渡してもいいのでは？未調査）
 */
# define MSG_ARG		"Error: argument out of specification\
							-> Usage \"./minishell\"\n"

/**
 * @brief readline関数が失敗した時のエラーメッセージ
 */
# define MSG_READLINE	"Error: readline function\n"

# define MSG_CREATE_ENV	"Error: create_env_list function\n"

/**
 * @brief handle_error関数に渡すエラーコード
 * @details
 * ERR_ARG : minishell実行時に引数が存在した時のエラー処理\n
 * ERR_READLINE : read_line関数のエラー処理\n
 * ERR_CREATE_ENV : create_env_list関数のエラー処理\n
 * ERR_NUM : put_error_message関数（error_code関数のヘルパー関数）で使用
 * @note 要検討（ERR_ARGはいらないかも...）
 */
enum	e_error_code
{
	ERR_ARG,
	ERR_READLINE,
	ERR_CREATE_ENV,
	ERR_NUM
};

/**
 * @brief システムコール失敗時のエラーメッセージに使う
 */
# define NAME			"minishell"

/**
 * @brief システムコール以外のエラー処理。標準エラー出力へのメッセージ出力と、
 * エラーコードを終了ステータスとして返す関数。
 */
void	handle_error(int error_code);
int	handle_syntax_error(char *unexpected_token, int sig);
# define MSG_SYNTAX_ERR	"syntax error near unexpected token"
# define MSG_NEW_LINE	"newline"

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
