/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:22:57 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/21 17:38:37 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file expansion.c
 * @brief 全ノードのトークンを走査して、適宜展開処理を行う関数 （未実装）
 */

/**
 * @brief 各トークンを展開する関数
 *
 * @param ast トークナイズで生成された抽象構文木のデータ構造の先頭ノード
 * @param env 環境変数
 *
 * @return 展開後の抽象構文木データ構造の先頭ノード
 */
t_ast	*expansion(t_ast *ast, char **env)
{
	//　未実装
}
//t_list	*expansion(t_ast *head, char **env)
//{
//	return(ast);
//}
	// メモ　展開の順序
	// ブレース展開、チルダ展開、パラメータ・ 変数・算術式展開、コマンド置換 (左から右へ)、単語分割、パス名展開
	// プロセス置換もサポートするバージョンがある。
	//
	// 1. Parameter and Variable Expansion　変数展開
	//      before:$VAR  after:variable
	//
	// 2. Brace Expansion  中括弧の展開 {}
	//      before: pre{one,two,three}post
	//      after : preonepost pretwopost prethreepost
	//
	// 3. Word_split  単語区切り
	//      変数展開の時に、デフォルト(unset IFS)なら' 'スペースで区切られる。
	//      区切り文字(IFS="s")がセットされていると、' 'スペースではなく"s"で
	//
	//      デフォルト(unset IFS)  ' 'で区切られる。
	//             VAR="sss-a   -l"
	//             bash-3.2$ VAR="sss-a   -l"
	//             bash-3.2$ ls $VAR
	//             ls: -l: No such file or directory
	//             ls: sss-a: No such file or directory
	//
	//      IFS="s"  's'で区切られる。 ' 'は単語の文字続きとして認識される。
	//             VAR="sss-a   -l"  IFS="s"
	//             bash-3.2$ ls $VAR
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: -a   -l: No such file or directory
	// 4. 
	//
	//       memo
	//             bash-3.2$ VAR="sss-asss-l"
	//             bash-3.2$ $VAR
	//             bash: sss-asss-l: command not found
	//             bash-3.2$ ls $VAR
	//             ls: sss-asss-l: No such file or directory
	//             bash-3.2$ IFS="s"
	//             bash-3.2$ $VAR
	//             bash: : command not found
	//             bash-3.2$ echo $VAR
	//                -a   -l
	//
	//             bash-3.2$ ls $VAR
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: -a: No such file or directory
	//             ls: -l: No such file or directory
	//             bash-3.2$ unset IFS
	//             bash-3.2$ echo $VAR
	//             sss-asss-l
	//             bash-3.2$ ls $VAR
	//             ls: sss-asss-l: No such file or directory
	//
	//             bash-3.2$ VAR="sss-a   -lss"
	//             bash-3.2$ ls $VAR
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: : No such file or directory
	//             ls: -a   -l: No such file or directory
	//
	//             bash-3.2$ ls " " " " " " "-a" " " " " " " "-l"
	//             ls:  : No such file or directory
	//             ls:  : No such file or directory
	//             ls:  : No such file or directory
	//             ls:  : No such file or directory
	//             ls:  : No such file or directory
	//             ls:  : No such file or directory
	//             ls: -a: No such file or directory
	//             ls: -l: No such file or directory
	//
