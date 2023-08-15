/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:25:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 17:40:06 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
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
}
// 目的
// リストの構造体にtokenコマンドライン<command-line>をリストとして繋いでいく。
// 例
// line[ls -a | cat -e && echo $VAR | grep "abc"]
// |
// tokens[0] [ls -a | cat -e ]
// tokens[1] [&&]
// tokens[2] [ echo $VAR | grep "abc"]
// tokens[3] NULL
// |
// t_node->content ... target [ls -a | cat -e]
//        |
// t_node ... t_parse parse.var = [ls] [-a] NULL
//                           parse.type = TOK_PIPE_COM | TOK_PIPE_OUT
//                           parse.status = (コマンドのexit statusを格納する変数)
// list->next
//       |
//     list->content ... t_parse parse.var = [cat] [-e] NULL
//                               parse.type = TOK_PIPE_COM | TOK_PIPE_IN
//                               parse.status = (？？？使わないかも)
//     list->next
//           |
//         list->content ... t_parse parse.var = [&&] NULL
//                                   parse.type = TOK_CONNECT | TOK_CON_AND
//                                   parse.status = (？？？使わないかも)
//         list->next
//               |
//             list->content ... t_parse parse.var = [ echo] [$VAR] ] NULL
//                                       parse.type = TOK_CONNECT | TOK_CON_AND
//                                       parse.status = (？？？使わないかも)
//
// 以下は不採用
// コマンド<command> or を＋抽象構文木を作る t_ast *head;
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
