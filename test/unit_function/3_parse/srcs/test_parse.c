/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/18 08:50:18 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"

int main() {
    char* tokens[] = { "ls", "-l", "file.txt", "&&", "cat", "file.txt", NULL };
//    char* tokens[] = { "ls", "argument", "argument", "operator", "cat", "argument", NULL };
	debug_token(tokens);
    t_ASTNode* ast = parse(tokens);
	debug_ast(ast);

    // Traverse the AST and execute the commands (implementation not shown here)

    // Free the allocated memory for the AST
    free_ast(ast);

    return 0;
}
