/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:39:31 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/17 10:24:34 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "execute.h"
#include "debug.h"

int	handle_operator(t_ASTNode* operator_node, char **env) {
	int		status;

	status = -1;
	if (operator_node->type != NODE_OPERATOR)
		return (status);
	if (strcmp(operator_node->value, "|") == 0)
	{
		t_ASTNode** commands = operator_node->children;
		// Execute the pipeline
		status = execute_pipeline(commands, operator_node->num_children, env);
	}
	else if (strcmp(operator_node->value, "&") == 0)
	{
		// Implement background execution logic
		// ...
	}
	else
	{
		// Handle other operators if needed
		// ...
	}
	return (status);
}
