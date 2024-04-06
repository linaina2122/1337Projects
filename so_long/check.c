/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 05:57:26 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 19:08:36 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_long.h"

int	ft_len_check(t_my_struct *va)
{
	int	len;

	va->count = 0;
	len = ft_strlen(va->split[0]);
	while (va->count != va->height)
	{
		if (va->count == (va->height - 1))
		{
			if (ft_strlen(va->split[va->count++]) != len - 1)
				return (1);
		}
		else
		{
			if (ft_strlen(va->split[va->count++]) != len)
				return (1);
		}
	}
	return (0);
}

int	ft_check2(t_my_struct *va)
{
	if (va->countc < 1 || va->counte < 1 || va->countp != 1)
		return (1);
	return (0);
}

void	ft_error(void)
{
	write (1, "Error\n", 6);
	exit (1);
}

void	ft_exit1(void)
{
	exit (0);
}
