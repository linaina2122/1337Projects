/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 23:51:54 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 19:20:11 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_long.h"

void	ft_background(t_my_struct *va)
{
	va->ht = -1;
	va->hcount = 0;
	while (++(va->ht) <= va->height - 1)
	{
		va->wt = -1;
		va->wcount = 0;
		while (++(va->wt) < va->width)
		{
			if (va->split[va->ht][va->wt] == '0')
			{
				mlx_put_image_to_window(va->ptr, va->win, va->img_back,
					va->wcount, va->hcount);
			}
			va->wcount += 50;
		}
		va->hcount += 50;
	}
}

void	ft_wall(t_my_struct *va)
{
	va->ht = -1;
	va->hcount = 0;
	while (++(va->ht) <= va->height - 1)
	{
		va->wt = -1;
		va->wcount = 0;
		while (++(va->wt) < va->width)
		{
			if (va->split[va->ht][va->wt] == '1')
			{
				mlx_put_image_to_window(va->ptr, va->win, va->img_wall,
					va->wcount, va->hcount);
			}
			va->wcount += 50;
		}
		va->hcount += 50;
	}
}

void	ft_collectible(t_my_struct *va)
{
	va->ht = -1;
	va->hcount = 0;
	while (++(va->ht) <= va->height - 1)
	{
		va->wt = -1;
		va->wcount = 0;
		while (++(va->wt) < va->width)
		{
			if (va->split[va->ht][va->wt] == 'C')
			{
				mlx_put_image_to_window(va->ptr, va->win, va->col_img,
					va->wcount, va->hcount);
			}
			va->wcount += 50;
		}
		va->hcount += 50;
	}
}

void	ft_exit(t_my_struct *va)
{
	va->ht = -1;
	va->hcount = 0;
	while (++(va->ht) <= va->height - 1)
	{
		va->wt = -1;
		va->wcount = 0;
		while (++(va->wt) < va->width)
		{
			if (va->split[va->ht][va->wt] == 'E')
			{
				mlx_put_image_to_window(va->ptr, va->win, va->exit_img,
					va->wcount, va->hcount);
			}
			va->wcount += 50;
		}
		va->hcount += 50;
	}
}

void	ft_player(t_my_struct *va)
{
	va->ht = -1;
	va->hcount = 0;
	while (++(va->ht) <= va->height - 1)
	{
		va->wt = -1;
		va->wcount = 0;
		while (++(va->wt) < va->width)
		{
			if (va->split[va->ht][va->wt] == 'P')
			{
				mlx_put_image_to_window(va->ptr, va->win,
					va->player_img, va->wcount, va->hcount);
			}
			va->wcount += 50;
		}
		va->hcount += 50;
	}
}
