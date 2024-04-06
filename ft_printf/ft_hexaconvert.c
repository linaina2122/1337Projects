/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconvert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 07:42:16 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/04 16:37:35 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_hexaconvert(unsigned long long n, int c)
{
	int	hex;
	int	count;

	count = 0;
	hex = n % 16;
	n = n / 16;
	if (n != 0)
		count += ft_hexaconvert(n, c);
	if (hex < 10)
			count += ft_putchar(hex + 48);
	else
		if (c == 1)
			count += ft_putchar(ft_tolower(hex + 55));
	else
		count += ft_putchar(hex + 55);
	return (count);
}
