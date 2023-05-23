/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:57 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/23 19:45:03 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_pthread_mutex_lock(pthread_mutex_t *c)
{
	if (pthread_mutex_lock(c) != 0)
		exit(printf("Lock Failed"));
}

void	ft_pthread_mutex_unlock(pthread_mutex_t *c)
{
	if (pthread_mutex_unlock(c) != 0)
		exit(printf("Unlock Failed"));
}

void	ft_pthread_mutex_destroy(pthread_mutex_t *c)
{
	if (pthread_mutex_destroy(c) != 0)
		exit(printf("Error Mutex Destroyed"));
}

void	ft_pthread_join(pthread_t *philo)
{
	if (pthread_join(*philo, NULL) != 0)
		exit(printf("Error joining the threads"));
}