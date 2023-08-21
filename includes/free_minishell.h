/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:53:39 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 16:28:52 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file free_minishell.h
 * @brief minishellで確保したヒープ領域のメモリを開放する関数を定義
 */

#ifndef FREE_MINISHELL_H
# define FREE_MINISHELL_H

/**
 * @brief readlineで読み取った関数をフリーする\n
 * lineのfreeは不要（スタック領域を使っているため）
 */
void	free_line(char **line);

/**
 * @brief char**型の二次元配列をフリーする関数\n
 * tokensのfreeは必要（ヒープ領域にメモリ確保しているため）
 */
void	free_tokens(char **tokens);

/**
 * @brief 抽象構文木のノードとその子ノードを全てフリーする関数
 */
void	free_ast(t_ast *node);

#endif
