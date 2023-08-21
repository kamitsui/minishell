/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 18:50:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file traverse.h
 * @brief 抽象構文木の全ノードを走査する関数を定義
 */
#ifndef TRAVERSE_H
# define TRAVERSE_H

/**
 * @brief 抽象構文木のノード全てを走査して、順番に実行していく再帰関数
 */
int		traverse_ast(t_ast *node, char **env, int status);

/**
 * @brief ノードのタイプがオペレーターノードの時に呼び出す関数をを割り振る
 */
int		handle_operator(t_ast *operator_node, char **env, int status);

/**
 * @brief traverse_ast関数内で行う各ノードタイプ毎の関数を関数ポインタとして使う
 * （ステートマシンの制御手法）
 */
typedef int	(*t_handle_node)(t_ast *node, char **env, int status);

#endif
