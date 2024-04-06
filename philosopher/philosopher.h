/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 06:46:28 by marvin            #+#    #+#             */
/*   Updated: 2022/08/02 06:46:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				index;
	long			last_eat;
	int				id;
	struct s_all	*all;
}		t_philos;

typedef struct s_all
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	plast_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	pcounter;
	pthread_mutex_t	pflag;
	pthread_mutex_t	try;
	pthread_t		*th;
	long			start;
	int				count;
	int				t_die;
	int				index;
	int				flag;
	int				counter;
	int				n_philo;
	int				t_sleep;
	int				n_meals;
	int				t_eat;
	t_philos		*philo;
}		t_all;

int		ft_atoi(const char *str);
int		check_digit(int argc, char **argv);
int		fill_args(t_all *strct, char **argv, int argc);
void	*routine(void *arg);
int		thread_create(t_all *all);
int		mutex_create(t_all *all);
long	get_time(void);
void	sup_fun(t_all *all);
int		check_flag(t_all *all);
void	ussleep(int num);
void	check_flags(t_all	*all, int flag);
int		last_meal(t_all *all);
void	fnorm(t_all *all);

#endif