/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:27:32 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/19 15:30:57 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ftry(t_cmd *arg, char **env, int count)
{
	int		no;
	int		count2;
	char	*holder;

	count2 = 1;
	no = 0;
	while (arg->after_expand[count2] != NULL)
	{
		holder = find_env_var(env[count]);
		if (!ft_strcmp(holder, arg->after_expand[count2]))
		{
			free(holder);
			free(env[count]);
			no = 1;
			break ;
		}
		free(holder);
		count2++;
	}
	if (no == 0)
		return (1);
	return (0);
}

void	ft_check(t_cmd *arg, char **env, char **str)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (env[count])
	{
		if (ftry(arg, env, count))
		{
			str[index] = env[count];
			index++;
		}
		count++;
	}
	str[index] = NULL;
}

char	**allocate_env(char **env, t_cmd *arg, int size)
{
	char	**my_new_env;

	my_new_env = malloc(sizeof(char *) * \
	(size - ft_counterr(arg, env) + 1));
	if (!my_new_env)
		return (NULL);
	ft_check(arg, env, my_new_env);
	free(env);
	return (my_new_env);
}

char	**unset_imp(t_cmd *arg, char ***env)
{
	int	count;

	count = 0;
	while ((*env)[count])
		count++;
	if (arg->after_expand && arg->after_expand[1] == NULL)
		return (NULL);
	*env = allocate_env(*env, arg, count);
	return (*env);
}
