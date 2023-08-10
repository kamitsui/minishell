/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:23:56 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/10 13:26:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 抽象構文木のすべてのノードを探して、＄変数のトークンを展開する。環境変数を用いる。
 *
 * @param t_ast
 * @param data
 *
 * @return 
 */
int	execute(t_list *list, t_data *data)
{
	// int	result;
	//
	// typeのフラグを見て、処理内容を分ける。
	// while(tokens[i].var != NULL)
	// {
	//		if (tokens[i]->type == TOK_CON_AND)
	//		{
	//			result = exec_connect(tokens[i], data);
	//			//１つ前のプロセス（コマンド）のexit statusを見て、
	//			//0なら実行　1ならexit(result);
	//		}
	//		else if (tokens[i]. == TOK_PIPE_COM)
	//		{
	//			result = exec_pipe(tokens[i], data);
	//		}
	//		else if ...
	//		else ...
	//		i++;
	// }
	// return(result);
}

int	main(void)
{
	t_list	list;
	list.contents = tokens;
	// list 1
	// tokens[0].var = {"ls", "-a", "|", "grep", "42", NULL};
	// tokens[0].type = TOK_PIPE_COM;
	// tokens[1].var = {">", "file", NULL};
	// tokens[1].type = TOK_OUT_REDIR;
	// tokens[2].var = {"&&", NULL};
	// tokens[2].type = TOK_CON_AND;
	// tokens[3].var = NULL;
	// tokens[3].type = 0;
	// list 2
	// tokens[0].var = {"cat", "-e", NULL};
	// tokens[0].type = TOK_SIMPLE_COM;
	// tokens[1].var = NULL;
	// tokens[1].type = 0;
	int status = execute(list, data);
	return (status);
}
