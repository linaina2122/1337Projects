/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:54:16 by marvin            #+#    #+#             */
/*   Updated: 2022/07/31 13:54:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

void    thread_create(t_all *thread)
{
    pthread_t *philo;
    int thread;
    int count;

    count = 0;
    philo = malloc(sizeof(pthread_t));
    if(!philo)
        error();
    while(count < thread->number_of_philo)
    {
        thread = pthread_create(&philo[count], NULL, routine, &philo[count]);
        if(thread != 0)
            error();
        count++;
    }
}

void    philo_init(t_all *philosopher)
{
    int count;
    int thread;
    pthread_t philo;

    count = 1;
    philospher->philo = malloc(sizeof(t_philo) * philosopher->number_of_philo);
    if(!philosopher->philo)
        error();
    philosopher->fork = malloc(sizeof(int) * philosopher->number_of_philo);
    if(!philosopher->fork)
        error();
    while(count <= philosopher->number_of_philo)
    {
        philosopher->philo[count] = count;
        philosopher->philo->left_fork = count;
        philosopher->philo->right_fork = (count + 1) % philosopher->number_of_philo;
        philosopher->philo->eat = 0;
        philosopher->philo->sleep = 0;
        philosopher->philo->think = 0;
        count++;
    }
    count = 0;
}


void    mutex_init(t_all *init)
{
    int count;
    count = 0;
    init->print = malloc(sizeof(pthread_mutex_t));
    if(!init->print)
        error();
    pthread_mutex_init(init->print, NULL);
    init->forks = malloc(sizeof(pthread_mutex_t) * init->number_of_philo)
    if(!init->forks)
        error();
    while(count < init->number_of_philo)
    {
        pthread_mutex_init(&init->forks[count]);
        count++;
    }
}

void*   routine(void *arg)
{
    t_all print;
    print.print = (void)arg;
    pthread_mutex_lock(&print.print);
   printf("here\n");
   pthread_mutex_unlock(&print.print);
   return(arg);

}