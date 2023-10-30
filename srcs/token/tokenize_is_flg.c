/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_is_flg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:27:47 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 14:26:00 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

bool	flg_is_operator(t_flg flg)
{
	if (flg == ampersand || flg == single_pipe)
		return (true);
	else if (flg == allow_read || flg == allow_write)
		return (true);
	else
		return (false);
}

bool	flg_is_quote(t_flg flg)
{
	if (flg == doube_quote || \
		flg == single_quote || \
		flg == parenthesis_open || \
		flg == parenthesis_close)
	{
		return (true);
	}
	else
		return (false);
}
