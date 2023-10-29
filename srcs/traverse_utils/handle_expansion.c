/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:09:06 by kamitsui          #+#    #+#             */
/*   Updated: 2023/10/29 12:54:51 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "environ.h"
#include "expansion.h"
#include "error_minishell.h"
#include "meta_minishell.h"

enum e_exp_state
{
	EXP_LETTER,
	EXP_DQUOTE,
	EXP_SQUOTE,
	EXP_VAR,
	EXP_END
};

typedef struct s_exp_sm
{
	enum e_exp_state	state;
	t_string		str;
}	t_exp_sm;

void	init_exp_sm(t_exp_sm *machine)
{
	machine->state = EXP_LETTER;
	init_t_string(&machine->str);
}

bool	is_allowd_variable_char(char c)
{
	return (ft_isalnum(c) == true || c == META_UNDER_CHR || c == META_QUESTION_CHR);
}

size_t	count_variable_char(char *value)
{
	size_t	len;

	len = 0;
	if (ft_strncmp(value, "$?", 2) == 0)
		len = 2;
	else
	{
		len++;
		while (is_allowd_variable_char(value[len]) == true)
		{
			len++;
			if (value[len] == META_QUESTION_CHR)
				break ;
		}
	}
	return (len);
}

size_t	exp_var(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_var;
	size_t	len;

	len = count_variable_char(value);
	if (len == 1)
	{
		str_add_to_buff(&machine->str, *value);
		machine->state = EXP_LETTER;
	}
	else
	{
		str_var = ft_strndup(value, len);
		expand_dollar_sign_on_char(&str_var, env_wrapper);
		add_token(&machine->str, str_var);
		free(str_var);
		machine->state = EXP_LETTER;
	}
	return (len);
}

size_t	exp_squote(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_squote;
	size_t	len;

	value++;
	len = ft_strchr(value, META_SQUOT_CHR) - value;
	if (len == 0)
	{
		machine->state = EXP_LETTER;
		return (2);
	}
	str_squote = ft_strndup(value, len);
	add_token(&machine->str, str_squote);
	free(str_squote);
	(void)env_wrapper;
	machine->state = EXP_LETTER;
	return (len + 2);
}

size_t	exp_dquote(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	char	*str_dquote;
	size_t	len;
	size_t	len_var;
	size_t	i;

	value++;
	len = ft_strchr(value, META_DQUOT_CHR) - value;
	if (len == 0)
		machine->state = EXP_LETTER;
	i = 0;
	while (value[i] != '"')
	{
		len_var = count_variable_char(value + i);
		if (value[i] == '$' && len_var > 1)
		{
			str_dquote = ft_strndup(value + i, len_var);
			expand_dollar_sign_on_char(&str_dquote, env_wrapper);
			add_token(&machine->str, str_dquote);
			free(str_dquote);
			i += len_var;
		}
		else
		{
			str_add_to_buff(&machine->str, value[i]);
			i++;
		}
	}
	len = i;
	machine->state = EXP_LETTER;
	return (len + 2);
}

size_t	exp_letter(char *value, t_exp_sm *machine, t_envwrap *env_wrapper)
{
	if (*value == META_DQUOT_CHR || *value == META_SQUOT_CHR)
	{
		if (*value == META_DQUOT_CHR && is_dquote(value) == true)
		{
			machine->state = EXP_DQUOTE;
			return (0);
		}
		else if (*value == META_SQUOT_CHR && is_squote(value) == true)
		{
			machine->state = EXP_SQUOTE;
			return (0);
		}
		else
			str_add_to_buff(&machine->str, *value);
	}
	else if (*value == META_VAR_CHR)
	{
		machine->state = EXP_VAR;
		return (0);
	}
	else
		str_add_to_buff(&machine->str, *value);
	(void)env_wrapper;
	return (1);
}

typedef size_t	(*t_f_exp)(char *, t_exp_sm *, t_envwrap *);

void	expansion(char **value, t_envwrap *env_wrapper)
{
	t_exp_sm	machine;
	char	*current_value;
	size_t	ret;
	static t_f_exp	f_expansion[4] = {exp_letter, exp_dquote, exp_squote, exp_var};

	init_exp_sm(&machine);
	current_value = *value;
	while (*current_value != '\0')
	{
		ret = f_expansion[machine.state](current_value, &machine, env_wrapper);
		current_value += ret;
	}
	free(*value);
	*value = str_join_to_out(machine.str.out, machine.str.buffer, machine.str.len);
}

void	handle_expansion(t_ast *node, t_envwrap *env_wrapper)
{
	size_t	i;

	if (node->flag & BIT_EXPANSION
		&& node->flag & (BIT_EXECUTABLE | BIT_ARGUMENT | BIT_FILE))
	{
		expansion(&node->value, env_wrapper);
		if (*node->value == '\0')
			node->flag |= BIT_EMPTY;
	}
	i = 0;
	while (i < node->num_children)
	{
		handle_expansion(node->children[i], env_wrapper);
		i++;
	}
}
