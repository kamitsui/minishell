/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:05:41 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 17:39:16 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error.c
 * @brief エラー検出時のエラー処理する関数
 * @note 注意ft_fprintf -> ft_dprintf リネームする（未完）
 */
#include "error_minishell.h"
#include "ft_printf.h"
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
static void	error_message(int error_code)
{
	static char	*msg[ERR_NUM] = {NULL, MSG_ARG, MSG_READLINE};

	ft_fprintf(STDERR_FILENO, msg[error_code]);
}

/**
 * @brief システムコール以外のエラー処理。標準エラー出力へのメッセージ出力と、
 * エラーコードを終了ステータスとして返す関数。
 *
 * @param error_code エラー判定の内容
 */
void	error_code(int error_code)
{
	error_message(error_code);
	exit(error_code);
}

/**
 * @brief システムコール失敗時のエラーメッセージ出力とexitを行う関数。
 *
 * @param cause 失敗したシステムコールの名前
 */
void	ft_errno_exit(char *cause)
{
	int		error_number;
	char	*error_message;

	error_number = errno;
	error_message = strerror(error_number);
	ft_fprintf(STDERR_FILENO, "%s: %s: %s\n", NAME, cause, error_message);
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
