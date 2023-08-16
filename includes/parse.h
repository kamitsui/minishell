/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:04:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 15:11:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>

typedef enum e_NodeType {
    NODE_COMMAND,
    NODE_ARGUMENT,
    NODE_OPERATOR
} t_NodeType;

typedef struct s_ASTNode t_ASTNode;
struct s_ASTNode {
    t_NodeType type;
    char* value;
    t_ASTNode** children;
    size_t num_children;
};

t_ASTNode* parse(char** tokens);
void free_ast(t_ASTNode* node);

#endif
