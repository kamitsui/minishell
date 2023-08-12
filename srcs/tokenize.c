/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:26:16 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/12 15:26:02 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	get_goken(char *line)
{
	
}

/**
 * @brief 文字列1行を受け取って、トークン単位に分けていく。
 *
 * @param line : type (char *)
 *
 * @return type (t_token *) 
 */
t_token	*tokenize(char *line)
{
	t_token	*tokens

	while (line[i] != NULL)
	{
		tokens = get_token(line[i]);
		i++;
	}
	return (tokens);
}
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
