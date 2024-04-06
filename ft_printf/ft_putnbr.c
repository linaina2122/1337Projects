/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 06:38:28 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/03 05:54:42 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		count;

	count = 0;
	n = (long) nb;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * (-1);
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}
