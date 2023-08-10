/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:25:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/10 12:25:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 各トークンをリスト構造のデータ構造に入れる。
 *
 * @param token : type (t_list *)
 * @param data  : 環境変数envやcurrent_dirなどの変数
 *
 * @return list : リスト構造を返す。
 */
t_list	*parse(t_deque *tokens, t_data *data)
{
	// tokenコマンドライン<command-line>をリストとして繋いでいく。 を コマンド<command> or を＋抽象構文木を作る t_ast *head;
	// 例
	// 　引数　tokens = {[ls], [-a], [|], [grep], ["$VAR"], [&&], [echo], [42], [>], [file], [;], [$CMD], [-a]}
	//
	// 　抽象構文木 = ast ↓
	// 　                                                                             <connector> [;]
	//                                               L <connector> [&&]               R <simple-command> [$CMD],[-a]
	//                     L <simple-command>                            R <command>
	//                              |                                         |
	//                              |                                      <out_redirect>
	//                              |                                  L <simple-command> [echo],[42]
	//                      <pipeline-command> [|]
	//                 L <simple-command> [ls],[-l]    R <simple-command> [grep],[$VAR]
	//
	// return(head);
}
