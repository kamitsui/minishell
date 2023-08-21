/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minishell.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:36 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 17:18:09 by kamitsui         ###   ########.fr       */
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

/**
 * @brief minishell実行時に引数が存在した時のエラー番号
 * （終了ステータスとして返す）
 * @note 要検討（exit status の番号として使っていいのか...未調査）
 */
# define ERR_ARG		1

/**
 * @brief readline関数が失敗した時のエラー番号
 * （終了ステータスとして返す）
 * @note 要検討（exit status の番号として使っていいのか...未調査）
 */
# define ERR_READLINE	2

/**
 * @brief minishellのエラー番号の数
 * error_message関数（error_code関数のヘルパー関数）で使用
 */
# define ERR_NUM		3

/**
 * @brief システムコール失敗時のエラーメッセージに使う
 */
# define NAME			"minishell"

/**
 * @brief システムコール以外のエラー処理。標準エラー出力へのメッセージ出力と、
 * エラーコードを終了ステータスとして返す関数。
 */
void	error_code(int error_code);

/**
 * @brief システムコール失敗時のエラーメッセージ出力とexitを行う関数。
 */
void	ft_errno_exit(char *cause);

/**
 * @brief エラーメッセージ出力とexit(1)を行う関数
 */
void	ft_perror_exit(char *message);

#endif
