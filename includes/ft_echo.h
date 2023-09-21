/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:10:51 by mogawa            #+#    #+#             */
/*   Updated: 2023/09/21 09:42:13 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ECHO_H
# define FT_ECHO_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# define SPACE (32)
# define FIRST_IDX (0)

void	ft_echo(char **argv);

#endif