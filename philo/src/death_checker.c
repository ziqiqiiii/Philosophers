/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:48 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/23 19:39:28 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	eat_flag_checker(t_info	*ps, int i, )
// {
	
// }

void	death_checker(t_info *ps)
{
	int		i;
	long	death_time;
	long	t;
	int		eaten;

	i = 0;
	while (1)
	{
		if (i + 1 > ps[0].num)
            i = 0;
		if (helper(&ps[i]) != 0)
			break ;
		ft_pthread_mutex_lock(&ps[i].mutex->last_eat_lock);
		death_time = ps[i].death_time;
		ft_pthread_mutex_unlock(&ps[i].mutex->last_eat_lock);
		t = current_t();
		if (t > death_time)
		{
			ft_pthread_mutex_lock(&ps[i].mutex->death_block);
			*ps[i].death_state += 1;
			print(ps, 'd');
			ft_pthread_mutex_unlock(&ps[i].mutex->death_block);
			break ;
		}
		ft_pthread_mutex_lock(&ps[i].mutex->eaten);
		eaten = ps[i].eaten;
		ft_pthread_mutex_unlock(&ps[i].mutex->eaten);
		if (eaten == ps[i].min_eat)
		{
			ft_pthread_mutex_lock(&ps[i].mutex->eat_flag);
			*ps[i].eat_flag = 1;
			ft_pthread_mutex_unlock(&ps[i].mutex->eat_flag);
			break ;
		}
		ft_usleep(10);
		i++;
	}
}

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
