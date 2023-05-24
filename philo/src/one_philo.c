/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:28:13 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 15:10:51 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	one_philo(t_info *ps)
{
	int	death_state;

	ft_pthread_mutex_lock(&ps->forks->forks[0]);
	ft_pthread_mutex_lock(&ps->mutex->print);
	printf("%s%ld %d has taken a fork\n%s", PEACH, \
			current_t() - ps->start_time, ps->id + 1, NC);
	ft_pthread_mutex_unlock(&ps->mutex->print);
	while (1)
	{
		if (helper(ps) != 0)
		{
			ft_pthread_mutex_unlock(&ps->forks->forks[0]);
			break ;
		}
		ft_usleep(50);
	}
}
