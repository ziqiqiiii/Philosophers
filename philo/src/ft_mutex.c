/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:57 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 15:16:18 by tzi-qi           ###   ########.fr       */
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