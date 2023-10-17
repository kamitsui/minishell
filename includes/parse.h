/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:04:14 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 16:27:57 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse.h
 * @brief 抽象構文木ASTのデータを作るための構造体、関数、マクロなどを定義
 */
#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stdbool.h>

/**
 * @brief ノードタイプを特定するための列挙型変数を定義
 * @details
 * NODE_OPERATOR : \<command-line>\n
 * NODE_COMMAND : \<command>\n
 * NODE_CONNECTOR : \<connector>\n
 * NODE_END : ノード走査(traverse_ast関数)のストップ条件として活用
 */
enum	e_NodeType
{
	NODE_OPERATOR,
	NODE_COMMAND,
	NODE_CONNECTOR,
	NODE_PIPE_COM,
	NODE_SIMPLE_COM,
	NODE_EXECUTABLE,
	NODE_ARGUMENT,
	NODE_IO_REDIRECTIONS,
	NODE_REDIRECTION,
	NODE_FILE,
	NODE_END
};

/**
 * @brief [<simple-command>] + [<io-redirection>]*
 * @detail
 * <sinmple-command> が1個 もしくは\n
 * <io-redirection> が1~n個　もしくは\n
 * <io-redirection> + <simple-command> が1個　順序不同\n
 */
# define BIT_OPERATOR			0x00000001
# define BIT_COMMAND			0x00000002
# define BIT_CONNECTOR			0x00000004
# define BIT_PIPE_COM			0x00000008
# define BIT_SIMPLE_COM			0x00000010
# define BIT_EXECUTABLE			0x00000020
# define BIT_ARGUMENT			0x00000040
# define BIT_IO_REDIRECTIONS	0x00000080
# define BIT_REDIRECTION		0x00000100
# define BIT_FILE				0x00000200

# define BIT_AND_LIST			0x00001000
# define BIT_OR_LIST			0x00002000

# define BIT_IN_RED				0x00010000
# define BIT_HERE_DOC			0x00020000
# define BIT_OUT_RED			0x00040000
# define BIT_APPEND				0x00080000

# define BIT_EXPANSION			0x00100000
# define BIT_DQUOTE				0x00200000
# define BIT_SQUOTE				0x00400000
# define BIT_VAR				0x00800000

# define BIT_PARENTHESIS		0x01000000

/**
 * @brief コネクタータイプの種類数
 * @details 関数 is_connector で使用
 */
# define NUM_CONNECTOR		2

/**
 * @brief ノードの値（文字列）に対して、種類を調べる関数の数
 * @details get_node_flag関数 で使用 ( create_node.c 内のヘルパー関数 )
 */

# define NUM_NOT_STRING		4
# define NUM_REDIRECTION	4
# define NUM_EXPANSION		3
# define NUM_GET_FLAG		11

/**
 * @brief 抽象構文木の構造体名を定義
 */
typedef struct s_ast	t_ast;

/**
 * @brief 抽象構文木ASTのデータ構造体
 * @details
 * type : ノードのタイプ。\n
 * flag : expansion（展開）の処理で使う。BIT単位でflagを立てる。\n
 * value : ノードの名前　traverse_ast（全ノード走査）の処理で使う。\n
 * children : 全ての子ノードのアドレスの保管場所(AST構造体のダブルポインタ)\n
 * num_children : 子ノードの数
 */
struct s_ast
{
	enum e_NodeType	type;
	int				flag;
	char			*value;
	t_ast			**children;
	size_t			num_children;
};

/**
 * @brief parse関数はトークンの情報を解析し、
 * 抽象構文木のデータ構造に置き換えます。
 */
t_ast	*parse(char **tokens);

t_ast	*parse_connector(char ***tokens);

/**
 * @brief \<simple-command> or <pipe-command> のノードを作る関数
 */
t_ast	*parse_command(char ***tokens, char *head_value);

/**
 * @brief \<pipe-command> のノードを作る関数
 */
t_ast	*parse_pipe_command(char ***tokens, char *head_value);

/**
 * @brief \<simple-command>のノードを作る関数
 */
t_ast	*parse_simple_command(char ***tokens, char *head_value);

t_ast	*parse_io_redirections(char **tokens, char *head_value);
//t_ast	*parse_io_redirections_in_simple_command(char **tokens, char *head_value);
t_ast	*parse_file(char **tokens);
t_ast	*parse_executable(char ***tokens);

/**
 * @brief 新規ノードを作る関数
 * ノードのタイプと値を引数で受け取り、ノードの構造体にセットする
 */
t_ast	*create_node(enum e_NodeType type, char *value);

char	*get_command_value(char **tokens);
char	*get_pipe_command_value(char **tokens);
char	*get_one_pipe_command_value(char **tokens);
char	*get_simple_command_value(char **tokens);
char	*get_redirection_value(char **tokens);
char	*get_redirection_value_in_simple_command(char **tokens);
char	*get_one_redirection_value(char **tokens);
char	*get_executable_value(char **tokens);

/**
 * @brief 現在のトークンがオペレーターかどうか調べる関数
 */
bool	is_connector(const char *token);
bool	is_and_list(const char *token);
bool	is_or_list(const char *token);
bool	is_pipe(const char *token);
bool	is_redirection(const char *token);
bool	is_in_red(const char *token);
bool	is_here_doc(const char *token);
bool	is_out_red(const char *token);
bool	is_out_append(const char *token);
bool	is_string(const char *token);
bool	is_expansion(const char *token);
bool	is_dquote(const char *token);
bool	is_squote(const char *token);
bool	is_variable(const char *token);
bool	is_end(const char *token);

bool	is_include_redirection(char **tokens);
bool	is_include_redirection_in_simple_com(char **tokens);
bool	is_include_pipe_command(char **tokens);

/**
 * @brief ノードの値（文字列）に対して、種類を調べる関数を関数ポインタとして宣言
 * @details 使用関数\n
 * get_node_flag関数 で使用 ( create_node.c 内のヘルパー関数 )
 */
typedef bool	(*t_is_type_node)(const char *);

#endif
