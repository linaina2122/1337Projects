/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:31:00 by hcharef           #+#    #+#             */
/*   Updated: 2021/11/19 02:55:22 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd (nb / 10, fd);
	}
	ft_putchar_fd (nb % 10 + 48, fd);
}
