/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/17 02:58:28 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file traverse.h
 * @brief 抽象構文木の全ノードを走査する関数を定義
 */
#ifndef TRAVERSE_H
# define TRAVERSE_H

# include "environ.h"

# define NUM_HANDLE	2

/**
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 */
int	traverse_ast(t_ast *node, t_envwrap *env_wrapper);

int	handle_connector(t_ast *node, t_envwrap *env_wrapper);
/**
 * @brief \<simple-command>のノードに対しての処理
 */
int	handle_command(t_ast *node, t_envwrap *env_wrapper);

/**
 * @brief \<argument>のノードに対しての処理
 */
int	handle_argument(t_ast *node, t_envwrap *env_wrapper);

/**
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 * "|" / "&&" / "||"
 */
int	handle_operator(t_ast *operator_node, t_envwrap *env_wrapper);

int	handle_redirection(t_ast *node, t_envwrap *env_wrapper);
int	handle_file(t_ast *node, t_envwrap *env_wrapper);

/**
 * @brief ノードタイプが　”｜”　パイプに対しての処理
 */
int	handle_pipe_command(t_ast *pipe_node, t_envwrap *env_wrapper);

/**
 * @brief traverse_ast関数内で行う各ノードタイプ毎の関数を関数ポインタとして使う
 * （ステートマシンの制御手法）
 */
typedef int	(*t_handle_node)(t_ast *node, t_envwrap *env_wrapper);

int		buck_up_fd(int fd);
void	recover_fd(int prev_fd, int recover_fd);

#endif
