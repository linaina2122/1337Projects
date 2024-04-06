/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:28:46 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/04 20:43:37 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_check(char x, va_list ap)
{
	int	count;

	count = 0;
	if (x == 'd' || x == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (x == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (x == 'u')
		count += ft_unputnbr(va_arg(ap, unsigned int));
	else if (x == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (x == 'x')
		count += ft_hexaconvert(va_arg(ap, unsigned int), 1);
	else if (x == 'X')
		count += ft_hexaconvert(va_arg(ap, unsigned int), 0);
	else if (x == 'p')
		count += ft_printaddress(va_arg(ap, unsigned long long));
	else if (x == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_vprintf(const char *s, va_list ap)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_check(s[i], ap);
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	ap;

	counter = 0;
	va_start (ap, str);
	counter += ft_vprintf(str, ap);
	va_end (ap);
	return (counter);
}
