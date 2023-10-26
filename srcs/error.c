/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:05:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/26 13:52:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error.c
 * @brief エラー検出時のエラー処理する関数
 */
#include "error_minishell.h"
#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief エラーメッセージを標準エラー出力する関数。(ヘルパー関数）
 *
 * @param error_code 出力させたいエラーメッセージに対するエラーコード
 * @note 文字列要素の順番や組み合わせを修正した方がいいかも。。。
 */
static void	put_error_message(int error_code)
{
	static char	*msg[ERR_NUM] = {MSG_ARG, MSG_READLINE, MSG_CREATE_ENV};

	ft_dprintf(STDERR_FILENO, msg[error_code]);
}

/**
 * @brief システムコール以外のエラー処理。標準エラー出力へのメッセージ出力と、
 * エラーコードを終了ステータスとして返す関数。
 *
 * @param error_code エラー判定の内容
 */
void	handle_error(int error_code)
{
	put_error_message(error_code);
	exit(error_code);// 要検討　使っていいエラーコードを調べる
}

int	handle_syntax_error(char *unexpected_token, int sig)
{
	char	*message = MSG_SYNTAX_ERR;

	if (unexpected_token == NULL)
		unexpected_token = MSG_NEW_LINE;
	ft_dprintf(STDERR_FILENO, "%s: %s `%s'\n", NAME, message, unexpected_token);
	if (sig == SIGINT)
	{
		if (kill(getpid(), sig) == -1)
			perror("kill");
	}
	return (SIGINT);
}

void	put_error_message_from_errno(char *cause)
{
	int		error_number;
	char	*error_message;

	error_number = errno;
	error_message = strerror(error_number);
	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", NAME, cause, error_message);
}

/**
 * @brief システムコールや関数の失敗時のエラーハンドル
 * （errnoからエラーメッセージ出力とexitを行う関数）
 *
 * @param cause 失敗したシステムコールの名前
 */
void	ft_errno_exit(char *cause)
{
	put_error_message_from_errno(cause);
	exit (1);
}

/**
 * @brief エラーメッセージ出力とexit(1)を行う関数
 *
 * @param message エラー出力に書かせるメッセージ
 * @note 不要かも。。。
 */
void	ft_perror_exit(char *message)
{
	perror(message);
	exit (1);
}
