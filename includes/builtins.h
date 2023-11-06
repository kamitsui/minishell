/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:52:12 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/04 21:48:49 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parse.h"

# define NUM_BUILTINS	7
# define STR_ECHO		"echo"
# define STR_CD			"cd"
# define STR_PWD		"pwd"
# define STR_ENV		"env"
# define STR_UNSET		"unset"
# define STR_EXPORT		"export"
# define STR_EXIT		"exit"

# define OPTION_ECHO	"n"

int		call_echo(t_ast *node, t_envwrap *env_wrapper);
int		call_cd(t_ast *node, t_envwrap *env_wrapper);
int		call_pwd(t_ast *node, t_envwrap *env_wrapper);
int		call_env(t_ast *node, t_envwrap *env_wrapper);
int		call_unset(t_ast *node, t_envwrap *env_wrapper);
int		call_export(t_ast *node, t_envwrap *env_wrapper);
int		call_exit(t_ast *node, t_envwrap *env_wrapper);

typedef int		(*t_call_builtins)(t_ast *, t_envwrap *);

bool	is_builtins_command(const char *value);
bool	is_valid_export_variable(char *str);

#endif
