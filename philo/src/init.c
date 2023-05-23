/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:08 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/23 20:31:05 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	initialize_fork(int num, t_info *ps)
{
	t_forks	*f;
	int		i;

	f = (t_forks *)malloc(sizeof(t_forks));
	i = 0;
	f->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	while (i < num)
	{
		pthread_mutex_init(&f->forks[i], NULL);
		ps[i].forks = f;
		i++;
	}
}

void	init_mutex(t_info *ps, int num)
{
	int		i;
	t_mutex	*mutex;

	i = -1;
	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->death_block, NULL);
	pthread_mutex_init(&mutex->last_eat_lock, NULL);
	pthread_mutex_init(&mutex->eaten, NULL);
	pthread_mutex_init(&mutex->eat_flag, NULL);
	while (++i < num)
		ps[i].mutex = mutex;
}

void	init_data(int argc, char **argv, t_info *ps)
{
	int		num;
	long	sleep;
	long	die;
	long	eat;
	int		i;

	num = ft_atoi(argv[1]);
	die = ft_atoi(argv[2]);
	eat = ft_atoi(argv[3]);
	sleep = ft_atoi(argv[4]);
	i = -1;
	while (++i < num)
	{
		ps[i].id = i;
		ps[i].num = num;
		ps[i].sleep = sleep;
		ps[i].die = die;
		ps[i].eat = eat;
	}
}

t_info	*initialize(int argc, char **argv)
{
	t_info	*ps;
	// int		num;
	int		i;
	// long	sleep;
	// long	die;
	// long	eat;
	int		min_eat;
	int		*eat_flag;
	long	t;
	int		*death_state;

	// num = ft_atoi(argv[1]);
	// die = ft_atoi(argv[2]);
	// eat = ft_atoi(argv[3]);
	// sleep = ft_atoi(argv[4]);
	if (argc == 6)
		min_eat = ft_atoi(argv[5]);
	else
		min_eat = -1;
	ps = (t_info *)malloc(sizeof(t_info) * num);
	init_data(argc, argv, ps);
	initialize_fork(ps->num, ps);
	init_mutex(ps, ps->num);
	death_state = malloc(sizeof(int));
	*death_state = 0;
	eat_flag = malloc(sizeof(int));
	*eat_flag = 0;
	i = -1;
	t = current_t();
	while (++i < ps->num)
	{
		ps[i].philos = (pthread_t *)malloc(sizeof(pthread_t));
		// ps[i].id = i;
		// ps[i].num = num;
		// ps[i].sleep = sleep;
		// ps[i].die = die;
		// ps[i].eat = eat;
		ps[i].min_eat = min_eat;
		ps[i].eaten = 0;
		ps[i].death_state = death_state;
		ps[i].eat_flag = eat_flag;
		ps[i].start_time = t;
		ps[i].death_time = ps[i].start_time + ps[i].die;
		if (pthread_create(ps[i].philos, NULL, \
			(void *)philosopher, (void *)(ps + i)) != 0)
			exit(printf("\nThread creation error"));
	}
	return (ps);
}
