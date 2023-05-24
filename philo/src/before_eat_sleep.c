/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    before_eat_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:18:03 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 14:18:31 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	before_sleep(t_info *ps)
{
	long	t;
	int		i;
	long	death_time;

	i = 0;
	if (helper(ps) != 0)
		return (1);
	ft_pthread_mutex_lock(&ps->mutex->last_eat_lock);
	death_time = ps->death_time;
	ft_pthread_mutex_unlock(&ps->mutex->last_eat_lock);
	t = current_t();
	if (t + ps->sleep > death_time)
	{
		ft_pthread_mutex_lock(&ps->mutex->death_block);
		*ps->death_state += 1;
		ft_usleep(death_time - t);
		print(ps, 'd');
		ft_pthread_mutex_unlock(&ps->mutex->death_block);
		i = 1;
	}
	return (i);
}

int	before_eat(t_info *ps)
{
	long	t;
	int		i;
	long	death_time;

	i = 0;
	if (helper(ps) != 0)
		return (1);
	ft_pthread_mutex_lock(&ps->mutex->last_eat_lock);
	death_time = ps->death_time;
	ft_pthread_mutex_unlock(&ps->mutex->last_eat_lock);
	t = current_t();
	if (t + ps->sleep > death_time)
	{
		ft_pthread_mutex_lock(&ps->mutex->death_block);
		*ps->death_state += 1;
		ft_usleep(death_time - t);
		print(ps, 'd');
		ft_pthread_mutex_unlock(&ps->mutex->death_block);
		i = 1;
	}
	return (i);
}
