/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:18:46 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/21 20:59:46 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "error_minishell.h"

void	init_t_string(t_string *str)
{
	ft_bzero(&str->buffer, BUFF_SIZE);
	str->len = 0;
	str->out = ft_strnew(1);
	if (str->out == NULL)
		ft_errno_exit("ft_strnew");
	str->out_len = 0;
}
