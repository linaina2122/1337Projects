/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:59:42 by hcharef           #+#    #+#             */
/*   Updated: 2022/10/09 05:59:42 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static	int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	check_digit(int argc, char **argv)
{
	int	count1;
	int	count2;

	count1 = 1;
	while (count1 < argc)
	{
		if (ft_strlen (argv[count1]) == 0)
			return (1);
		count2 = 0;
		while (argv[count1][count2])
		{
			if (argv[count1][0] == '+')
				count2++;
			if (argv[count1][count2] < '0' || argv[count1][count2] > '9')
				return (1);
			count2++;
		}
		count1++;
	}
	return (0);
}
