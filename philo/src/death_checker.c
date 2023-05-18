/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:48 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 17:23:05 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void death_checker(t_info *ps)
{
    int		i;
    long	death_time;
	long	t;

    i = 0;
    while (1)
    {
        if (i + 1 > ps[0].num)
            i = 0;
        if (helper(&ps[i]) != 0)
            break ;
        ft_pthread_mutex_lock(ps[i].last_eat_lock);
        death_time = ps[i].death_time;
        ft_pthread_mutex_unlock(ps[i].last_eat_lock);
		t = current_t();
		// printf("%i cuurent - death_t %li | die %li\n", ps[i].id + 1, t - death_time, ps->die);
        if (t > death_time)
        {   
            ft_pthread_mutex_lock(ps[i].death_block);
            *ps[i].death_state += 1;
			printf("%i death checker %i\n", *ps[i].death_state , ps[i].id + 1);
            print(ps, 'd');
            ft_pthread_mutex_unlock(ps[i].death_block);
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
	ft_pthread_mutex_lock(ps->last_eat_lock);
	death_time = ps->death_time;
	ft_pthread_mutex_unlock(ps->last_eat_lock);
	t = current_t();
   	if (t + ps->sleep > death_time)
	{
		ft_usleep(death_time - t);
		ft_pthread_mutex_lock(ps->death_block);
		*ps->death_state += 1;
		printf("%i before sleep %i time %li\n", *ps->death_state, ps->id + 1, t + ps->sleep - death_time);
		print(ps, 'd');
		ft_pthread_mutex_unlock(ps->death_block);
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
	ft_pthread_mutex_lock(ps->last_eat_lock);
	death_time = ps->death_time;
	ft_pthread_mutex_unlock(ps->last_eat_lock);
	t = current_t();
	if (t + ps->sleep > death_time)
	{
		ft_usleep(death_time - t);
		ft_pthread_mutex_lock(ps->death_block);
		*ps->death_state += 1;
		printf("%i before eat %i time %li\n", *ps->death_state, ps->id + 1, t + ps->eat - death_time);		print(ps, 'd');
		ft_pthread_mutex_unlock(ps->death_block);
		i = 1;
	}
	return (i);
}

int helper(t_info *ps)
{
    int i;

    i = 0;
    ft_pthread_mutex_lock(ps->death_block);
    if (*(ps->death_state) != 0)
        i = 1;
    ft_pthread_mutex_unlock(ps->death_block);
    return (i);
}