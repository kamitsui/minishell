/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tentative.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:07:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/30 20:28:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc_tentative(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return ((void *)malloc(new_size));
	if (new_size == 0 || old_size > new_size)
		return (NULL);
	new_ptr = (void *)malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	else
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}
