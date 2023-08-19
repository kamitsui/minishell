/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:06:24 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 14:06:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "tokenize.h"
#include "parse.h"
#include "execute.h"

void	debug_input(char *line);
//void	debug_tokenize(t_token *tokens);
void	debug_token(char **tokens);
void	debug_ast(t_ASTNode *ast);
void	debug_command(t_command *command);

#endif
