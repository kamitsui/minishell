/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:06:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/24 01:49:10 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "environ.h"
#include "libft.h"
#include "error_minishell.h"
#include "minishell.h"
#include "parse.h"

//todo astarisk expansion

static char	*exp_strjoin(char *new_word, char *to_add, t_list *env, char sign)
{
	char	*tmp;
	char	*joined_word;

	if (sign == '$')
	{
		tmp = to_add;
		to_add = env_get_value_by_key(env, &to_add[1]);
		if (!to_add)
			to_add = ft_strdup("");
		free(tmp);
	}
	joined_word = ft_strjoin(new_word, to_add);
	if (!joined_word)
	{
		return (NULL);
	}
	free(new_word);
	free(to_add);
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

static char	*expansion_exit_status(t_envwrap *env_wrapper)
{
	char	*new_value;
	t_string	str;

	init_t_string(&str);
	new_value = ft_itoa(env_wrapper->exit_code);
	if (new_value == NULL)
		ft_perror_exit("ft_itoa");
	add_token(&str, new_value);
	free(new_value);
	str.out = str_join_to_out(str.out, str.buffer, str.len);
	return (str.out);
}

//! char cmdline has to be already verified only for "" or nonclasified
int	expand_dollar_sign_on_char(char **cmdline, t_envwrap *env_wrap)
{
	size_t	start;
	size_t	end;
	char	*old_cmd;
	char	*new_cmd;
	char	*join_str;

	old_cmd = *cmdline;
	new_cmd = ft_strdup("");
	start = 0;
	end = 0;
	while (old_cmd[start])
	{
		end = get_end(old_cmd, end, old_cmd[start]);
		if (ft_strcmp(old_cmd + start, "$?") == 0)
		{
			join_str = expansion_exit_status(env_wrap);
			new_cmd = ft_strjoin_free(new_cmd, join_str);
			if (!new_cmd)
				return (EXIT_FAILURE);
			break ;
		}
		else
		{
			join_str = ft_substr(old_cmd, (unsigned int) start, end - start);
			if (!join_str)
				return (EXIT_FAILURE);
			new_cmd = exp_strjoin(new_cmd, join_str, env_wrap->env, \
															old_cmd[start]);
			if (!new_cmd)
				return (EXIT_FAILURE);
			start = end;
		}
	}
	*cmdline = new_cmd;
	free(old_cmd);
	return (EXIT_SUCCESS);
}
//
//void	tkn_expansion_tester(void)
//{
//	extern char	**environ;
//	t_envwrap	*env_wrap;
//	char		*test_word;
//	char		*tmp;
//
//	env_wrap = create_env_list(environ);
//	test_word = ft_strdup("\"$PWD@$HOME$H@ME\"");
//	// while (cmdlst)
//	// {
//	// 	token = cmdlst->content;
//	// 	if (token->flg == unclassified || token->flg == doube_quote)
//	// 	{
//	// 		if (ft_strchr(token->word, '$') != NULL)
//	// tmp = test_word;
//	printf("before:[%s]\n", test_word);//!
//	expand_dollar_sign_on_char(&test_word, env_wrap);//!＄展開関数
//	tmp = test_word;
//	test_word = ft_strtrim(test_word, "\"\'");//!クオートを削除
//	free(tmp);
//	// 	}
//	// 	cmdlst = cmdlst->next;
//	// }
//	// free(tmp);
//	printf("after:[%s]\n", test_word);//!
//	ft_lstclear(&env_wrap->env, _env_del_content);
//	free(env_wrap->pwd);
//	free(env_wrap);
//	free(test_word);
//	system("leaks -q expansion");
//}
//
//int main(void)
//{
//	tkn_expansion_tester();
//	return (0);
//}
