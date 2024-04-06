/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:01:49 by marvin            #+#    #+#             */
/*   Updated: 2022/07/31 14:01:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philosopher.h"

static	int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	res;
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
		if (res > INT_MAX && sign == 1)
			return (-1);
		if (res > INT_MAX && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}

void	check_flags(t_all	*all, int flag)
{
	pthread_mutex_lock(&all->try);
	if (flag == 0)
		return ;
	pthread_mutex_unlock(&all->try);
}

void	fnorm(t_all *all)
{
	pthread_mutex_lock(&all->pflag);
	check_flags(all, all->flag);
	pthread_mutex_unlock(&all->pflag);
}
