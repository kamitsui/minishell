/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:45 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/19 12:55:38 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAVERSE_H
# define TRAVERSE_H

//int		traverse_ast(t_ASTNode* node, char **env);
int		traverse_ast(t_ASTNode* node, char **env, int status);
int		handle_operator(t_ASTNode* operator_node, char **env, int status);

typedef int	(*t_handle_node)(t_ASTNode *node, char **env, int status);


#endif
