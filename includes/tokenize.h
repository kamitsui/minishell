/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:14:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 12:25:12 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

#include <stdlib.h>
#include <stdbool.h>

// Delimiter in tokenize
# define CONNECT_AND	"&&"
# define CONNECT_OR		"||"

size_t	count_tokens(char *line);
char	*get_next_token(char *str, char const *sep);
bool	inc_connect(char *line);

#endif
