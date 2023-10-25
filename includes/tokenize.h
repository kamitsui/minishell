/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:25 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/25 14:18:12 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

// # include <readline/history.h>
// # include <readline/readline.h>
// # include <stdbool.h>
// # include <stdlib.h>
# include "libft.h"
# include "environ.h"
# include <sys/wait.h>//? in this h file?
# include <fcntl.h>//? in this h file? for func open

# define READ_END 0
# define WRITE_END 1

typedef enum e_flg
{
	unclassified,//0
	doube_quote,
	single_quote,
	parenthesis_open,
	parenthesis_close,
	space,//5
	newline,
	ampersand,
	double_ampersand,
	single_pipe,
	double_pipe,//10
	allow_read,//<11
	allow_write,//>12 todo name changes to allow_write_to
	allow_heredoc,//13<<
	allow_append,//14>>
	astarisk,//15
	end, 
}	t_flg;

typedef struct s_token
{
	char	*word;
	t_flg	flg;
	size_t	concat_idx;
}	t_token;

typedef struct s_cmd
{
	t_list		*cmdline;
	t_list		*input;
	t_list		*output;
	t_flg		flg;
	char		**cmddpter;
	char		*cmdname;
	// t_envwrap	*envs;
}	t_cmd;

//* lstiter関数の関数ポインタ引数として渡される関数類
void	_tkn_print_list(void *content);//! debug purpose so to be deleted
void	_tkn_delete_list(void *content);
void	_tkn_assign_flg_to_char(void *content);
void	_tkn_reassign_flg_to_operator(void *content);
void	_tkn_assign_flg_to_str(void *content);
void	*_tkn_dup_content(void *content);
bool	flg_is_operator(t_flg flg);

//* tokenizeユーティリティ関数類
// bool	flg_is_metachar(t_flg div);
// bool	flg_is_control(t_flg div);
bool	flg_is_redirect(t_flg div);
bool	flg_is_join_operator(t_flg flg);
bool	flg_is_cmd_divider(t_flg flg);
bool	flg_is_quote(t_flg div);
t_flg	tkn_assign_flg_to_c(char c);
t_flg	tkn_assign_flg_to_word(char *s);
t_flg	tkn_get_closing_flg(t_flg opening_flg);
char	**tkn_create_dptrchar_from_list(t_list *cmdlst);
void   tkn_del_one_by_flg(t_list **cmdlst, t_flg del_flg);
t_token	*tkn_create_new_token_by_copy_old(t_token *old);

//* tokenizeマーカー
void	tkn_mark_quote_to_concatinate(t_list *cmdlst);
void	tkn_mark_operators_to_concatinate(t_list *dummyhead);
void	tkn_mark_to_concat_on_flg(t_list *cmdlst, t_flg const to_concat[]);

//* parse.c
// t_cmd	*create_redirect_list(t_list **crnt);
char	**token_controller(char *cmdline);
t_list	*create_cmdslst_from_tknlst(t_list *tknlst);

//* execution.c
void	ft_exec(t_list *cmdslst, t_envwrap *env_wrapper);

//* expansion.c
int	expand_dollar_sign_on_char(char **cmdline, t_envwrap *env_wrap);

#endif