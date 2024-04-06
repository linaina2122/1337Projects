/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:03:32 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/23 03:02:05 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

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
		if (res > LLONG_MAX && sign == 1)
			return (-1);
		if (res > LLONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}
