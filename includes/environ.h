/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:21:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/25 09:30:24 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file environ.h
 * @brief 環境変数に関する関数を宣言
 */
#ifndef ENVIRON_H
# define ENVIRON_H

# include <stdlib.h>
// # include <stdbool.h>
# include "libft.h"

# define KEY (0)
# define VALUE (1)

typedef struct s_env
{
	char	*key;
	char	*val;
}	t_env;

typedef struct s_env_wrap
{
	t_env	*env;
	int		exit_code;
	char	*pwd;
}	t_env_wrap;

/**
 * @brief 環境変数からPATHを取り出す時に使う関数(free必要)
 */
char	*substr_env(char *name, char *env[]);

//* ft_env
void	ft_env(t_list *lst_head);

//* ft_unset.c
void	ft_unset(t_list **env_head, char *tgt_key);

//* env_utils
// void	env_set_tgt_key_value(t_list *env_head, char *key, char *val);
char	*env_get_value(t_list *env_head, char *key);
t_env	*env_create_node_from_char(char *env_line);

//* env ft_lstiter funcs
void	_env_del_content(void *content);
void	_env_print_lst(void *content);
void	_env_print_with_export(void *content);

//* export
void	ft_export(t_list **env_head, char *new_env);

#endif
