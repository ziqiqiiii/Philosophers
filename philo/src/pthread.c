/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:26 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 14:51:36 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pthreadjoin(t_info *ps)
{
	int	i;

	i = -1;
	while (++i < ps[0].num)
	{
		ft_pthread_join(ps[i].philos);
		free(ps[i].philos);
	}
}

void	mutexdestroy(t_info *ps)
{
	int	i;

	i = -1;
	while (++i < ps->num)
		ft_pthread_mutex_destroy(&ps->forks->forks[i]);
	free(ps->forks->forks);
	free(ps->forks);
	ft_pthread_mutex_destroy(&ps->mutex->print);
	ft_pthread_mutex_destroy(&ps->mutex->death_block);
	ft_pthread_mutex_destroy(&ps->mutex->eaten);
	ft_pthread_mutex_destroy(&ps->mutex->last_eat_lock);
	free(ps->mutex);
	free(ps->death_state);
	free(ps->eat_flag);
	free(ps);
}
