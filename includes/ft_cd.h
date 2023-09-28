/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:47:28 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/25 14:42:31 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CD_H
# define FT_CD_H

# include <unistd.h>
# include "environ.h"

# define SYSCALL_FAILED (-1)
# define SYSCALL_SUCCESS (0)

void	ft_cd(char *path, t_envwrap *env_wrap);

#endif