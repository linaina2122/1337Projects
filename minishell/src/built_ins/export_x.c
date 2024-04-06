/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:06:07 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/20 19:06:10 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_var_validition(char *s)
{
	int	index;

	if (!ft_isalpha(s[0]) && s[0] != '_')
		return (0);
	index = 1;
	while (s[index])
	{
		if (!ft_isalnum(s[index]) && s[index] != '_')
			return (0);
		index++;
	}
	return (1);
}

char	**sorted_env(char **env)
{
	int		i[2];
	char	*temp;

	i[0] = 0;
	i[1] = 0;
	while (env[i[0]])
	{
		i[1] = 0;
		while (env[i[1] + i[0]])
		{
			if (ft_strcmp(env[i[0]], env[i[1] + i[0]]) > 0)
			{
				temp = env[i[0]];
				env[i[0]] = env[i[1] + i[0]];
				env[i[1] + i[0]] = temp;
			}
			i[1]++;
		}
		i[0]++;
	}
	env[i[0]] = NULL;
	return (env);
}
