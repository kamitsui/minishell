/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:21:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/09/30 20:28:41 by mogawa           ###   ########.fr       */
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

// for ft_pwd
# define UNDEFINED (1)

// t_env
# define KEY (0)
# define VALUE (1)

typedef struct s_env
{
	char	*key;
	char	*val;
}	t_env;

typedef struct s_envwrap
{
	t_list	*env;
	int		exit_code;
	char	*cwd;
}	t_envwrap;

/**
 * @brief 環境変数からPATHを取り出す時に使う関数(free必要)
 */
char	*substr_env(char *name, char *env[]);

// * ft_pwd
void	ft_pwd(t_envwrap *env);
char	*ft_getcwd(t_envwrap *env);

//* ft_env
void	ft_env(t_envwrap *env_wrapper);

//* ft_unset.c
void	ft_unset(t_envwrap *env_wrap, char *tgt_key);

//* env_utils
// void	env_set_tgt_key_value(t_list *env_head, char *key, char *val);
char	*env_get_value_by_key(t_list *env_head, char *key);
t_env	*env_create_node_from_char(char *key_or_full, char *val_or_null);

//* env ft_lstiter funcs
void	_env_del_content(void *content);
void	_env_print_lst(void *content);
void	_env_print_with_export(void *content);

//* export
// void	ft_export(t_list **env_head, char *new_env);
void	ft_export(t_envwrap *env_wrap, char *key_or_full, char *val_or_null);

#endif
