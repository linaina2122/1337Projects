/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 05:36:29 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/15 09:14:47 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	int				sign;

	i = ft_isspace(str);
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	if (str[i] < '0' && str[i] > '9')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		if (res > INT_MAX && sign == 1)
			ft_error();
		if (res > 2147483648 && sign == -1)
			ft_error();
		i++;
	}
	return (res * sign);
}
