/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:58:01 by hcharef           #+#    #+#             */
/*   Updated: 2022/11/21 22:36:09 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static	int	ft_checkk(t_cmd *arg, int count)
{
	int	count2;

	while (arg->after_expand[count])
	{
		count2 = 0;
		if ((arg->after_expand[count][count2] != '-' \
		&& arg->after_expand[count][count2 + 1] != 'n')
		|| (arg->after_expand[count][count2] == '-' && \
		(arg->after_expand[count][count2 + 1] != 'n')))
			return (count);
		else if (arg->after_expand[count][count2] == '-' \
		&& arg->after_expand[count][count2 + 1] == 'n')
		{
			count2 += 1;
			while (arg->after_expand[count][count2])
			{
				if (arg->after_expand[count][count2] != 'n')
					return (count);
				count2++;
			}
		}
		count++;
	}
	return (count);
}

static	int	check(t_cmd *arg)
{
	int	count;

	count = 0;
	if (ft_strcmp(arg->after_expand[1], "-") == 0 \
	|| arg->after_expand[1][count] != '-')
		return (1);
	if (arg->after_expand[1][count] == '-')
	{
		count++;
		while (arg->after_expand[1][count])
		{
			if (arg->after_expand[1][count] != 'n')
				return (1);
			count++;
		}
	}
	return (0);
}

static	void	f_print(t_cmd *arg, int index)
{
	while (arg->after_expand[index] != NULL)
	{
		printf("%s", arg->after_expand[index]);
		if (arg->after_expand[index + 1] == NULL)
			break ;
		else
			printf(" ");
		index++;
	}
}

static	int	f_norm(t_cmd *arg)
{
	if (arg->after_expand && !arg->after_expand[1])
	{
		printf("\n");
		return (1);
	}
	return (0);
}

void	echo_imp(t_cmd *arg)
{
	int	count;
	int	index;

	count = 1;
	if (f_norm(arg))
		return ;
	if (ft_strcmp(arg->after_expand[0], "echo") == 0)
	{
		if (check(arg) == 0)
		{
			if (!arg->after_expand[count + 1])
				return ;
			index = ft_checkk(arg, count);
			f_print(arg, index);
		}
		else if (check(arg))
		{
			index = ft_checkk(arg, count);
			f_print(arg, count);
			printf("\n");
		}
	}
}
