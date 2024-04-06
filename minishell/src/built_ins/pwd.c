/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 06:54:54 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/18 14:56:58 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static	void	pwd_x(char **env)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	while (env[count] != NULL)
	{
		if (ft_strncmp(env[count], "PWD=", 4) == 0)
		{
			str = ft_substr(env[count], 5, ft_strlen(env[count]));
			break ;
		}
		count++;
	}
	printf("%s\n", str);
	free(str);
}

void	pwd_imp(char ***env)
{
	char	*buffer;
	char	**my_env;

	my_env = env[0];
	buffer = getcwd(NULL, 0);
	if (buffer)
	{
		printf("%s\n", buffer);
		free(buffer);
		return ;
	}
	else if (buffer == NULL)
		pwd_x(my_env);
}

void	env_imp(char ***env)
{
	int		count;
	char	*str;
	char	**my_env;

	my_env = env[0];
	count = 0;
	if (!my_env[count])
		return ;
	while (my_env[count])
	{
		str = ft_strchr(my_env[count], '=');
		if (str)
			printf("%s\n", my_env[count]);
		count++;
	}
}
