/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:08:41 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/04 23:00:27 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_unputnbr(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
		n = (- (long) n);
	count += ft_count(n);
	if (n > 9)
		ft_unputnbr (n / 10);
	write (1, &"0123456789"[n % 10], 1);
	return (count);
}
