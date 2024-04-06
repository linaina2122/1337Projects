/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:58:49 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 20:30:19 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_dim(t_my_struct *va, char **argv)
{
	char	*str;

	va->height = 0;
	va->fd = open(argv[1], O_RDONLY);
	if (va->fd < 0)
		ft_error();
	str = get_next_line(va->fd);
	va->width = ft_strlen(str) - 1;
	while (str != NULL)
	{
		va->height++;
		free(str);
		str = get_next_line(va->fd);
	}
	free (str);
}

void	ft_file_check(t_my_struct *va, char **argv)
{
	int	i;

	i = 0;
	va->fd1 = open(argv[1], O_RDONLY);
	if (va->fd1 < 0 || va->height <= 1)
		ft_error();
	va->split = malloc(sizeof(char *) * va->height);
	while (i < va->height)
	{
		va->split[i] = get_next_line(va->fd1);
		i++;
	}
}

int	ft_wall_check(t_my_struct *va)
{
	int	count;

	count = 0;
	while (va->split[0][count] && va->split[0][count] != '\n')
	{
		if (va->split[0][count] != '1')
			return (1);
		count++;
	}
	count = 0;
	while (va->split[va->height - 1][count])
	{
		if (va->split[va->height - 1][count] != '1')
			return (1);
		count++;
	}
	count = 1;
	while (count < va->height - 1)
	{
		if (va->split[count][0] != '1' ||
				va->split[count][va->width - 1] != '1')
			return (1);
		count++;
	}
	return (0);
}

int	ft_check(t_my_struct *va)
{
	int	i;
	int	j;

	i = 1;
	while (i < va->height - 1)
	{
		j = 1;
		while (j < va->width - 1)
		{
			if (va->split[i][j] != '0' && va->split[i][j] != 'E'
					&& va->split[i][j] != 'P' && va->split[i][j] != 'C'
					&& va->split[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_find(t_my_struct *va)
{
	int	i;
	int	j;

	va->countc = 0;
	va->counte = 0;
	va->countp = 0;
	i = 0;
	while (++i <= va->height - 2)
	{
		j = 0;
		while (++j < va->width - 1)
		{
			if (va->split[i][j] == 'E')
				va->counte++;
			if (va->split[i][j] == 'P')
			{
				va->wp = j;
				va->hp = i;
				va->countp++;
			}
			if (va->split[i][j] == 'C')
				va->countc++;
		}
	}
}
