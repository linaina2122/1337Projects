/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 06:54:54 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/18 14:57:35 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static	int	my_func(t_cmd *arg)
{
	struct stat	buf;

	stat(arg->after_expand[1], &buf);
	return (S_ISREG(buf.st_mode));
}

void	cd_x(char **env, char *buffer)
{
	int	count;

	count = 0;
	while (env[count])
	{
		if (ft_strncmp(env[count], "OLDPWD=", 7) == 0)
		{
			free(env[count]);
			env[count] = ft_strjoin("OLDPWD=", buffer);
			break ;
		}
		count++;
	}
	free(buffer);
}

void	chdir_n(t_cmd *arg)
{
	if (chdir(arg->after_expand[1]) == -1)
	{
		if (my_func(arg) == 1)
			print_error_cd(arg, 1);
		else
			print_error_cd(arg, 2);
	}
}

void	cd_imp(t_cmd *arg, char ***env)
{
	int		count;
	char	*buffer;

	buffer = getcwd(NULL, 0);
	count = 0;
	if (arg->after_expand[1] == NULL)
	{
		ft_putstr_fd("you should insert a path\n", 2);
		free(buffer);
		return ;
	}
	cd_x(env[0], buffer);
	chdir_n(arg);
	buffer = getcwd(NULL, 0);
	while (env[0][count])
	{
		if (ft_strncmp(env[0][count], "PWD=", 4) == 0)
		{
			free(env[0][count]);
			env[0][count] = ft_strjoin("PWD=", buffer);
			break ;
		}
		count++;
	}
	free(buffer);
}
