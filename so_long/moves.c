/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:36:20 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 20:19:24 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_long.h"

void	ft_d_move(t_my_struct *va)
{
	if (va->split[va->hp][va->wp + 1] == 'C')
		va->countc--;
	if (va->split[va->hp][va->wp + 1] == '0' ||
			va->split[va->hp][va->wp + 1] == 'C')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp][va->wp + 1] = 'P';
		va->wp++;
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
	}
	else if (va->countc == 0 && va->split[va->hp][va->wp + 1] == 'E')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp][va->wp + 1] = 'P';
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
		write(1, "WINNER ._.\n", 12);
		exit(0);
	}
}

void	ft_w_move(t_my_struct *va)
{
	if (va->split[va->hp - 1][va->wp] == 'C')
		va->countc--;
	if (va->split[va->hp - 1][va->wp] == '0' ||
			va->split[va->hp - 1][va->wp] == 'C')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp - 1][va->wp] = 'P';
		va->hp--;
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
	}
	else if (va->countc == 0 && va->split[va->hp - 1][va->wp] == 'E')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp - 1][va->wp] = 'P';
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
		write(1, "WINNER ._.\n", 12);
		exit(0);
	}
}

void	ft_a_move(t_my_struct *va)
{
	if (va->split[va->hp][va->wp - 1] == 'C')
		va->countc--;
	if (va->split[va->hp][va->wp - 1] == '0' ||
			va->split[va->hp][va->wp - 1] == 'C')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp][va->wp - 1] = 'P';
		va->wp--;
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
	}
	else if (va->countc == 0 && va->split[va->hp][va->wp - 1] == 'E')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp][va->wp - 1] = 'P';
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
		write(1, "WINNER ._.\n", 12);
		exit(0);
	}
}

void	ft_s_move(t_my_struct *va)
{
	if (va->split[va->hp + 1][va->wp] == 'C')
		va->countc--;
	if (va->split[va->hp + 1][va->wp] == '0' ||
			va->split[va->hp + 1][va->wp] == 'C')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp + 1][va->wp] = 'P';
		va->hp++;
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
	}
	else if (va->countc == 0 && va->split[va->hp + 1][va->wp] == 'E')
	{
		va->split[va->hp][va->wp] = '0';
		va->split[va->hp + 1][va->wp] = 'P';
		va->move_count++;
		ft_putnbr(va->move_count);
		ft_putchar('\n');
		write(1, "WINNER ._.\n", 12);
		exit(0);
	}
}

int	key_hook(int keycode, t_my_struct *va)
{
	mlx_clear_window(va->ptr, va->win);
	if (keycode == 2)
		ft_d_move(va);
	if (keycode == 0)
		ft_a_move(va);
	if (keycode == 13)
		ft_w_move(va);
	if (keycode == 1)
		ft_s_move(va);
	if (keycode == 53)
		ft_exit1();
	ft_draw_map(va);
	return (0);
}
