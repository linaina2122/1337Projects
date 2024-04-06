/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:56:52 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/21 03:11:43 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_var(char *str)
{
	int	count;
	int	count2;

	count = 1;
	count2 = 0;
	count2 = 1;
	if (((str[0] < 'a' || str[0] > 'z') \
	&& (str[0] < 'A' || str[0] > 'Z')) \
	&& str[0] != '_')
		return (1);
	while (str[count2])
	{
		if (str[count2] == '_')
			count2++;
		else if ((str[count2] < '0' || str[count2] > '9') \
		&& (str[count2] < 'A' || str[count2] > 'Z') \
		&& (str[count2] < 'a' || str[count2] > 'z'))
			return (1);
		count2++;
	}
	return (0);
}

char	*find_env_var(char *env)
{
	int		index;
	int		count2;
	char	*str;

	index = 0;
	count2 = 0;
	while (env[index] && env[index] != '=')
		index++;
	str = malloc(sizeof(char *) * index + 1);
	while (count2 < index)
	{
		str[count2] = env[count2];
		count2++;
	}
	str[count2] = '\0';
	return (str);
}

int	my_func(t_cmd *arg, int index)
{
	int	count;

	count = index - 1;
	while (count > 0)
	{
		if (ft_strcmp(arg->after_expand[count], \
		arg->after_expand[index]) == 0)
			return (1);
		count--;
	}
	return (0);
}

t_indices	ft_try(t_cmd *arg, char **env, t_indices ind)
{
	ind.count1 = -1;
	while (env[++ind.count1])
	{
		ind.count = 0;
		while (env[ind.count1][ind.count] && \
		env[ind.count1][ind.count] != '=')
			ind.count++;
		ind.str = ft_substr(env[ind.count1], 0, ind.count);
		if (ft_strcmp(ind.str, arg->after_expand[ind.index]) == 0)
			ind.index2++;
		free(ind.str);
	}
	return (ind);
}

int	ft_counterr(t_cmd *arg, char **env)
{
	t_indices	ind;

	ind.index2 = 0;
	ind.index = 1;
	while (arg->after_expand && arg->after_expand[ind.index])
	{
		if (my_func(arg, ind.index) == 1)
		{
			ind.index++;
			continue ;
		}
		if (check_var(arg->after_expand[ind.index]) == 1)
			print_error_unset(arg);
		ind = ft_try(arg, env, ind);
		ind.index++;
	}
	return (ind.index2);
}
