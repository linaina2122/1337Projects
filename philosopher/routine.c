/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:54:30 by hcharef           #+#    #+#             */
/*   Updated: 2022/10/13 07:37:22 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	last_meal(t_all *all)
{
	pthread_mutex_lock(&all->pcounter);
	if (all->counter >= all->n_philo)
	{
		pthread_mutex_lock(&all->pflag);
		all->flag = 0;
		pthread_mutex_unlock(&all->pflag);
		return (1);
	}
	pthread_mutex_unlock(&all->pcounter);
	return (0);
}

static	void	forks_lock_unlock(t_philos *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->all->pflag);
	if (philo->all->flag == 0)
		return ;
	pthread_mutex_unlock(&philo->all->pflag);
	pthread_mutex_lock(&philo->all->print);
	printf("%ld %d  has taken a fork\n\
", get_time() - philo->all->start, philo->id);
	pthread_mutex_unlock(&philo->all->print);
	pthread_mutex_lock(philo->r_fork);
	fnorm(philo->all);
	pthread_mutex_lock(&philo->all->print);
	printf("%ld %d  has taken a fork\n\
", get_time() - philo->all->start, philo->id);
	fnorm(philo->all);
	pthread_mutex_unlock(&philo->all->print);
	printf("%ld %d is eating\n\
", get_time() - philo->all->start, philo->id);
	pthread_mutex_unlock(&philo->all->print);
	pthread_mutex_lock(&philo->all->plast_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->all->plast_eat);
	ussleep(philo->all->t_eat);
	philo->index++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static	void	meal_check(t_philos *philo)
{
	if (philo->all->n_meals != -1 && (philo->index >= philo->all->n_meals))
	{
		pthread_mutex_lock(&philo->all->pcounter);
		philo->all->counter++;
		pthread_mutex_unlock(&philo->all->pcounter);
	}
}

static	void	sleep_think(t_philos *philo)
{
	pthread_mutex_lock(&philo->all->print);
	printf("%ld %d is sleeping\n\
", get_time() - philo->all->start, philo->id);
	pthread_mutex_unlock(&philo->all->print);
	ussleep(philo->all->t_sleep);
	pthread_mutex_lock(&philo->all->pflag);
	check_flags(philo->all, philo->all->flag);
	pthread_mutex_unlock(&philo->all->pflag);
	pthread_mutex_lock(&philo->all->print);
	printf("%ld %d is thinking\n\
", get_time() - philo->all->start, philo->id);
	pthread_mutex_unlock(&philo->all->print);
}

void	*routine(void *arg)
{
	t_philos	*philo;
	int			flagy;

	philo = (t_philos *)arg;
	flagy = 1;
	while (flagy)
	{
		pthread_mutex_lock(&philo->all->pflag);
		flagy = philo->all->flag;
		pthread_mutex_unlock(&philo->all->pflag);
		forks_lock_unlock(philo);
		meal_check(philo);
		check_flags(philo->all, flagy);
		sleep_think(philo);
	}
	return (NULL);
}
