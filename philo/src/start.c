/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:35 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 16:29:37 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start(t_info *ps)
{
	long t;

	ft_pthread_mutex_lock(ps->start);
	t = current_t();
	ps->start_time = t;
	ft_pthread_mutex_lock(ps->last_eat_lock);
	ps->death_time = t + ps->die;
	ft_pthread_mutex_unlock(ps->last_eat_lock);
	ft_pthread_mutex_unlock(ps->start);
}