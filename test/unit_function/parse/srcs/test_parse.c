/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/16 12:35:41 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"

int main() {
    char* tokens[] = { "ls", "-l", "file.txt", "operator", "cat", "file.txt", NULL };
	debug_token(tokens);
    t_ASTNode* ast = parse_program(tokens);

    // Traverse the AST and execute the commands (implementation not shown here)

    // Free the allocated memory for the AST
    free_ast(ast);

    return 0;
}
