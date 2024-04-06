/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:26:43 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/25 04:13:25 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static	int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

long	my_atoi(const char *str)
{
	int						i;
	unsigned long int		res;
	int						sign;

	i = ft_isspace(str);
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

long	check_long(const char *str)
{
	int						i;
	unsigned long int		res;
	int						sign;

	i = ft_isspace(str);
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		if ((res > LONG_MAX && sign == 1) \
		|| (res > (unsigned long)LONG_MAX + 1 && sign == -1))
			return (1);
		i++;
	}
	return (0);
}

int	one_arg(t_cmd *arg)
{
	int	count;

	count = 0;
	if (arg->after_expand[1][count] == '-' \
	|| arg->after_expand[1][count] == '+')
		count++;
	while (arg->after_expand[1][count])
	{
		if (ft_isdigit(arg->after_expand[1][count]) == 0)
			return (1);
		count++;
	}
	return (0);
}

int	more_than_arg(t_cmd *arg)
{
	if (arg->after_expand[2] != NULL)
	{
		if (one_arg(arg) == 1)
		{
			exit_errors(arg, 2);
			g_exit_code = 255;
			exit(g_exit_code);
		}
		else
		{
			exit_errors(arg, 1);
			g_exit_code = 255;
			return (1);
		}
	}
	return (0);
}
