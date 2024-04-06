/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 04:05:08 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 04:05:08 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_dir(t_cmd *arg)
{
	struct stat	path_stat;

	stat(arg->after_expand[0], &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

int	check_no_cmds(t_cmd	*cmd)
{
	if (cmd->after_expand == NULL || cmd->after_expand[0] == NULL)
	{
		if (cmd->input)
			close(cmd->input->fd);
		if (cmd->output)
			close(cmd->output->fd);
		g_exit_code = 0;
		return (0);
	}
	return (1);
}

int	one_cmd(t_node *node, char ***env)
{
	pid_t	pid;
	int		save[2];
	t_cmd	*cmd;

	pid = 0;
	cmd = (t_cmd *)node->content;
	save[0] = dup(0);
	save[1] = dup(1);
	if (!check_no_cmds(cmd))
		return (0);
	if (ft_is_dir(cmd) == 1)
		return (print_dir(cmd));
	redirection(cmd);
	if (cmd->e_rtype == VALID && ft_check_buils(cmd, env, 0))
		pid = first_handling(env, node);
	dup2(save[0], 0);
	close(save[0]);
	dup2(save[1], 1);
	close(save[1]);
	return (pid);
}

static	void	signals(int status)
{
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit_code = WTERMSIG(status) + 128;
}

void	execution(char ***env, t_node *node)
{
	pid_t	res;
	int		status;
	t_cmd	*cmd;
	pid_t	pid;

	pid = 0;
	if (node == NULL)
		return ;
	cmd = (t_cmd *)node->content;
	if (node->next == NULL)
		pid = one_cmd(node, env);
	else if (node->next)
		pid = pipe_redirection(node, env);
	while (1)
	{
		res = waitpid(-1, &status, 0);
		if (res == -1)
			break ;
		else if (res == pid)
			signals (status);
	}
	signal(SIGINT, sig_handler);
}
