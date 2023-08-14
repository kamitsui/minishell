/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenclosed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:33:35 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/14 21:21:26 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdbool.h>

static int	get_start_idx(const char *str, size_t len, char start)
{
	int		start_idx;
	size_t	i;

	start_idx = -1;
	i = 0;
	while (i < len)
	{
		if (str[i] == start)
		{
			start_idx = i;
			break ;
		}
		i++;
	}
	return (start_idx);
}

static int	get_end_idx(const char *str, size_t len, char end)
{
	int		end_idx;
	size_t	i;

	end_idx = -1;
	i = len;
	while (i >= 1)
	{
		if (str[i - 1] == end)
		{
			end_idx = i - 1;
			break ;
		}
		i--;
	}
	return (end_idx);
}

bool	ft_isenclosed(const char *str, char start, char end)
{
	int	len;
	int	start_idx;
	int	end_idx;

	len = strlen(str);
	start_idx = get_start_idx(str, len, start);
	if (start_idx == -1)
		return (false);
	end_idx = get_end_idx(str, len, end);
	if (end_idx == -1 || end_idx <= start_idx)
		return (false);
	return (true);
}
//
//#include <stdio.h>
//int main() {
//    char str1[] = "123(abc)XYZ";
//    char str2[] = "[not enclosed";
//    char str3[] = "not enclosed)";
//    char str4[] = "()";
//    char str5[] = "abc)123(XYZ";
//
//    char start = '(';
//    char end = ')';
//
//    if (ft_isenclosed(str1, start, end)) {
//        printf("'%s' is enclosed.\n", str1);
//    } else {
//        printf("'%s' is not enclosed.\n", str1);
//    }
//
//    if (ft_isenclosed(str2, start, end)) {
//        printf("'%s' is enclosed.\n", str2);
//    } else {
//        printf("'%s' is not enclosed.\n", str2);
//    }
//
//    if (ft_isenclosed(str3, start, end)) {
//        printf("'%s' is enclosed.\n", str3);
//    } else {
//        printf("'%s' is not enclosed.\n", str3);
//    }
//
//    if (ft_isenclosed(str4, start, end)) {
//        printf("'%s' is enclosed.\n", str4);
//    } else {
//        printf("'%s' is not enclosed.\n", str4);
//    }
//
//    if (ft_isenclosed(str5, start, end)) {
//        printf("'%s' is enclosed.\n", str5);
//    } else {
//        printf("'%s' is not enclosed.\n", str5);
//    }
//
//    return 0;
//}
