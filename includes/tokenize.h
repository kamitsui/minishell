/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:14:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 15:10:17 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

#include <stdlib.h>
#include <stdbool.h>

// token->type で使う。
# define TOK_CONNECT	0x00000001
# define TOK_CON_AND	0x00000002
# define TOK_CON_OR		0x00000004
//# define TOK_			0x00000008
# define TOK_COMMAND	0x00000010
# define TOK_SIMPLE_COM	0x00000020
# define TOK_PIPE_COM	0x00000040
//# define TOK_			0x00000080
# define TOK_IO_REDIR	0x00000100
# define TOK_IN_REDIR	0x00000200
# define TOK_OUT_REDIR	0x00000400
# define TOK_FILE		0x00000800
# define TOK_DQUOTED	0x00001000
# define TOK_SQUOTED	0x00002000
# define TOK_VAR		0x00004000
//# define TOK_			0x00008000
# define TOK_END		0x00010000

// Delimiter in tokenize
# define CONNECT_AND	"&&"
# define CONNECT_OR		"||"
# define PIPE			"|"
# define IN_RED			">"

size_t	count_tokens(char *line);
char	*get_next_token(char *str, char const *sep);
int	get_token_type(char *var);

#endif
