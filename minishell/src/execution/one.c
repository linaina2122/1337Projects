/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:23:06 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 03:56:29 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	my_fun(t_cmd *cmds, char ***env)
{
	char	**str;
	char	**join;
	char	*path;

	if (cmds->after_expand && cmds->after_expand[0])
	{
		if (ft_strchr(cmds->after_expand[0], '/'))
		{
			path = check_path(cmds->after_expand);
			execve(path, cmds->after_expand, *env);
		}
		else
		{
			str = find_path(env);
			join = join_path(str, cmds);
			path = check_path(join);
			execve(path, cmds->after_expand, *env);
		}
		print_error_commands(cmds);
	}
}

pid_t	first_handling(char ***env, t_node *node)
{
	pid_t	pid;
	t_cmd	*cmds;

	cmds = (t_cmd *)node->content;
	pid = fork();
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		my_fun(cmds, env);
		exit(g_exit_code);
	}
	signal(SIGINT, SIG_IGN);
	return (pid);
}
