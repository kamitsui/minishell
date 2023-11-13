/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exp_sm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/11/13 09:34:20 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traverse.h"

void	init_exp_sm(t_exp_sm *machine)
{
	machine->state = EXP_LETTER;
	init_t_string(&machine->str);
}
