/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:21:44 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/19 02:14:47 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	int	ft_count(long int n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		j++;
		n *= -1;
	}
	if (n == 0)
		j++;
	while (n > 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	long int	number;
	int			len;
	char		*p;
	int			i;

	i = 0;
	number = n;
	len = ft_count(number);
	p = malloc(((len + 1) * sizeof(char)));
	if (!p)
		return (NULL);
	p[len--] = '\0';
	if ((long int)(n) < 0)
	{
		p[i++] = '-';
		number = number * (-1);
	}
	while (len >= i)
	{
		p[len--] = number % 10 + '0';
		number /= 10;
	}
	return (p);
}
