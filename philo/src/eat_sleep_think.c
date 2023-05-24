/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:35:25 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 12:21:08 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	thinking(t_info *ps)
{
	print(ps, 't');
}

void	sleeping(t_info *ps)
{
	if (before_sleep(ps) == 0)
	{
		print(ps, 's');
		ft_usleep(ps->sleep);
	}
}

void	eating(t_info *ps)
{
	pick_up(ps);
	put_down(ps);
}

void	pick_up(t_info *ps)
{
	t_forks	*f;
	int		num;

	f = (t_forks *)ps->forks;
	num = ps->num;
	if (helper(ps) != 0)
		return ;
	if (even_odd(ps->id) == 0)
	{
		ft_pthread_mutex_lock(&f->forks[ps->id]);
		ft_pthread_mutex_lock(&f->forks[(ps->id + 1) % num]);
	}
	else
	{
		ft_pthread_mutex_lock(&f->forks[(ps->id + 1) % num]);
		ft_pthread_mutex_lock(&f->forks[ps->id]);
	}
	if (helper(ps) != 0)
		return ;
	print(ps, 'f');
}

void	put_down(t_info *ps)
{
	t_forks	*f;
	int		num;

	f = (t_forks *)ps->forks;
	num = ps->num;
	if (before_eat(ps) == 0)
	{
		print(ps, 'e');
		ft_usleep(ps->eat);
	}
	if (even_odd(ps->id) == 0)
	{
		ft_pthread_mutex_unlock(&f->forks[(ps->id + 1) % num]);
		ft_pthread_mutex_unlock(&f->forks[ps->id]);
	}
	else
	{
		ft_pthread_mutex_unlock(&f->forks[ps->id]);
		ft_pthread_mutex_unlock(&f->forks[(ps->id + 1) % num]);
	}
	ft_pthread_mutex_lock(&ps->mutex->last_eat_lock);
	ps->death_time = current_t() + ps->die;
	ft_pthread_mutex_unlock(&ps->mutex->last_eat_lock);
}
