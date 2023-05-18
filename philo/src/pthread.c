/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:26 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 15:58:51 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    pthreadjoin(t_info *ps)
{
    int i;

    i = -1;
    // printf("nummmmm? %li\n", ps[1].eat);
    // printf("pthreadjoin %i %p\n", *ps->death_state, ps->death_state);
    while (++i < ps->num)
    {
        if (pthread_join(ps[i].philos, NULL) != 0)
        {
            printf("\nError joining the threads\n");
            exit(1);
        }
    }
}

void free_mutex(t_mutex *mutex)
{
    pthread_mutex_destroy(&mutex->print);
    pthread_mutex_destroy(&mutex->death_block);
    pthread_mutex_destroy(&mutex->last_eat_lock);
    pthread_mutex_destroy(&mutex->death_checker);
    pthread_mutex_destroy(&mutex->start);
    free(mutex);
}

void    mutexdestroy(t_info *ps)
{
    int i;

    i = -1;
    while (++i < ps->num)
    {
        if (pthread_mutex_destroy(&ps->forks->forks[i]) != 0)
        {
            printf("\nError Mutex Destroyed\n");
            exit(1);
        }
    }
    free_mutex(ps[0].mutex);
}