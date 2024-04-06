/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:38:24 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/21 21:48:22 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**find_path(char ***env)
{
	char	*ev;
	char	**path;
	int		j;

	path = NULL;
	j = 0;
	while (env[0][j])
	{
		if (ft_strncmp(env[0][j], "PATH=", 5) == 0)
		{
			ev = ft_strdup(env[0][j]);
			ev = ft_substr(ev, 5, ft_strlen(ev));
			path = ft_split(ev, ':');
			free(ev);
			return (path);
		}
		j++;
	}
	return (path);
}

char	**join_path(char **str, t_cmd *arg)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str && str[i])
	{
		tmp = str[i];
		tmp = ft_strjoin(str[i], "/");
		str[i] = ft_strjoin(tmp, arg->after_expand[0]);
		i++;
	}
	return (str);
}

char	*check_path(char **path)
{
	int	i;

	i = 0;
	if (path == NULL)
		return (NULL);
	while (path[i])
	{
		if (access(path[i], X_OK) == 0)
			break ;
		i++;
	}
	return (path[i]);
}

void	redirection(t_cmd *arg)
{
	if (arg->input)
	{
		dup2(arg->input->fd, 0);
		close(arg->input->fd);
	}
	if (arg->output)
	{
		dup2(arg->output->fd, 1);
		close(arg->output->fd);
	}
}

void	dup_pipe(t_node *arg, int *fd)
{
	if (arg->next)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
}
