/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:06:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/30 18:23:26 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "environ.h"
#include "libft.h"
#include "error_minishell.h"

char	*exp_join(char *new, char *add, t_envwrap *e_wrap, bool is_exit)
{
	char	*tmp;
	char	*joined_word;

	if (!is_exit)
	{
		tmp = add;
		add = env_get_value_by_key(e_wrap->env, &add[1]);
		if (!add)
			add = ft_strdup("");
		free(tmp);
	}
	else if (is_exit)
	{
		tmp = add;
		add = ft_itoa(e_wrap->exit_code);
		free(tmp);
	}
	joined_word = ft_strjoin(new, add);
	if (!joined_word)
	{
		ft_errno_exit("ft_strjoin");
	}
	free(new);
	free(add);
	return (joined_word);
}

static int	get_end(char const *str, size_t end, char sign)
{
	end++;
	if (sign == '$')
	{
		if (str[end] == '?')
			return (end + 1);
		while (str[end] && (ft_isalnum(str[end])))
			end++;
	}
	else
	{
		while (str[end] && str[end] != '$')
			end++;
	}
	return (end);
}

int	expand_dollar_sign_on_char(char **cmdline, t_envwrap *env_wrap)
{
	unsigned int	start;
	unsigned int	end;
	char			*old_cmd;
	char			*new_cmd;
	char			*join_str;

	old_cmd = *cmdline;
	new_cmd = ft_strdup("");
	start = 0;
	end = 0;
	while (old_cmd[start])
	{
		end = get_end(old_cmd, end, old_cmd[start]);
		join_str = ft_substr(old_cmd, start, end - start);
		if (!join_str)
			ft_errno_exit("ft_substr");
		if (ft_strcmp(old_cmd + start, "$?") == 0)
			new_cmd = exp_join(new_cmd, join_str, env_wrap, true);
		else
			new_cmd = exp_join(new_cmd, join_str, env_wrap, false);
		start = end;
	}
	*cmdline = new_cmd;
	free(old_cmd);
	return (EXIT_SUCCESS);
}
