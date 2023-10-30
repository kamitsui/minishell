/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 17:28:45 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file traverse.h
 * @brief 抽象構文木の全ノードを走査する関数を定義
 */
#ifndef TRAVERSE_H
# define TRAVERSE_H

# include "environ.h"
# include "parse.h"

# define NUM_HANDLE	3

/**
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 */
int		traverse_ast(t_ast *node, t_envwrap *env_wrapper);

int		handle_operator(t_ast *operator_node, t_envwrap *env_wrapper);

/**
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 * "|" / "&&" / "||"
 */
int		handle_connector(t_ast *node, t_envwrap *env_wrapper);

/**
 * @brief \<simple-command> <pipe-command>のノードに対しての処理
 */
int		handle_command(t_ast *node, t_envwrap *env_wrapper);

int		handle_simple_command(t_ast *node, t_envwrap *env_wrapper);

int		handle_io_redirections(t_ast *node);

# define PROMPT_HERE_DOC	"> "
# define READ_END	0
# define WRITE_END	1

/**
 * @brief ノードタイプが　”｜”　パイプに対しての処理
 */
int		handle_pipe_command(t_ast *pipe_node, t_envwrap *env_wrapper);
int		handle_parenthesis(t_ast *node, t_envwrap *env_wrapper);

void	handle_expansion(t_ast *node, t_envwrap *env_wrapper);
void	handle_empty_node(t_ast **node, t_envwrap *env_wrapper);

/**
 * @brief traverse_ast関数内で行う各ノードタイプ毎の関数を関数ポインタとして使う
 * （ステートマシンの制御手法）
 */
typedef int		(*t_handle_node)(t_ast *node, t_envwrap *env_wrapper);

int		buck_up_fd(int fd);
void	recover_fd(int prev_fd, int recover_fd);

typedef int		(*t_select_redirection)(char *);
int		input_redirection(char *file_name);
int		here_doc(char *end_of_block);
int		out_redirection_trunc(char *file_name);
int		out_redirection_append(char *file_name);

// ----------- for handle_expansion.c -----------------
enum e_exp_state
{
	EXP_LETTER,
	EXP_DQUOTE,
	EXP_SQUOTE,
	EXP_VAR,
	EXP_END
};

typedef struct s_exp_sm
{
	enum e_exp_state	state;
	t_string			str;
}	t_exp_sm;

typedef size_t	(*t_f_exp)(char *, t_exp_sm *, t_envwrap *);
size_t	exp_letter(char *value, t_exp_sm *machine, t_envwrap *env_wrapper);
size_t	exp_dquote(char *value, t_exp_sm *machine, t_envwrap *env_wrapper);
size_t	exp_squote(char *value, t_exp_sm *machine, t_envwrap *env_wrapper);
size_t	exp_var(char *value, t_exp_sm *machine, t_envwrap *env_wrapper);
size_t	count_variable_char(char *value);

#endif
