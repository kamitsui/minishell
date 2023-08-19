/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 15:14:09 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAVERSE_H
# define TRAVERSE_H

int		traverse_ast(t_ast *node, char **env, int status);
int		handle_operator(t_ast *operator_node, char **env, int status);

typedef int	(*t_handle_node)(t_ast *node, char **env, int status);

#endif
