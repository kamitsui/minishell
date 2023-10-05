/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:53:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/05 20:44:48 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_minishell.h
 * @brief minishellで確保したヒープ領域のメモリを開放する関数を定義
 */

#ifndef FREE_MINISHELL_H
# define FREE_MINISHELL_H

# include "environ.h"

/**
 * @brief char**型の二次元配列をフリーする関数\n
 */
void	free_two_darray(char *array[]);

/**
 * @brief 抽象構文木のノードとその子ノードを全てフリーする関数
 */
void	free_ast(t_ast *node);

void	free_envwrap(t_envwrap *env_wrapper);

#endif
