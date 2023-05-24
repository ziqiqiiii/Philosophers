/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/24 14:08:31 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char	*choose_colour(int id)
{
	if (id == 2)
		return (RED);
	else if (id == 3)
		return (YELLOW);
	else if (id == 4)
		return (BLUE);
	else if (id == 5)
		return (GREEN);
	else if (id == 6)
		return (NC);
	else
		return (TEAL);
}

void	print_fork_n_dead(t_info *ps, int c, long t, char *colour)
{
	if (c == 'f')
	{
		printf("%s%ld %d has taken a fork\n%s", colour, \
				t - ps->start_time, ps->id + 1, NC);
		printf("%s%ld %d has taken a fork\n%s", colour, \
				t - ps->start_time, ps->id + 1, NC);
	}
	else if (c == 'd' && *ps->death_state == 1)
	{
		printf("%s%ld %d died\n%s", PINK, \
				t - ps->start_time, ps->id + 1, NC);
	}
}

void	print(t_info *ps, int c)
{
	long	t;
	char	*colour;

	colour = choose_colour(ps->id + 1);
	ft_pthread_mutex_lock(&ps->mutex->print);
	t = current_t();
	if (c == 't')
	{
		printf("%s%ld %d is thinking%s\n", colour, \
				t - ps->start_time, ps->id + 1, NC);
	}
	else if (c == 'e')
	{
		printf("%s%ld %d is eating%s\n", colour, \
				t - ps->start_time, ps->id + 1, NC);
	}
	else if (c == 's')
	{
		printf("%s%ld %d is sleeping%s\n", colour, \
				t - ps->start_time, ps->id + 1, NC);
	}
	print_fork_n_dead(ps, c, t, colour);
	ft_pthread_mutex_unlock(&ps->mutex->print);
}
