/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:08 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/05/18 15:57:23 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_forks *initialize_fork(int num)
{
	t_forks *f;
	int     i;

	f = (t_forks *)malloc(sizeof(t_forks));
	i = 0;
	f->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	while (i < num)
	{
		pthread_mutex_init(&f->forks[i], NULL);
		i++;
	}
	return (f);
}

void    init_mutex(t_info *ps, int num)
{
	int i;
	t_mutex *mutex;

	i = -1;
	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->death_block, NULL);
	pthread_mutex_init(&mutex->last_eat_lock, NULL);
	pthread_mutex_init(&mutex->eaten, NULL);
	pthread_mutex_init(&mutex->start, NULL);
	pthread_mutex_init(&mutex->eat_flag, NULL);
	while (++i < num)
		ps[i].mutex = mutex;
}

t_info *initialize(int argc, char **argv)
{
	t_info *ps;
	t_forks *forks;
	int     num;
	int     i;
	int     *j;
	long    sleep;
	long    die;
	long    eat;
	int     min_eat;
	int		*eat_flag;
	long    t;
	int		*death_state;

	num = ft_atoi(argv[1]);
	die = ft_atoi(argv[2]);
	eat = ft_atoi(argv[3]);
	sleep = ft_atoi(argv[4]);
	if (argc == 6)
		min_eat = ft_atoi(argv[5]);
	else
		min_eat = -1;
	// printf("min eat in init %i\n", min_eat);
	ps = (t_info *)malloc(sizeof(t_info) * num);
	forks = initialize_fork(num);
	init_mutex(ps, num);
	death_state = malloc(sizeof(int));
	*death_state = 0;
	eat_flag = malloc(sizeof(int));
	*eat_flag = 0;
	i = -1;
	while (++i < num)
	{
		ps[i].philos = (pthread_t)malloc(sizeof(pthread_t));
		ps[i].forks = forks;
		ps[i].id = i;
		ps[i].num = num;
		ps[i].sleep = sleep;
		ps[i].die = die;
		ps[i].eat = eat;
		ps[i].min_eat = min_eat;
		ps[i].eaten	= 0;
		ps[i].death_state = death_state;
		ps[i].eat_flag = eat_flag;
		if (pthread_create(&ps[i].philos, NULL, (void *)philosopher, (void *)(ps + i)) != 0)
		{
			printf("\nThread creation error\n");
			exit (1);
		}
	}
	return(ps);
}