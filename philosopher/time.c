/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:41:44 by hcharef           #+#    #+#             */
/*   Updated: 2022/10/13 07:49:51 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ussleep(int num)
{
	long	start;

	start = get_time();
	while (get_time() - start < num)
		usleep(100);
}

void	sup_fun(t_all *all)
{
	int	flagy;

	flagy = 1;
	while (flagy)
	{
		pthread_mutex_lock(&all->pflag);
		flagy = all->flag;
		pthread_mutex_unlock(&all->pflag);
		pthread_mutex_lock(&all->plast_eat);
		if (get_time() - all->philo[all->philo->id - 1].last_eat >= all->t_die)
		{
			pthread_mutex_lock(&all->pflag);
			all->flag = 0;
			pthread_mutex_unlock(&all->pflag);
			pthread_mutex_lock(&all->print);
			printf("%ld %d died\n", get_time() - all->start, all->philo->id);
			return ;
		}
		if (last_meal(all))
			return ;
		pthread_mutex_unlock(&all->plast_eat);
	}
}
