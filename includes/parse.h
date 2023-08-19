/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:04:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 10:30:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>

# define BIT_COMMAND	0x00000001
# define BIT_ARGUMENT	0x00000002
# define BIT_OPERATOR	0x00000004
//# define BIT_CONNECT	0x00000008

//# define BIT_CON_AND	0x00000002
//# define BIT_CON_OR		0x00000004
//# define BIT_SIMPLE_COM	0x00000010
//# define BIT_PIPE_COM	0x00000020
//# define BIT_PIPE_OUT	0x00000040
//# define BIT_PIPE_IN	0x00000080
//# define BIT_IO_RED		0x00000100
//# define BIT_IN_RED		0x00000200
//# define BIT_HERE_DOC	0x00000400
//# define BIT_OUT_RED	0x00000800
//# define BIT_APPEND		0x00001000
//# define BIT_FILE		0x00002000
//# define BIT_DQUOTED	0x00010000
//# define BIT_SQUOTED	0x00020000
//# define BIT_VAR		0x00040000
//# define BIT_			0x00080000
//# define BIT_END		0x00100000

typedef enum e_NodeType
{
	NODE_COMMAND,
	NODE_ARGUMENT,
	NODE_OPERATOR,
//	NODE_DEFAULT,
	NODE_END
} t_NodeType;

typedef struct	s_ASTNode t_ASTNode;
struct s_ASTNode
{
	t_NodeType	type;
	int			flag;
	char		*value;
	t_ASTNode	**children;
	size_t		num_children;
} ;

t_ASTNode	*parse(char** tokens);
void		free_ast(t_ASTNode* node);
t_ASTNode	*create_node(t_NodeType type, char* value);
size_t		is_pipe_command(char **tokens);

#endif
