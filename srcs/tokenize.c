/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:26:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/10 12:26:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 文字列1行を受け取って、トークン単位に分けていく。
 *
 * @param line : type (char *)
 *
 * @return type (t_token *) 
 */
t_token	*tokenize(char *line)
{
	// t_token	*tokens
	//
	// 例　"ls -a | grep "$VAR"
	//
	// tokens[0]
	//     **var   [ls] [-a] [|] [grep] ["$VAR"]
	//     type               ^          ^    ^ <quoted-string>
	//                   <pipe_command>
	// tokens[1]
	//     **var  [&&]
	//     type    ^ <connector>
	// tokens[2]
	//     **var  [echo] [42] [>] [file]
	//     type    ^           ^ <output-redirection>
	//             <simple-command>
	//
	// return (tokens);
}
