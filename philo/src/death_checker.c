/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:48 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 15:10:58 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat_checker(t_info *ps)
{
	int	i;
	int	eaten;

	i = 0;
	ft_pthread_mutex_lock(&ps->mutex->eaten);
	eaten = ps->eaten;
	ft_pthread_mutex_unlock(&ps->mutex->eaten);
	if (eaten == ps->min_eat)
	{
		ft_pthread_mutex_lock(&ps->mutex->eat_flag);
		*ps->eat_flag = 1;
		i = 1;
		ft_pthread_mutex_unlock(&ps->mutex->eat_flag);
	}
	return (i);
}

int	death_checker(t_info	*ps)
{
	long	death_time;
	long	t;
	int		i;
	int		j;

	i = 0;
	ft_pthread_mutex_lock(&ps->mutex->last_eat_lock);
	death_time = ps->death_time;
	ft_pthread_mutex_unlock(&ps->mutex->last_eat_lock);
	t = current_t();
	if (t > death_time)
	{
		ft_pthread_mutex_lock(&ps->mutex->death_block);
		*ps->death_state += 1;
		print(ps, 'd');
		i = 1;
		ft_pthread_mutex_unlock(&ps->mutex->death_block);
	}
	return (i);
}

void	checker(t_info	*ps)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i + 1 > ps[0].num)
			i = 0;
		if (helper(&ps[i]) != 0)
			break ;
		if (death_checker(ps) == 1)
			break ;
		if (eat_checker(ps) == 1)
			break ;
		ft_usleep(10);
		i++;
	}
}

int	helper(t_info *ps)
{
	int	i;

	i = 0;
	ft_pthread_mutex_lock(&ps->mutex->death_block);
	if (*(ps->death_state) != 0)
		i = 1;
	ft_pthread_mutex_unlock(&ps->mutex->death_block);
	ft_pthread_mutex_lock(&ps->mutex->eat_flag);
	if (*(ps->eat_flag) == 1)
		i = 1;
	ft_pthread_mutex_unlock(&ps->mutex->eat_flag);
	return (i);
}
