/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:12:21 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 19:41:24 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	my_norm(t_node *arg, char ***env)
{
	char	**join;
	t_cmd	*cmds;

	cmds = (t_cmd *)arg->content;
	if (cmds->after_expand && cmds->after_expand[0] && cmds->e_rtype == VALID)
	{
		if (ft_is_dir(cmds) == 1)
			print_dir(cmds);
		else
		{
			if (ft_strchr(cmds->after_expand[0], '/'))
				execve(check_path(cmds->after_expand), \
				cmds->after_expand, *env);
			else
			{
				join = join_path(find_path(env), cmds);
				if (ft_check_buils(cmds, env, 1) == 0)
					exit (g_exit_code);
				execve(check_path(join), cmds->after_expand, *env);
			}
			print_error_commands(cmds);
		}
	}
	exit(g_exit_code);
}

static void	fk(int *fd, t_node *arg, char ***env)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)arg->content;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	dup_pipe(arg, fd);
	redirection(cmds);
	close(fd[0]);
	my_norm(arg, env);
	exit (g_exit_code);
}

void	ft_close_leaks(int *fd, t_cmd *cmds)
{
	close(fd[0]);
	close(fd[1]);
	if (cmds->input)
		close(cmds->input->fd);
	if (cmds->output)
		close(cmds->output->fd);
}

pid_t	pipe_redirection(t_node *arg, char ***env)
{
	t_cmd	*cmds;
	pid_t	pid;
	int		save[2];
	int		fd[2];

	save[0] = dup(0);
	while (arg)
	{
		pipe(fd);
		cmds = (t_cmd *)arg->content;
		pid = fork();
		if (pid < 0)
			ft_putstr_fd("error\n", 2);
		if (pid == 0)
			fk(fd, arg, env);
		arg = arg->next;
		dup2(fd[0], 0);
		ft_close_leaks(fd, cmds);
	}
	signal(SIGINT, SIG_IGN);
	dup2(save[0], 0);
	return (pid);
}
