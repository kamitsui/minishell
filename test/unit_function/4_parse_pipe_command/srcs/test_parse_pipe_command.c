/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_pipe_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/24 14:50:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "parse.h"
#include <string.h>

int main() {
//    char **tokens[] = { strdup("ls"), strdup("-l"), strdup("-a"), strdup("|"), strdup("cat"), strdup("-e"), strdup("|"), strdup("grep"), strdup("Make"), NULL };
    char **tokens = (char **)malloc(sizeof(char *) * 10);
	tokens[0] = strdup("ls");
	tokens[1] = strdup("-l");
	tokens[2] = strdup("-a");
	tokens[3] = strdup("|");
	tokens[4] = strdup("cat");
	tokens[5] = strdup("-e");
	tokens[6] = strdup("|");
	tokens[7] = strdup("grep");
	tokens[8] = strdup("Make");
	tokens[9] = NULL;
//    char* tokens[] = { "ls", "-l", "-a", "|", "cat", "-e", "|", "grep", "Make", "&&", NULL };
//    char* tokens[] = { "ls", "argument", "argument", "operator", "cat", "argument", NULL };
	debug_token(tokens);
    t_ast* ast = parse_pipe_command(&tokens, 3);
	debug_ast(ast);

    // Traverse the AST and execute the commands (implementation not shown here)

    // Free the allocated memory for the AST
    free_ast(ast);

    return 0;
}
