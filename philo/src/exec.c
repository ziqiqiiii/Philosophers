/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:59 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 14:53:31 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_num_checker(t_info *ps)
{
	if (ps->num == 1)
	{
		one_philo(ps);
		return (1);
	}
	else
		return (0);
}

void	philosopher(void *v)
{
	t_info	*ps;

	ps = (t_info *)v;
	if (philo_num_checker(ps) == 1)
		return ;
	if ((ps->id + 1) % 2 == 1)
	{
		thinking(ps);
		ft_usleep(30);
	}
	while (helper(ps) == 0)
	{
		eating(ps);
		if (helper(ps) != 0)
			break ;
		sleeping(ps);
		if (helper(ps) != 0)
			break ;
		thinking(ps);
		ft_pthread_mutex_lock(&ps->mutex->eaten);
			ps->eaten += 1;
		ft_pthread_mutex_unlock(&ps->mutex->eaten);
	}
}
