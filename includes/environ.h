/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:21:15 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/10 13:27:12 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file environ.h
 * @brief 環境変数に関する関数を宣言
 */
#ifndef ENVIRON_H
# define ENVIRON_H

# include <stdlib.h>
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

// * ft_pwd
void	ft_pwd(t_envwrap *env);
char	*ft_getcwd(t_envwrap *env);

//* ft_env
void	ft_env(t_envwrap *env_wrapper);

//* ft_unset.c
void	ft_unset(t_envwrap *env_wrap, char *tgt_key);

//* env_utils
char	*env_get_value_by_key(t_list *env_head, char *key);
t_env	*env_create_node_from_char(char *envline);

//* env ft_lstiter funcs
void	_env_del_content(void *content);
void	_env_print_lst(void *content);
void	_env_print_with_export(void *content);

//* ft_export
void	ft_export(t_envwrap *env_wrap, char *envline);

//* ft_exit
void	ft_exit(int status);

// env_listからchar **env(二次元配列)にコンバートする関数
char	**convert_env_list_to_two_darray(t_list *env);

#endif
