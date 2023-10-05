/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:28:22 by mogawa            #+#    #+#             */
/*   Updated: 2023/10/04 14:29:57 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "ft_cd.h"

t_envwrap	*create_env_list(char **environ)
{
	t_list		*env_head;
	t_envwrap	*env_wrapper;
	t_env		*env_node;
	// char		**one_env_line;
	size_t		i;

	env_head = ft_lstnew(NULL);
	env_wrapper = ft_calloc(1, sizeof(t_envwrap));//todo to be curved out
	if (!env_head || !env_wrapper)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		env_node = env_create_node_from_char(environ[i], NULL);
		if (env_node == NULL)
			return (NULL);
		ft_lstadd_back(&env_head, ft_lstnew(env_node));
		i++;
	}
	//todo below env_wrapper creat to be curved out.
	env_wrapper->env = env_head;
	env_wrapper->exit_code = EXIT_SUCCESS;
	env_wrapper->cwd = ft_getcwd(env_wrapper);
	return (env_wrapper);
}



//! *env_headはdummy node
int	env_cd_checker(void)
{
	extern char	**environ;
	t_list		*env_head;
	t_envwrap	*env_wrapper;

	env_wrapper = create_env_list(environ);
	if (env_wrapper == NULL)
		return (EXIT_FAILURE);
	printf("***cwd***\n");//!
	ft_pwd(env_wrapper);
	printf(">> mkdir sample_dir\n");
	system("mkdir sample_dir");
	system("ls");
	printf(">> cd  sample_dir\n");
	ft_cd("sample_dir", env_wrapper);
	ft_pwd(env_wrapper);
	printf(">> rm  -rf ../sample_dir\n");
	system("rm -rf ../sample_dir");
	ft_pwd(env_wrapper);
	ft_cd("..", env_wrapper);// abort here !!
	ft_pwd(env_wrapper);
	ft_cd("-", env_wrapper);// ?? Not required
	ft_pwd(env_wrapper);
	exit(0);
}

int	env_controller(void)
{
	extern char	**environ;
	// t_list		*env_head;
	t_envwrap	*env_wrapper;

	env_wrapper = create_env_list(environ);
	if (env_wrapper == NULL)
		return (EXIT_FAILURE);
	ft_env(env_wrapper);
	printf("\n***initial env lst***\n");
	// ft_unset(env_wrapper, "LANG");
	// ft_export(env_wrapper, "SHELL=TAKOHACHIRO", NULL);
	// ft_export(env_wrapper, "PWD=42tokyo", NULL);
	// ft_export(env_wrapper, "NOTHING", "hogehoge");
	// printf("\n***after exports ****\n");
	// ft_env(env_wrapper);
	// printf("\n***export with no arg ****\n");
	// ft_export(env_wrapper, NULL, NULL);
	// printf("\n***after export with no arg ****\n");
	// ft_env(env_wrapper);
	printf("***cwd***\n");//!
	ft_pwd(env_wrapper);
	// ft_cd("/Users/masaru/42", env_wrapper);
	ft_cd(NULL, env_wrapper);
	printf("***cwd***\n");//!
	ft_pwd(env_wrapper);
	ft_env(env_wrapper);
	ft_lstclear(&env_wrapper->env, _env_del_content);
	free(env_wrapper->cwd);
	free(env_wrapper);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	// env_controller();
	env_cd_checker();
	system("leaks -q env");
}
