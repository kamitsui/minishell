/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:14:02 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 16:28:15 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file tokenize.h
 * @brief <command-line>の文字列をトークン分けするための関数、マクロを定義
 */
#ifndef TOKENIZE_H
# define TOKENIZE_H

# include <stdlib.h>
# include <stdbool.h>

/**
 * @brief \<connector\> "&&"
 */
# define CONNECT_AND	"&&"

/**
 * @brief \<connector\> "||"
 */
# define CONNECT_OR		"||"

/**
 * @brief \<pipe-operator\> "|"
 */
# define PIPE			"|"

/**
 * @brief \<in-operator\> "<"
 */
# define IN_RED			"<"

/**
 * @brief \<out-operator\> ">"
 */
# define OUT_RED		">"

/**
 * @brief \<here_doc-operator\> "<<"
 */
# define HERE_DOC		"<<"

/**
 * @brief \<append-operator\> ">>"
 */
# define APPEND			">>"

/**
 * @brief \<double-quote-operator\> """"
 */
# define DQUOT			"\""

/**
 * @brief \<single-quote-operator\> "''"
 */
# define SQUOT			"\'"

/**
 * @brief \<double-quote-operator\> "$"
 */
# define VAR			"$"

/**
 * @brief 入力文字列を条件に応じてトークン分けする。
 */
char	**tokenize(char *line);

#endif
