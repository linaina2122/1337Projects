/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:50:25 by hcharef           #+#    #+#             */
/*   Updated: 2022/10/13 08:00:34 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	thread_create(t_all *all)
{
	all->count = 0;
	while (all->count < all->n_philo)
	{
		if (pthread_create(&(all)->th[all->count], NULL, &routine, \
			&all->philo[all->count]))
			return (1);
		usleep(60);
		all->count++;
	}
	sup_fun(all);
	all->count = 0;
	while (all->count < all->n_philo)
	{
		pthread_detach(all->th[all->count]);
		all->count++;
	}
	return (0);
}

int	mutex_create(t_all *all)
{
	int	count;

	count = 0;
	pthread_mutex_init(&all->print, NULL);
	pthread_mutex_init(&all->pcounter, NULL);
	pthread_mutex_init(&all->pflag, NULL);
	pthread_mutex_init(&all->plast_eat, NULL);
	while (count < all->n_philo)
	{
		pthread_mutex_init(&all->forks[count], NULL);
		count++;
	}
	return (0);
}
