/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 06:46:13 by marvin            #+#    #+#             */
/*   Updated: 2022/08/02 06:46:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static	int	allocation(t_all *strct)
{
	strct->philo = malloc(sizeof(t_philos) * strct->n_philo);
	if (!strct->philo)
		return (-1);
	strct->th = malloc(sizeof(pthread_t) * strct->n_philo);
	if (!strct->th)
		return (-1);
	strct->forks = malloc(sizeof(pthread_mutex_t) * strct->n_philo);
	if (!strct->forks)
		return (-1);
	return (0);
}

static	void	last_eat_init(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->n_philo)
	{
		all->philo[i].last_eat = get_time();
		i++;
	}
}

static	int	fill_arg(t_all *strct, char **argv, int argc)
{
	strct->n_philo = ft_atoi(argv[1]);
	if (strct->n_philo == -1 || strct->n_philo == 0)
		return (-2);
	strct->t_die = ft_atoi(argv[2]);
	if (strct->t_die == -1)
		return (-2);
	strct->t_eat = ft_atoi(argv[3]);
	if (strct->t_eat == -1)
		return (-2);
	strct->t_sleep = ft_atoi(argv[4]);
	if (strct->t_sleep == -1)
		return (-2);
	strct->n_meals = -1;
	if (argc == 6)
	{
		strct->n_meals = ft_atoi(argv[5]);
		if (strct->n_meals == -1)
			return (-2);
	}
	return (0);
}

int	fill_args(t_all *strct, char **argv, int argc)
{
	int	count;

	count = 0;
	if (fill_arg(strct, argv, argc) == -2)
		return (-1);
	if (allocation(strct) == -1)
		return (-1);
	while (count < strct->n_philo)
	{
		strct->philo[count].id = count + 1;
		strct->philo[count].l_fork = &strct->forks[count];
		strct->philo[count].r_fork = &strct->forks[(count + 1) \
		% strct->n_philo];
		strct->philo[count].all = strct;
		strct->philo[count].index = 0;
		count++;
	}
	strct->counter = 0;
	strct->flag = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc < 5 || argc > 6 || check_digit(argc, argv))
	{
		printf("error\n");
		return (0);
	}
	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	if (fill_args(all, argv, argc) == -1)
	{
		printf ("error\n");
		return (0);
	}
	if (mutex_create(all))
		return (0);
	all->start = get_time();
	last_eat_init(all);
	if (thread_create(all))
		return (0);
	return (0);
}
