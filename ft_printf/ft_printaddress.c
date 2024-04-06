/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 06:11:56 by hcharef           #+#    #+#             */
/*   Updated: 2021/12/04 16:21:17 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(unsigned long long n)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_hexaconvert(n, 1);
	return (count);
}
