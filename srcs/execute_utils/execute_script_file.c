/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_script_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:51:34 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/07 10:32:31 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_minishell.h"

/**
 * @brief minishell起動時に引数で渡されたスクリプトファイルを実行する関数
 *
 * @param file インタプリンタ言語で書かれたスクリプトファイル
 * @param env[] 環境変数
 *
 * @return 実行結果の終了ステータス
 */
int	execute_script_file(char *file, char *env[])
{
	int	status;

	handle_error(ERR_ARG);// 仮
	// fileをPATHを通して実行する。(未着手)
	(void)status;// 仮
	(void)file;// 仮
	(void)env;// 仮
	return(EXIT_SUCCESS);// 本番は実行した終了ステータスを返す
}
