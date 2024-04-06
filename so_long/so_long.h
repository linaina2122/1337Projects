/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:58:12 by hcharef           #+#    #+#             */
/*   Updated: 2022/03/24 19:34:14 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_my_struct
{
	int		i;
	int		j;
	int		hp;
	int		wp;
	int		width;
	int		height;
	int		fd;
	int		fd1;
	char	**split;
	int		new_img;
	int		count;
	int		countp;
	int		counte;
	int		countc;
	int		count0;
	int		count1;
	int		hcount;
	char	*path_back;
	void	*img_back;
	char	*path_wall;
	void	*img_wall;
	char	*col_path;
	void	*col_img;
	char	*exit_path;
	void	*exit_img;
	char	*player_path;
	void	*player_img;
	int		wcount;
	void	*ptr;
	void	*win;
	int		ht;
	int		wt;
	int		move_count;
}t_my_struct;

void	ft_map_dim(t_my_struct *va, char **argv);
void	ft_file_check(t_my_struct *va, char **argv);
int		ft_wall_check(t_my_struct *va);
int		ft_check(t_my_struct *va);
void	ft_find(t_my_struct *va);
int		ft_check2(t_my_struct *va);
void	ft_wall(t_my_struct *va);
void	ft_background(t_my_struct *va);
void	ft_collectible(t_my_struct *va);
void	ft_exit(t_my_struct *va);
void	ft_player(t_my_struct *va);
int		ft_exit_win(int keycode, t_my_struct *va);
void	ft_d_move(t_my_struct *va);
int		ft_e_move(t_my_struct *va);
void	ft_s_move(t_my_struct *va);
void	ft_a_move(t_my_struct *va);
int		key_hook(int keycode, t_my_struct *va);
void	ft_exit1(void);
void	ft_draw_map(t_my_struct *va);
int		ft_extension_check(char **argv);
int		ft_close(void);
void	ft_error(void);
int		ft_len_check(t_my_struct *va);
void	ft_link_image(t_my_struct *va);

#endif