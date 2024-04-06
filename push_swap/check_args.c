/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:47:10 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/19 11:57:02 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char **num)
{
	int	i;
	int	j;

	i = 0;
	while (num[++i])
	{
		j = -1;
		if (ft_strcmp(num[i], "\0") == 0)
			ft_error();
		while (num[i][++j])
		{
			if (!(num[i][j] == '+' || num[i][j] == '-' ||
			(num[i][j] >= '0' && num[i][j] <= '9')))
				ft_error();
			if (num[i][j + 1] == '+' || num[i][j + 1] == '-')
				ft_error();
			if (ft_strcmp(num[i], "+") == 0 || ft_strcmp(num[i], "-") == 0)
				ft_error();
		}
	}
}

void	check_dup(int argc, char **argv)
{
	int		i;
	int		count;
	char	*tmp;

	count = 1;
	while (count < argc)
	{
		tmp = argv[count];
		i = count + 1;
		while (i < argc)
		{
			if (ft_strcmp(tmp, argv[i]) == 0)
				ft_error();
			i++;
		}
		count++;
	}
}

int	check_sort(int argc, char **argv)
{
	int	count1;

	count1 = 0;
	while (++count1 < argc - 1)
	{
		if (ft_atoi(argv[count1]) < ft_atoi(argv[count1 + 1]))
		{
			continue ;
			count1++;
		}
		else
			return (0);
	}
	return (1);
}

void	test(char **argv)
{
	int	i;

	i = 1;
	if (ft_atoi(argv[i]) == 0 && ft_atoi(argv[i + 1]) == -0)
		ft_error();
}
