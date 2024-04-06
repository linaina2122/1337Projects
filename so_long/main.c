/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:24:59 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 20:39:59 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_long.h"

void	ft_draw_map(t_my_struct *va)
{
	ft_background(va);
	ft_wall(va);
	ft_collectible(va);
	ft_exit(va);
	ft_player(va);
}

void	ft_link_image(t_my_struct *va)
{
	int	i;
	int	j;

	va->path_back = "xpms/back.xpm";
	va->path_wall = "xpms/wall.xpm";
	va->col_path = "xpms/star.xpm";
	va->exit_path = "xpms/exit.xpm";
	va->player_path = "xpms/player.xpm";
	va->img_wall = mlx_xpm_file_to_image(va->ptr, va->path_wall, &i, &j);
	va->img_back = mlx_xpm_file_to_image(va->ptr, va->path_back, &i, &j);
	va->col_img = mlx_xpm_file_to_image(va->ptr, va->col_path, &i, &j);
	va->exit_img = mlx_xpm_file_to_image(va->ptr, va->exit_path, &i, &j);
	va->player_img = mlx_xpm_file_to_image(va->ptr, va->player_path, &i, &j);
}

int	main(int argc, char **argv)
{
	t_my_struct	va;

	if (argc != 2)
		ft_error ();
	ft_map_dim (&va, argv);
	va.move_count = 0;
	ft_file_check(&va, argv);
	ft_find (&va);
	if (ft_wall_check(&va) == 1)
		return (write (1, "ERROR MAP\n", 10));
	if (ft_len_check(&va) == 1)
		return (write (1, "ERROR LEN\n", 10));
	if (ft_check(&va) == 1)
		return (write (1, "Error\n", 6));
	if (ft_extension_check(argv) == 1)
		return (write(1, "extension error\n", 16));
	if (ft_check2(&va) == 1)
		return (write(1, "least caracter\n", 15));
	va.ptr = mlx_init();
	va.win = mlx_new_window(va.ptr, va.width * 50, va.height * 50, "so_long");
	ft_link_image (&va);
	ft_draw_map (&va);
	mlx_hook (va.win, 2, 0, key_hook, &va);
	mlx_hook (va.win, 17, 0, ft_close, &va);
	mlx_loop (va.ptr);
}
