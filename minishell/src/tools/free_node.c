/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:02:54 by waboutzo          #+#    #+#             */
/*   Updated: 2022/11/03 03:47:17 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_double_char(char **tmp, int t)
{
	int	i;

	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	if (t == 0)
	{
		free(tmp);
	}
}

void	free_args(t_node **head)
{
	t_node	*temporary;
	t_args	*tmp;
	t_node	*s;

	temporary = *head;
	while (temporary != NULL)
	{
		tmp = (t_args *) temporary->content;
		s = temporary;
		free_double_char(tmp->after_expand, 0);
		free(tmp->value);
		free(tmp);
		temporary = temporary->next;
		free(s);
	}
}

void	free_redirc(t_node **head)
{
	t_node		*temporary;
	t_redirec	*tmp;
	t_node		*s;

	temporary = *head;
	while (temporary != NULL)
	{
		tmp = (t_redirec *)temporary->content;
		s = temporary;
		free_double_char(tmp->after_expand, 0);
		free(tmp->path);
		free(tmp->file);
		free(tmp);
		temporary = temporary->next;
		free(s);
	}
}

void	free_node(t_node **head)
{
	t_node	*temporary;
	t_cmd	*cmd;
	t_node	*s;

	temporary = *head;
	while (temporary != NULL)
	{
		cmd = (t_cmd *)temporary->content;
		s = temporary;
		free_args(&cmd->args);
		free_redirc(&cmd->redrec);
		free_double_char(cmd->after_expand, 0);
		free(cmd);
		temporary = temporary->next;
		free(s);
	}
}

void	free_var(t_env_var *var)
{
	free((var)->name);
	free(var->value);
	free(var);
}
