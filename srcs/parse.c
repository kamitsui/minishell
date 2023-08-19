/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:25:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 09:38:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_ASTNode	*parse_argument(char ***tokens)
{
	//if (**tokens && strcmp(**tokens, "argument") == 0)
	if (**tokens && strcmp(**tokens, "&&") != 0)
	{
		(*tokens)++; // Move to the next token (argument)
		return (create_node(NODE_ARGUMENT, *(*tokens - 1)));
	}
	return (NULL);
}

t_ASTNode	*parse_command(char ***tokens)
{
	t_ASTNode	*node;
	t_ASTNode	*arg_node;

	node = create_node(NODE_COMMAND, **tokens);
	(*tokens)++; // Move to the next token (command_name)
	while (**tokens && strcmp(**tokens, "&&") != 0)
	{
		arg_node = parse_argument(tokens);
		if (arg_node == NULL)
		{
			(*tokens)++;
			break ;
		}
		else
		{
			node->num_children++;
			node->children = (t_ASTNode**)realloc(node->children, node->num_children * sizeof(t_ASTNode *));
			node->children[node->num_children - 1] = arg_node;
		}
	}
	return (node);
}

t_ASTNode	*parse_operator(char ***tokens)
{
	if (**tokens && strcmp(**tokens, "&&") == 0)
	{
		(*tokens)++; // Move to the next token (operator)
		return (create_node(NODE_OPERATOR, *(*tokens - 1)));
	}
	return (NULL);
}


t_ASTNode	*parse(char **tokens)
{
	t_ASTNode	*ast;
	t_ASTNode	*operator_node;
	t_ASTNode	*command_node;

	ast = create_node(NODE_OPERATOR, PROGRAM_NAME);
	while (*tokens)
	{
		if (strcmp(*tokens, "&&") == 0)
		{
			operator_node = parse_operator(&tokens);
			if (operator_node)
			{
				ast->num_children++;
				ast->children = (t_ASTNode**)realloc(ast->children, ast->num_children * sizeof(t_ASTNode *));
				ast->children[ast->num_children - 1] = operator_node;
			}
		}
		else
		{
			// <pipe-command> [ls] [-a] [-l] [|] [cat] | [grep] [Make] .... num_pipe = 2
			size_t num_pipe = is_pipe_command(tokens);
			if (num_pipe > 0)
			{
				//t_ASTNode	*pipe_node = parse_pipe(&tokens);
				exit (1);
			}
			// <simple-command>  [ls] [-a] [-l]
			command_node = parse_command(&tokens);
			if (command_node)
			{
				ast->num_children++;
				ast->children = (t_ASTNode **)realloc(ast->children, ast->num_children * sizeof(t_ASTNode *));
				ast->children[ast->num_children - 1] = command_node;
			}
		}
	}
	return (ast);
}

// The way of test parse function
// |
// cd minishell/test/unit_function
// |
// parse test ...  tokens = { "ls", "-l", "file.txt", "&&", "cat", "file.txt", NULL }
// make 3
// make run3
// |
// parse & execute ... tokens = { "ls", "-l", "-a", "&&", "echo", "\n", "42", "tokyo", NULL }
// make 4
// make run4


// void code
/**
 * @brief 各トークンをリスト構造のデータ構造に入れる。
 *
 * @param token : type (t_list *)
 * @param data  : 環境変数envやcurrent_dirなどの変数
 *
 * @return list : リスト構造を返す。
 */
//t_list	*parse(t_deque *tokens, t_data *data)
//{
//}
// 目的
// リストの構造体にtokenコマンドライン<command-line>をリストとして繋いでいく。
// 例
// line[ls -a | cat -e && echo $VAR | grep "abc"]
// |
// tokens[0] [ls -a | cat -e ]
// tokens[1] [&&]
// tokens[2] [ echo $VAR | grep "abc"]
// tokens[3] NULL
// |
// t_node->content ... target [ls -a | cat -e]
//        |
// t_node ... t_parse parse.var = [ls] [-a] NULL
//                           parse.type = TOK_PIPE_COM | TOK_PIPE_OUT
//                           parse.status = (コマンドのexit statusを格納する変数)
// list->next
//       |
//     list->content ... t_parse parse.var = [cat] [-e] NULL
//                               parse.type = TOK_PIPE_COM | TOK_PIPE_IN
//                               parse.status = (？？？使わないかも)
//     list->next
//           |
//         list->content ... t_parse parse.var = [&&] NULL
//                                   parse.type = TOK_CONNECT | TOK_CON_AND
//                                   parse.status = (？？？使わないかも)
//         list->next
//               |
//             list->content ... t_parse parse.var = [ echo] [$VAR] ] NULL
//                                       parse.type = TOK_CONNECT | TOK_CON_AND
//                                       parse.status = (？？？使わないかも)
//
// 以下は不採用
// コマンド<command> or を＋抽象構文木を作る t_ast *head;
// 例
// 　引数　tokens = {[ls], [-a], [|], [grep], ["$VAR"], [&&], [echo], [42], [>], [file], [;], [$CMD], [-a]}
//
// 　抽象構文木 = ast ↓
// 　                                                                             <connector> [;]
//                                               L <connector> [&&]               R <simple-command> [$CMD],[-a]
//                     L <simple-command>                            R <command>
//                              |                                         |
//                              |                                      <out_redirect>
//                              |                                  L <simple-command> [echo],[42]
//                      <pipeline-command> [|]
//                 L <simple-command> [ls],[-l]    R <simple-command> [grep],[$VAR]
//
// return(head);
