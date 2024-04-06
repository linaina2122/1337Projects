/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:13 by waboutzo          #+#    #+#             */
/*   Updated: 2022/11/20 02:31:20 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	child_herdoc(t_node **head, char **envp)
{
	t_node	*temporary;
	t_cmd	*cmd;

	temporary = *head;
	while (temporary != NULL)
	{
		cmd = (t_cmd *)temporary->content;
		open_heredoc_in_signle_cmd(&cmd->redrec, envp);
		temporary = temporary->next;
	}
	exit(0);
}

int	parent(pid_t id)
{
	int		status;

	signal(SIGINT, SIG_IGN);
	waitpid(id, &status, 0);
	signal(SIGINT, sig_handler);
	if (WIFSIGNALED(status))
	{
		g_exit_code = 1;
		return (1);
	}
	return (0);
}

void	*open_heredoc_in_all_pipe_lines(t_node **head, char **envp)
{
	pid_t	id;

	if (here_doc_counter(*head) >= 17)
	{
		printf_error("minishell: maximum ",
			"here-document ", "count exceeded\n");
		exit(258);
	}
	id = fork();
	if (id == -1)
	{
		perror("minishell: fork");
		g_exit_code = 1;
	}
	else if (!id)
		child_herdoc(head, envp);
	if (parent(id))
		return (NULL);
	return ((void *)1);
}

void	*open_file_descriptor(t_node **head)
{
	t_node		*temporary;
	t_redirec	*redrec;

	temporary = *head;
	while (temporary != NULL)
	{
		redrec = (t_redirec *) temporary->content;
		if (redrec->e_rtype == INPUT)
			redrec->fd = open(redrec->after_expand[0], O_RDONLY, 0666);
		else if (redrec->e_rtype == OUTPUT)
			redrec->fd = open(redrec->after_expand[0],
					O_WRONLY | O_TRUNC | O_CREAT, 0666);
		else if (redrec->e_rtype == APPEND)
			redrec->fd = open(redrec->after_expand[0],
					O_WRONLY | O_APPEND | O_CREAT, 0666);
		else if (redrec->e_rtype == HERE_DOC)
			redrec->fd = open(redrec->path, O_RDONLY, 0666);
		if (ft_check_ambiguous(redrec))
			return (NULL);
		temporary = temporary->next;
	}
	return ((void *)1);
}

void	*parsing(t_node **command, char **envp, int *index)
{
	t_node	*temporary;
	t_cmd	*cmd;

	temporary = *command;
	while (temporary != NULL)
	{
		cmd = (t_cmd *)temporary->content;
		if (temporary != *command)
			g_exit_code = 0;
		parsing_args(&(cmd)->args, envp);
		parsing_redrection(&(cmd)->redrec, envp, index);
		cmd->after_expand = join_args(cmd->args);
		(*index)++;
		cmd->e_rtype = VALID;
		temporary = temporary->next;
	}
	if (!open_heredoc_in_all_pipe_lines(command, envp))
		return (NULL);
	open_all_redrec(command);
	return ((void *)1);
}
